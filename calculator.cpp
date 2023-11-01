#include <stack>

#include "calculator"

//                                             (  )  +  -  *  /  $
const int Calculator::in_stack_precedence[] = {0, 3, 1, 1, 2, 2, 0};
const int Calculator::incoming_precedence[] = {4, 3, 1, 1, 2, 2, 0};

bool Calculator::calculator(vector<string> expression) {
	stack<inf_int> s;

}
