
#pragma once
#include <windows.h>
#include "Type_def.h"
#include "VisionImageHC.h"
#include "VisionPatternHC.h"
#include "VisionMatchHC.h"
#include "VisionRegion.h"
#include "VisionMatchResults.h"
#include "VisionGrabberHC.h"
#include "CCDHC.h"
#include <map>
#include <list>
#include "afxcmn.h"
#include "afxwin.h"
#pragma comment(lib, "halconcpp.lib")

#ifdef AUTOMAVHC_EXPORTS
#define AUTOMAVHC_API __declspec(dllexport)
#else
#define AUTOMAVHC_API __declspec(dllimport)
#endif
// MVisionDisplayHC 命令目標
namespace AutoLib{
class MVisionImage;
AUTOMAVHC_API class MVisionDisplayHC:public CStatic
{ 
	DECLARE_DYNCREATE(MVisionDisplayHC)
public:
	enum DragPoint {
		dpLT,
		dpRT,
		dpLB,
		dpRB,
		dpRIL, //
		dpRIR,
		dpTL,
		dpBL,
		dpRL,
		dpLL,
		dpRP,
	};
	enum EventCode {
		ecRegionSelectedChange,
		ecRegionDeleted,
		ecRegionSizeChange,
		ecRegionMove,
		ecRegionFocusChange,
		ecRegionColorChange,
		ecRegionLineWidthChange,
		ecClearDisplay,
		ecLButtonDown,
	};
	AUTOMAVHC_API MVisionDisplayHC();
	AUTOMAVHC_API virtual ~MVisionDisplayHC();
	AUTOMAVHC_API void ClearDisplay();
	AUTOMAVHC_API void UIClearDisplay();
	AUTOMAVHC_API void RefreshGraphic();
	AUTOMAVHC_API void AddDrawObj(MVisionBase *pDrawObj);
	AUTOMAVHC_API void AddActiveRegion(MVisionRegion* pRegioin);
	AUTOMAVHC_API void DelActiveRegion(MVisionRegion *pRegioin);
	AUTOMAVHC_API void ClearActiveRegion();
	AUTOMAVHC_API void ClearAllDrawObj();
	AUTOMAVHC_API void AddMatchResult(MVisionMatchResult *pResult);
	AUTOMAVHC_API void AddMessage(CString strMsg);
	AUTOMAVHC_API void ClearMessage();
	AUTOMAVHC_API void RemoveMatchResult(MVisionMatchResult *pResult);
	AUTOMAVHC_API void ClearMatchResult();
	AUTOMAVHC_API void SetInterActive(bool bOn);
	AUTOMAVHC_API bool GetInterActive();
	AUTOMAVHC_API void FlushGraphic(bool bFlush);
	AUTOMAVHC_API void DrawImage(MVisionImageHC *pImage, bool bDrawCross);
	AUTOMAVHC_API void DrawPattern(MVisionPatternHC *pPattern);
	AUTOMAVHC_API void DrawMatch(MVisionMatchHC *pMatch);
	AUTOMAVHC_API void SetFocusDistance(USHORT distance);
	AUTOMAVHC_API void OpenHWindow(void(*EventCallBackFunction)(CWnd*, UINT, void*));
	AUTOMAVHC_API void SetCrossColor(COLORREF crColor);
	AUTOMAVHC_API void SetMessageColor(COLORREF crColor);
	AUTOMAVHC_API void SetFontSize(int size);
	AUTOMAVHC_API void SetShowPixel(bool bShowAsPixel);
	AUTOMAVHC_API void SetTextPosition(int intFontSize,int Row,int Col);
	AUTOMAVHC_API MVisionRegion* GetSelectRegion();
	HTuple m_hHalconWindow;
	HObject m_hDraw;
	HImage m_hDrawImage;

protected:
	DECLARE_MESSAGE_MAP()
	void DrawActiveRegion(MVisionRegion *pRegion);
	bool m_bInterActive;
	bool m_bOffseting;
	std::list<MVisionMatchResult*> m_lstMatchResults;
	CArray<MVisionBase*> m_DrawObjs;
	CArray<MVisionRegion*> m_InterActiveRegions;
	CArray<CString> m_strMessages;
	HHomMat2D m_hMatrix;
	HSystem m_hSystem;
	MVisionRegion* m_pDragRegion;
	MVisionRegion* m_pSelectRegion;
	MVisionRegion* m_pFocusRegion;
	int m_DragPoint;
	DCoordinate m_StartDrag;
	DCoordinate m_StartCenter;
	DCoordinate m_OffsetScreen;
	USHORT m_FocusDistance;
	COLORREF m_crCross, m_crMessage;
	CMenu m_PopupRegionMenu;
	double m_dblZoom;
	int m_intFontSize;
	double m_dblOffsetX, m_dblOffsetY;
	double m_dblImageWidth,m_dblImageHeight;
	void(*m_EventCallBackFunction)(CWnd*,UINT,void*);
	bool m_bShowAsPixel;
	CRITICAL_SECTION m_csDisplay;
	int m_intMouseX, m_intMouseY;

public:
	void ReSetZoom();
	AUTOMAVHC_API void GetMousePoint(int &x, int &y); 
	AUTOMAVHC_API afx_msg void OnMove(int x, int y); //視窗移動
	AUTOMAVHC_API afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	AUTOMAVHC_API afx_msg void OnNcPaint();
	AUTOMAVHC_API afx_msg void OnPaint();
	AUTOMAVHC_API afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	AUTOMAVHC_API afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);

};
}

