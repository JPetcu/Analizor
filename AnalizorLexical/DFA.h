#pragma once




#include <vector>
#include <set>
#include <map>

using namespace std;


class DFA
{
public:
	explicit DFA(int initial, bool isfinal);
	~DFA(void);
	void add_state(int s, bool isfinal);
	void add_transition(int src, char input, int dest);
	bool is_accepting();
	void reset();
	int input(char inp);
	int state();
	void add_transition(int src, std::vector<char> xVector, int dest);
	void add_transition(int src, std::vector<string> keyWords, int dest);

private:
	int m_initial;
	int m_state;
	set<int> m_states;
	set<int> m_final_states;
	map<pair<int, char>, int> m_transitions;
	map<pair<int, string>, int> m_transitionsS;
};