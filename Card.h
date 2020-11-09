#pragma once
#pragma warning( disable : 4091)

#include "Base.h"	
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib{
	AUTOMALIB_API class MCard : public MBase
	{
	public:
		AUTOMALIB_API MCard(MBase *pParent,CString strID,CString strName);
		AUTOMALIB_API virtual ~MCard();
		AUTOMALIB_API virtual bool Open();
		AUTOMALIB_API virtual void Close();
		AUTOMALIB_API virtual bool isOpen();
	protected:
		bool m_isOpen;
	};

}//namespace AutoLib
