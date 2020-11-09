#pragma once
#include "Coordinate.h"
#ifdef AUTOMALIB_EXPORTS
#define AUTOMALIB_API __declspec(dllexport)
#else
#define AUTOMALIB_API __declspec(dllimport)
#endif
namespace AutoLib {
	struct UserRight {
		UserRight(UserRight* pRoot, CString strRightID, CString strRightName) {
			root = pRoot;
			m_strRightID = strRightID;
			m_strRightName = strRightName;
		}
		~UserRight() {
		}
		UserRight *root;		//上層
		CString m_strRightID;	//權限代號
		CString m_strRightName;	//權限名稱
	};
	class DUser
	{
	public:
		AUTOMALIB_API DUser(int UserID,CString strName,CString strPassword,int Level);
		AUTOMALIB_API ~DUser(void);
		AUTOMALIB_API bool SetUserID(int UserID);
		AUTOMALIB_API int GetUserID();
		AUTOMALIB_API bool SetName(CString strName);
		AUTOMALIB_API CString GetName();
		AUTOMALIB_API bool SetPassword(CString strPassword);
		AUTOMALIB_API bool CheckPassword(CString strPassword);
		AUTOMALIB_API CString GetPassword();
		AUTOMALIB_API int GetLevel();
		AUTOMALIB_API bool SetLevel(int intLevel);
		CArray<BOOL> m_Rights;
	protected:
		int m_UserID;
		CString m_strName;
		CString m_strPassword;
		int m_Level;
	};
}