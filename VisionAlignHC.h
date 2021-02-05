
#pragma once
#include "Unit.h"
#include "IO.h" 
#include "Halcon.h"
#include "VisionDisplayHC.h"
#include "VisionGrabberHC.h"
#include "VisionImageHC.h"
#include "VisionPatternHC.h"
#include "VisionMatchHC.h"
#include "CCDHC.h"
#include "VisionBinaryHC.h"
#include "VisionDisplayHC.h"
#include "RGBLightSamNet.h"
#include <list>

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;

namespace AutoLib{
AUTOMAVHC_API class MVisionAlignHC : public MUnit
{
protected:
	AUTOMAVHC_API MVisionAlignHC(MUnit *pParent, CString strID, CString strName, int intCCD, int intMarkNum, int ErrorCodeBase = -1);
	AUTOMAVHC_API virtual ~MVisionAlignHC();
	static UINT DoThread(void *);
	enum STEP {
		stpStartGrabber,
		stpWaitImage,
		stpMatchImage,
	};
	struct ImageProcessData
	{
		bool m_bBinaryProcess=false;
		int m_intBinLowThreshold = 0;
		int m_intBinHiThreshold = 127;
	};
	//-----------------------------------------------------------
	AUTOMAVHC_API virtual void StepCycle(const double dblTime);
	AUTOMAVHC_API virtual void LoadMachineData(CADOConnection * p_C, bool bAllChildsLoad = true);
	AUTOMAVHC_API virtual void SaveMachineData(CADOConnection * p_C, bool bAllChildsSave = true);
	AUTOMAVHC_API virtual void LoadRecipeData(CADOConnection * p_C, bool bAllChildsLoad = true);
	AUTOMAVHC_API virtual void SaveRecipeData(CADOConnection * p_C, bool bAllChildsSave = true);
	//-----------------------------------------------------------
public:
	AUTOMAVHC_API virtual void CreateCCD() {};
	AUTOMAVHC_API virtual void VisionCycle(const double dblTime);
	AUTOMAVHC_API virtual bool GetLive();
	AUTOMAVHC_API virtual bool Init();
	AUTOMAVHC_API virtual void SetLive(bool bLive);
	AUTOMAVHC_API virtual int GetSelectedROIIndex();
	AUTOMAVHC_API virtual void SetRegionType(MVisionRegion::RegionType rtType);
	AUTOMAVHC_API virtual MVisionRegion::RegionType GetRegionType();
	AUTOMAVHC_API virtual unsigned long GetImageListCount();
	AUTOMAVHC_API virtual unsigned long GetCCDBufferSize();
	AUTOMAVHC_API virtual unsigned long GetCCDBufferCount();
	AUTOMAVHC_API virtual void SelectPattern(int intPatternID);
	AUTOMAVHC_API virtual int GetPatternID();
	AUTOMAVHC_API virtual int GetPatternType();
	AUTOMAVHC_API virtual void SetPatternType(int intPatternType);
	AUTOMAVHC_API virtual void TeachPattern(bool bTeach);
	AUTOMAVHC_API virtual void CreatePattern();
	AUTOMAVHC_API virtual void SetMaxMatchNum(int intMaxNum);
	AUTOMAVHC_API virtual void MatchPattern();
	AUTOMAVHC_API virtual void LoadImageFile(CString strFile);
	AUTOMAVHC_API virtual void SaveImageFile(CString strFile);
	AUTOMAVHC_API virtual void SetCalibrationFile(int index, CString strFile);
	AUTOMAVHC_API virtual void ClearMatch();
	AUTOMAVHC_API virtual MVisionImageHC GetImage();
	AUTOMAVHC_API virtual void SetImageDisplay(MVisionDisplayHC* pDisplay);
	AUTOMAVHC_API virtual void SetPatternDisplay(MVisionDisplayHC* pDisplay);
	AUTOMAVHC_API virtual void SetGrabberNum(int intGrabberNum);
	AUTOMAVHC_API virtual void GetOneFromList();
	AUTOMAVHC_API virtual void SoftTrigger();
	AUTOMAVHC_API virtual bool TriggerMatch(int intMatchNum=0);
	AUTOMAVHC_API virtual MVisionImageHC ProcessImage(MVisionImageHC Image);
	AUTOMAVHC_API virtual void AddRegion(MVisionPattern::RegionFunction rfFunction);
	AUTOMAVHC_API virtual void DelRegion();
	AUTOMAVHC_API virtual bool GetGrabberLineInStatus();
	AUTOMAVHC_API virtual CString GetImagePath() { return m_strImagePath; }
	AUTOMAVHC_API virtual unsigned long GetGrabberStatus();
	AUTOMAVHC_API virtual bool GetTeachMode() { return m_bTeach; };
	AUTOMAVHC_API virtual void ReDraw();
	AUTOMAVHC_API virtual void OnSelectPatternChange();
	AUTOMAVHC_API virtual void SetRangeLimmited(bool bRangeLimmited);
	AUTOMAVHC_API virtual void SetAreaCheck(bool bCheck);
	AUTOMAVHC_API virtual void SetDarkAreaCheck(bool bDark);
	AUTOMAVHC_API virtual void SetExporeTime(double ExporeTime_us);
	AUTOMAVHC_API virtual int GetMarkNum();
	AUTOMAVHC_API virtual double GetExporeTime();
	AUTOMAVHC_API virtual void SetBinaryEnable(bool bEnable);
	AUTOMAVHC_API virtual bool GetBinaryEnable();
	AUTOMAVHC_API virtual void SetRetPointToCenter();
	AUTOMAVHC_API virtual void SetShowPixel(bool bShowPixel);
	AUTOMAVHC_API virtual bool GetShowPixel();

	AUTOMAVHC_API virtual void OnMatchImage() {};
	AUTOMAVHC_API virtual void OnGrabImage() {};
	AUTOMAVHC_API virtual void OnGrabTimeOut() {};
	AUTOMAVHC_API virtual void OnMatchError() {};
	AUTOMAVHC_API virtual void AddActiveRegion(MVisionDisplayHC *pDisplay, bool bTeach);
	AUTOMAVHC_API virtual MVisionImageHC GetImageByIndex(int index);

	double m_dblScanTime;
	MCCDHC *m_pCCD;
	MVisionMatchHC *m_pMatch;
	MVisionPatternHC *m_pPattern;
	ImageProcessData *m_pImageProcessData;
	MVisionLib *m_pVisionLib;
	MTimer *m_pTmVisionTimeout;
	MRGBLightSamNet *m_pRGBLight;
	bool m_bAutoSaveImage;
	bool m_bUseFileOnVirtualMode;
	COLORREF m_crCross, m_crMessage;
protected:
	CArray<MVisionPatternHC *> m_Patterns;
	CArray<MVisionMatchHC *> m_Matchs;
	CArray<ImageProcessData *> m_ImageProcessDatas;
	CString m_strImagePath;
	CRITICAL_SECTION m_csVisionSys;
	MVisionDisplayHC*  m_pHWXDisplay;
	MVisionDisplayHC*  m_pHWXDispSet;
	MVisionDisplayHC*  m_pHWXPattern;
	DWORD m_pThread;
	MVisionGrabberHC *m_pGrabber;
	MVisionImageHC m_ImageProcessed;
	MVisionImageHC m_Image;
	MVisionBinaryHC m_Binary;
	HSystem m_hSystem;
	std::list<MVisionImageHC> m_ImageList;
	bool m_bLive;
	bool m_bTeach;
	int m_intGrabberNum;
	int m_intCCD;
	int m_intMarkIndex;
	int m_intMarkNum;
	bool m_bGetOne;
	bool m_bVisionInit;
	bool m_bShowPixel;
	int m_intMatchNum;
	int m_intMatchCount;
	bool m_bFailAddResult;
};
}

