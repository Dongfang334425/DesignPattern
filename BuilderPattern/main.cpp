#include <iostream>
using namespace::std;
class PersonBuilder
{
public:
	virtual void  BuildHead()=0;
	virtual void  BuildBody() = 0;
	virtual void  BuildArmLeft() = 0;
	virtual void  BuildArmRight() = 0;
	virtual void  BuildLegLeft() = 0;
	virtual void  BuildLegRight() = 0;
};

class PersonThinBuilder :public PersonBuilder
{
public:
	void BuildHead() override{cout << "BuildHead" << endl;}
	void BuildBody() override{cout << "Build Thin Body" << endl;}
	void BuildArmLeft() override{cout << "Build Arm Left" << endl;}
	void BuildArmRight() override{cout << "Build Arm Right" << endl;}
	void BuildLegLeft() override{cout << "Build Leg Left" << endl;}
	void BuildLegRight() override{cout << "Build Leg Right" << endl;}
};
class PersonThickBuilder :public PersonBuilder
{
public:
	void BuildHead() override { cout << "BuildHead" << endl; }
	void BuildBody() override { cout << "Build Thick Body" << endl; }
	void BuildArmLeft() override { cout << "Build Arm Left" << endl; }
	void BuildArmRight() override { cout << "Build Arm Right" << endl; }
	void BuildLegLeft() override { cout << "Build Leg Left" << endl; }
	void BuildLegRight() override { cout << "Build Leg Right" << endl; }
};

class PersonDirector
{
private:
	PersonBuilder* m_pb;
public:
	PersonDirector(PersonBuilder* pb)
	{
		m_pb = pb;
	}
	void CreatePerson()
	{
		m_pb->BuildHead();
		m_pb->BuildBody();
		m_pb->BuildArmLeft();
		m_pb->BuildArmRight();
		m_pb->BuildLegLeft();
		m_pb->BuildLegRight();
	}
};

int main()
{
	PersonThinBuilder* ptb = new PersonThinBuilder();//PersonBuilder* ptb = new PersonThinBuilder() works too.
	PersonDirector* pd = new PersonDirector(ptb);
	pd->CreatePerson();
	delete ptb;
	delete pd;
	ptb = NULL;
	pd = NULL;

	return system("pause");
}