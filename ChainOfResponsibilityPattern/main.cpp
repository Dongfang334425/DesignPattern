#include <iostream>
#include <vector>
using namespace::std;

class Handler
{
protected:
	Handler* successor;
public:
	Handler():successor(NULL){}
	void SetSuccessor(Handler* _successor)
	{
		successor = _successor;
	}
	virtual void HandleRequest(int request) = 0;
};

class ConcreteHandler1 :public Handler
{
public:
	ConcreteHandler1():Handler(){}
	void HandleRequest(int request)
	{
		if (request >= 0 && request < 10)
		{
			cout << "Handler1 can handle " << request << endl;
		}
		else if (successor != NULL)
		{
			successor->HandleRequest(request);
		}
	}
};

class ConcreteHandler2 :public Handler
{
public:
	ConcreteHandler2() :Handler() {}
	void HandleRequest(int request)
	{
		if (request >= 10 && request < 20)
		{
			cout << "Handler2 can handle " << request<< endl;
		}
		else if (successor != NULL)
		{
			successor->HandleRequest(request);
		}
	}
};


class ConcreteHandler3 :public Handler
{
public:
	ConcreteHandler3() :Handler() {}
	void HandleRequest(int request)
	{
		if (request >= 20 && request < 30)
		{
			cout << "Handler3 can handle " << request << endl;
		}
		else
		{
			cout << "No Handler can handle it" << endl;
		}
	}
};

int main()
{
	Handler* h1 = new ConcreteHandler1();
	Handler* h2 = new ConcreteHandler2();
	Handler* h3 = new ConcreteHandler3();

	h1->SetSuccessor(h2);
	h2->SetSuccessor(h3);

	vector<int> requests = { 2,5,14,22,18,3,27,50 };
	for (auto r : requests)
	{
		h1->HandleRequest(r);
	}
	delete h1;
	delete h2;
	delete h3;

	return system("pause");
}