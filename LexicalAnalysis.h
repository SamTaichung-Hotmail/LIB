#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include <fstream>
#include <regex> 
#include "KeyWord.h"
#define LIMIT 255
namespace AutoLib
{
	AUTOMASECS_API class MLexicalAnalysis
	{

	public:
		enum OperatorIndex {
			PLUS,
			MINUS,
			MULT,
			DIV,
			EQ,
			NEQ,
			LESSER,
			GREATER,
			LESSEREQ,
			GREATEREQ,
			AND,
			OR,
			ASSIGN,
		};
	enum LexicalTokenType {
		PROGRAM_START,
		KEYWORD,
		OPERATOR,
		IDENTIFY,
		STRING,
		INT,
		HEX,
		FLOAT,
		COMMA,
		COLON,
		SEMI,
		LPAREN,
		RPAREN,
		LBRACK,
		RBRACK,
		LBRACE,
		RBRACE,
		PERIOD,
		DOT,
		// NULL token
		NULLL,
		// End of file token
		EOFF,
		NONTERMINAL,
		ACTION,
	};
	enum LexicalErrorCode {
		lecNoError,
		lecIdentifierErr,
		lecStringErr,
		lecParseErr,
	};
	AUTOMASECS_API struct LexicalToken {

		KeyWord *pKeyWord=NULL;
		CString strInstance;	
		int lineNum;
		int columNum;
	};
	AUTOMASECS_API MLexicalAnalysis();
	~MLexicalAnalysis();
	AUTOMASECS_API void InitAnalysis();
	AUTOMASECS_API LexicalErrorCode Analysis(std::ifstream &AnalysisText, LexicalToken **pToken);
	CArray<KeyWord*> m_KeyWords;
	CArray<KeyWord*> m_Operators;
	CArray<KeyWord*> m_Delimiters;
	KeyWord *m_pkwProgramStart;
	KeyWord *m_pkwIdentify;
	KeyWord *m_pkwFloat;
	KeyWord *m_pkwHex;
	KeyWord *m_pkwInteger;
	KeyWord *m_pkwString;
	KeyWord *m_pkwEOF;
	KeyWord *m_pkwError;
	KeyWord *m_pkwPLUS, *m_pkwMINUS, *m_pkwMULT, *m_pkwDIV, *m_pkwEQ, *m_pkwNEQ,
		*m_pkwLESSER, *m_pkwGREATER, *m_pkwLESSEREQ1, *m_pkwLESSEREQ2, *m_pkwGREATEREQ1, *m_pkwGREATEREQ2,
		*m_pkwAND, *m_pkwOR, *m_pkwASSIGN;
	KeyWord *m_pkwCOMMA, *m_pkwCOLON, *m_pkwSEMI, *m_pkwLPAREN, *m_pkwRPAREN,
		*m_pkwLBRACK, *m_pkwRBRACK, *m_pkwLBRACE, *m_pkwRBRACE, *m_pkwPERIOD;
	KeyWord *m_pkwNULL;
protected:
	AUTOMASECS_API virtual KeyWord* GetKeyWord(CString strWord);
	AUTOMASECS_API KeyWord* SearchKeyWord(CArray<KeyWord*>& Table,CString word);
private:
	LexicalErrorCode ReadDigis(std::ifstream &AnalysisText,int &col, CString& strDigitString, bool bHex);
	LexicalErrorCode ReadWords(std::ifstream &AnalysisText, int &col, CString& strWordString);
	CString m_strTmp;
	LexicalToken m_TmpToken;
	LexicalErrorCode m_lecErrorCode;
	int m_Row;
	int m_Col;
};

}
