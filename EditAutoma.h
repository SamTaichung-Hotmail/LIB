#pragma once
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif

using CallChangeWndText = void  (CALLBACK * )(LPVOID,const CString&);

namespace AutoLib {
	AUTOMAUI_API class EditAutoma : public CMFCEditBrowseCtrl
	{
		DECLARE_DYNAMIC(EditAutoma)

	public:
		AUTOMAUI_API EditAutoma();
		AUTOMAUI_API void SetValueExchange(double &pV, const double max=0, const double mini=0);
		AUTOMAUI_API void SetValueExchange(int &pV, const double max = 0, const double mini = 0);
		AUTOMAUI_API void SetFormat(CString strFormat);
		AUTOMAUI_API void EnableInputButton(BOOL bUseInputPanel = FALSE);
		AUTOMAUI_API void BindCallBackFunc(CallChangeWndText pFunc, LPVOID Param);
	protected:
		DECLARE_MESSAGE_MAP()
		void OnBrowse() override;
		void SetValueRange(const double max, const double mini);
		CallChangeWndText m_pFunction;
		LPVOID m_LPVParam;
		CString m_strFormat;
		double *m_pdblValue;
		double m_dblMaximum;
		double m_dblMinimum;
		int *m_pIntValue;
	public:
		afx_msg void OnEnKillfocus();
		afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
		afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	};
}
