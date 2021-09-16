
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Protocol.h"				
#include "ComNet.h"			
#include "ComPort.h"			
#include "TimeCounter.h"
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <assert.h>
#include <limits.h>

typedef unsigned char U8;
typedef short I16;
typedef unsigned short U16;
typedef long I32;
typedef unsigned long U32;
typedef unsigned long long U64;
typedef float F32;
typedef enum {
	xmfcNone,
	xmfcReadCoil,
	xmfcReadInputStatus,
	xmfcReadHoldingRegister,
	xmfcReadInputRegister,
	xmfcForceSingleCoil,
	xmfcPresentSingleRegister,
	xmfcEcho = 0x08,
	xmfcForceMultiCoil = 0x0F,
	xmfcPresentMultiRegister = 0x10,
}XModbusFuncCode;
namespace AutoLib{
AUTOMALIB_API class MModbus : public MProtocol
{

public:
	enum ProtocolFormat {
		pfRTU_CLIENT,
		pfRTU_SERVER,
		pfTCP_CLIENT,
		pfTCP_SERVER,
	};
	static UINT DoThread(void *);
	void Synchronize();
	AUTOMALIB_API MModbus(MBase *pB,CString strID,CString strName);
	AUTOMALIB_API ~MModbus();
	AUTOMALIB_API bool Init();
	AUTOMALIB_API bool StopSynchronize();	//停止通訊同步
	AUTOMALIB_API void SetTCP(CString strIP, CString strPort);
	AUTOMALIB_API void SetComport(int intComport, int intBaudRate, 
		CString strParity,int intByteSize,int intStopBit);
	AUTOMALIB_API void SetModbusID(byte MasterID,byte SlaveID);
	AUTOMALIB_API void SetProtocol(ProtocolFormat Protocol);
	AUTOMALIB_API bool isIDLE();
	AUTOMALIB_API bool Open();
	AUTOMALIB_API void InsertInputRegArray(ProtocolWordArray* pArray);
	AUTOMALIB_API int GetCountOfInputRegArray();
	AUTOMALIB_API void InsertHoldRegArray(ProtocolWordArray* pArray);
	AUTOMALIB_API int GetCountOfHoldRegArray();
	AUTOMALIB_API void InsertCoilBitArray(ProtocolBitArray* pArray);
	AUTOMALIB_API int GetCountOfCoilBitArray();
	AUTOMALIB_API void InsertInputBitArray(ProtocolBitArray* pArray);
	AUTOMALIB_API int GetCountOfInputBitArray();
	AUTOMALIB_API bool ReadInputRegArray(ProtocolWordArray* pArray);
	AUTOMALIB_API bool ReadHoldRegArray(ProtocolWordArray* pArray);
	AUTOMALIB_API bool WriteHoldRegArray(ProtocolWordArray* pArray);
	AUTOMALIB_API bool WriteCoilArray(ProtocolBitArray* pArray);
	AUTOMALIB_API bool ReadCoilArray(ProtocolBitArray* pArray);
	AUTOMALIB_API bool ReadInputStatusArray(ProtocolBitArray* pArray);
	MComPort *m_pComport;
	MComNet *m_pTCPServer;
	MComNet *m_pTCPClient;
protected:
	bool m_bWriteData;
	std::vector<ProtocolWordArray*> m_InputWords;
	std::vector<ProtocolWordArray*> m_HoldWords;
	std::vector<ProtocolBitArray*> m_CoilBits;
	std::vector<ProtocolBitArray*> m_InputBits;
	ProtocolWordArray* m_pWordArray;
	ProtocolBitArray* m_pBitArray;
	ProtocolFormat m_Protocol;
	XModbusFuncCode m_ActionCode;
	U16 m_ReadCoilNum;
	CTimeCounter m_TmCounter;
	CString m_strServerIP, m_strServerPort;
	DWORD m_pThread;
	HANDLE m_hThread;
	CRITICAL_SECTION m_csSynchronize;
	bool m_bSynchronized;
	int m_intArrayIndex;
	int m_intParseCount;
	int m_intRecvCount;
	byte m_chSend[1024];
	byte m_chRecv[1024];
	bool m_bSkip;
	WORD m_wdErrorCode;
	U16 m_UID;
private:
	int m_intComport;
	int m_intBaudRate;
	CString m_strParity;
	int m_intByteSize;
	int m_intStopBit;
	byte m_MasterID, m_SlaveID;
	void Modbus_TCPServer(U8 SlaveID, byte* pRecv, int intRecv, byte* pSend, int* intSend);
	void Modbus_COMServer(U8 SlaveID, byte* pRecv, int intRecv, byte* pSend, int* intSend);
};
}//namespace AutoLib

