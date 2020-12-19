#include <iostream>
#include <string>
#include <list>

using namespace::std;

class Context;

class AbstractExpression
{
public:
	virtual void Interpret(Context* context) = 0;
};

class TerminalExpression :public AbstractExpression
{
public:
	void Interpret(Context* context)
	{
		cout << "Terminal Expression" << endl;
	}
};

class NonterminalExpression :public  AbstractExpression
{
public:
	void Interpret(Context* context)
	{
		cout << "Non Terminal Expression" << endl;
	}
};

class Context
{
private:
	string input;
	string output;
public:
	Context():input(""),output(""){ }
	void setInput(string _input) { input = _input; }
	string getInput() { return input; }
	void setOutput(string _output) { output = _output; }
	string getOutput() { return output; }
};
int main()
{
	Context* context = new Context();
	list<AbstractExpression*>* lt = new list<AbstractExpression*>();
	lt->push_back(new TerminalExpression());
	lt->push_back(new NonterminalExpression());
	lt->push_back(new TerminalExpression());
	lt->push_back(new TerminalExpression());

	for (auto it=lt->begin();it!=lt->end();it++)
	{
		(*it)->Interpret(context);
	}

	return system("pause");
}