#include <iostream>
using namespace::std;
int main()
{
	//for beginner to implement a simple calculator.
	int a = 0, b = 0;
	char c;
	cout << "please enter number A:";
	cin >> a;
	cout << endl;
	cout << "please enter operator(+,-,*,/):";
	cin >> c;
	cout << endl;
	cout << "please enter number B:";
	cin >> b;
	cout << endl;
	//cout << a << " " << c << " " << b << endl;
	cout << "result: ";
	switch (c)
	{
	case '+':
		cout << a + b << endl;
		break;
	case '-':
		cout << a - b << endl;
		break;
	case '*':
		cout << a * b << endl;
		break;
	case '/':
		cout << a / b << endl;
		break;
	}
	

	return system("pause");
}