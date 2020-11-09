#pragma once
#pragma warning( disable : 4091)

#include "DALib.h"
#include "Type_def.h"

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib{

	AUTOMALIB_API class MDALibSamNet : public MDALib
	{
	public:
		AUTOMALIB_API MDALibSamNet(MBase *pParent, CString strID, CString strName);
		AUTOMALIB_API virtual ~MDALibSamNet();
		AUTOMALIB_API virtual U32 GetValue(MDA* pDA);
		AUTOMALIB_API virtual bool SetValue(MDA* pDA, U32 Value);
	protected:
	};


}//AutoLib
