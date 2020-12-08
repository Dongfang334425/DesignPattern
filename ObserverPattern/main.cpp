#include <iostream>
#include <list>
#include <string>

using namespace::std;

class Observer;
class Secretary
{
private:
	list<Observer *> m_observers;
	string  m_action;
public:

	Secretary()
	{
		m_observers.resize(0);
		m_action = "";
	}

	void Attach(Observer *observer)
	{
		m_observers.push_back(observer);
	}

	void Notify();

	string getSecretaryAction()
	{
		return m_action;
	}

	void setSecretaryAction(string action)
	{
		m_action = action;
	}
};

class Observer
{
protected:
	string m_name;
	Secretary *m_sub;
public:
	Observer(string name, Secretary *sub):m_name(name),m_sub(sub){}
	virtual void Update() = 0;
};

class StockObserver :public Observer
{
public:
	StockObserver(string name, Secretary* sub):Observer(name,sub){}
	void Update() override
	{
		cout << m_sub->getSecretaryAction() << " " << m_name << " Close Stock market, go to work!" << endl;
	}
};

class NBAObserver :public Observer
{
public:
	NBAObserver(string name, Secretary* sub):Observer(name,sub){}
	void Update() override
	{
		cout << m_sub->getSecretaryAction() << " " << m_name << " Close NBA live, go to work!" << endl;
	}
};

void Secretary::Notify()
{
	for (auto it = m_observers.begin(); it != m_observers.end(); it++)
	{
		(*it)->Update();
	}
}

int main()
{
	Secretary* tongzhizhe = new Secretary();
	StockObserver* tongshi1 = new StockObserver("WeiGuanCha", tongzhizhe);
	NBAObserver* tongshi2 = new NBAObserver("YiGuanCha", tongzhizhe);
	
	tongzhizhe->Attach(tongshi1);
	tongzhizhe->Attach(tongshi2);

	tongzhizhe->setSecretaryAction("Laoban comes back!");

	tongzhizhe->Notify();



	return system("pause");
}