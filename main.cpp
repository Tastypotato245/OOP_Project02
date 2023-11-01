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

		inf_int result = Calculator::calculate(expression);
		cout << "Output: " << result << '\n';
	}
}

void	argv_process(int argc, char **argv)
{
		deque<string> expression;

		for (int i = 1; i < argc; i++) {
			string word(argv[i]);
			expression.push_back(word);
		}
		inf_int result = Calculator::calculate(expression);
		cout << result << '\n';
}

int main(int argc, char **argv)
{
	if (argc == 1)
		read_process();
	argv_process(argc, argv);
}
