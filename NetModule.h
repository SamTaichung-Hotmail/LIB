#pragma once
#pragma warning( disable : 4091)
#include "Base.h"	
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib{
	AUTOMALIB_API class MNetModule : public MBase
	{
	public:
		AUTOMALIB_API MNetModule(MBase *pParent,CString strID,CString strName,int CardID, int ConnectID, int StationID);
		AUTOMALIB_API virtual ~MNetModule();
		AUTOMALIB_API int GetCardID();
		AUTOMALIB_API int GetConnectID();
		AUTOMALIB_API int GetStationID();
	protected:
		int m_CardID;
		int m_ConnectID;
		int m_StationID;
	};

}//namespace AutoLib
