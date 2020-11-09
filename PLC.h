
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
AUTOMALIB_API class PLCDataArray
{
public:
	enum PLCDataType {
		pdt_WORD,
		pdt_BIT,
	};
	enum PLCDataDir {
		pdd_PC2PLC,
		pdd_PLC2PC,
	};

	AUTOMALIB_API PLCDataArray(PLCDataDir pddDir,
		char DataClassification, //������O�A�ҦpD,M,R,S...
		unsigned long ulStartAddress,//�}�l��}2000,3000...
		unsigned short usAmount);
	AUTOMALIB_API virtual PLCDataType GetType() = 0;
	AUTOMALIB_API virtual PLCDataDir GetDir() { return m_pddDir; };
	AUTOMALIB_API char GetRegister() { return m_DataClassification; };
	AUTOMALIB_API void SetStartAddr(unsigned long Addr) { m_ulStartAddress=Addr; };
	AUTOMALIB_API unsigned long GetStartAddr() { return m_ulStartAddress; };
	AUTOMALIB_API unsigned short GetAmount() { return m_usAmount; };
	AUTOMALIB_API CTimeCounter* GetLastRecvTimer() { return &m_tmLastRecv; };
	AUTOMALIB_API int GetLastError();
	AUTOMALIB_API void SetReturnCode(int intReturnCode);
protected:
	PLCDataDir m_pddDir;
	char m_DataClassification;		//������O�A�ҦpD,M,R,S...
	unsigned long m_ulStartAddress;	//�}�l��}2000,3000...
	unsigned short m_usAmount;		//��Ƽƶq
	CTimeCounter m_tmLastRecv;
	int m_intRetCode;
};
AUTOMALIB_API class PLCWordArray:public PLCDataArray
{
public:
	AUTOMALIB_API PLCWordArray(PLCDataDir pddDir,
							char DataClassification, //������O�A�ҦpD,M,R,S...
							unsigned short usStartAddress,//�}�l��}2000,3000...
							unsigned short usAmount);
	AUTOMALIB_API ~PLCWordArray();
	AUTOMALIB_API WORD GetData(int index);
	AUTOMALIB_API void* GetDataPtr() { return m_pWordData; };
	AUTOMALIB_API void SetData(int index, WORD data);
	AUTOMALIB_API PLCDataType GetType();
protected:
	WORD *m_pWordData;
};
AUTOMALIB_API class PLCBitArray :public PLCDataArray
{
public:
	AUTOMALIB_API PLCBitArray(PLCDataDir pddDir, 
		char DataClassification, //������O�A�ҦpD,M,R,S...
		unsigned short usStartAddress,//�}�l��}2000,3000...
		unsigned short usAmount);
	AUTOMALIB_API ~PLCBitArray();
	AUTOMALIB_API bool GetData(int index);
	AUTOMALIB_API void SetData(int index, bool data);
	AUTOMALIB_API PLCDataType GetType();
protected:
	
	bool *m_pBitData;

};
AUTOMALIB_API class MPLC : public MBase
{
public:
	AUTOMALIB_API MPLC(MBase *pB,CString strID,CString strName,MCommunication *pCom);
	AUTOMALIB_API virtual ~MPLC();
	AUTOMALIB_API virtual bool StartSynchronize(PLCDataArray* pDataAry)=0; //�}�l�q�T�P�B
	AUTOMALIB_API virtual bool StopSynchronize() = 0;	//����q�T�P�B
protected:
	MCommunication *m_pCom;
};
}//namespace AutoLib

