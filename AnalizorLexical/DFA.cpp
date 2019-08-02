#include "stdafx.h"
#include "DFA.h"


DFA::DFA(int initial, bool isfinal)
{
	this->m_initial = this->m_state = initial;
	add_state(initial, isfinal);
	add_state(-1, false); // invalid dead state
}


DFA::~DFA(void)
{
}


void DFA::add_state(int s, bool isfinal)
{
	m_states.insert(s);
	if (isfinal) m_final_states.insert(s);
}


void DFA::add_transition(int src, char input, int dest)
{
	m_transitions.insert(pair<pair<int, char>, int>(pair<int, char>(src, input), dest));
}


void DFA::add_transition(int src, std::vector<char> xVector, int dest)
{
	int i = 0;
	for (i = 0; i<xVector.size(); i++)
		m_transitions.insert(pair<pair<int, char>, int>(pair<int, char>(src, xVector.at(i)), dest));
}
void DFA::add_transition(int src, std::vector<string> xVector, int dest)
{
	for (int i = 0; i<xVector.size(); i++)
		m_transitionsS.insert(pair<pair<int, string>, int>(pair<int, string>(src, xVector[i]), dest));
}


void DFA::reset()
{
	m_state = m_initial;
}

int DFA::input(char inp)
{
	auto tr = make_pair(m_state, inp);
	if (m_transitions.count(tr)>0)
	{
		auto it = m_transitions.find(tr);
		return m_state = it->second;
	}
	else
	{
		return m_state = -1;
	}
}


bool DFA::is_accepting()
{
	return m_final_states.count(m_state) != 0;
}


int DFA::state()
{
	return m_state;
}

