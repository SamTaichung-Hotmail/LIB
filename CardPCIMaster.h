#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "Card.h"				
namespace AutoLib{
	AUTOMALIB_API class MCardPCIMaster : public MCard
	{
	public:
		AUTOMALIB_API MCardPCIMaster(MBase *pParent,CString strID,CString strName);
		AUTOMALIB_API ~MCardPCIMaster();
		AUTOMALIB_API bool Open();
		AUTOMALIB_API void Close();
		AUTOMALIB_API int GetCardCount();
		AUTOMALIB_API short Set4XMAEMGLogic(short CardID, short ConnectID, short StationID, short Logic);
		AUTOMALIB_API short SetSpeed(short CardID, short ConnectID, unsigned long Speed); //0:25M 1:12.5M 2:6M 3:3M

	protected:
		int m_intCardCount;
	};

}//namespace AutoLib
