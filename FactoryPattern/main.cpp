#include <iostream>
using namespace::std;

class LeiFeng
{
public:
	void Sweep()
	{
		cout << "Sweep" << endl;
	}
	void Wash()
	{
		cout << "Wash" << endl;
	}
	void BuyRice()
	{
		cout << "BuyRice" << endl;
	}
};
class Undergraduate :public LeiFeng
{

};
int main()
{
	LeiFeng* xueleifeng = new Undergraduate();
	xueleifeng->BuyRice();
	xueleifeng->Sweep();
	xueleifeng->Wash();
	delete xueleifeng;
	xueleifeng = NULL;
	return system("pause");
}