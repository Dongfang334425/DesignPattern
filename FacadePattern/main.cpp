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


int main()
{
	Stock1* gu1 = new Stock1();
	Stock2* gu2 = new Stock2();
	Stock3* gu3 = new Stock3();
	NationalDebt1* nd1 = new NationalDebt1();
	Realty1* rt1 = new Realty1();

	gu1->Buy();
	gu2->Buy();
	gu3->Buy();
	nd1->Buy();
	rt1->Buy();

	gu1->Sell();
	gu2->Sell();
	gu3->Sell();
	nd1->Sell();
	rt1->Sell();

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

	return system("pause");
}