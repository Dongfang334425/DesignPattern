#include <iostream>
using namespace::std;

class State;
class Work
{
private:
	State* current;
	int hour;
	bool finish;
	//Work(int _hour,bool _finish):hour(_hour),finish(_finish){}
public:
	Work();

	int getHour() { return hour; }
	void setHour(int _hour) { hour = _hour; }

	bool getFinish() { return finish; }
	void setFinish(bool _finish) { finish = _finish; }

	void writeProgram();

	void setState(State* s)
	{
		current = s;
	}
};

class State
{
public:
	virtual void WriteProgram(Work* w)=0;
};

class ForenoonState :public State
{
	void WriteProgram(Work* w) override;
};

class NoonState :public State
{
	void WriteProgram(Work* w) override;
};

class AfternoonState :public State
{
	void WriteProgram(Work* w) override;
};

Work::Work():hour(0), finish(false)
{
	current = new ForenoonState();
}

void Work::writeProgram()
{
	current->WriteProgram(this);
}

void ForenoonState::WriteProgram(Work* w)
{
	if (w->getHour() < 12)
	{
		cout << "current time: " << w->getHour() << " morning." << endl;
	}
	else
	{
		w->setState(new NoonState());
		w->writeProgram();
	}
}

void NoonState::WriteProgram(Work* w)
{
	if (w->getHour() < 13)
	{
		cout << "current time: " << w->getHour() << " lunch time. Break" << endl;
	}
	else
	{
		w->setState(new AfternoonState());
		w->writeProgram();
	}
	
}

void AfternoonState::WriteProgram(Work* w)
{
	cout << "current time: " << w->getHour() << " afternoon, go ahead" << endl;
}

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
	/*emergencyProjects->setHour(17);
	

	emergencyProjects->setFinish(false);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(19);
	emergencyProjects->writeProgram();
	emergencyProjects->setHour(22);
	emergencyProjects->writeProgram();*/

	return system("pause");
}