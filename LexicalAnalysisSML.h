#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "LexicalAnalysis.h"

namespace AutoLib
{
AUTOMASECS_API class MLexicalAnalysisSML:public MLexicalAnalysis
{

public:
	enum KeyWordIndex {
		kwi_HSMS,
		kwi_IF,
		kwi_EVERY,
		kwi_SEND,
		kwi_WAIT,
		kwi_LIST,
		kwi_BYTE,
		kwi_BOOLEAN,
		kwi_ASCII,
		kwi_I1,
		kwi_I2,
		kwi_I4,
		kwi_I8,
		kwi_U1,
		kwi_U2,
		kwi_U4,
		kwi_U8,
		kwi_F4,
		kwi_F8,
	};
	AUTOMASECS_API MLexicalAnalysisSML();
	AUTOMASECS_API KeyWord* GetKeyWord(CString strWord);
	~MLexicalAnalysisSML();
	KeyWord *m_pkwHSMS, *m_pkwIF, *m_pkwEVERY, *m_pkwSEND, *m_pkwWAIT,
		*m_pkwLIST, *m_pkwBYTE, *m_pkwBOOLEAN, *m_pkwASCII,
		*m_pkwI1, *m_pkwI2, *m_pkwI4, *m_pkwI8, *m_pkwU1, *m_pkwU2, *m_pkwU4, *m_pkwU8,
		*m_pkwF4, *m_pkwF8;
	KeyWord *m_pkwDot;
private:

};

}
