#pragma once
#ifndef __AFXWIN_H__
#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif
#ifdef _M_X64
	#ifdef DEBUG
		#pragma comment(lib, "AutomaBase64D.Lib")
		#pragma comment(lib, "AutomaLib64D.Lib")
	#else
		#pragma comment(lib, "AutomaBase64.Lib")
		#pragma comment(lib, "AutomaLib64.Lib")
	#endif // DEBUG
#else	
	#ifdef DEBUG
		#pragma comment(lib, "AutomaBase32D.Lib")
		#pragma comment(lib, "AutomaLib32D.Lib")
	#else
		#pragma comment(lib, "AutomaBase32.Lib")
		#pragma comment(lib, "AutomaLib32.Lib")
	#endif
#endif
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
#include "MachineBase.h"
#include "CCD.h"
#include "MTray.h"
#include "TabPageAutoma.h"
#include "TabCtrlAutoma.h"
#include <stack>
namespace AutoLib {
	enum UITabPageID {
		tpMotor,
		tpValve,
		tpTimer,
		tpIO,
		tpPilot,
		tpFileRecipe,
		tpFileMachine,
		tpFileLanguage,
		tpProductionAlarm,
		tpProductionTime,
	};
	enum UIViewID {
		uvTop,
	};
	AUTOMAUI_API void UIShowCCDConfig(CWnd* pParent, MCCD* pCCD);
	AUTOMAUI_API void UIShowMotorConfig(CWnd* pParent, MMotor* pMotor);
	AUTOMAUI_API void UIShowUserLogin(CWnd* pParent, MachineBase *pMachine);
	AUTOMAUI_API void UIShowTraySet(CWnd* pParent, MTray *pTray);
	AUTOMAUI_API void UIShowError(CWnd* pParent, MError* pError , CDialog **pp_DialogAlarm);
	AUTOMAUI_API void UIShowEmgStop(CWnd* pParent, MachineBase *pMachine);
	AUTOMAUI_API void UIShowSystemStatus(CWnd* pParent, MachineBase* pMachine);
	AUTOMAUI_API void UIShowExpireWarn(CWnd* pParent, MachineBase* pMachine);
	AUTOMAUI_API INT_PTR UIShowValueInput(CWnd* pParent, double& dblValue,double dblMax=0,double dblMin=0);
	AUTOMAUI_API TabPageAutoma* UICreateTabPage(UITabPageID PageID);
	AUTOMAUI_API CRuntimeClass* UICreateView(UIViewID ViewID);
	AUTOMAUI_API BOOL UICreateView2(CSplitterWnd* pSplitter,int nRow, int nCol,
		CRuntimeClass * pViewClass,
		 int sx, int sy,CCreateContext* pContext);

	AUTOMAUI_API class AutomaUI : public CWinApp
{
	DECLARE_DYNCREATE(AutomaUI)
public:
	AUTOMAUI_API	AutomaUI();           // 動態建立所使用的保護建構函式
	AUTOMAUI_API virtual ~AutomaUI();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
protected:
	DECLARE_MESSAGE_MAP()
};
}

