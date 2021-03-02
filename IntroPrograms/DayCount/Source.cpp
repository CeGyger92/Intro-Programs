#include<iostream>
#include<fstream>
#include<string>

using namespace std;



struct Date
{
	int d, m, y;
};

const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };


int countLeapYears(Date d)
{
	int years = d.y;

	
	if (d.m <= 2)
	{
		years--;
	}
	
	return years / 4 - years / 100 + years / 400;
}


int getDifference(Date dt1, Date dt2)
{
	

	
	long int days1 = dt1.y * 365 + dt1.d;
	for (int i = 0; i < dt1.m - 1; i++)
	{
		days1 += monthDays[i];
	}
	
	days1 += countLeapYears(dt1);

	

	long int days2 = dt2.y * 365 + dt2.d;
	for (int i = 0; i < dt2.m - 1; i++)
	{
		days2 += monthDays[i];
	}
	days2 += countLeapYears(dt2);

	
	return (days2 - days1);
}




void main()
{
	ifstream dates("dates.txt");
	ofstream fout("TotalDays.txt");
	
	Date startingDate;
	Date endingDate;

	char junk;
	while (!dates.eof())
	{
		

		dates >> junk;
		dates >> junk;
		dates >> startingDate.m;
		dates >> junk;
		dates >> startingDate.d;
		dates >> junk;
		dates >> startingDate.y;
		
		dates >> endingDate.m;
		dates >> junk;
		dates >> endingDate.d;
		dates >> junk;
		dates >> endingDate.y;
	
		fout << "There are " << getDifference(startingDate, endingDate) << " total days between " << startingDate.m << "/" << startingDate.d << "/" << startingDate.y << " and " << endingDate.m << "/" << endingDate.d << "/" << endingDate.y << "\n";
		}
		
	}
	
	








