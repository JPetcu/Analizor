// Analizor Lexical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//#include "C:\Users\Justin\source\repos\Analizor Lexical\Analizor Lexical\DFA.h"
#include "DFA.h"

using namespace std;

void vectors(vector<char> &alpha, vector<char> &alphaNum, vector<string> &keyWords, DFA &dfa)
{
	for (int i = 65; i <= 90; i++)
	{
		char c = (char)i;
		alpha.push_back(c);
	}
	for (int i = 97; i <= 122; i++)
	{
		char c = (char)i;
		alpha.push_back(c);
	}

	for (int i = 65; i <= 90; i++)
	{
		char c = (char)i;
		alphaNum.push_back(c);
	}
	for (int i = 97; i <= 122; i++)
	{
		char c = (char)i;
		alphaNum.push_back(c);
	}
	for (int i = 48; i <= 58; i++)
	{
		char c = (char)i;
		alphaNum.push_back(c);
	}
	

}

void init(DFA &dfa)
{

	dfa.add_state(1, false);
	dfa.add_state(2, true);
	dfa.add_state(3, true);
	dfa.add_state(4, false);
	dfa.add_state(5, false);
	dfa.add_state(6, false);
	dfa.add_state(7, true);
	dfa.add_state(8, false);
	dfa.add_state(9, false);
	dfa.add_state(10, true);
	dfa.add_state(11, true);
	dfa.add_state(12, true);
	dfa.add_state(13, false);
	dfa.add_state(14, false);
	dfa.add_state(15, false);

	vector<char> alpha;
	vector<char> alphaNum;
	vector<string> keyWords = { "alignas", "alignof" , "and", "and_eq", "auto",
"bool", "break", "case", "catch", "char", "class"  ,"const constexpr"  ,"const_cast" ,"continue",
 "default" ,"delete", "do" ,"double", "dynamic_cast", "else" ,"enum", "explicit", "export" ,
"extern", "false" ,"float" ,"for", "friend" ,"goto", "if", "import", "inline", "int", "long", "namespace" ,"new",  "not",
"operator", "private" ,"protected" ,"public" ,"return" ,"short" ,"static", "struct" ,"switch" ,"template" ,"this" ,"throw", "true" ,"try" ,"typedef" ,"unsigned" ,"using",
"virtual" ,"void" ,"while"
	};
	vectors(alpha, alphaNum, keyWords, dfa);

	dfa.add_transition(0, alpha, 1);
	dfa.add_transition(1, alphaNum, 1);
	dfa.add_transition(1, ';', 2);
	dfa.add_transition(1, ' ', 2);
}


int main(int argc, char* argv[])
{
	
	DFA dfa(0, false);
		
	init(dfa);


	dfa.add_transition(1, ';', 2);
	dfa.add_transition(1, ';', 3);
	dfa.add_transition(0, '"', 4);
	dfa.add_transition(4, 'a', 5);
	dfa.add_transition(5, 'a', 6);
	dfa.add_transition(6, 'a', 6);
	dfa.add_transition(6, '"', 7);
	dfa.add_transition(0, '\'', 8);
	dfa.add_transition(8, 'a', 9);
	dfa.add_transition(9, '\'', 10);
	dfa.add_transition(0, 'O', 11);
	dfa.add_transition(11, 'O', 12);
	dfa.add_transition(0, 'a', 1);
	dfa.add_transition(0, 'a', 1);
	dfa.add_transition(0, 'a', 1);



	char inp;
	while (true)
	{
		cout << "State: " << dfa.state() << "  " << dfa.is_accepting() ? "true" : "false";
		cout << endl;
		cin >> inp;
		if (cin.eof()) break;
		dfa.input(inp);
	}

	return 0;
}

