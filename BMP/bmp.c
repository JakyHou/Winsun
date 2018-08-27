#define WIDTHBYTES(bits) ((DWORD)(((bits)+31) & (~31)) / 8)

void makebmp()
{
int nSize =abs(long(240 * WIDTHBYTES(24 * 320)));
char*  buff = new char[nSize];
memset(buff, 0, nSize);

BITMAPINFOHEADER header;
header.biSize = sizeof(BITMAPINFOHEADER);

header.biWidth = 320;
header.biHeight = 240*(-1);
header.biBitCount = 24;
header.biCompression = 0;
header.biSizeImage = 0;
header.biClrImportant = 0;
header.biClrUsed = 0;
header.biXPelsPerMeter = 0;
header.biYPelsPerMeter = 0;
header.biPlanes = 1;


//3 构造文件
BITMAPFILEHEADER bmpFileHeader;
HANDLE hFile = NULL;
DWORD dwTotalWriten = 0;
DWORD dwWriten;


bmpFileHeader.bfType = 0x4d42; //'BM';
bmpFileHeader.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
bmpFileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)+ nSize;


FILE* pf = fopen("d:\\test.bmp", "wb");
fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, pf);
fwrite(&header, sizeof(BITMAPINFOHEADER), 1, pf);
fwrite(buff, 1, nSize, pf);
fclose(pf);


delete buff;
}