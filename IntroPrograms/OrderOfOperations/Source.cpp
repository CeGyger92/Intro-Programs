#include<iostream>
#include<fstream>

using namespace std;

void main()
{
	ifstream fin("Equations.txt");
	ofstream fout("Answers.txt");
	int num1;
	char operator1;
	int num2;
	char operator2;
	int num3;
	int answer;

	while (!fin.eof())
	{

		fin >> num1;
		fin >> operator1;
		fin >> num2;
		fin >> operator2;
		fin >> num3;

		if (operator2 == '*')
		{
			if (operator1 == '*')
			{
				answer = (num3 * num2) * num1;
			}
			else if (operator1 == '/')
			{
				answer = (num1 / num2) * num3;
			}
			else if (operator1 == '+')
			{
				answer = (num3 * num2) + num1;
			}
			else
			{
				answer = (num3 * num2) - num1;
			}
		}
		else if (operator2 == '/')
		{
			if (operator1 == '*')
			{
				answer = (num1 * num2) / num3;
			}
			else if (operator1 == '/')
			{
				answer = (num1 / num2) / num3;
			}
			else if (operator1 == '+')
			{
				answer = (num2 / num3) + num1;
			}
			else
			{
				answer = (num2 / num3) - num1;
			}
		}
		else if (operator2 == '+')
		{
			if (operator1 == '*')
			{
				answer = (num1 * num2) + num3;
			}
			else if (operator1 == '/')
			{
				answer = (num1 / num2) + num3;
			}
			else if (operator1 == '+')
			{
				answer = num1 + num2 + num3;
			}
			else
			{
				answer = (num1 - num2) + num3;
			}
		}
		else
		{
			if (operator1 == '*')
			{
				answer = (num1 * num2) - num3;
			}
			else if (operator1 == '/')
			{
				answer = (num1 / num2) - num3;
			}
			else if (operator1 == '+')
			{
				answer = num1 + num2 - num3;
			}
			else
			{
				answer = (num1 - num2) - num3;
			}
		}
		fout << num1 << " " << operator1 << " " << num2 << " " << operator2 << " " << num3 << " = " << answer << "\n";
	}
}