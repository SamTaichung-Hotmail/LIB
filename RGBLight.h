#pragma once
#include "Base.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib{
AUTOMALIB_API class MRGBLight : public MBase
{
public:
	AUTOMALIB_API MRGBLight(MBase *pB, CString strID, CString strName, int intMin = 0, int intMax = 255);
	AUTOMALIB_API ~MRGBLight(void);
	AUTOMALIB_API virtual bool SetValue(int R, int G, int B);
	AUTOMALIB_API virtual bool IncreaseValue(int R, int G, int B);
	AUTOMALIB_API virtual bool DescreaseValue(int R, int G, int B);
	AUTOMALIB_API virtual bool GetValue(int *R, int *G, int *B){ *R = m_RValue; *G = m_GValue; *B = m_BValue; return true; };
	AUTOMALIB_API virtual bool SetOn(bool blOn){ m_isOn = blOn; return m_isOn; };
	AUTOMALIB_API virtual bool GetOn(){ return m_isOn; };
	AUTOMALIB_API virtual bool Active(){ return false; };
	AUTOMALIB_API virtual void LoadRecipeData(CADOConnection * pC, bool bAllChildsLoad = true);
	AUTOMALIB_API virtual void SaveRecipeData(CADOConnection * pC, bool bAllChildsSave = true);
	AUTOMALIB_API virtual void SetMaxMin(int MaxValue, int MinValue){ m_Max = MaxValue; m_Min = MinValue; };	// 50706
	AUTOMALIB_API virtual int GetMax(){ return m_Max; };	
	AUTOMALIB_API virtual int GetMin(){ return m_Min; };	
protected:
	int m_RValue,m_GValue,m_BValue,m_Min,m_Max;
	int m_CardID, m_ConnectID, m_StationID, m_ChannelID; //卡號,網路埠,站號,埠號
	bool m_isOn;
};
}
