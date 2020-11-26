#include <iostream>
#include <string>

using namespace::std;
class Resume
{
private:
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

};

int main()
{
	Resume* a = new Resume("Daliao");
	a->setPersonalInfo("Male", "29");
	a->setWorkExperience("1998-2000", "XX Company");

	Resume* b = new Resume("Daliao");
	b->setPersonalInfo("Male", "29");
	b->setWorkExperience("1998-2000", "XX Company");

	Resume* c = new Resume("Daliao");
	c->setPersonalInfo("Male", "29");
	c->setWorkExperience("1998-2000", "XX Company");

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