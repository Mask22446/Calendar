#include <iomanip>
#include <iostream>

using namespace std;

int getMonth();
int getYear();
int computeOffset(int Year, int Month);
int numDaysInYear(int Year);
int numDaysInMonth(int Month, int Year);
bool isLeapYear(int Year);
void display(int& Month, int& Year, int& Offset, int& NumberDaysInMonth);
void displayTable(int& Offset, int& NumberDaysInMonth);
void displayHeader(int& Month, int& Year);

//calling all functions
int main()
{
	int Month = getMonth();
	int Year = getYear();
	cout << endl;
	int NumDaysInYear = numDaysInYear(Year);
	int NumDaysInMonth = numDaysInMonth(Year, Month);
	int Offset = computeOffset(Year, Month);
	display(Month, Year, Offset, NumDaysInMonth);
	return 0;
}

//get prompt from user for month

int getMonth()
{
	int Month;
	cout << "Enter a month number: ";
	cin >> Month;
	while (Month < 1 || Month>12)
	{
		cout << "Month must be between 1 and 12." << endl;
		cin >> Month;
	}
	return Month;
}

//get prompt from user for year

int getYear()
{
	int Year;
	cout << "Enter year: ";
	cin >> Year;
	while (Year < 1753)
	{
		cout << "Year must be 1753 or later." << endl;
		cout << "Enter year: ";
		cin >> Year;
	}
	return Year;
}

//check for leap year
bool isLeapYear(int Year)
{
	if (Year % 4 != 0)return false;
	if (Year % 100 != 0)return true;
	if (Year % 400 == 0)return true;
	return false;
}

//compute number of days in year
int numDaysInYear(int Year)
{
	bool LeapYear = isLeapYear(Year);
	if (LeapYear)return 366;
	else return 365;
}

//compute offset
int computeOffset(int Year, int Month)
{
	int NumDays = 0;
	for (int YearCount = 1753; YearCount < Year; YearCount++)
	{
		NumDays += numDaysInYear(YearCount);
	}
	for (int MonthCount = 1; MonthCount < Month; MonthCount++)NumDays += numDaysInMonth(MonthCount, Year);
	int Offset = NumDays % 7;
	return Offset;
}
//colculate number of days with checking of leap year
int numDaysInMonth(int Month, int Year) {
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
		return 31;
	else if (Month == 2) {
		if (isLeapYear(Year))
			return 29;
		else
			return 28;
	}
	else
		return 30;
}

//combine of displayHeader and displayTable functions.
void display(int& Month, int& Year, int& Offset, int& NumberDaysInMonth) {
	displayHeader(Month, Year);
	displayTable(Offset, NumberDaysInMonth);
	return;
}

//actual calendar

void displayTable(int& Offset, int& NumberDaysInMonth) {
	cout << " Su  Mo  Tu  We  Th  Fr  Sa" << endl;
	cout << setw(4 + (Offset + 1) % 7 * 4);
	for (int i = 1; i <= NumberDaysInMonth; i++) {
		cout << i << setw(4);
		if (((i % 7) + Offset) == 6)
			cout << endl << setw(4);
	}
	if ((Offset + NumberDaysInMonth - 1) % 7 != 5)
		cout << endl;
	return;
}

void displayHeader(int& Month, int& Year) {
	if (Month == 1)
		cout << "January, " << Year << endl;
	if (Month == 2)
		cout << "Febraury, " << Year << endl;
	if (Month == 3)
		cout << "March, " << Year << endl;
	if (Month == 4)
		cout << "April, " << Year << endl;
	if (Month == 5)
		cout << "May, " << Year << endl;
	if (Month == 6)
		cout << "June, " << Year << endl;
	if (Month == 7)
		cout << "July, " << Year << endl;
	if (Month == 8)
		cout << "August, " << Year << endl;
	if (Month == 9)
		cout << "September, " << Year << endl;
	if (Month == 10)
		cout << "October, " << Year << endl;
	if (Month == 11)
		cout << "November, " << Year << endl;
	if (Month == 12)
		cout << "December, " << Year << endl;
	return;
}