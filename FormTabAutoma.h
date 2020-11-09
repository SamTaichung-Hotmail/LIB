#pragma once
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
#include <vector>
#include "Message.h"
#include "FormViewAutoma.h"
#include "TabCtrlAutoma.h"
#include "MachineBase.h"
using namespace AutoLib;
namespace AutoLib{
// FormTabAutoma 表單檢視
	AUTOMAUI_API class FormTabAutoma : public FormViewAutoma
	{
#ifdef AUTOMAUI_EXPORTS
		DECLARE_DYNAMIC(FormTabAutoma)
#endif
	protected:
		AUTOMAUI_API virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
		AUTOMAUI_API FormTabAutoma(UINT nIDTemplate,UINT nIDTab);
		AUTOMAUI_API virtual ~FormTabAutoma();

	public:

	#ifdef _DEBUG
		AUTOMAUI_API virtual void AssertValid() const;
		AUTOMAUI_API virtual void Dump(CDumpContext& dc) const;
	#endif
		AUTOMAUI_API virtual void RefreshForm();
		AUTOMAUI_API virtual void SetMachine(MachineBase* pM);
		AUTOMAUI_API virtual void OnMachineMessage(MMessage *pMsg);
		AUTOMAUI_API virtual void OnButtonKeyEvent(MachineBase::ButtonKeyIndex key, MButtonEvent::ButtonEvenCode code);
		AUTOMAUI_API virtual void AddPage(TabPageAutoma *pDlg);
		AUTOMAUI_API virtual int GetPageCount();
		AUTOMAUI_API virtual CString GetPageName(int index);
		AUTOMAUI_API virtual void OnShowForm();
		AUTOMAUI_API virtual void OnHideForm();
	protected:
		DECLARE_MESSAGE_MAP()
		TabCtrlAutoma m_TabControl;
		UINT m_TabID;
	};
}//namespace AutoLib
