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

class IFactory
{
public:
	virtual LeiFeng* CreateLeiFeng() = 0;
};

class UndergraduateFactory :public IFactory
{
public:
	LeiFeng* CreateLeiFeng()
	{
		return new Undergraduate();
	}
};

class VolunteerFactory :public IFactory
{
public:
	LeiFeng* CreateLeiFeng()
	{
		return new Volunteer();
	}
};
int main()
{
	/*factory vs simple factory
	if we want to change to 3 volunteers, we just need to change 
	IFactory* factory = new UndergraduateFactory(); to
	IFactory* factory = new VolunteerFactory();
	pls ignore the name of studentA, studentB, studentC, pls we could 
	make the name more common, such as personA, personB, personC.
	But if we want to change to 3 volunteers using simple factory,
	we need to change 
	LeiFeng* studentA = SimpleFactory::CreateLeiFeng(0);
	LeiFeng* studentB = SimpleFactory::CreateLeiFeng(0);
	LeiFeng* studentc = SimpleFactory::CreateLeiFeng(0); (see the previous version)
	to
	LeiFeng* studentA = SimpleFactory::CreateLeiFeng(1);
	LeiFeng* studentB = SimpleFactory::CreateLeiFeng(1);
	LeiFeng* studentc = SimpleFactory::CreateLeiFeng(1);
	3 lines need to be changed.
	*/
	IFactory* factory = new UndergraduateFactory();
	LeiFeng* studentA = factory->CreateLeiFeng();
	LeiFeng* studentB = factory->CreateLeiFeng();
	LeiFeng* studentC = factory->CreateLeiFeng();
	studentA->BuyRice();
	studentB->Sweep();
	studentC->Wash();
	delete studentA;
	delete studentB;
	delete studentC;
	studentA = NULL;
	studentB = NULL;
	studentC = NULL;
	delete factory;
	factory = NULL;
	

	return system("pause");
}