#include "inf_int.h"

using namespace std;

int	op_switching(inf_int a, char op, inf_int b)
{
	if (op == '+')
		cout << "Output: " << a + b << "\n";
	else if (op == '-')
		cout << "Output: " << a - b << "\n";
	else if (op == '*')
		cout << "Output: " << a * b << "\n";
	else
		return (-1);
	return (0);
}

int	read_process()
{
	while (1)
	{
		string	num_1;
		char	op;
		string	num_2;
		cout << "Input: ";
		cin >> num_1;
		cin >> op;
		cin >> num_2;
		inf_int a(num_1.c_str());
		inf_int b(num_2.c_str());
		if (op_switching(a, op, b) == -1)
			return (-1);
	}
}

int	argv_process(char **argv)
{
	inf_int a(argv[1]);
	char	op = argv[2][0];
	inf_int b(argv[3]);

	if (strlen(argv[2]) != 1)
		return (-1);
	return (op_switching(a, op, b));
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (read_process());
	else if (argc == 4)
		return (argv_process(argv));
	else if (argc == 2 && argv[1][0] == 0)
		return (0);
	return (-1);
}
