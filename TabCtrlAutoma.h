#pragma once
#include "MachineBase.h"
#include "TabPageAutoma.h"
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
using namespace AutoLib;
namespace AutoLib {
	AUTOMAUI_API class TabCtrlAutoma : public CTabCtrl
	{
#ifdef AUTOMAUI_EXPORTS
		DECLARE_DYNAMIC(TabCtrlAutoma)
#endif
	public:
		AUTOMAUI_API TabCtrlAutoma();
		AUTOMAUI_API virtual ~TabCtrlAutoma();
		AUTOMAUI_API virtual void AddPage(TabPageAutoma *pDlg);
		AUTOMAUI_API virtual void DeleteAllPages();
		AUTOMAUI_API virtual void ReDrawPage();
		AUTOMAUI_API virtual void SetPageVisible(TabPageAutoma *pDlg, bool bVisible);
		AUTOMAUI_API virtual void SetMachine(MachineBase *pM);
		AUTOMAUI_API virtual void RefreshPages();
		AUTOMAUI_API virtual void OnMachineMessage(MMessage *pMsg);
		AUTOMAUI_API virtual void OnButtonKeyEvent(MachineBase::ButtonKeyIndex key, MButtonEvent::ButtonEvenCode code);
		AUTOMAUI_API virtual void OnShowForm();
		AUTOMAUI_API virtual void OnHideForm();
	protected:
		AUTOMAUI_API void ResizeDialog(int nIndex, int cx, int cy);
		AUTOMAUI_API afx_msg void OnSelChanging(NMHDR* pNMHDR, LRESULT* pResult);
		AUTOMAUI_API afx_msg void OnSelChange(NMHDR* pNMHDR, LRESULT* pResult);
		CArray<TabPageAutoma*> m_pageArray;
		CArray<bool> m_pageVisible;
		DECLARE_MESSAGE_MAP()
	};
}


