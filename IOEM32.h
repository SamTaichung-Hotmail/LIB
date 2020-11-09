#pragma once
#ifdef AUTOMADMC3000_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
				
#include "IOLib.h"	

namespace AutoLib {
	AUTOMALIB_API class MIOEM32 : public MIOLib
	{
	public:
		AUTOMALIB_API MIOEM32(MBase *pParent, CString strID, CString strName);
		AUTOMALIB_API ~MIOEM32();
		AUTOMALIB_API bool GetValue(MIO* pIO);
		AUTOMALIB_API void SetValue(MIO* pIO, bool bValue);
	protected:
		void ScanSlavesType(WORD m_CardID);
		std::vector<WORD> DigitalOuts;
		std::vector<WORD> DigitalIns;
		int OutsCount = 0;
		int InsCount = 0;
		WORD m_CardID;
	};

}//namespace AutoLib
