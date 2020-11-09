#pragma once
#pragma warning( disable : 4091)
#include "base.h"
#include "DALib.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif

namespace AutoLib{

	AUTOMALIB_API class MDA : public MBase
{
public:
	AUTOMALIB_API MDA(MBase *pB,CString strID,CString strC,MDALib* pLib, int CardID, int Connection, int Station,int ChannelID,
				double Max,double Min);
	AUTOMALIB_API virtual ~MDA(void);
	
	static std::map<CString,MDA*>	m_Members;
	
	AUTOMALIB_API virtual double GetValue();
	AUTOMALIB_API virtual bool SetValue(double dblValue);
		
public:
	int		m_CardID;
	int		m_ConnectionID;
	int		m_StationID;
	int		m_ChannelID;

protected:
	double		m_dblMax,m_dblMin;
	MDALib*	m_pLib;
};


}//AutoLib
