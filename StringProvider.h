#pragma once
#include "Tool.h"
#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
namespace AutoLib{
AUTOMABASE_API class CStringProvider
{
public:
	AUTOMABASE_API CStringProvider(CIniFile *pLangFile);
	AUTOMABASE_API CString GetString(CString strSection, CString strItem, CString strDefault);
	AUTOMABASE_API CString GetString(CString strSection, CString strItem);
private:
	CIniFile *m_pLangFile;
};

}//namespace AutoLib