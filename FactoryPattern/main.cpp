#include <iostream>
using namespace::std;

class LeiFeng
{
public:
	void Sweep()
	{
		cout << "Sweep" << endl;
	}
	void Wash()
	{
		cout << "Wash" << endl;
	}
	void BuyRice()
	{
		cout << "BuyRice" << endl;
	}
};
class Undergraduate :public LeiFeng
{

};
class Volunteer :public LeiFeng
{

};

class SimpleFactory
{
public:
	static LeiFeng* CreateLeiFeng(int type) // must be static because of the pointer return type.
	{
		LeiFeng* result = NULL;
		switch (type)
		{
		case 0:
			result = new Undergraduate();
			break;
		case 1:
			result = new Volunteer();
			break;
		}
		return result;
	}
};
int main()
{
	LeiFeng* studentA = SimpleFactory::CreateLeiFeng(0);
	LeiFeng* studentB = SimpleFactory::CreateLeiFeng(0);
	LeiFeng* studentC = SimpleFactory::CreateLeiFeng(0);

	studentA->BuyRice();
	studentB->Sweep();
	studentC->Wash();
	delete studentA;
	delete studentB;
	delete studentC;
	studentA = NULL;
	studentB = NULL;
	studentC = NULL;

	return system("pause");
}