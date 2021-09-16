
#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"		
#include "TimeCounter.h"
#include "Communication.h"
namespace AutoLib{ 
AUTOMALIB_API class ProtocolDataArray
{
public:
	enum ProtocolDataType {
		pdt_WORD,
		pdt_BIT,
	};
	AUTOMALIB_API ProtocolDataArray(
		ProtocolDataType DataType,
		unsigned long long ulStartAddress,//開始位址2000,3000...
		unsigned long usAmount);
	AUTOMALIB_API ProtocolDataType GetType() { return m_DataType; };
	AUTOMALIB_API void SetStartAddr(unsigned long long Addr) { m_ulStartAddress=Addr; };
	AUTOMALIB_API unsigned long long GetStartAddr() { return m_ulStartAddress; };
	AUTOMALIB_API unsigned long GetAmount() { return m_usAmount; };
	AUTOMALIB_API CTimeCounter* GetLastRecvTimer() { return &m_tmLastRecv; };
	AUTOMALIB_API int GetLastError();
	AUTOMALIB_API void SetReturnCode(int intReturnCode);
protected:
	ProtocolDataType m_DataType;		//資料類別，例如D,M,R,S...
	unsigned long long m_ulStartAddress;	//開始位址2000,3000...
	unsigned long m_usAmount;		//資料數量
	CTimeCounter m_tmLastRecv;
	int m_intRetCode;
};
AUTOMALIB_API class ProtocolWordArray :public ProtocolDataArray
{
public:
	AUTOMALIB_API ProtocolWordArray(
							unsigned long long usStartAddress,//開始位址2000,3000...
							unsigned long usAmount);
	AUTOMALIB_API ~ProtocolWordArray();
	AUTOMALIB_API WORD GetData(unsigned long long  Addr);
	AUTOMALIB_API void* GetDataPtr() { return m_pWordData; };
	AUTOMALIB_API void SetData(unsigned long long  Addr, WORD data);
protected:
	WORD *m_pWordData;
};
AUTOMALIB_API class ProtocolBitArray :public ProtocolDataArray
{
public:
	AUTOMALIB_API ProtocolBitArray(
		unsigned long long usStartAddress,//開始位址2000,3000...
		unsigned long usAmount);
	AUTOMALIB_API ~ProtocolBitArray();
	AUTOMALIB_API bool GetData(unsigned long long  Addr);
	AUTOMALIB_API void SetData(unsigned long long  Addr, bool data);
protected:
	
	bool *m_pBitData;

};

AUTOMALIB_API class MProtocol : public MBase
{
public:
	enum TransStatus {
		tsClose,
		tsOpen,
		tsConnecting,
		tsIDLE,
		tsSendRequest,
		tsWaitResponse,
		tsError,
	};
	enum TransError {
		teNoError,
		teTimeOut,
		teFormatError,
		teCrcError,
		teResultError,
		teUIDError,
		teFunctionCodeError,
		teLengthError,
		teProtocolError,
		teNotOpen,
	};
	AUTOMALIB_API MProtocol(MBase *pB,CString strID,CString strName);
	AUTOMALIB_API virtual ~MProtocol();
	AUTOMALIB_API TransStatus GetStatus();
	AUTOMALIB_API virtual void Reset();
	AUTOMALIB_API TransError GetLastError();
protected:
	TransStatus m_Status;
	TransError m_LastError;
};
}//namespace AutoLib

