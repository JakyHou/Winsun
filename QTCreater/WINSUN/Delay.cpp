#include <windows.h>
#include <mmsystem.h>
//#include "typedef.h"
#include "Delay.h"

//----------------------------------------
#pragma   comment(lib,   "winmm.lib") 



//#pragma   comment(linker,   "/ENTRY:mainCRTStartup") 


long hDlyTime1=0;

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#define		TIMER0_FINETUNE	15

//多媒体定时器回调函数
void CALLBACK MultimediaProc1(UINT wTimerID, UINT msg, DWORD dwUser, DWORD dw1,DWORD dw2)
{
	//Timer10MsCallBack();
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void Delay1Us(ULONG ulMicroSeconds)
{
	LARGE_INTEGER  timeStop; 
	LARGE_INTEGER  timeStart; 
	LARGE_INTEGER  Freq; 
	LONGLONG  ulTimeToWait;
	
	if (!QueryPerformanceFrequency( &Freq ))
		return;
	
	ulTimeToWait = Freq.QuadPart * ulMicroSeconds / 1000 / 1000; 
	
	QueryPerformanceCounter ( &timeStart ); 
	
	timeStop = timeStart; 
	
	while( timeStop.QuadPart - timeStart.QuadPart < ulTimeToWait ) 
	{ 
		QueryPerformanceCounter( &timeStop ); 
	}
}
void Delay1Ms(unsigned short ms)
{
	Delay1Us(1000*ms);
}

void Delay10Ms(unsigned short m10s)
{
	Delay1Ms(m10s*10);
}
//Timer
void InitTimer(void)
{
//	hDlyTime1=timeSetEvent(10,1,(LPTIMECALLBACK) MultimediaProc1,(DWORD)NULL,TIME_PERIODIC);
}

