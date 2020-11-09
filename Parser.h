#pragma once
#pragma warning( disable : 4091)
#ifdef AUTOMASECS_EXPORTS
#define AUTOMASECS_API __declspec(dllexport)
#else
#define AUTOMASECS_API __declspec(dllimport)
#endif
#include "LexicalAnalysis.h"
#include "KeyWord.h"
#include "SymbolTerminalPair.h"
#include <stack>
#include <fstream>

namespace AutoLib
{
template <typename T>
class reverse_range final {
private:
	T &x;

public:
	explicit reverse_range(T &x) : x(x) {}
	auto begin() const -> decltype(this->x.rbegin()) { return x.rbegin(); }
	auto end() const -> decltype(this->x.rend()) { return x.rend(); }
};

template <typename T>
reverse_range<T> reverse_iterate(T &x) {
	return reverse_range<T>(x);
}

AUTOMASECS_API class Parser
{
public:
	AUTOMASECS_API Parser(MBase *pParent, MLexicalAnalysis* pLA);
	~Parser();
	AUTOMASECS_API virtual void DoAction(KeyWord* pAction) {};
	AUTOMASECS_API virtual void DoMatch(MLexicalAnalysis::LexicalToken* pMatch) {};
	AUTOMASECS_API virtual int parser(std::ifstream &ParserFile);
	AUTOMASECS_API virtual KeyWord* addNonterminals(KeyWord* nonterm);
	AUTOMASECS_API virtual void addToParseTable(KeyWord* nonterm,
			const std::vector<KeyWord*>& terminals,
		const std::vector<KeyWord*>& expand_rule);
protected:
	MBase *m_pParent;
	std::vector<KeyWord*> m_Nonterminals;
	MLexicalAnalysis* m_pLA;
	std::stack<KeyWord*> m_ParseStack;  /// parse stack
	std::map<SymbolTerminalPair*, std::vector<KeyWord*>> m_ParseTable;
};

}
