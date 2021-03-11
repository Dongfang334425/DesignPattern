#include <iostream>
#include <vector>

using namespace::std;

enum PRODUCTTYPE
{
	SFJ,
	XSL,
	NAS
};

class soapBase
{
public:
	virtual ~soapBase()
	{}

	virtual void show() = 0;
};

class SFJSoap :public soapBase
{
public:
	void show() { cout << "SFJ Soap!" << endl; }
	~SFJSoap()
	{
		cout << "~SFJSoap" << endl;
	}
};

class XSLSoap :public soapBase
{
public:
	void show() { cout << "XSL Soap!" << endl; }
};

class NASSoap :public soapBase
{
public:
	void show() { cout << "NAS Soap!" << endl; }
};

//一个工厂生产一种产品。提供工厂抽象接口
//简单工厂是一个工厂生产多种产品。通过switch 决定生产某种产品。
class Factory
{
public:
	virtual soapBase * createSoap() = 0;
};

class SFJFactory:public Factory
{
public:
	soapBase* createSoap()
	{
		return new SFJSoap();
	}
};

class XSLFactory :public Factory
{
public:
	soapBase* createSoap()
	{
		return new XSLSoap();
	}
};

class NASFactory :public Factory
{
public:
	soapBase* createSoap()
	{
		return new NASSoap();
	}
};

int main()
{
	SFJFactory factory1;
	soapBase* pSoap1 = factory1.createSoap();
	pSoap1->show();

	XSLFactory factory2;
	soapBase* pSoap2 = factory2.createSoap();
	pSoap2->show();

	NASFactory factory3;
	soapBase* pSoap3 = factory3.createSoap();
	pSoap3->show();

	delete pSoap1;
	delete pSoap2;
	delete pSoap3;


	return system("pause");
}
