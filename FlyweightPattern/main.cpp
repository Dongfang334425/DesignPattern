#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace::std;

class Flyweight
{
public:
	virtual void Operation(int extrinsicstate) = 0;
};

class ConcreteFlyweight :public Flyweight
{
public:
	void Operation(int extrinsicstate)
	{
		cout << "Concrete Flyweight: " << extrinsicstate << endl;
	}
};

class UnsharedConcreteFlyweight :public Flyweight
{
public:
	void Operation(int extrinsicstate)
	{
		cout << "Unshared Concrete Flyweight: " << extrinsicstate << endl;
	}
};

class FlyweightFactory
{
private:
	map<char,Flyweight*> *flyweights;
public:
	FlyweightFactory()
	{
		flyweights = new map<char, Flyweight*>();
		flyweights->insert({ 'X',new ConcreteFlyweight() });
		flyweights->insert({ 'Y',new ConcreteFlyweight() });
		flyweights->insert({ 'Z',new ConcreteFlyweight() });
	}
	Flyweight* getFlyweight(char key)
	{
		return (*flyweights)[key];
	}


};
int main()
{
	
	int extrinsicstate = 22;
	FlyweightFactory* f = new FlyweightFactory();

	Flyweight* fx = f->getFlyweight('X');
	fx->Operation(--extrinsicstate);

	Flyweight* fy = f->getFlyweight('Y');
	fx->Operation(--extrinsicstate);

	Flyweight* fz = f->getFlyweight('Z');
	fx->Operation(--extrinsicstate);

	Flyweight* uf = new UnsharedConcreteFlyweight();
	uf->Operation(--extrinsicstate);

	return system("pause");
}