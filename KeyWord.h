#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "Unit.h"
#include "HSMS.h" 
#include "TimeCounter.h"
#include "SecsDataItem.h"
namespace AutoLib
{
AUTOMASECS_API class KeyWord
{
public:
	AUTOMASECS_API KeyWord(int Type,CString strKeywords, CString strKeywordName,int index);
	~KeyWord();
	AUTOMASECS_API bool operator== (KeyWord &Op);
	AUTOMASECS_API bool operator< (KeyWord &Op);
	AUTOMASECS_API bool operator== (CString &strOp);
	AUTOMASECS_API bool operator%= (CString &strOp);
	AUTOMASECS_API CString GetKeyName();
	AUTOMASECS_API int GetKeyIndex();
	AUTOMASECS_API int GetTypeIndex();
	AUTOMASECS_API CString GetKeyWord();

private:
	CString m_strKeywords;
	CString m_strKeyName;
	int m_intType,m_intKeyIndex;
};

}
