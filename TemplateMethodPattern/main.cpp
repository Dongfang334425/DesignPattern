#include <iostream>
#include <string>

using namespace::std;

class TestPaper
{
public:
	void TestQ1()
	{
		cout << "TestQ1" << endl;
		cout << "Answer: " << Answer1() << endl;
	}
	void TestQ2()
	{
		cout << "TestQ2" << endl;
		cout << "Answer: " << Answer2() << endl;
	}
	void TestQ3()
	{
		cout << "TestQ3" << endl;
		cout << "Answer: " << Answer3() << endl;
	}
protected:
	virtual string Answer1()
	{
		return "";
	}
	virtual string Answer2()
	{
		return "";
	}
	virtual string Answer3()
	{
		return "";
	}
};
class TestPaperA :public TestPaper
{
	string Answer1() override
	{
		return "b";
	}
	string Answer2() override
	{
		return "c";
	}
	string Answer3() override
	{
		return "a";
	}
};
class TestPaperB :public TestPaper
{
	string Answer1() override
	{
		return "c";
	}
	string Answer2() override
	{
		return "a";
	}
	string Answer3() override
	{
		return "a";
	}
};
int main()
{
	//Template Method Pattern:
	//define the whole structure of the algorithm, but could defer some steps to the child classes.
	//--->Abstract all same steps.
	TestPaper* studentA = new TestPaperA();
	studentA->TestQ1();
	studentA->TestQ2();
	studentA->TestQ3();

	TestPaper* studentB = new TestPaperB();
	studentB->TestQ1();
	studentB->TestQ2();
	studentB->TestQ3();

	return system("pause");
}