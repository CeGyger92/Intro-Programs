#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void main()
{
	
	ifstream People("People.txt");

	string originalLetter = "";
	string name;
	string address;
	string major;
	string line;
	string nothing;

	while (!People.eof())
	{
		
		getline(People, name);
		getline(People, address);
		getline(People, major);
		getline(People, nothing);
		ifstream Letter("Letter.txt");
		string newLetter = name + ".txt";
		ofstream fout(newLetter);

		while (!Letter.eof())
		{
			string newline ="";
			getline(Letter, line);
			if (line.find("#NAME#") != string::npos)
			{
				newline += line.substr(0, (line.find("#NAME#")));
				newline += name;
				newline += line.substr(line.find("#NAME#") + 6);


			}
			if (line.find("#ADDRESS#") != string::npos)
			{
				newline += line.substr(0, (line.find("#ADDRESS#")));
				newline += address;
				newline += line.substr(line.find("#ADDRESS#") + 9, (line.find("#MAJOR#")- (line.find("#ADDRESS#") + 9)));
				newline += major;
				newline += line.substr(line.find("#MAJOR#") + 7);

			}
		
			
			fout << newline;
			fout << "\n";
		}


		fout.close();
	}

}