#pragma once
#define TRANS_BACK -1

#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
namespace AutoLib{
	AUTOMAUI_API class StaticAutoma : public CStatic
	{
#ifdef AUTOMAUI_EXPORTS
		DECLARE_DYNAMIC(StaticAutoma)
#endif
	public:
		AUTOMAUI_API StaticAutoma();
		AUTOMAUI_API virtual ~StaticAutoma();
		AUTOMAUI_API void SetTextColor(COLORREF col);
		AUTOMAUI_API COLORREF GetTextColor();
		AUTOMAUI_API void SetBackColor(COLORREF col);
		AUTOMAUI_API COLORREF GetBackColor();
	protected:
		afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
		DECLARE_MESSAGE_MAP()
	private:
		void UpdateCtrl();
		COLORREF m_TextColor;
		COLORREF m_BackColor;
		CBrush   m_Brush;
	};
}