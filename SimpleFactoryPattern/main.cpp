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

class OperationFactory
{
public:
	static COperation* createOperation(char operatorC)
	{
		COperation* oper = NULL;
		switch (operatorC)
		{
		case '+':
			oper = new COperationAdd();
			break;
		case '-':
			oper = new COperationSub();
			break;
		case '*':
			oper = new COperationMul();
			break;
		case '/':
			oper = new COperationDiv();
			break;
		}
		return oper;
	}
};

int main()
{
	//split calculation process and display process.
	//inherit Operation class and split different calculation classes.
	//implement Simple Factory Pattern.
	/*brief definition of Simple Factory Pattern:
	In simple Factory Pattern, we have a factory class which has a method
	that returns different types of object based on given input.
	*/
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

	COperation *oper= OperationFactory::createOperation(c);
	cout << oper->GetResult(a, b, c) << endl;
	delete oper;
	oper = NULL;

	return system("pause");
}