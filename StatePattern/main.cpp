#include <iostream>
using namespace::std;

class Work
{
private:
	int hour;
	bool finish;
	//Work(int _hour,bool _finish):hour(_hour),finish(_finish){}
public:
	Work():hour(0),finish(false){}

	int getHour() { return hour; }
	void setHour(int _hour) { hour = _hour; }

	bool getFinish() { return finish; }
	void setFinish(bool _finish) { finish = _finish; }

	void writeProgram()
	{
		if (hour < 12)
		{
			cout << "current time: " << hour << " morning." << endl;
		}
		else if (hour < 13)
		{
			cout << "current time: " << hour << " lunch time. Break" << endl;
		}
		else if (hour < 17)
		{
			cout << "current time: " << hour << " afternoon, go ahead" << endl;
		}
		else
		{
			if (finish)
			{
				cout << "current time: " << hour << "go off work" << endl;
			}
			else
			{
				if (hour < 21)
				{
					cout << "current time: " << hour << " work overtime, tired" << endl;
				}
				else
				{
					cout << "current time: " << hour << " fall asleep" << endl;
				}
			}
		}
	}

};

int main()
{
	Work* emergencyProjects = new Work();
	emergencyProjects->setHour(9);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(10);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(12);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(13);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(14);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(17);
	

	emergencyProjects->setFinish(false);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(19);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(22);
	emergencyProjects->writeProgram();

	return system("pause");
}