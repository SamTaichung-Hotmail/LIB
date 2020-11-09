
// MainFrm.h : CMainFrame ���O������
//

#pragma once
#include "MachineBase.h"
#include "MultiViewSplitterAutoma.h"
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
namespace AutoLib {
	AUTOMAUI_API class CMainFrameAutoma : public CFrameWnd
	{
	protected: // �ȱq�ǦC�ƫإ�
		AUTOMAUI_API CMainFrameAutoma();
		DECLARE_DYNCREATE(CMainFrameAutoma)
	protected:
		AUTOMAUI_API LRESULT MachineMessage(WPARAM wParam, LPARAM lParam);
		AUTOMAUI_API LRESULT ButtonEventHandle(WPARAM wParam, LPARAM lParam);
			MultiViewSplitterAutoma m_wndSplitter;
	public:
		AUTOMAUI_API virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
		AUTOMAUI_API virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
		AUTOMAUI_API virtual MachineBase* CreateMachine(CMainFrameAutoma* pMainFrame) { return NULL; };
		AUTOMAUI_API virtual void CreateFormView(CCreateContext* pContext) {};
		AUTOMAUI_API virtual void OnRefreshTimer() {};
		AUTOMAUI_API virtual void OnMachineMessage(MMessage *pMsg);
		AUTOMAUI_API virtual void OnButtonKeyEvent(MachineBase::ButtonKeyIndex key,MButtonEvent::ButtonEvenCode code);
	public:
		AUTOMAUI_API virtual ~CMainFrameAutoma();
	#ifdef _DEBUG
		AUTOMAUI_API virtual void AssertValid() const;
		AUTOMAUI_API virtual void Dump(CDumpContext& dc) const;
	#endif
		MachineBase *m_pMachine;
	protected:  // ����C���O������
		//CToolBar          m_wndToolBar;
		CStatusBar        m_wndStatusBar;
		// ���ͪ��T�������禡
		CDialog *m_pDialgAlarm;

	protected:
		AUTOMAUI_API afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
		AUTOMAUI_API virtual BOOL PreTranslateMessage(MSG* pMsg);
		DECLARE_MESSAGE_MAP()

	public:
		AUTOMAUI_API virtual BOOL DestroyWindow();
		AUTOMAUI_API afx_msg void OnTimer(UINT_PTR nIDEvent);
	};
}


