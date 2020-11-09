#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Base.h"				
#include "Communication.h"		
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <list>
#include <stdlib.h>
#pragma comment(lib, "ws2_32")
#define EVT_CONSUCCESS      0x0000  // Connection established
#define EVT_CONFAILURE      0x0001  // General failure - Wait Connection failed
#define EVT_CONDROP         0x0002  // Connection dropped
#define EVT_ZEROLENGTH      0x0003  // Zero length message

#ifndef BUFFER_SIZE
#define BUFFER_SIZE     MAX_PATH
#endif
#define HOSTNAME_SIZE   MAX_PATH
#define STRING_LENGTH   40
namespace AutoLib{

AUTOMALIB_API class MComNet : public MCommunication
{
public:
	enum enuSocketType {
		TCPServer,
		TCPClient,
		UDPServer,
		UDPClient,
	};
	AUTOMALIB_API MComNet(MBase *pB,CString strID,CString strName, enuSocketType sockettype=enuSocketType::TCPClient,int MaxTxBuff=1024,int MaxRxBuff=1024);
	AUTOMALIB_API virtual ~MComNet();
	AUTOMALIB_API virtual bool Init();
	AUTOMALIB_API virtual int ReceiveData(byte* buff, int DataBuffLen);
	AUTOMALIB_API virtual int SendData(byte* buff, int DataBuffLen);

	AUTOMALIB_API virtual int GetRecvDataCount();
	AUTOMALIB_API virtual bool isOpen();
	AUTOMALIB_API virtual bool Close();
	AUTOMALIB_API virtual bool ConnectTo(CString strHost, CString strPort);
	AUTOMALIB_API virtual bool Accept(MComNet*);
	AUTOMALIB_API virtual bool Listen(CString strHost, CString strPort);
	AUTOMALIB_API virtual bool isDisConnected();
protected:
	enuSocketType m_SocketType;
	CString m_strServer;
	CString m_strPort;
	bool m_bInit;
	bool m_bOpen;
	SOCKET m_socket;
	struct sockaddr m_UDPServerAddr;

};
}//namespace AutoLib

