#include <iostream>
#include <string>

using namespace ::std;
class SchoolGirl
{
public:
	string m_name;
public:
	SchoolGirl(string name):m_name(name){}
};

class IGiveGift
{
public:
	virtual void GiveDolls() = 0;
	virtual void GiveFlowers() = 0;
	virtual void GiveChocolate() = 0;
};
class Pursuit :public IGiveGift 
{
private:
	SchoolGirl* mmm;
public:
	Pursuit(SchoolGirl* mm):mmm(mm){}
	void GiveDolls()
	{
		cout << mmm->m_name << " " << "Dolls" << endl;
	}
	void GiveFlowers()
	{
		cout << mmm->m_name << " " << "Flowers" << endl;
	}
	void GiveChocolate()
	{
		cout << mmm->m_name << " " << "Chocolate" << endl;
	}
};

class Proxy :public IGiveGift
{
	Pursuit* gg;//hide pursuit
public:
	Proxy(SchoolGirl* mm)
	{
		gg = new Pursuit(mm);//!!!
	}
	void GiveDolls()//share the same interface with Puisuit. but it communicates with the client.
	{
		gg->GiveDolls();
	}
	void GiveFlowers()
	{
		gg->GiveFlowers();
	}
	void GiveChocolate()
	{
		gg->GiveChocolate();
	}
};
int main()
{
	SchoolGirl* jiaojiao = new SchoolGirl("jiaojiao");

	Proxy* daili = new Proxy(jiaojiao);
	daili->GiveDolls();
	daili->GiveFlowers();
	daili->GiveChocolate();

	return system("pause");

}