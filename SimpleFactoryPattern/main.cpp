#include <iostream>


using namespace::std;

class COperation
{
public:
	virtual double GetResult(double numberA, double numberB, char operatorC) = 0;
};

class COperationAdd:public COperation
{
public:
	double GetResult(double numberA, double numberB, char operatorC) override
	{
		
		double res = 0.0f;
		res = numberA + numberB;
		return res;
	}
	
};

class COperationSub :public COperation
{
public:
	double GetResult(double numberA, double numberB, char operatorC) override
	{

		double res = 0.0f;
		res = numberA - numberB;
		return res;
	}
};

class COperationMul :public COperation
{
public:
	double GetResult(double numberA, double numberB, char operatorC) override
	{

		double res = 0.0f;
		res = numberA * numberB;
		return res;
	}
};

class COperationDiv :public COperation
{
public:
	double GetResult(double numberA, double numberB, char operatorC) override
	{

		double res = 0.0f;
		res = numberA / numberB;
		return res;
	}
};

int main()
{
	//split calculation process and display process.
	//inherit Operation class and split different calculation classes.
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
	COperationAdd myOAdd;
	COperationSub myOSub;
	COperationMul myOMul;
	COperationDiv myODiv;

	COperationAdd* pmyOAdd = new COperationAdd(2);
	switch (c)
	{
	case '+':
		/*cout << pmyOAdd->GetResult(a, b, c) << endl;
		*/
		cout << myOAdd.GetResult(a,b,c) << endl;
		break;
	case '-':
		cout << myOSub.GetResult(a, b, c) << endl;
		break;
	case '*':
		cout << myOMul.GetResult(a, b, c) << endl;
		break;
	case '/':
		cout << myODiv.GetResult(a, b, c) << endl;
		break;
	}
	

	return system("pause");
}