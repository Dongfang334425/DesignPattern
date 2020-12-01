#include <iostream>
using namespace::std;
class Stock1
{
public:
	void Sell() { cout << "Stock1 Sell" << endl; }
	void Buy() { cout << "Stock1 Buy" << endl; }
};
class Stock2
{
public:
	void Sell() { cout << "Stock2 Sell" << endl; }
	void Buy() { cout << "Stock2 Buy" << endl; }
};
class Stock3
{
public:
	void Sell() { cout << "Stock3 Sell" << endl; }
	void Buy() { cout << "Stock3 Buy" << endl; }
};

class NationalDebt1
{
public:
	void Sell() { cout << "NationalDebt1 Sell" << endl; }
	void Buy() { cout << "NationalDebt1 Buy" << endl; }
};

class Realty1
{
public:
	void Sell() { cout << "Realty1 Sell" << endl; }
	void Buy() { cout << "Realty1 Buy" << endl; }
};

class Fund
{
private:
	Stock1* gu1;
	Stock2* gu2;
	Stock3* gu3;
	NationalDebt1* nd1;
	Realty1* rt1;
public:
	Fund()
	{
		gu1 = new Stock1();
		gu2 = new Stock2();
		gu3 = new Stock3();
		nd1 = new NationalDebt1();
		rt1 = new Realty1();
	}
	void Buy()
	{
		gu1->Buy();
		gu2->Buy();
		gu3->Buy();
		nd1->Buy();
		rt1->Buy();
	}
	void Sell()
	{
		gu1->Sell();
		gu2->Sell();
		gu3->Sell();
		nd1->Sell();
		rt1->Sell();
	}
	~Fund()
	{
		delete gu1;
		delete gu2;
		delete gu3;
		delete nd1;
		delete rt1;

		gu1 = NULL;
		gu2 = NULL;
		gu3 = NULL;
		nd1 = NULL;
		rt1 = NULL;
	}
};
int main()
{
	{
	Fund* jijin = new Fund();
	jijin->Buy();
	jijin->Sell();
	}

	return system("pause");
}