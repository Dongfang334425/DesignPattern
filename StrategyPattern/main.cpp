#include <iostream>
#include <string>

using namespace::std;
class CashSuper
{
public:
	virtual double acceptCash(double money) = 0;
};

class CashNormal:public CashSuper
{
public:
	double acceptCash(double money) override
	{
		return money;
	}
};

class CashRebate :public CashSuper
{
private:
	double moneyRebate;
	
public:
	CashRebate(double moneyRebate) :moneyRebate(moneyRebate) {}
	double acceptCash(double money) override
	{
		return money*moneyRebate;
	}
};

class CashReturn :public CashSuper
{
private:
	double moneyCondition;
	double moneyReturn;
public:
	CashReturn(double moneyCondition, double moneyReturn):
		moneyCondition(moneyCondition),moneyReturn(moneyReturn){}
	double acceptCash(double money) override
	{
		return (money>moneyCondition)?(money-moneyReturn):money;
	}
};

//class CashFactory
//{
//public:
//	static CashSuper* createCashAccept(int type)
//	{
//		CashSuper* cs = NULL;
//		switch (type)
//		{
//		case 0://normal
//			cs = new CashNormal();
//			break;
//		case 1://debate
//			cs = new CashRebate(0.8);
//			break;
//		case 2://return
//			cs = new CashReturn(100.0f, 30.0f);
//		}
//		return cs;
//	}
//};

/*combine Strategy pattern and simple factory, the CashFactory
will be obsolete.
Using CashContext to create csuper will avoid the exposure of acceptCash 
member function to the user to realize the complete isolation of operation and
 display
*/
class CashContext
{
private:
	CashSuper* csuper;
public:
	CashContext(int type) 
	{ 
		csuper = NULL;
		switch (type)
		{
		case 0://normal
			csuper = new CashNormal();
			break;
		case 1://debate
			csuper = new CashRebate(0.8);
			break;
		case 2://return
			csuper = new CashReturn(100.0f, 30.0f);
			break;
		}
	}
	double GetResult(double money)
	{
		return csuper->acceptCash(money);
	}

};
int main()
{
	cout << "strategy pattern" << endl;
	/*CashSuper* csuper = CashFactory::createCashAccept(1);
	cout << csuper->acceptCash(100) << endl;*/
	CashContext ccontext(1);
	cout << ccontext.GetResult(100) << endl;

	return system("pause");
}