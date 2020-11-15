#include <iostream>


using namespace::std;

class COperation
{
public:
	double GetResult(double numberA, double numberB, char operatorC)
	{
		double res = 0.0f;
		switch (operatorC)
		{
		case '+':
			res = numberA + numberB;
			break;
		case '-':
			res = numberA - numberB;
			break;
		case '*':
			res = numberA * numberB;
			break;
		case '/':
			res = numberA / numberB;
			break;
		}
		return res;
	}
};
int main()
{
	//split calculation process and display process.
	double a = 0.0f, b = 0.0f;
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
	COperation myO;
	cout << "result: " << myO.GetResult(a, b, c) << endl;
	

	return system("pause");
}