#pragma once
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
#include <vector>
#include "Message.h"
#include "MultiViewSplitterAutoma.h"
#include "MachineBase.h"
using namespace AutoLib;
namespace AutoLib{
// FormViewAutoma 表單檢視
	AUTOMAUI_API class FormViewAutoma : public CFormView
	{
#ifdef AUTOMAUI_EXPORTS
		DECLARE_DYNAMIC(FormViewAutoma)
#endif
	protected:
		AUTOMAUI_API FormViewAutoma(UINT nIDTemplate);
	
		AUTOMAUI_API virtual ~FormViewAutoma();

	public:
		struct Position
		{
			int		iID;
			int		iX;
			int		iY;
			UINT	uResouseID;
			int		iViewID;
		};
	
		std::map<int,Position>	m_ViewMap;
		MultiViewSplitterAutoma*	m_pSplitter;

	
	#ifdef _DEBUG
		AUTOMAUI_API virtual void AssertValid() const;
		AUTOMAUI_API virtual void Dump(CDumpContext& dc) const;
	#endif
		AUTOMAUI_API virtual void RefreshForm(){};					//更新Form要Override此function
		AUTOMAUI_API virtual void SetBackColor(COLORREF color);		//設定此View的背景顏色
		AUTOMAUI_API virtual COLORREF GetBackColor();				//取得此View的背景顏色
		AUTOMAUI_API virtual void SetMachine(MachineBase* pM);		//Machine建立完成
		AUTOMAUI_API virtual void OnMachineMessage(MMessage *pMsg) {};//系統傳送訊息到達
		AUTOMAUI_API virtual void OnButtonKeyEvent(MachineBase::ButtonKeyIndex key, MButtonEvent::ButtonEvenCode code) {}; //按鈕事件
		AUTOMAUI_API virtual void OnShowForm() {};
		AUTOMAUI_API virtual void OnHideForm() {};
		AUTOMAUI_API virtual int GetPageCount() { return 0; };
		AUTOMAUI_API virtual CString GetPageName(int index) { return _T(""); };
		AUTOMAUI_API int GetIconSize();
	protected:
		DECLARE_MESSAGE_MAP()
		int m_ViewIDofSpliter;						//目前的ViewID
		COLORREF m_BackColor;
		MachineBase* m_pMachine;
	public:
		bool m_isEnglish;
		CString m_csCurViewID;
		int m_nCurMenuID;
		void SetViewID(int iViewID);
		void SelectRightMenu(void);
		void SelectLeftMenu(void);
		CString GetCurViewID(void);
		void SetCurViewID(CString csCurViewID);
		int GetCurMenuID(void);
		void SetCurMenuID(int nMenuID);

	public:
		AUTOMAUI_API void SetSplitter(MultiViewSplitterAutoma* pSplitter);
		AUTOMAUI_API void OnDraw(CDC* pDC);
	};
}//namespace AutoLib
