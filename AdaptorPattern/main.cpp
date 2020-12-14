#include <iostream>
using namespace::std;

class Target
{
public:
	virtual void Request()
	{
		cout << "Normal Request" << endl;
	}
};

class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "Specific Request" << endl;
	}
};

class Adaptor :public Target
{
private:
	Adaptee* adaptee;
public:
	Adaptor() { adaptee = new Adaptee(); }
	void Request() override
	{
		adaptee->SpecificRequest();
	}
};
int main()
{
	Target* target = new Adaptor();
	target->Request();
	delete target;

	return system("pause");
}