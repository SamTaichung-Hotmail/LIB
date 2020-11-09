#pragma once
#pragma warning( disable :4091)
#ifdef _M_X64
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#endif
#pragma comment(lib, "Version.Lib")

#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
#define cTmFormat_yymmdd_HHMMSS _T("%y%m%d-%H:%M:%S")
#define cTmFormat_yyyymmdd_HHMMSS _T("%Y%m%d-%H:%M:%S")
#define cTmFormat_mmdd_HHMMSS _T("%m%d-%H:%M:%S")
#define cTmFormat_dd_HHMMSS _T("%d-%H:%M:%S")
#define cTmFormat_DD_HHMMSS _T("%D-%H:%M:%S")
#define cTmFormat_HHMMSS _T("%H:%M:%S")
//時間的格式,y十進位不含世紀的年份,Y十進位含世紀的年份,
//m十進位月份(01-12),d十進位天(01-31),D十進位天(001-366),
//H小時(00-23),M分(00-59),S秒(00-59)
#define cDefaultLogFileName _T("Log.txt")	//預設的Log檔名.
#define cDefaultTimeFormat TIMEFORMAT::yymmdd_HHMMSS
#define charBackSlash char(92)
#define cBackupDBFileNo 6

#include "ADOConnection.h"
#include "ADORecordset.h"
#include <afxtempl.h>		// 50912
#include <iostream>
#include "fstream"
#include <sys/stat.h>	// to use FileExist

namespace AutoLib{

AUTOMABASE_API BOOL IsWow64();
AUTOMABASE_API void GetVersion(CString strFile, VS_FIXEDFILEINFO* verInfo);
AUTOMABASE_API class CIniFile
{
private:
	CString m_LastError;
	bool	m_isIniFileOpen;
private:
	//stores path of ini file to read/write
	CString FilePath;
	//stores name of ini file to read/write
	CString FileName;
	CString FullFileName;

public:

	AUTOMABASE_API void SetName(CString Name);
	AUTOMABASE_API void SetPath(CString Path);
	AUTOMABASE_API CIniFile();
	AUTOMABASE_API virtual ~CIniFile();
	AUTOMABASE_API BOOL GetItemString(CString Section,CString Key,CString& strData,CString strDefault=_T(""));
	AUTOMABASE_API BOOL WriteItemString(CString Section, CString Key, CString Data);
}; /* CIniFile */

}//namespace AutoLib