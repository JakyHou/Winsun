//#include "stdafx.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef struct
{
	BITMAPFILEHEADER file_header;
	BITMAPINFOHEADER info_header;
	unsigned long width,height;
	//BYTE *rgbData;
}BMPSTRUCT;

BMPSTRUCT bmp;

static bool MakePalette(FILE * pFile,BITMAPFILEHEADER &file_h,BITMAPINFOHEADER & info_h,RGBQUAD *pRGB_out)
{
	if ((file_h.bfOffBits - sizeof(BITMAPFILEHEADER) - info_h.biSize) == sizeof(RGBQUAD)*pow(float(2),info_h.biBitCount))
	{
		fseek(pFile,sizeof(BITMAPFILEHEADER)+info_h.biSize,0);
		fread(pRGB_out,sizeof(RGBQUAD),(unsigned int)pow(float(2),info_h.biBitCount),pFile);
		return true;
	}
	else
		return false;
}

static void ReadRGB(FILE * pFile,BITMAPFILEHEADER & file_h,BITMAPINFOHEADER & info_h,unsigned char * rgbDataOut)
{
	unsigned long Loop,iLoop,jLoop,width,height,w,h;
	unsigned char mask,*Index_Data,* Data;

	if (((info_h.biWidth/8*info_h.biBitCount)%4) == 0)
		w = info_h.biWidth;
	else
		w = (info_h.biWidth*info_h.biBitCount+31)/32*4;
	if ((info_h.biHeight%2) == 0)
		h = info_h.biHeight;
	else
		h = info_h.biHeight + 1;

	width = w/8*info_h.biBitCount;
	height = h;

	Index_Data = (unsigned char *)malloc(height*width);
	Data = (unsigned char *)malloc(height*width);

	fseek(pFile,file_h.bfOffBits,0);
	if(fread(Index_Data,height*width,1,pFile) != 1)
	{
		printf("read file error!\n\n");
		exit(0);
	}


	for ( iLoop = 0;iLoop < height;iLoop ++)
		for (jLoop = 0;jLoop < width;jLoop++)
		{
 			Data[iLoop*width+jLoop] = Index_Data[(height-iLoop-1)*width+jLoop];
		}

	switch(info_h.biBitCount)
	{
	case 32:
		for(Loop=0;Loop<w*h;Loop++)
		{
			rgbDataOut[Loop*3+0]=Data[Loop*4+0];
			rgbDataOut[Loop*3+1]=Data[Loop*4+1];
			rgbDataOut[Loop*3+2]=Data[Loop*4+2];
		}
		if(Index_Data)
			free(Index_Data);
		if(Data)
			free(Data);
		return;
	case 24:
		memcpy(rgbDataOut,Data,height*width);
		if(Index_Data)
			free(Index_Data);
		if(Data)
			free(Data);
		return;
	case 16:
		if(info_h.biCompression == BI_RGB)
		{
			for (Loop = 0;Loop < height * width;Loop +=2)
			{
				*rgbDataOut = (Data[Loop]&0x1F)<<3;
				*(rgbDataOut + 1) = ((Data[Loop]&0xE0)>>2) + ((Data[Loop+1]&0x03)<<6);
				*(rgbDataOut + 2) = (Data[Loop+1]&0x7C)<<1;

				rgbDataOut +=3;
			}
		}
		if(Index_Data)
			free(Index_Data);
		if(Data)
			free(Data);
		return;
	default:
		RGBQUAD *pRGB = (RGBQUAD *)malloc(sizeof(RGBQUAD)*(unsigned int)pow(float(2),info_h.biBitCount));
		int temp = sizeof(pRGB);
		if(!MakePalette(pFile,file_h,info_h,pRGB))
			printf("No palette!\n\n");

		for (Loop=0;Loop<height*width;Loop++)
		{
		
			switch(info_h.biBitCount)
			{
			case 1:
				mask = 0x80;
				break;
			case 2:
				mask = 0xC0;
				break;
			case 4:
				mask = 0xF0;
				break;
			case 8:
				mask = 0xFF;
			}

			int shiftCnt = 1;

			while (mask)
			{
				unsigned char index = mask == 0xFF ? Data[Loop] : ((Data[Loop] & mask)>>(8 - shiftCnt * info_h.biBitCount));
				* rgbDataOut = pRGB[index].rgbBlue;
				* (rgbDataOut+1) = pRGB[index].rgbGreen;
				* (rgbDataOut+2) = pRGB[index].rgbRed;

				if(info_h.biBitCount == 8)
					mask =0;
				else
					mask >>= info_h.biBitCount;
				rgbDataOut+=3;
				shiftCnt ++;
			}
		}
		if(Index_Data)
			free(Index_Data);
		if(Data)
			free(Data);
 		if(pRGB)
 			free(pRGB);
	}

}


bool ReadBmp(const char *strFileName,unsigned long *width,unsigned long *height,BYTE *rgbData)
{
	FILE *bmpFile;

	if(rgbData == NULL)
		return false;

	bmpFile=fopen(strFileName,"rb");

	if(fread(&bmp.file_header,sizeof(BITMAPFILEHEADER),1,bmpFile) != 1)
	{
		printf("read file header error!\n\n");
		return false;
	}
	
	if (bmp.file_header.bfType != 0x4D42)
	{
		printf("Not bmp file!\n\n");
		return false;
	}
	if(fread(&bmp.info_header,sizeof(BITMAPINFOHEADER),1,bmpFile) != 1)
	{
		printf("read info header error!\n\n");
		return false;
	}

	if(bmp.info_header.biWidth <=0 || bmp.info_header.biHeight<=0)
	{
		fclose(bmpFile);
		return false;
	}
	
	if (((bmp.info_header.biWidth/8*bmp.info_header.biBitCount)%4) == 0)
		bmp.width = bmp.info_header.biWidth;
	else
		bmp.width = (bmp.info_header.biWidth*bmp.info_header.biBitCount+31)/32*4;
	if ((bmp.info_header.biHeight%2) == 0)
		bmp.height = bmp.info_header.biHeight;
	else
		bmp.height = bmp.info_header.biHeight + 1;
	
	//bmp.rgbData = (unsigned char *)malloc(bmp.height*bmp.width*3);
	memset(rgbData,0,bmp.height*bmp.width*3);
	
	printf("This is a %d bits image!\n",bmp.info_header.biBitCount);
	printf("\nbmp size: \t%d X %d\n\n",bmp.info_header.biWidth,bmp.info_header.biHeight);
	
	ReadRGB(bmpFile,bmp.file_header,bmp.info_header,rgbData);

	fclose(bmpFile);

	if( width!=NULL || height!=NULL)
	{
		*height=bmp.height;
		*width=bmp.width;
	}
	
	return true;
}

