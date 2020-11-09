#pragma once
#pragma warning( disable : 4091)

#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "KeyWord.h"

namespace AutoLib
{
AUTOMASECS_API class SymbolTerminalPair
{
public:
	SymbolTerminalPair(KeyWord* pFirst, KeyWord* pSecond);
	AUTOMASECS_API bool operator< (const SymbolTerminalPair &Op);
	AUTOMASECS_API bool operator== (const SymbolTerminalPair &Op);
	friend bool operator<(const SymbolTerminalPair &lhs,
		const SymbolTerminalPair &rhs) {
		return (lhs < rhs);
	}
private:
	KeyWord* m_pFirst, *m_pSecond;

};

}
