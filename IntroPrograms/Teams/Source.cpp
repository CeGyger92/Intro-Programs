#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;



void main()
{
	ifstream fin("Input.txt");
	ofstream fout("Output.txt");
	string teamA;
	string teamB;
	int scoreA;
	int scoreB;


	vector<string>teamName;
	vector<string>::iterator it;
	vector<int>wins;
	vector<int>loss;
	

	while (!fin.eof())
	{

		fin >> teamA;
		fin >> teamB;
		fin >> scoreA;
		fin >> scoreB;
		
		if (find(teamName.begin(), teamName.end(), teamA) == teamName.end())
		{
			teamName.push_back(teamA);
			wins.push_back(0);
			loss.push_back(0);

		}
		if (find(teamName.begin(), teamName.end(), teamB) == teamName.end())
		{
			teamName.push_back(teamB);
			wins.push_back(0);
			loss.push_back(0);

		}
		if (scoreA > scoreB)
		{
			it = find(teamName.begin(), teamName.end(), teamA);
			auto pos = it - teamName.begin();
			wins[pos]++;
			it = find(teamName.begin(), teamName.end(), teamB);
			pos = it - teamName.begin();
			loss[pos]++;
		}
		else if(scoreB > scoreA)
		{
			it = find(teamName.begin(), teamName.end(), teamB);
			auto pos = it - teamName.begin();
			wins[pos]++;
			it = find(teamName.begin(), teamName.end(), teamA);
			pos = it - teamName.begin();
			loss[pos]++;
		}
	}
	fout << "Team Name:W/L" << endl;
	for (int i = 0; i < teamName.size(); i++)
	{
		fout << teamName[i] << ":" << wins[i] << "/" << loss[i] << "\n";
	}
	
}
