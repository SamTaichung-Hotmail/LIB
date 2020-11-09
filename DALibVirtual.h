#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
// MCard
#include "DALib.h"				
namespace AutoLib{
	AUTOMALIB_API class MDALibVirtual : public MDALib
	{
	public:
		AUTOMALIB_API MDALibVirtual(MBase *pParent,CString strID,CString strName);
		AUTOMALIB_API virtual ~MDALibVirtual();
		AUTOMALIB_API virtual U32 GetValue(MDA* pDA);
		AUTOMALIB_API virtual bool SetValue(MDA* pDA, U32 dblValue);
	protected:
		std::map<MDA*,U32> m_DAVirtuals;

	};

}//namespace AutoLib
