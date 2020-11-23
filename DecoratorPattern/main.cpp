#include <iostream>

using namespace::std;

class Person
{
private:
	string name;
public:
	Person():name(""){}
	Person(string name):name(name){}
	virtual void Show()
	{
		cout << "Decorator: " << name << endl;
	}
};

class Finery :public Person
{
protected:
	Person* component;
public:
	Finery():component(NULL){}
	void Decorate(Person* mComponent)
	{
		component = mComponent;
	}

	void Show() override
	{
		if (component != NULL)
		{
			component->Show();
		}
	}
};

class TShirts :public Finery
{
public:
	void Show() override
	{
		cout << "T Shirt" << " ";
		Finery::Show();
	}
};

class Sneakers :public Finery
{
public:
	
	void Show() override
	{
		cout << "Sneakers" << " ";
		Finery::Show();
	}
};

class BigTrousers :public Finery
{
public:
	void Show() override
	{
		cout << "BigTrousers"<<" ";
		Finery::Show();
	}
};

class Parent
{
public:
	int m_val;
	Parent() :m_val(3) {}
};
class Child :public Parent
{
public:
	int m_c;
	Child():m_c(2){}
};

int main()
{
	Person* xc = new Person("XiaoCai");
	cout << "First Decorator:" << endl;

	Sneakers* pqx = new Sneakers();
	BigTrousers* kk = new BigTrousers();
	TShirts* dtx = new TShirts();

	pqx->Decorate(xc);//Sneakers
	kk->Decorate(pqx);//BigTrousers
	dtx->Decorate(kk);//TShirts
	dtx->Show();//reverse order

	//output: T Shirt BigTrousers Sneakers Decorator: XiaoCai

	Parent* p = new Parent();
	Child* c = new Child();
	cout << c->m_val << " "<<c->m_c<<endl;

	return system("pause");
}