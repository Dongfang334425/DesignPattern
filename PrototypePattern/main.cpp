#include <iostream>
#include <string>

using namespace::std;
class ICloneable
{
public:
	virtual ICloneable* Clone() = 0;
};

class Resume:public ICloneable
{
public:
	string name;
	string sex;
	string age;
	string timeArea;
	string company;
public:
	Resume(string _name):name(_name){}
	void setPersonalInfo(string _sex, string _age) 
	{
		sex = _sex;
		age = _age;
	}
	void setWorkExperience(string _timeArea, string _company)
	{
		timeArea = _timeArea;
		company = _company;
	}
	void Display()
	{
		cout << name << " " << sex << " " << age << endl;
		cout << "Work Experience: " << timeArea << " " << company << endl;
	}

	Resume* Clone()
	{
		Resume* res = NULL;
		res = new Resume(name);
		res->setPersonalInfo(sex, age);
		res->setWorkExperience(timeArea, company);
		return res;
	}

};

int main()
{
	//I could not see the advantage of prototype Pattern compared with copy-assignment constructor.
	Resume* a = new Resume("Daliao");
	a->setPersonalInfo("Male", "29");
	a->setWorkExperience("1998-2000", "XX Company");

	Resume* b =(Resume*) a->Clone();
	b->setWorkExperience("1998-2006", "XX Enterprise");

	Resume* c = (Resume*)a->Clone();
	c->setPersonalInfo("Male", "26");

	a->Display();
	b->Display();
	c->Display();

	delete a;
	delete b;
	delete c;
	a = NULL;
	b = NULL;
	c = NULL;

	return system("pause");
}