#pragma once
#pragma warning( disable : 4091)
#include "Type_def.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MCard
#include "Base.h"				
namespace AutoLib{
	class MDA;
	AUTOMALIB_API class MDALib : public MBase
	{
	public:
		AUTOMALIB_API MDALib(MBase *pParent,CString strID,CString strName);
		AUTOMALIB_API virtual ~MDALib();
		AUTOMALIB_API virtual U32 GetValue(MDA* pDA)=0;
		AUTOMALIB_API virtual bool SetValue(MDA* pDA, U32 Value)=0;
	protected:
	};

}//namespace AutoLib
