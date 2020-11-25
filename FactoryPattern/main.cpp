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
	LeiFeng* student1 = new Undergraduate();
	student1->BuyRice();
	LeiFeng* student2 = new Undergraduate();
	student2->Sweep();
	LeiFeng* student3 = new Undergraduate();
	student3->Wash();
	delete student1;
	delete student2;
	delete student3;
	student1 = NULL;
	student2 = NULL;
	student3 = NULL;
	return system("pause");
}