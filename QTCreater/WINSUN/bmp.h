#ifndef   __BMP_H__
#define   __BMP_H__

#define		DATA_TYPE_I8       0
#define		DATA_TYPE_ARGB8888 1
#define		DATA_TYPE_RGB565   2
#define     DATA_TYPE_YUV422   3
#define     DATA_TYPE_ARGB1555 4


#define     USE_DATA_TYPE	DATA_TYPE_I8

extern bool ReadBmp(const char *strFileName,unsigned long *width,unsigned long *height,BYTE *rgbData);

#endif