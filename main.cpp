#include "inf_int.h"

using namespace std;

int main(int argc, char **argv)
{
	inf_int a, e;
	inf_int b(100);
	inf_int c("123");
	inf_int d("12345");
	inf_int f = d;
	inf_int g(f);

	cout << "a : " << a << "\n";
	cout << "b : " << b << "\n";
	cout << "c : " << c << "\n";
	cout << "d : " << d << "\n";
	cout << "e : " << e << "\n";

	cout << "b : " << b << "\n";
	cout << "c : " << c << "\n";
	cout << "=========================" << "\n";
	cout << "b * c : " <<  b * c << "\n";
	a = b * c;
	cout << "a : " << a << "\n";
	a = a * c;
	cout << "a : " << a << "\n";
	a = a * c;
	cout << "a : " << a << "\n";
	cout << "=========================" << "\n";
	cout << "+++++++++++++++++++++++++" << "\n";
	a = b + c;
	cout << "a : " << a << "\n";
	b = c - d;

	if (f == d) {
		cout << "a : " << a << "\n";
		cout << "b : " << b << "\n";
		cout << "c : " << c << "\n";
		cout << "d : " << d << "\n";
		cout << "f : " << f << "\n";
	}
	return (0);
}
