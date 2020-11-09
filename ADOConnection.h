#pragma once
#ifdef _M_X64
	#define DefaultProviderString _T("Provider=Microsoft.ACE.OLEDB.12.0;")
	#define DefaultDBFileExt _T("accdb")
	#import "c:\\program files (x86)\\common files\\system\\ado\\msadox.dll"
	#import "c:\\program files (x86)\\common files\\system\\ado\\msado15.dll" rename(_T("EOF"),_T("adoEOF"))
#else
	#define	DefaultProviderString _T("Provider=Microsoft.Jet.OLEDB.4.0;")
	#define DefaultDBFileExt _T("mdb")
	#import "c:\\program files\\common files\\system\\ado\\msadox.dll"
	#import "c:\\program files\\common files\\system\\ado\\msado15.dll" rename(_T("EOF"),_T("adoEOF"))
#endif
#define DefaultMSSQLString _T("Provider=SQLOLEDB;")
//"Provider=SQLOLEDB;Data Source=.\\SQLEXPRESS;DataBase= PartSorterDB;User ID=username;Password=****;"
#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif
using namespace ADODB;
namespace AutoLib{
AUTOMABASE_API class CADOConnection
{
public:
	enum enuDataBase {
		AccessFile,
		MSSQL,
	};
	AUTOMABASE_API CADOConnection(enuDataBase DataBase=enuDataBase::AccessFile,
		CString strDataSource=_T(""),
		CString strUserID=_T(""),
		CString strPassword=_T(""));
	AUTOMABASE_API virtual ~CADOConnection();
	AUTOMABASE_API int GetTableIndex(CString TBName);
	AUTOMABASE_API int GetFieldIndex(CString TBName,CString FDName);
	AUTOMABASE_API bool ExecuteSQL(CString strSQL);
	AUTOMABASE_API bool BeginTrans();
	AUTOMABASE_API bool CommitTrans();
	AUTOMABASE_API bool RollBackTrans();
	AUTOMABASE_API bool Open();
	AUTOMABASE_API bool isOpen();
	AUTOMABASE_API void Close();
	AUTOMABASE_API int GetState();
	AUTOMABASE_API void SetProvider(CString strProvider);
	AUTOMABASE_API CString GetProvider();
	AUTOMABASE_API void SetUserID(CString strUserID);
	AUTOMABASE_API CString GetUserID();
	AUTOMABASE_API void SetPassword(CString strUserID);
	AUTOMABASE_API CString GetPassword();
	AUTOMABASE_API void SetDataSource(CString strDataSource);
	AUTOMABASE_API CString GetDataSource();
	AUTOMABASE_API bool CreateDataBase(CString strDataBase);
	ADODB::_ConnectionPtr	m_pConnection;
	ADODB::_ConnectionPtr operator =(const CADOConnection *);
protected:
	CString	m_strDataSource;
	CString m_strProvider;
	CString m_strUserID;
	CString m_strPassword;
	enuDataBase m_DataBase;
private:
	bool m_bIsOpen;
};
}//namespace AutoLib

