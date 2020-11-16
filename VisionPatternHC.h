
#pragma once
#include "VisionPattern.h"
#include "VisionImageHC.h"
#include "Coordinate.h"
#include "HalconCpp.h"
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
using namespace HalconCpp;
using namespace std;

namespace AutoLib{
class MVisionPatternHC : public MVisionPattern
{
public:
	AUTOMAVHC_API MVisionPatternHC();
	AUTOMAVHC_API virtual ~MVisionPatternHC();
	AUTOMAVHC_API virtual bool GetImage(MVisionImage *pImage);
	AUTOMAVHC_API virtual bool PutImage(MVisionImage *pImage);
	AUTOMAVHC_API virtual void PutDxfFile(HObject Contours);
	AUTOMAVHC_API virtual void Gen_model_image_of_bright_object_with_holes(HObject ho_Contours, HObject* ho_ModelImage,
		HTuple hv_Scale, HTuple hv_Width, HTuple hv_Height);
	AUTOMAVHC_API virtual bool Load();
	AUTOMAVHC_API virtual bool Save();
	AUTOMAVHC_API virtual void SetMinContrast(long contrast);
	AUTOMAVHC_API virtual long GetMinContrast();
	AUTOMAVHC_API virtual int GetMinRegionCount();
	AUTOMAVHC_API virtual void SetGapCheck(bool bAutoContrast);
	AUTOMAVHC_API virtual bool GetGapCheck();
	AUTOMAVHC_API virtual void SetMinGapAngle(double dblAngle);
	AUTOMAVHC_API virtual double GetMinGapAngle();
	AUTOMAVHC_API virtual double GetPatternLength1();
	AUTOMAVHC_API virtual void SetPatternLength1(double dblPatternLength1);
	AUTOMAVHC_API virtual double GetPatternLength2();
	AUTOMAVHC_API virtual void SetPatternLength2(double dblPatternLength2);
	AUTOMAVHC_API virtual void SetDispPatternType(bool bPatternType);
	AUTOMAVHC_API virtual bool GetDispPatternType();
	AUTOMAVHC_API virtual double GetPatternCenterRow();
	AUTOMAVHC_API virtual double GetPatternCenterColumn();
	HRegion m_hShapeModelTrans;
	HImage m_hImage, m_hImageReduced;
	HTuple m_hModel;
	MVisionImageHC *m_pImagePattern;
	HRegion m_hRectangle;
	HObject m_hContours;
	HObject m_hModelRegions;
	HTuple m_hCenterRow, m_hCenterColumn;
private:
	bool m_bGapCheck;
	double m_dblMinGapAngle;
	int m_Contrast;
	int m_MinContrast;
	double m_dblPatternLength1, m_dblPatternLength2;
	bool m_bPatternType;
};
}

