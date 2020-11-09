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
		unsigned short  m_wCardNum;      //�w�q�d��
		unsigned short  m_wCardList[8];   //�w�q�d���Ʋ�
		unsigned long   m_dwCardTypeList[8];   //�w�q�U�d����
	
	};
}
