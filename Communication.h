#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Lock.h"				
namespace AutoLib{
AUTOMALIB_API class MCommunication : public MLock
{
public:
	AUTOMALIB_API MCommunication(MBase *pB,CString strID,CString strName);
	AUTOMALIB_API virtual ~MCommunication();
	// Member function
	AUTOMALIB_API virtual bool isOpen()=0;
	AUTOMALIB_API virtual int ReceiveData(byte* buff, int DataBuffLen) = 0;
	AUTOMALIB_API virtual int SendData(byte* buff, int DataBuffLen)=0;
	AUTOMALIB_API virtual int GetRecvDataCount()=0;

protected:
};
}//namespace AutoLib

