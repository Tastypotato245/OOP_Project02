#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <queue>

#include "inf_int.h"

using namespace std;

enum Operator {
	LPAREN,
	RPAREN,
	ADD,
	SUB,
	MULT,
	DIV,
	EOS,
	CONST,
};

class Calculator {
	public:
	static inf_int calculate(deque<string> expression);

	private:
	const static int in_stack_precedence[];
	const static int incoming_precedence[];

	static deque<string> infix_to_postfix(deque<string> expression);
	static Operator get_operator(string str);
};

#endif
