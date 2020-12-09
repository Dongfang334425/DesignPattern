#include <iostream>
using namespace::std;

class KeyBoard
{
public:
	virtual void show() = 0;
};
class KeyBoardMicro :public KeyBoard
{
public:
	void show()
	{
		cout << "Micro's keyboard" << endl;
	}
};

class KeyBoardLenovo :public KeyBoard
{
public:
	void show()
	{
		cout << "Lenovo's keyboard" << endl;
	}
};

class Mouse
{
public:
	virtual void show() = 0;
};
class MouseMicro :public Mouse
{
public:
	void show()
	{
		cout << "Micro's Mouse" << endl;
	}
};

class MouseLenovo :public Mouse
{
public:
	void show()
	{
		cout << "Lenovo's Mouse" << endl;
	}
};

class Factory
{
public:
	virtual KeyBoard* createKeyBoard() = 0;
	virtual Mouse* createMouse() = 0;
};

class FactoryMicro : public Factory
{
public:
	KeyBoard* createKeyBoard()
	{
		return new KeyBoardMicro();
	}
	Mouse* createMouse()
	{
		return new MouseMicro();
	}
};

class FactoryLenovo : public Factory
{
public:
	KeyBoard* createKeyBoard()
	{
		return new KeyBoardLenovo();
	}
	Mouse* createMouse()
	{
		return new MouseLenovo();
	}
};
int main()
{
	Factory* p = new FactoryMicro();
	KeyBoard* pKeyBoard = p->createKeyBoard();
	Mouse* pMouse = p->createMouse();

	pKeyBoard->show();
	pMouse->show();
	delete pMouse;
	delete pKeyBoard;
	delete p;

	return system("pause");
}