//#include "stdafx.h"
#include <windows.h>
#include <mmsystem.h>
//#include <stdio.h>
//#include "typedef.h"
#include "Queue.h"
#include "cnComm.h"
#include "uart.h"
#include "Delay.h"
//----------------------------------------
#pragma warning(disable: 4530) 
#pragma warning(disable: 4786) 
#include <cassert> 
#include <iostream> 
#include <vector> 
#include <string> 
#include <exception> 
using namespace std;

static RingBuffer_t UartRingBuffer;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//uart

class meComm : public CnComm//自动接受所有数据
{
public:
    bool IsTXEmptyFlag;
	virtual void OnReceive()
	{
		char buf[255];
		int len,i;
		len = Read(buf, 100);
		for(i=0;i<len;i++)
		RingBufferWrite(&UartRingBuffer,buf[i]);
	}
	virtual void OnTxEmpty()
	{
		IsTXEmptyFlag=TRUE;
	}
public:
    unsigned char GetInput(void)
	{
		if(RingBufferHasData(&UartRingBuffer))
			return RingBufferCount(&UartRingBuffer);
		else
			return 0;
	}
    void GetChars(char * buffer,unsigned char len)
	{
        unsigned char i;
		for(i=0;i<len;i++)
			buffer[i]=RingBufferRead(&UartRingBuffer);
	}

    bool IsTXEmpty(void)
	{
        bool flag;
		flag=IsTXEmptyFlag;
		IsTXEmptyFlag=FALSE;
		return flag;
	}
	
};
//打开串口 缺省 baud_rate, 8, n, 1
//	bool Open(DWORD dwPort, DWORD dwBaudRate)
static meComm Com[255];
static unsigned char PortIndex=1;

bool OpenUart(unsigned char dwPort,unsigned long dwBaudRate)
{
	//DCB* meDCB;
	PortIndex=dwPort;
	if(Com[PortIndex].IsOpen())
		Com[PortIndex].Close();
	//if(!Com.Open(1,9600))
	if(!Com[PortIndex].Open(dwPort, dwBaudRate, NOPARITY, 8, ONESTOPBIT))//115200
	{
		cout << "COM not open , error : " << GetLastError() << endl;
		return FALSE;
	}
	/*
	//得到串口参数 DCB
	meDCB=Com.GetState();
	meDCB->fDtrControl=DTR_CONTROL_ENABLE;
	meDCB->fRtsControl=RTS_CONTROL_ENABLE;
	//设置串口参数 DCB
	Com.SetState(meDCB);
	meDCB=Com.GetState();
	Com.SetDTR(true);
	Com.SetRTS(true);
	Sleep(300);
	*/
	return TRUE;
}

bool GetChars(char * buffer,unsigned char len)
{
    unsigned char i;
    unsigned short wait=8 * len;
	do
	{
		i = Com[PortIndex].GetInput();//获得缓冲区
		//Com.ReadSync(resBuff,4);
		if(i>=len)
		{
			Com[PortIndex].GetChars(buffer,len);
			//break;
			return TRUE;
		}
	Delay1Ms(1);
	}while(wait--);
	return FALSE;
}
void SendChars(unsigned char * buffer,unsigned char len)
{
    unsigned short wait=1000;
	Com[PortIndex].IsTXEmptyFlag=FALSE;
	Com[PortIndex].Write(buffer,len);
	do 
	{
		if(Com[PortIndex].IsTXEmpty()==TRUE)
			break;
		Delay1Ms(1);
	} while(wait--);
}

void ReceiveBufferClear(void)
{
	RingBufferClear(&UartRingBuffer);
}

void CloseUart(unsigned char dwPort)
{
	if(Com[PortIndex].IsOpen())
	Com[PortIndex].Close();
}
