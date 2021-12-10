#include <iostream>
using namespace std;

class Time
{
private:
	/* Data members */
	int hours, minutes, seconds;

public:
	/* Constructor initializing to 0 */
	Time();
	/* Constructor initializing to fixed values */
	Time(int, int, int);
	/* Copy constructor */
	Time(Time&);

	/* Member functions to get data members */
	int getHrs() { return this->hours; }
	int getMin() { return this->minutes; }
	int getSec() { return this->seconds; }

	/* Member function to display time in HH:MM:SS */
	void display();
	/* Member function to add two time variables */
	Time add(Time&, Time&);
};

Time::Time()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Time::Time(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes;
	this->seconds = seconds;
}

Time::Time(Time& time)
{
	this->hours = time.getHrs();
	this->minutes = time.getMin();
	this->seconds = time.getSec();
}

void Time::display()
{
	(hours / 10) ? cout << hours : cout << 0 << hours;
	cout << ':';
	(minutes / 10) ? cout << minutes : cout << 0 << minutes;
	cout << ':';
	(seconds / 10) ? cout << seconds : cout << 0 << seconds;
}

Time Time::add(Time& time1, Time& time2)
{
	int hrsAdd = time1.getHrs() + time2.getHrs();
	if (hrsAdd >= 24)
		hrsAdd -= 24;
	int minAdd = time1.getMin() + time2.getMin();
	if (minAdd >= 60)
	{
		minAdd -= 60;
		hrsAdd += 1;
	}
	int secAdd = time1.getSec() + time2.getSec();
	if (secAdd >= 60)
	{
		secAdd -= 60;
		minAdd += 1;
	}
	Time timeAdd(hrsAdd, minAdd, secAdd);
	return timeAdd;
}

int main()
{
	/* Initialized Time objects */
	Time time1(7, 45, 30), time2(19, 15, 45);
	/* Uninitialized Time object */
	Time time3;

	/* Adding Time objects */
	time3 = time3.add(time1, time2);

	/* Calling copy constructor */
	Time time4 = time3;

	/* Displaying results */
	cout << "Time 1: "; time1.display();
	cout << "\nTime 2: "; time2.display();
	cout << "\nTime 3: "; time3.display();
	cout << "\nTime 4: "; time4.display();
	cout << '\n';
	return 0;
}