#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "Unit.h"
#include "ComNet.h" 
#include "TimeCounter.h"
#include "SecsDataItem.h"
namespace AutoLib
{

	AUTOMASECS_API class MHSMS :
	public MUnit
{
	enum STEP {
		stpConnectToHost,
		stpWaitConnect,
		stpWaitSelected,
		stpSeleted,
		stpReConnect,
	};
public:
	AUTOMASECS_API enum HSMS_STATE {
		hsInit,
		hsDisConnected,
		hsConneted,
		hsSeleted,
	};
	AUTOMASECS_API enum HSMS_MESSAGE_TYPE
	{
		hmtDataMessage,
		hmtSelectReq,
		hmtSelectRsp,
		hmtDeSelectReq,
		hmtDeSelectRsp,
		hmtLinktestReq,
		hmtLinktestRsp,
		hmtRejectReq,
		hmtRevers1,
		hmtSeparateReq,
	};

	AUTOMASECS_API MHSMS(MUnit *pParent, CString strID, CString strName, int ErrorCodeBase = -1);
	~MHSMS();
	void Cycle(const double dblTime);
	void StepCycle(const double dblTime);
	AUTOMASECS_API virtual void Stop();

	AUTOMASECS_API void SetHost(CString strHost);
	AUTOMASECS_API CString GetHost();
	AUTOMASECS_API void SetPort(CString strPort);
	AUTOMASECS_API CString GetPort();
	AUTOMASECS_API void SetNetMode(bool bActive);
	AUTOMASECS_API bool GetNetMode();
	AUTOMASECS_API bool ConnectToHost();
	AUTOMASECS_API void ClosePort();
	AUTOMASECS_API void SendPacket(HSMS_Packet* pPacket);
	AUTOMASECS_API CString GetPacketName(HSMS_Packet* pPacket);
	int SearchRecvPacket(HSMS_MESSAGE_TYPE msgType);
	HSMS_Packet* ParserRecv(byte *pRecv, int RecvCount);
	AUTOMASECS_API HSMS_Packet* BuildPacket(HSMS_MESSAGE_TYPE msgType);
	AUTOMASECS_API CString ToSML(HSMS_Packet* pPacket);
	AUTOMASECS_API HSMS_STATE GetState();
	AUTOMASECS_API void SetDeviceID(WORD ID);
	AUTOMASECS_API WORD GetDeviceID();
private:
	MComNet *m_pServer;
	MComNet *m_pComNet;
	bool m_bNetMode;
	HSMS_STATE m_hsState;
	CString m_strHost, m_strPort;
	CTimeCounter m_tcT5;
	CTimeCounter m_tcT7;
	WORD m_wdDeviceID;
	CArray<HSMS_Packet*>m_RecvPacketArray;
	CArray<HSMS_Packet*>m_SendPacketArray;
	CArray<HSMS_Packet*>m_WaitRecvArray;
	bool m_bWaitRecvComplete;
	bool m_bWaitLinkRsp;
	unsigned long m_ulWaitRecvSize;
	CRITICAL_SECTION m_csRecv;
	CRITICAL_SECTION m_csSend;

};

}
