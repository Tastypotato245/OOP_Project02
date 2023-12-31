#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <queue>

#include "inf_int.h"

using namespace std;

enum Operator {
	LPAREN,	//(
	RPAREN,	//)
	ADD,		//+
	SUB,		//-
	MULT,		//* (input must be "\*")
	DIV,		//(Not gonna work, theres no any implementation on DIV)
	EOS,		//$ (End of String)
	CONST,
};

class Calculator {
	public:
	static void calculate(deque<string>& expression);

	private:
	const static int in_stack_precedence[];
	const static int incoming_precedence[];

	static deque<string> infix_to_postfix(deque<string>& expression);
	static Operator get_operator(const string& str);
};

#endif
