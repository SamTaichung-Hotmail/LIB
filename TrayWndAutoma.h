#pragma once
#include "MTray.h"
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif

// CTrayWndAutoma
namespace AutoLib {

	AUTOMAUI_API class CTrayWndAutoma : public CStatic
	{
		DECLARE_DYNAMIC(CTrayWndAutoma)
	public:
		AUTOMAUI_API CTrayWndAutoma();
		AUTOMAUI_API virtual ~CTrayWndAutoma();
	protected:
		DECLARE_MESSAGE_MAP()
		AUTOMAUI_API void CalParameters(int &MaxXNum, int &MaxYNum, int &Pitch, int &Radius);
		int m_intHightLightRow;
		MTray *m_pTray;
		CString m_strStatus;
		bool m_bEditMode;
		bool m_bTempMode;
	public:
		AUTOMAUI_API void SetTray(MTray *pTray);
		AUTOMAUI_API MTray* GetTray();
		AUTOMAUI_API void SetEditMode(bool bEditMode) { m_bEditMode = bEditMode; };
		AUTOMAUI_API void SetTempMode(bool bTempMode) { m_bTempMode = bTempMode; };
		AUTOMAUI_API void SetHighLightRow(int row);
		AUTOMAUI_API void GetMoveTo(int &Row, int &Col, int &Num);
		AUTOMAUI_API afx_msg void OnPaint();
		AUTOMAUI_API afx_msg void OnMouseMove(UINT nFlags, CPoint point);
		AUTOMAUI_API afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
		AUTOMAUI_API afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
		int m_MoveToRow, m_MoveToCol, m_MoveToNum;
		double m_dblXDir;
		bool m_bShowNumber = true;
	};

}
