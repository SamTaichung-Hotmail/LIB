
#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "PLC.h"				
#include "ComNet.h"			
#include "TimeCounter.h"
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <assert.h>
#include <limits.h>
namespace AutoLib{
AUTOMALIB_API class MPLCMC : public MPLC
{
#pragma pack(push)
#pragma pack(1)

	struct MCCommand3E
	{
		unsigned short Head;
		byte NetNo;
		byte PCNo;
		unsigned short RequestIONO;
		byte RequestStationNO;
		unsigned short RequestDataLen;
		unsigned short CPUMonitorTimer;
		unsigned short Command;
		unsigned short SubCommand;
		unsigned short StartAddr;
		byte HiStartAddr;
		byte RegisterID;
		unsigned short RWAmount;
	};
	struct MCCommand4C
	{
		unsigned short FrameHead;
		unsigned short ByteCount;
		byte FrameNo;
		byte StationNo;
		byte NetNo;
		byte PLCNo;
		unsigned short RequestIONO;
		byte RequestStationNO;
		byte HostStationNo;
		unsigned short Command;
		unsigned short SubCommand;
		unsigned short StartAddr;
		byte HiStartAddr;
		byte RegisterID;
		unsigned short RWAmount;
	};

	struct MCCommandKV
	{
		byte Head;//0x05
		unsigned short StationNo;
		unsigned short PcNo;
		unsigned short Command;
		byte StartAddr_bytes[6];
		byte RequestTime;//
		byte RegisterID;
		unsigned short EndSign;//0x0D , 0x0A
		unsigned short RWAmount;
	};

	struct MCReturn3E
	{
		byte NetNo;
		byte PCNo;
		unsigned short RequestIONO;
		byte RequestStationNO;
		unsigned short ReturnDataLen;
		unsigned short ReturnCode;
	};
	struct MCReturn4C
	{
		unsigned short ByteCount;
		byte FrameNo;
		byte StationNo;
		byte NetNo;
		byte PLCNo;
		unsigned short RequestIONO;
		byte RequestStationNO;
		byte HostStationNo;
		unsigned short AnswerCode;
		unsigned short ReturnCode;
	};
	struct MCReturnKV
	{
		unsigned short StationNo;
		unsigned short PcNo;
	};
#pragma pack(pop)

public:
	enum ProtocolFormat {
		pf3E,	//For Ethernet
		pf4C,	//For Comport
		pfKV,
	};

	enum KVRegisterCode
	{
		KV_NUL = 0x00,
		KV_STX = 0x02,
		KV_ETX = 0x03,
		KV_EOT = 0x04,
		KV_ENQ = 0x05,
		KV_ACK = 0x06,
		KV_LF = 0x0A,
		KV_CL = 0x0C,
		KV_CR = 0x0D,
		KV_NAK = 0x15,
		KV_M = 0x4D,
		KV_D = 0x44,
	};

	enum MCRegisterCode {
		MC_X=0x9C,
		MC_Y=0x9D,
		MC_B=0xA0,
		MC_M=0x90,
		MC_L=0x92,
		MC_SM=0x91,
		MC_SD=0xA9,
		MC_D=0xA8,
		MC_W=0xB4,
		MC_TN=0xC2,
		MC_TS=0xC1,
		MC_CN=0xC5,
		MC_CS=0xC4,
	};
	enum PLCMCStep {
		stpIdle,
		stpStart,
		stpWaitConnect,
		stpSend,
		stpWaitRecvHead1,
		stpWaitRecvHead2,
		stpWaitRecv,
		stpParse4C,
		stpParseKV,
		stpCleanRecv,
	};
	enum PLCComStatus {
		plsNoError,
		plsWaitConnectTimeOut,
		plsRecvErrorCode,
		plsRecvTimeOut,
	};
	static UINT DoThread(void *);
	void Synchronize();
	AUTOMALIB_API MPLCMC(MBase *pB,CString strID,CString strName, MCommunication *pCom, ProtocolFormat Protocol);
	AUTOMALIB_API ~MPLCMC();
	AUTOMALIB_API bool StartSynchronize(PLCDataArray *pdaArray); //開始通訊同步
	AUTOMALIB_API bool StopSynchronize();	//停止通訊同步
	AUTOMALIB_API void ConnectPLC(CString strIP, CString strPort);
	AUTOMALIB_API PLCComStatus GetComStatus() { return m_plsStatus; };
	AUTOMALIB_API void SetProtocol(ProtocolFormat Protocol);
	AUTOMALIB_API bool isIDLE();
	bool m_bCheckSumEnable;
protected:
	ProtocolFormat m_PLC_Protocol;
	CTimeCounter m_TmCounter;
	CString m_strPLCIP, m_strPLCPort;
	DWORD m_pThread;
	HANDLE m_hThread;
	CRITICAL_SECTION m_csSynchronize;
	bool m_bSynchronized;
	int m_intArrayIndex;
	PLCDataArray *m_pdaArray;
	PLCMCStep m_Step;
	int m_intParseCount;
	MCReturn4C m_mcReturn4C;
	MCReturnKV m_mcReturnKV;
	byte m_chSend[4096];
	byte m_chRecv[4096];
	bool m_bSkip;
	WORD m_wdErrorCode;
	PLCComStatus m_plsStatus;

	void ConvertAddr2KVHex(unsigned long addr, bool isMRBytes, int count, byte* bytes);
	WORD ConvertKVHex2Data(WORD data);
};
}//namespace AutoLib

