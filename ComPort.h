#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"				
#include "Communication.h"		

#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
#define FC_XONXOFF      0x04
#define ASCII_BEL       0x07
#define ASCII_BS        0x08
#define ASCII_LF        0x0A
#define ASCII_CR        0x0D
#define ASCII_XON       0x11
#define ASCII_XOFF      0x13

namespace AutoLib{
AUTOMALIB_API class MComPort : public MCommunication
{
public:
	AUTOMALIB_API MComPort(MBase *pB,CString strID,CString strName, DWORD MaxTxBuff=1024, DWORD MaxRxBuff=1024);
	AUTOMALIB_API virtual ~MComPort();
	// Member function
	AUTOMALIB_API virtual int ReceiveData(byte* buff, int DataBuffLen);
	AUTOMALIB_API virtual int SendData(byte* buff, int DataBuffLen);
	AUTOMALIB_API virtual int GetRecvDataCount();
	AUTOMALIB_API virtual bool isOpen();
	AUTOMALIB_API BOOL Open(int nPort, int nBaud, CString strParity, int iByteSize, float fStopBit);
	AUTOMALIB_API BOOL Close(void);
	AUTOMALIB_API BOOL GetPortData(int& nPort, int& nBaud, CString& strParity, int& iByteSize, float& fStopBit);
protected:
	DWORD WriteCommByte(const byte *ucByte, int nLength);
	HANDLE m_hIDComDev;
	OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
	BOOL m_bOpened;
	int m_intPort;
	DWORD m_dwMaxRxBuff, m_dwMaxTxBuff;
};
}//namespace AutoLib

