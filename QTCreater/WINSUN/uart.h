#ifndef __UART_H__
#define __UART_H__

#ifdef __cplusplus
extern "C" {
#endif

bool OpenUart(unsigned char dwPort,unsigned long dwBaudRate);
bool GetChars(char * buffer,unsigned char len);
void SendChars(unsigned char * buffer,unsigned char len);
void CloseUart(unsigned char dwPort);
void ReceiveBufferClear(void);

bool OpenUartEx(unsigned char dwPort);
bool GetCharsEx(char * buffer,unsigned char len);
void SendCharsEx(unsigned char * buffer,unsigned char len);
void CloseUartEx(unsigned char dwPort);
void ReceiveBufferClearEx(void);

#ifdef __cplusplus
};
#endif
#endif
