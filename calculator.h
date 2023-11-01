#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <vector>

#include "inf_int.h"

class Calculator {
	public:
	static bool calculate(vector<string> expression);

	private:
	const static int in_stack_precedence[];
	const static int incoming_precedence[];
}

#endif
