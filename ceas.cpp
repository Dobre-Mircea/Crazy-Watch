#include <iostream>
#include <iomanip>
using namespace std;

class Watch
{
private:
	int _min, _hour;
	int _state = -1;
public:
	Watch(int hour, int min)
	{
		_min = min;
		_hour = hour;
	}
	Watch()
	{
		_min = 0;
		_hour = 0;
	}
	Print()
	{
		cout << "Current hour is:" << endl;
		cout << "   " << setfill('0') << setw(2) << _hour << " : "<< setfill('0') << setw(2) << _min << endl; 
		if(_state == 1)
				cout << "   --" << endl;	
			else if(_state == 2)
				cout << "        --" << endl;
	}

	void Wait_1_Min()
	{
		_min++;
		if(_min == 61)
		{
			_min = 0;
			_hour++;
			if(_hour == 25)
				_hour = 0;
		}
	}

	void IncrementHour() //button A
	{
		if(_state == 1)
			{
				_hour++;
				if(_hour == 25)
					_hour = 0;
			}
		else 
			{
				_state = 1;
			}
	}

	void IncrementMinute()
	{
		if(_state == 2)
		{
			_min++;
			if(_min == 60)
			{
				_min = 0;
			    _hour++;
				if(_hour == 25)
					_hour = 0;
			}
		}
		else 
			{
				_state = 2;		
			}
	}

	void PrintOptions()
	{
		cout << "1 - Increment hours" << endl;
		cout << "2 - Increment minutes" << endl;
		cout << "0 - Exit watch" << endl;
	}

	void StartWatch()
	{
		int option = 100;
		while(option != 0)
		{
			system("cls");
			Print();
			cout << endl << endl;
			PrintOptions();
			cin >> option;
			if(option == 1)
				IncrementHour();
			else if(option == 2)
				IncrementMinute();
			else return;
		}
	}
};


int main(){
	Watch gigel(12, 45);
	gigel.StartWatch();
	return 0;
}
