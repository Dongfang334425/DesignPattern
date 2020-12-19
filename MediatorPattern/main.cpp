#include <iostream>
#include <string>

using namespace::std;
class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;

class Mediator
{
public:
	virtual void Send(string message, Colleague* colleague) = 0;
};


class ConcreteMediator :public Mediator
{
private:
	ConcreteColleague1* colleague1;
	ConcreteColleague2* colleague2;

public:
	ConcreteMediator() :Mediator()
	{
		colleague1 = NULL;
		colleague2 = NULL;
	}
	void setColleague1(ConcreteColleague1* _colleague1)
	{
		colleague1 = _colleague1;
	}
	void setColleague2(ConcreteColleague2* _colleague2)
	{
		colleague2 = _colleague2;
	}
	void Send(string message, Colleague* colleague) override;
};

class Colleague
{
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* _mediator)
	{
		mediator = _mediator;
	}
};

class ConcreteColleague1 : public Colleague
{
public:
	ConcreteColleague1(Mediator* _mediator):Colleague(_mediator){}
	void Send(string message);
	void Notify(string message)
	{
		cout << "ConcreteColleague1 receives message " << message << endl;
	}
};

class ConcreteColleague2 :public Colleague
{
public:
	ConcreteColleague2(Mediator* _mediator) :Colleague(_mediator) {}
	void Send(string message);
	void Notify(string message)
	{
		cout << "ConcreteColleague2 receives message " << message << endl;
	}
};

void ConcreteMediator::Send(string message, Colleague* colleague)
{
	if (colleague1 == colleague)
	{
		colleague2->Notify(message);
	}
	else
	{
		colleague1->Notify(message);
	}
}

void ConcreteColleague1::Send(string message)
{
	mediator->Send(message, this);
}

void ConcreteColleague2::Send(string message)
{
	mediator->Send(message, this);
}



int main()
{
	ConcreteMediator* m = new ConcreteMediator();
	ConcreteColleague1* c1 = new ConcreteColleague1(m);
	ConcreteColleague2* c2 = new ConcreteColleague2(m);

	m->setColleague1(c1);
	m->setColleague2(c2);

	c1->Send("Did you eaten?");
	c2->Send("Not yet.");
	//cout << "yes" << endl;

	return system("pause");
}