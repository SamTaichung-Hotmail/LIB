#pragma once
#ifdef AUTOMABASE_EXPORTS
#define AUTOMABASE_API __declspec(dllexport)
#else
#define AUTOMABASE_API __declspec(dllimport)
#endif

#include "adoconnection.h"

// CADORecordset
namespace AutoLib{
AUTOMABASE_API class CADORecordset
{

public:
	AUTOMABASE_API CADORecordset();
	AUTOMABASE_API virtual ~CADORecordset();
	ADODB::_RecordsetPtr m_pRecordset;
	AUTOMABASE_API bool Open(CString strSQL,CADOConnection * pConnection);
	AUTOMABASE_API void Close();
	AUTOMABASE_API bool MoveLast();
	AUTOMABASE_API bool MoveFirst();
	AUTOMABASE_API bool MovePrevious();
	AUTOMABASE_API bool MoveNext();
	AUTOMABASE_API bool AddNew();
	AUTOMABASE_API bool Delete();
	AUTOMABASE_API bool Update();
	AUTOMABASE_API bool isEOF();
	AUTOMABASE_API bool isBOF();
	AUTOMABASE_API void SetValue(CString FDName,const CString V);
	AUTOMABASE_API void SetValue(CString FDName,const CTime V);
	AUTOMABASE_API void SetValue(CString FDName,const COleDateTime V);
	AUTOMABASE_API void SetValue(CString FDName,const int V);
	AUTOMABASE_API void SetValue(CString FDName,const long V);
	AUTOMABASE_API void SetValue(CString FDName,const double V);
	AUTOMABASE_API void SetValue(CString FDName,const bool V);
	AUTOMABASE_API void SetValue(CString FDName,const unsigned short V);
	AUTOMABASE_API void GetValue(CString FDName,CString &V);
	AUTOMABASE_API void GetValue(CString FDName,CTime &V);
	AUTOMABASE_API void GetValue(CString FDName,COleDateTime &V);
	AUTOMABASE_API void GetValue(CString FDName,int &V);
	AUTOMABASE_API void GetValue(CString FDName,long &V);
	AUTOMABASE_API void GetValue(CString FDName,double &V);
	AUTOMABASE_API void GetValue(CString FDName,bool &V);
	AUTOMABASE_API void GetValue(CString FDName,unsigned short &V);
	AUTOMABASE_API ADODB::EditModeEnum GetEditMode()
		{return(m_pRecordset->GetEditMode());};
	AUTOMABASE_API long GetState()
		{return(m_pRecordset->GetState());};
	AUTOMABASE_API bool CancelUpdate()
		{return(SUCCEEDED(m_pRecordset->CancelUpdate()));};
	
};

}//namespace AutoLib
