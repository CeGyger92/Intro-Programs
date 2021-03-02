#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



void main()
{
	ifstream fin("students.txt");
	ofstream fout("classification.txt");


	string firstName;
	string lastName;
	int creditHours;

	int freshCount = 0;
	int sophCount = 0;
	int junCount = 0;
	int senCount = 0;



	while (!fin.eof())
	{

		fin >> firstName;
		fin >> lastName;
		fin >> creditHours;

		if (creditHours > 0 && creditHours < 27)
		{
			freshCount++;
		}
		else if (creditHours > 26 && creditHours < 60)
		{
			sophCount++;
		}
		else if (creditHours > 59 && creditHours < 90)
		{
			junCount++;
		}
		else if (creditHours >= 90)
		{
			senCount++;
		}
		cout << firstName;
		system("pause");
	}
	fout << "Freshman = " << freshCount << endl;
	fout << "Sophomores = " << sophCount << endl;
	fout << "Juniors = " << junCount << endl;
	fout << "Seniors = " << senCount << endl;
}