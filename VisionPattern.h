#pragma once
#include "VisionRegion.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
#include "VisionBase.h"
namespace AutoLib {
	class MVisionPattern : public MVisionBase
	{
	public:
		enum ROIIndex {
			roiMaster,
			roiReturnPoint,
			roiAux1,
			roiAux2,
			roiAux3,
			roiOther,
		};
		enum PatternType {
			ptSigleMark,
			ptMarkFitCircle,
			ptCircleFitMark,
			ptSigleCircle,
			ptRing,
			ptDxf,
			ptFitLineVertical, 
			ptFitLineHorizontal,
		};
		enum RegionFunction {
			rfROI,
			rfReturnPoint,
			rfUnion,
			rfMask,
		};
		enum AreaCheckPolarity {
			acpDark,
			acpLight,
		};
		AUTOMALIB_API MVisionPattern();
		AUTOMALIB_API virtual ~MVisionPattern();
		AUTOMALIB_API virtual void Create(MVisionImage *pImage) {};
		AUTOMALIB_API virtual void SetPathFile(CString strPathFile);
		AUTOMALIB_API virtual int AddRegion(RegionFunction rfFun, MVisionRegion* pRegion);
		AUTOMALIB_API virtual bool DelRegion(int index);
		AUTOMALIB_API virtual MVisionRegion* GetRegion(int index, bool bTeach = false);
		AUTOMALIB_API virtual CString GetRegionName(int index, bool bTeach = false);
		AUTOMALIB_API virtual RegionFunction GetFunction(int index);
		AUTOMALIB_API virtual int GetRegionCount();
		AUTOMALIB_API virtual int GetMinRegionCount() { return 0; };
		AUTOMALIB_API virtual bool Load() { return false; };
		AUTOMALIB_API virtual bool Save() { return false; };
		AUTOMALIB_API virtual PatternType GetPatternType();
		AUTOMALIB_API virtual void SetPatternType(PatternType Type);
		AUTOMALIB_API virtual void SetRegionType(int index, MVisionRegion::RegionType Type);
		AUTOMALIB_API virtual void UpdateRegions(bool bUpdateToTeach);
		AUTOMALIB_API virtual MVisionRegion* GetRangeROI();
		AUTOMALIB_API virtual bool GetRangeLimmited();
		AUTOMALIB_API virtual void SetRangeLimmited(bool bRangeLimmited);
		AUTOMALIB_API virtual MVisionRegion* GetAreaCheckROI();
		AUTOMALIB_API virtual bool GetAreaCheck();
		AUTOMALIB_API virtual void SetAreaCheck(bool bAreaCheck);
		AUTOMALIB_API virtual int GetAreaCheckJudgeStart();
		AUTOMALIB_API virtual int GetAreaCheckJudgeEnd();
		AUTOMALIB_API virtual void SetAreaCheckJudgeStart(int intAreaCheckJudgeStart);
		AUTOMALIB_API virtual void SetAreaCheckJudgeEnd(int intAreaCheckJudgeStart);
		AUTOMALIB_API virtual int GetAreaCheckThreshold();
		AUTOMALIB_API virtual void SetAreaCheckThreshold(int intAreaCheckThreshold);
		AUTOMALIB_API virtual AreaCheckPolarity GetAreaCheckPolarity();
		AUTOMALIB_API virtual void SetAreaCheckPolarity(AreaCheckPolarity acpPolarity);

		AUTOMALIB_API virtual bool GetMultipleAreaCheck();
		AUTOMALIB_API virtual void SetMultipleAreaCheck(bool bAreaCheck);
		AUTOMALIB_API virtual int GetAreaCheckScale();
		AUTOMALIB_API virtual void SetAreaCheckScale(int intAreaCheckScale);
		CString m_strName;
	protected:
		CArray<RegionFunction> m_RegionFuns;
		CArray<MVisionRegion*> m_RegionObjs;
		CArray<MVisionRegion*> m_RegionTeachs;
		MVisionRegion m_RegionRange;
		MVisionRegion m_RegionAreaCheck;
		CString m_strPathFile;
		PatternType m_ptPatternType;
		bool m_bRangeLimmited;
		bool m_bAreaCheck;
		bool m_bMultipleAreaCheck;
		int m_intAreaCheckThreshold;
		int m_intAreaCheckJudgeStart;
		int m_intAreaCheckJudgeEnd;
		int m_intAreaCheckScale;
		AreaCheckPolarity m_acpAreaCheckPolarity;
	};
}
