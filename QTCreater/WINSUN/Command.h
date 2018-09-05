#ifndef __COMMAND_H__
#define __COMMAND_H__

#ifdef __cplusplus
extern "C" {
#endif


bool GetCurrent(unsigned short *Red,unsigned short *Green,unsigned short *Blue);
bool ShakeHands(void);

bool SetCurrent(unsigned short red,unsigned short green,unsigned short blue);
bool LedOnOff(unsigned char flag);

int FirmWareUpGrate(unsigned char *FileName,unsigned char Namelength);
bool GetTemperature(short int *r,short int *g,short int *b,short int *board);
bool CheckVersion(unsigned int Version);
bool Flip(unsigned char FlipX,unsigned char FlipY);
bool InputSource(unsigned char Value);
bool LightControl(unsigned char Index);
int PackageReceive(unsigned char *Buffer,unsigned char Size);

#ifdef __cplusplus
};
#endif


#endif
