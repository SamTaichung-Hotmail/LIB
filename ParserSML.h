#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "Parser.h"
#include "LexicalAnalysisSML.h"

namespace AutoLib
{
AUTOMASECS_API class ExpressSML
{
public:
	AUTOMASECS_API ExpressSML(MLexicalAnalysisSML::KeyWordIndex Function);
	AUTOMASECS_API ~ExpressSML();
	MLexicalAnalysisSML::KeyWordIndex m_Function;
	HSMS_Packet *m_pCondPacket=NULL;
	HSMS_Packet *m_pSendPacket=NULL;
	int m_intDataIndex = -1;
	KeyWord *m_pOperator = NULL;
	DSecsDataItem *m_pLeftData = NULL;
	DSecsDataItem *m_pRightData = NULL;
	CTimeCounter m_ctcEveryTimer;
};
AUTOMASECS_API class ParserSML:public Parser
{
public:
	enum SML_NONTERMINAL {
		STAT,
		STAT_SEQ,
		STAT_SEQ_TAIL,
		STAT_DEF_HSMS,
		STAT_HSMS_ALIAS,
		STAT_HSMS_ALIAS_ITEM,
		STAT_HSMS_WAIT,
		STAT_HSMS_TYPE,
		STAT_HSMS_DATA,
		VALUE_LIST_AMOUNT,
		VALUE_LIST,
		VALUE_ITEM,
		VALUE_ITEM_MINUS,
		STAT_HSMS,
		EXPR,
		EXPR_EQ,
		HSMS_SCAN,
		DATA_INDEX,
		COMPARE_OP,
		FACTOR,
		LVALUE,
		STAT_ASSIGN_TAIL,
	};
	enum SML_ACTION {
		ACTION_NONE,
		ACTION_MAKE_HSMS_BEGIN,
		ACTION_MAKE_HSMS_END,
		ACTION_MAKE_DATA_BEGIN,
		ACTION_MAKE_DATA_END,
		ACTION_MAKE_IF_BEGIN,
		ACTION_MAKE_IF_MID,
		ACTION_MAKE_IF_END,
		ACTION_MAKE_EVERY_BEGIN,
		ACTION_MAKE_EVERY_MID,
		ACTION_MAKE_EVERY_END,
		ACTION_MAKE_MINUS_VALUE_BEGIN,
		ACTION_MAKE_MINUS_VALUE_END,
		ACTION_MAKE_ITEM_AMOUNT_BEGIN,
		ACTION_MAKE_ITEM_AMOUNT_END,
		ACTION_DATA_INDEX_BEGIN,
		ACTION_DATA_INDEX_END,
	};
	enum ExpressPosition {
		epBegin,
		epMid,
		epEnd,
	};
	AUTOMASECS_API ParserSML(MBase *pParent, MLexicalAnalysisSML *pLA);
	~ParserSML();
	AUTOMASECS_API virtual void DoAction(KeyWord* pAction);
	AUTOMASECS_API virtual void DoMatch(MLexicalAnalysis::LexicalToken* pMatch);
	KeyWord* m_pkwSTAT;
	KeyWord* m_pkwSTAT_SEQ;
	KeyWord* m_pkwSTAT_SEQ_TAIL;
	KeyWord* m_pkwSTAT_DEF_HSMS;
	KeyWord* m_pkwSTAT_HSMS;
	KeyWord* m_pkwHSMS_ALIAS;
	KeyWord* m_pkwHSMS_ALIAS_ITEM;
	KeyWord* m_pkwHSMS_SCAN;
	KeyWord* m_pkwDATA_INDEX;
	KeyWord* m_pkwHSMS_WAIT;
	KeyWord* m_pkwHSMS_TYPE;
	KeyWord* m_pkwHSMS_DATA;
	KeyWord* m_pkwVALUE_LIST;
	KeyWord* m_pkwVALUE_LIST_AMOUNT;
	KeyWord* m_pkwVALUE_ITEM;
	KeyWord* m_pkwVALUE_ITEM_MINUS;
	KeyWord* m_pkwEXPR;
	KeyWord* m_pkwEXPR_EQ;
	KeyWord* m_pkwCOMPARE_OP;
	KeyWord* m_pkwFACTOR;
	KeyWord* m_pkwLVALUE;
	KeyWord* m_pkSTAT_ASSIGN_TAIL;
	KeyWord* m_pkwACTION_MAKE_HSMS_BEGIN;
	KeyWord* m_pkwACTION_MAKE_HSMS_END;
	KeyWord* m_pkwACTION_MAKE_DATA_BEGIN;
	KeyWord* m_pkwACTION_MAKE_DATA_END;
	KeyWord* m_pkwACTION_MAKE_IF_BEGIN;
	KeyWord* m_pkwACTION_MAKE_IF_MID;
	KeyWord* m_pkwACTION_MAKE_IF_END;
	KeyWord* m_pkwACTION_MAKE_EVERY_BEGIN;
	KeyWord* m_pkwACTION_MAKE_EVERY_MID;
	KeyWord* m_pkwACTION_MAKE_EVERY_END;
	KeyWord* m_pkwACTION_MINUS_VALUE_BEGIN;
	KeyWord* m_pkwACTION_MINUS_VALUE_END;
	KeyWord* m_pkwACTION_MAKE_ITEM_AMOUNT_BEGIN;
	KeyWord* m_pkwACTION_MAKE_ITEM_AMOUNT_END;
	KeyWord* m_pkwACTION_DATA_INDEX_BEGIN;
	KeyWord* m_pkwACTION_DATA_INDEX_END;
	AUTOMASECS_API int ParseSML(std::ifstream &ParserFile, CArray<HSMS_Packet*>* pPackets, CArray<ExpressSML*>* pExpresses);
protected:
	CArray<HSMS_Packet*>* m_pPackets;
	CArray<ExpressSML*>* m_pExpresses;
private:
	bool bCheckDataAmount;
	int m_intDataAmount;
	HSMS_Packet* m_pMakePacket;
	ExpressSML * m_pMakeExpress;
	DSecsDataItem * m_pMakeData;
	DSecsDataItem * m_pDataParent;
	byte *m_pItemData;
	bool m_bInDataBlock;
	bool m_bMinusValue;
	bool m_bItemAmount;
	bool m_bInFunctionBlock;
	SML_ACTION m_saParse;
};

}
