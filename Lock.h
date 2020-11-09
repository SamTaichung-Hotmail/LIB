#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Base.h"	
// MLock
namespace AutoLib {
	AUTOMALIB_API class MLock:public MBase
	{
	public:
		AUTOMALIB_API MLock(MBase *pB, CString strID, CString strName, int ErrorCodeBase = -1);
		AUTOMALIB_API ~MLock();
		AUTOMALIB_API virtual bool Lock(MBase *pLocker);
		AUTOMALIB_API virtual void UnLock(MBase *pLocker);
		AUTOMALIB_API virtual MBase* GetLocker();
	protected:
		CRITICAL_SECTION m_csLock;
		MBase *m_pLocker;
	};

}
