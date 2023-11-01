#include <stack>

#include "calculator.h"

//                                             (  )  +  -  *  /  $
const int Calculator::in_stack_precedence[] = {0, 3, 1, 1, 2, 2, 0};
const int Calculator::incoming_precedence[] = {4, 3, 1, 1, 2, 2, 0};

inf_int Calculator::calculate(deque<string> expression) {
	deque<string> postfix = infix_to_postfix(expression);
	stack<inf_int> s;

	inf_int x, y;

	while (postfix.size() != 0) {
		switch (get_operator(postfix.front())) {
			case CONST:
				s.push(inf_int(postfix.front().c_str()));
				postfix.pop_front();
				break;
			case ADD:
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(x + y);
				postfix.pop_front();
				break;
			case SUB:
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(x - y);
				postfix.pop_front();
				break;
			case MULT:
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				s.push(x * y);
				postfix.pop_front();
				break;
//			case DIV:
//				x = s.top();
//				s.pop();
//				y = s.top();
//				s.pop();
//				s.push(x / y);
//				break;
			default:
				cout << "unexpected situation\n";
				break;
		}
	}


	return s.top();
}

deque<string> Calculator::infix_to_postfix(deque<string> expression) {
	expression.push_back("$");
	stack<string> s;
	s.push("$");

	deque<string> postfix;
	while (get_operator(expression.front()) != EOS) {
		if (get_operator(expression.front()) == CONST) {
			postfix.push_back(expression.front());
			expression.pop_front();
		} else if (get_operator(expression.front()) == RPAREN) {
			expression.pop_front();
			while (get_operator(s.top()) != LPAREN) {
				postfix.push_back(s.top());
				s.pop();
			}
			s.pop();
		} else if (in_stack_precedence[get_operator(s.top())]
				<= incoming_precedence[get_operator(expression.front())]) {
			s.push(expression.front());
			expression.pop_front();
		} else {
			postfix.push_back(s.top());
			s.pop();
		}
	}
	while (get_operator(s.top()) != EOS) {
		postfix.push_back(s.top());
		s.pop();
	}

	return postfix;
}

Operator Calculator::get_operator(string str) {
	if (str.compare("(") == 0) {
		return LPAREN;
	}
	if (str.compare(")") == 0) {
		return RPAREN;
	}
	if (str.compare("+") == 0) {
		return ADD;
	}
	if (str.compare("-") == 0) {
		return SUB;
	}
	if (str.compare("*") == 0) {
		return MULT;
	}
	if (str.compare("/") == 0) {
		return DIV;
	}
	if (str.compare("$") == 0) {
		return EOS;
	}
	return CONST;
}
