#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<iomanip>

using namespace std;

ifstream fin("CourseGrades.txt");
ofstream fout("GPA.txt");
struct Grade
{
	string semester;
	int hours;
	int gradePoint;
	char letterGrade;
 };

ostringstream semesterGPA(string semesterYear, vector<Grade>courses);
ostringstream overallGPA(vector<Grade>courses);
void main()
{
	
	
	string line;
	string junk;
	vector<Grade>courses;
	


	while (!fin.eof())
	{
		Grade currentClass;
		getline(fin, line);
		istringstream sin(line);
		sin >> currentClass.semester;
		sin >> junk;
		sin >> junk;
		sin >> currentClass.hours;
		sin >> currentClass.letterGrade;


			switch (currentClass.letterGrade)
			{
			case 'A':
				currentClass.gradePoint = 4;
				break;
			case 'B':
				currentClass.gradePoint = 3;
				break;
			case 'C':
				currentClass.gradePoint = 2;
				break;
			case 'D':
				currentClass.gradePoint = 1;
				break;
			case 'F':
				currentClass.gradePoint = 0;
				break;

			}
			courses.push_back(currentClass);

			
	}
	fout << semesterGPA("Fall-2017", courses).str() << endl;
	fout << semesterGPA("Spring-2018", courses).str() << endl;
	fout << semesterGPA("Fall-2018", courses).str() << endl;
	fout << semesterGPA("Spring-2019", courses).str() << endl;
	fout << semesterGPA("Fall-2019", courses).str() << endl;
	fout << semesterGPA("Spring-2020", courses).str() << endl;
	fout << semesterGPA("Fall-2020", courses).str() << endl;
	fout << semesterGPA("Spring-2021", courses).str() << endl;
	
	fout << overallGPA(courses).str();
}

ostringstream semesterGPA(string semesterYear, vector<Grade>courses)
{
	
	float totalHours = 0;
	float gpXh = 0;
	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].semester == semesterYear)
		{
			totalHours += courses[i].hours;
			gpXh += courses[i].hours * courses[i].gradePoint;
		}
	}
	 
	float GPA = gpXh / totalHours;
	
	ostringstream answer;
	answer << semesterYear << " GPA = " << showpoint<< fixed << setprecision(2) << GPA;
		return answer;
}

ostringstream overallGPA(vector<Grade>courses)
{
	
	float totalHours = 0;
	float gpXh = 0;
	for (int i = 0; i < courses.size(); i++)
	{
		
			totalHours += courses[i].hours;
			gpXh += courses[i].hours * courses[i].gradePoint;
		
	}

	float GPA = gpXh / totalHours;
	ostringstream answer;
	answer << "The Overall GPA =" << showpoint << fixed << setprecision(2) << GPA;
	
	return answer;
}