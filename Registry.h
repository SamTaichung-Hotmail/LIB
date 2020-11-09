#pragma once
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
	AUTOMALIB_API class CRegistry{
	public:
		AUTOMALIB_API CRegistry();
		AUTOMALIB_API ~CRegistry();

		int m_nLastError;

		// CRegistry properties	
	protected:
		HKEY m_hRootKey;
		BOOL m_bLazyWrite;
		CString m_strCurrentPath;

	public:
		AUTOMALIB_API inline BOOL PathIsValid() {
			return (m_strCurrentPath.GetLength() > 0);
		}
		AUTOMALIB_API inline CString GetCurrentPath() {
			return m_strCurrentPath;
		}
		AUTOMALIB_API inline HKEY GetRootKey() {
			return m_hRootKey;
		}


		//CRegistry	methods
	public:
		AUTOMALIB_API BOOL ClearKey();
		AUTOMALIB_API BOOL SetRootKey(HKEY hRootKey);
		AUTOMALIB_API BOOL CreateKey(CString strKey);
		AUTOMALIB_API BOOL DeleteKey(CString strKey);
		AUTOMALIB_API BOOL DeleteValue(CString strName);
		AUTOMALIB_API int GetDataSize(CString strValueName);
		AUTOMALIB_API DWORD GetDataType(CString strValueName);
		AUTOMALIB_API int GetSubKeyCount();
		AUTOMALIB_API int GetValueCount();
		AUTOMALIB_API BOOL KeyExists(CString strKey, HKEY hRootKey = NULL);
		AUTOMALIB_API BOOL SetKey(CString strKey, BOOL bCanCreate);
		AUTOMALIB_API BOOL ValueExists(CString strName);
		AUTOMALIB_API void RenameValue(CString strOldName, CString strNewName);

		// data reading functions
		AUTOMALIB_API COleDateTime ReadDateTime(CString strName, COleDateTime dtDefault);
		AUTOMALIB_API double ReadFloat(CString strName, double fDefault);
		AUTOMALIB_API CString ReadString(CString strName, CString strDefault);
		AUTOMALIB_API int ReadInt(CString strName, int nDefault);
		AUTOMALIB_API BOOL ReadBool(CString strName, BOOL bDefault);
		AUTOMALIB_API COLORREF ReadColor(CString strName, COLORREF rgbDefault);
		AUTOMALIB_API BOOL ReadFont(CString strName, CFont* pFont);
		AUTOMALIB_API BOOL ReadPoint(CString strName, CPoint* pPoint);
		AUTOMALIB_API BOOL ReadSize(CString strName, CSize* pSize);
		AUTOMALIB_API BOOL ReadRect(CString strName, CRect* pRect);
		AUTOMALIB_API DWORD ReadDword(CString strName, DWORD dwDefault);

		// data writing functions
		AUTOMALIB_API BOOL WriteBool(CString strName, BOOL bValue);
		AUTOMALIB_API BOOL WriteDateTime(CString strName, COleDateTime dtValue);
		AUTOMALIB_API BOOL WriteString(CString strName, CString strValue);
		AUTOMALIB_API BOOL WriteFloat(CString strName, double fValue);
		AUTOMALIB_API BOOL WriteInt(CString strName, int nValue);
		AUTOMALIB_API BOOL WriteColor(CString strName, COLORREF rgbValue);
		AUTOMALIB_API BOOL WriteFont(CString strName, CFont* pFont);
		AUTOMALIB_API BOOL WritePoint(CString strName, CPoint* pPoint);
		AUTOMALIB_API BOOL WriteSize(CString strName, CSize* pSize);
		AUTOMALIB_API BOOL WriteRect(CString strName, CRect* pRect);
		AUTOMALIB_API BOOL WriteDword(CString strName, DWORD dwValue);
	};// end of CRegistry class definition
};
