#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

// MCard
#include "Card.h"				
namespace AutoLib{
	AUTOMALIB_API class MCardPCI6045 : public MCard
	{
	public:
		AUTOMALIB_API MCardPCI6045(MBase *pParent,CString strID,CString strName);
		AUTOMALIB_API ~MCardPCI6045();
		AUTOMALIB_API bool Open();
		AUTOMALIB_API void Close();
		AUTOMALIB_API int GetCardCount();
		AUTOMALIB_API int ResetCard(unsigned short CardNo);

	protected:
		int m_intCardCount;
	};

}//namespace AutoLib
