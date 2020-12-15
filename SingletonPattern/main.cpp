#include <iostream>
using namespace::std;

class Singleton
{
private:
	static Singleton* instance;
	Singleton() {};
public:
	static Singleton* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Singleton();
		}
		return instance;
	}
};
Singleton* Singleton::instance = NULL;

int main()
{
	Singleton* s1 = Singleton::GetInstance();
	Singleton* s2 = Singleton::GetInstance();

	if (s1 == s2)
	{
		cout << "The same instance." << endl;
	}
	return system("pause");
}