#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;


string reverse(string s)
{
	string result = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		result += s[i];

	}

	return result;
}

void main()
{
	std::ifstream fin("test.txt");
	ofstream fout("PalindromeOutput.txt");
	while (!fin.eof())
	{
		std::string line;
		getline(fin, line);
		std::istringstream sin(line);

		std::string word;
		int count = 0;
		while (!sin.eof())
		{
			sin >> word;
			//cout << reverse(word) << endl;
			if (word == reverse(word))
			{
				count++;
			}
		}
		//cout << count << endl;

		

		fout << line << " <--- contains " << count << " palindrome(s) and ";

		if (line == reverse(line))
		{
			fout << "is ";
		}
		else
		{
			fout << "is not ";
		}
		fout << "a palindrome itself." << endl;
	}
	
}