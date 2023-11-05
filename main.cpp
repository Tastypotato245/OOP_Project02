#include <sstream>
#include <queue>

#include "inf_int.h"
#include "calculator.h"

using namespace std;

void	read_process()
{
	while (1)
	{
		string str;
		cout << "Input: ";
		getline(cin, str);

		deque<string> expression;
		stringstream ss(str);  
		string word;
		while (ss >> word) {
			expression.push_back(word);
		}
		if (expression.size() == 1 && expression[0].compare("0") == 0)
			return;

		Calculator::calculate(expression);
	}
}

void	argv_process(int argc, char **argv)
{
		deque<string> expression;

		for (int i = 1; i < argc; i++) {
			string word(argv[i]);
			expression.push_back(word);
		}
		Calculator::calculate(expression);
}

int main(int argc, char **argv)
{
	// If an input is empty
	if (argc == 1)
		read_process();
	else
		argv_process(argc, argv);
	return 0;
}
