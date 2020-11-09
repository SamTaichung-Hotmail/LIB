#pragma once
#ifdef AUTOMADMC3000_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Card.h"	

namespace AutoLib {
	AUTOMALIB_API class MCardDMC3000 : public MCard
	{
	public:
		AUTOMALIB_API MCardDMC3000(MBase *pParent, CString strID, CString strName);
		AUTOMALIB_API ~MCardDMC3000();
		AUTOMALIB_API bool Open();
		AUTOMALIB_API void Close();
		AUTOMALIB_API void RefreshCard();
		AUTOMALIB_API int GetCardCount();
		AUTOMALIB_API bool SetCycleTime(int cycleTime);
		AUTOMALIB_API int ResetCard();
		AUTOMALIB_API int ResetCardSoft(unsigned short CardNo);

	protected:
		unsigned short  m_wCardNum;      //定義卡數
		unsigned short  m_wCardList[8];   //定義卡號數組
		unsigned long   m_dwCardTypeList[8];   //定義各卡類型
	
	};
}
