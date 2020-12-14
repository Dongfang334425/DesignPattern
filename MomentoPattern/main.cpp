#include <iostream>
#include <string>

using namespace::std;

class Memento;
class Originator
{
private:
	string state;//attribute needs to be stored.
public:
	void setState(string value)
	{
		state = value;
	}
	string getState()
	{
		return state;
	}

	Memento* CreateMemento();

	void SetMemento(Memento* memento);

	void Show()
	{
		cout << "State= " << state << endl;
	}
};

class Memento
{
private:
	string state;
public:
	Memento(string _state)
	{
		state = _state;
	}
	string getState()
	{
		return state;
	}
};

Memento* Originator::CreateMemento()
{
	return new Memento(state);
}

void Originator::SetMemento(Memento* memento)
{
	state = memento->getState();
}

class Caretaker
{
private:
	Memento* memento;
public:
	Caretaker() { memento = new Memento(""); }
	Memento *getMemento()
	{
		return memento;
	}

	void setMemento(Memento* _memento)
	{
		memento = _memento;
	}
};

int main()
{
	Originator* o = new Originator();
	o->setState("On");
	o->Show();

	Caretaker* c = new Caretaker();
	c->setMemento(o->CreateMemento());

	o->setState("Off");
	o->Show();

	o->SetMemento(c->getMemento());
	o->Show();


	return system("pause");
}