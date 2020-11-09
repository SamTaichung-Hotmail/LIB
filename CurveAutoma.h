#pragma once
#ifdef AUTOMAUI_EXPORTS
#define AUTOMAUI_API __declspec(dllexport)
#else
#define AUTOMAUI_API __declspec(dllimport)
#endif
#include <vector>
#define MaxGroupCount 8
namespace AutoLib {
	AUTOMAUI_API class CCurveAutoma :public CStatic
	{
		DECLARE_DYNAMIC(CCurveAutoma)

	public:
		AUTOMAUI_API CCurveAutoma();
		AUTOMAUI_API ~CCurveAutoma();
		AUTOMAUI_API void SetPointCount(const int count);
		AUTOMAUI_API int GetPointCount();
		AUTOMAUI_API void SetGroupCount(const int count);
		AUTOMAUI_API int GetGroupCount();
		AUTOMAUI_API void InsertData(double* pData, int GroupCount);
		AUTOMAUI_API void GetFeatureData(int GroupID, double& dblMax, double& dblMin, double& dblAverage);
		AUTOMAUI_API void SetGroupColor(int GroupID, COLORREF color);
		AUTOMAUI_API void SetRange(int GroupID, double dblMax, double dblMin);
		AUTOMAUI_API void SetOverRangeColor(int GroupID, COLORREF color);
		AUTOMAUI_API void SetGridColor(COLORREF color);
	protected:
		DECLARE_MESSAGE_MAP()
		int m_intPointCount;
		int m_intGroupCount;
		std::vector<double> m_vtTable[MaxGroupCount];
		COLORREF m_crGroupLine[MaxGroupCount];
		COLORREF m_crGroupOver[MaxGroupCount];
		COLORREF m_crBackGround;
		COLORREF m_crGridColor;
		double m_dblMax[MaxGroupCount], m_dblMin[MaxGroupCount], m_dblAverage[MaxGroupCount];
		double m_dblRangeMax[MaxGroupCount], m_dblRangeMin[MaxGroupCount];
	public:
		afx_msg void OnPaint();
	};

}