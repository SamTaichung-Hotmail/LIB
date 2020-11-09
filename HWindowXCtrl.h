#pragma once
#include "Type_def.h"
#include "VisionImageHC.h"
#include "VisionPatternHC.h"
#include "VisionMatchHC.h"
#include "VisionRegion.h"
#include "VisionMatchResults.h"
#include <map>
#include <list>
#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
/////////////////////////////////////////////////////////////////////////////
// CHWindowXCtrl 包裝函式類別 
#include <list>
namespace AutoLib {
AUTOMAVHC_API class CHWindowXCtrl : public CWnd
{
protected:
	DECLARE_DYNCREATE(CHWindowXCtrl)
public:
	enum DragPoint {
		dpLT,
		dpRT,
		dpLB,
		dpRB,
		dpTL,
		dpBL,
		dpRL,
		dpLL,
		dpRP,
	};
	AUTOMAVHC_API CHWindowXCtrl();
	AUTOMAVHC_API CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x4D5C5CB1, 0x11AE, 0x11D2, { 0x82, 0xCC, 0x0, 0x0, 0x92, 0x90, 0x28, 0x67 } };
		return clsid;
	}
	AUTOMAVHC_API virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

	AUTOMAVHC_API BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd,
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 屬性
public:


// 作業
public:

// IHWindowXCtrl

// Functions
//

	AUTOMAVHC_API void put_BorderColor(unsigned long newValue)
	{
		static BYTE parms[] = VTS_UI4 ;
		InvokeHelper(DISPID_BORDERCOLOR, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	AUTOMAVHC_API unsigned long get_BorderColor()
	{
		unsigned long result;
		InvokeHelper(DISPID_BORDERCOLOR, DISPATCH_PROPERTYGET, VT_UI4, (void*)&result, NULL);
		return result;
	}
	AUTOMAVHC_API void put_BorderWidth(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(DISPID_BORDERWIDTH, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	AUTOMAVHC_API long get_BorderWidth()
	{
		long result;
		InvokeHelper(DISPID_BORDERWIDTH, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	AUTOMAVHC_API long get_HWidthPixels()
	{
		long result;
		InvokeHelper(0x3f2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	AUTOMAVHC_API long get_HHeightPixels()
	{
		long result;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	AUTOMAVHC_API void put_HWidthPixels(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	AUTOMAVHC_API void put_HHeightPixels(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	AUTOMAVHC_API LPDISPATCH get_HalconWindow()
	{
		LPDISPATCH result;
		InvokeHelper(0x3fc, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

// Properties
//
	AUTOMAVHC_API void ClearDisplay();
	AUTOMAVHC_API void RefreshGraphic();
	AUTOMAVHC_API void AddStaticRegion(MVisionRegion *pRegioin);
	AUTOMAVHC_API void AddActiveRegion(MVisionRegion* pRegioin);
	AUTOMAVHC_API void AddActiveRegion(MVisionPattern* pPattern);
	AUTOMAVHC_API void DelActiveRegion(MVisionRegion *pRegioin);
	AUTOMAVHC_API void ClearActiveRegion();
	AUTOMAVHC_API void ClearStaticRegion();
	AUTOMAVHC_API void AddMatchResult(MVisionMatchResult *pResult);
	AUTOMAVHC_API void ClearMatchResult();
	AUTOMAVHC_API void SetInterActive(bool bOn);
	AUTOMAVHC_API bool GetInterActive();
	AUTOMAVHC_API void FlushGraphic(bool bFlush);
	AUTOMAVHC_API void DrawImage(MVisionImageHC *pImage, bool bDrawCross);
	AUTOMAVHC_API void DrawPattern(MVisionPatternHC *pPattern);
	AUTOMAVHC_API void DrawMatch(MVisionMatchHC *pMatch);
	AUTOMAVHC_API void SetFocusDistance(USHORT distance);
	AUTOMAVHC_API void OnMouseDown(short nButton, short nShiftState, long X, long Y);
	AUTOMAVHC_API void OnMouseUP(short nButton, short nShiftState, long X, long Y);
	AUTOMAVHC_API void OnMouseMove(short nButton, short nShiftState, long X, long Y);
	AUTOMAVHC_API MVisionRegion* GetSelectRegion();
	DECLARE_EVENTSINK_MAP()
protected:
	void DrawActiveRegion(MVisionRegion *pRegion);
	bool m_bInterActive;
	std::list<MVisionMatchResult*> m_lstMatchResults;
	CArray<MVisionRegion*> m_StaticRegions;
	CArray<MVisionRegion*> m_InterActiveRegions;
	IHHomMat2DXPtr m_hMatrix;
	IHSystemXPtr m_hSystem;
	MVisionRegion* m_pDragRegion;
	MVisionRegion* m_pSelectRegion;
	MVisionRegion* m_pFocusRegion;
	int m_DragPoint;
	DCoordinate m_StartDrag;
	DCoordinate m_StartCenter;
	USHORT m_FocusDistance;
};
};