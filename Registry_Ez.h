#pragma once
#include "..\stdafx.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
	AUTOMALIB_API class CRegistry
	{
	public:
		enum cregRestoreEnum
		{
			regVolatile = REG_WHOLE_HIVE_VOLATILE,
			regRefresh = REG_REFRESH_HIVE,
			regNoLazy = REG_NO_LAZY_FLUSH
		};
		/*
		enum Keys
		{
			classesRoot = HKEY_CLASSES_ROOT,
			currentUser = HKEY_CURRENT_USER,
			localMachine = HKEY_LOCAL_MACHINE,
			currentConfig = HKEY_CURRENT_CONFIG,
			users = HKEY_USERS,
			performanceData = HKEY_PERFORMANCE_DATA,	//Windows NT/2000
			dynData = HKEY_DYN_DATA						//Windows 95/98
		};
		*/
		AUTOMALIB_API CRegistry()
		{
			m_hKey = NULL;
		};

		AUTOMALIB_API ~CRegistry()
		{
			CloseKey();
			m_hKey = NULL;
		};

		AUTOMALIB_API BOOL OpenKey(enum Keys hKey, LPCTSTR szKey);
		AUTOMALIB_API BOOL CreateKey(enum Keys hKey, LPCTSTR szKey);
		AUTOMALIB_API BOOL DeleteKey(enum Keys hKey, LPCTSTR szKey);
		AUTOMALIB_API BOOL DeleteValue(LPCTSTR lpValueName);
		AUTOMALIB_API BOOL GetValue(LPCTSTR lpValueName, CString& strValue);
		AUTOMALIB_API BOOL GetValue(LPCTSTR lpValueName, DWORD& dwValue);
		AUTOMALIB_API BOOL SetValue(LPCTSTR lpValueName, LPCTSTR lpData);
		AUTOMALIB_API BOOL SetValue(LPCTSTR lpValueName, DWORD dwValue);
		AUTOMALIB_API BOOL SaveKey(LPCTSTR lpszFileName);
		AUTOMALIB_API BOOL RestoreKey(LPCTSTR lpszFileName, DWORD dwFlag);
		AUTOMALIB_API BOOL LoadKey(enum Keys hKey, LPCTSTR lpszSubKey, LPCTSTR lpszFileName);
		AUTOMALIB_API void CloseKey();

	protected:
		HKEY m_hKey;
	};
}