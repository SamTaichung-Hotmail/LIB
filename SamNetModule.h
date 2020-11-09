#pragma once
#pragma warning( disable : 4091)
#include "NetModule.h"	
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib{
	AUTOMALIB_API class MSamNetModule : public MNetModule
	{
	public:
		AUTOMALIB_API MSamNetModule(MBase *pParent,CString strID,CString strName,int CardID, int ConnectID, int StationID);
		AUTOMALIB_API virtual ~MSamNetModule();
		AUTOMALIB_API CString GetStateName();
	protected:
	};

}//namespace AutoLib
