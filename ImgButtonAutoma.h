#if !defined(AFX_IMAGEBUTTON_H__198CE0D4_D86C_43A8_9F37_B5372FBEF041__INCLUDED_)
#define AFX_IMAGEBUTTON_H__198CE0D4_D86C_43A8_9F37_B5372FBEF041__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
namespace AutoLib {
	AUTOMAUI_API class ImgButtonAutoma : public CButton
	{
		// Construction
	public:
		AUTOMAUI_API ImgButtonAutoma();

		enum {
			TEXT_INCLUDE = 0x0001,
			IMAGE_RIGHT = 0x0002,
			IMAGE_VCENTER = 0x0004,
			IMAGE_BOTTOM = 0x0008,
			IMAGE_HCENTER = 0x0010,
			FOCUS_TEXTONLY = 0x0020,
		};
	public:
		AUTOMAUI_API virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
		AUTOMAUI_API void SetTextColor(COLORREF color);
		AUTOMAUI_API BOOL SetAlignStyle(DWORD dwStyle);
		AUTOMAUI_API BOOL SetButtonImage(UINT uiImageID, COLORREF  clrMask);
		AUTOMAUI_API virtual ~ImgButtonAutoma();

	protected:
		void ReCalculateSettings();
		COLORREF    m_clrMask;
		CBitmap     m_bitmapImage;
		BITMAP      m_bitmap;
		HBITMAP	    m_hbmpDisabled;
		CImageList	m_ImageList;
		BOOL        m_bLoaded;

		DWORD       m_dwAlign;   //View Style 


		CRect       m_RectImage;
		CRect       m_RectText;
		CRect       m_RectTextFocus;

		COLORREF    m_clrText;       //Text Color

		//{{AFX_MSG(ImgButtonAutoma)
		afx_msg void OnSetFocus(CWnd* pOldWnd);
		afx_msg void OnSysColorChange();
		afx_msg void OnSize(UINT nType, int cx, int cy);
		afx_msg void OnEnable(BOOL bEnable);
		//}}AFX_MSG

		DECLARE_MESSAGE_MAP()
	};
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEBUTTON_H__198CE0D4_D86C_43A8_9F37_B5372FBEF041__INCLUDED_)
