#pragma once

#include "FormViewAutoma.h"
#include "ButtonAutoma.h"
#include "ImgButtonAutoma.h"
#include "PictureAutoma.h"
#include "MachineBase.h"
#include "afxcmn.h"
#include "afxwin.h"

namespace AutoLib
{
class FormViewTopAutoma : public FormViewAutoma
{
#ifdef AUTOMAUI_EXPORTS
	DECLARE_DYNCREATE(FormViewTopAutoma)
#endif
protected:
	FormViewTopAutoma();           // 動態建立所使用的保護建構函式
	virtual ~FormViewTopAutoma();
	void OnMachineMessage(MMessage *pMsg);

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEW_TOP };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
	void RefreshForm();
	CImageList *m_pImageList;

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listMessage;
	virtual void OnInitialUpdate();
	PictureAutoma m_stcLogo;
	afx_msg void OnBnClickedBtnStatus();
	ButtonAutoma m_btnSystemAir;
	ButtonAutoma m_btnHomeComplete;
	ButtonAutoma m_btnSystemStatus;
	ImgButtonAutoma m_btnLogin;
	ImgButtonAutoma m_btnStop;
	afx_msg void OnBnClickedBtnLogin();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnDoubleclickedBtnStop();
	afx_msg void OnStnClickedStaticLogo();
	afx_msg void OnPaint();
	afx_msg void OnLvnItemchangedListMsg(NMHDR *pNMHDR, LRESULT *pResult);
};

}



