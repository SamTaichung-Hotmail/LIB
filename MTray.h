#pragma once
#include "Unit.h"
#include "Coordinate.h"
#define MaxRowNum 50
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
	AUTOMALIB_API class MTray :
		public MUnit
	{
	public:
		AUTOMALIB_API MTray(MUnit *pParent, CString strID, CString strName, int ErrorCodeBase = -1);
		AUTOMALIB_API virtual ~MTray();
		AUTOMALIB_API virtual void LoadRecipeData(CADOConnection * p_C, bool bAllChildsLoad = true);
		AUTOMALIB_API virtual void SaveRecipeData(CADOConnection * p_C, bool bAllChildsLoad = true);
		//-------------------------------------------------------------------
		AUTOMALIB_API virtual void ResetTray(int intTrayIndex = 0, int intPlaceNum = 0);
		AUTOMALIB_API virtual int GetRowCount();
		AUTOMALIB_API virtual int GetPointCount();
		AUTOMALIB_API virtual int GetIndexByRowColumn(int Row, int Col);
		AUTOMALIB_API virtual void GetRowColumnByIndex(int index, int &Row, int &Col);
		AUTOMALIB_API virtual bool GetExcludeByIndex(int index);
		AUTOMALIB_API virtual void GetRowCol(int &Row, int &Col);
		AUTOMALIB_API virtual DCoordinate GetPutPosition(int index,bool bByTeach=true);
		AUTOMALIB_API virtual int GetTotal(bool bExcludeCount = true); //取得全部的點位（包含排除點位？）
		AUTOMALIB_API virtual void ResetNGRecord();
		AUTOMALIB_API virtual void SetNGRecord(int intIndex, bool bNG = true);
		AUTOMALIB_API virtual bool GetNGRecord(int intIndex);
		int m_Rows[MaxRowNum];				//每個Row上的Column數
		int m_TempRows[MaxRowNum];  //暫時給快速產生編排用
		int m_Exclude[MaxRowNum];			//排除的點位（以第1行第1列為1開始算）
		int m_intPlacedNum;
		int m_intTrayIndex;
		int m_intTrayNum;
		int m_intMaxTrayNum;
		DCoordinate m_cdBasePos;
		bool m_bXYChange, m_bYMirror;
		double m_dblXPitch;
		double m_dblYPitch;
		bool m_bInterlace; 
		double m_dblTrayYPitch;

	private:
		bool m_NG[MaxRowNum][MaxRowNum];
	};

}
