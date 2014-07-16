//Shannon Simpson
//Shannon.Simpson@uky.edu
//Program #1


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


void build (vector<vector<string>> &vvStrings, int iRows, int iCols, bool bTriangular, bool bOutter, bool bAll, bool bAlphabetical, string sCharacter)
{
	vvStrings.resize(iRows);
	for (int i = 0; i < iRows; i++)
	{
		if (bTriangular)
		{
			for (int j = 0; j <= i; j++)
			{
				vvStrings[i].push_back(sCharacter);
				if (bAlphabetical)
				{
					sCharacter[0]++;
				}
				if (bOutter)
				{
					if (i == j)
					{
						vvStrings[i].push_back(sCharacter);
					}
					else 
					{
						vvStrings[i].push_back(" ");
					}
				}
			}
		}
		for(int j = 0; j < iCols; j++)
		{
			if (bAlphabetical)
			{
				vvStrings[i].push_back(sCharacter);
				sCharacter[0]++;
			}
			else if (bOutter)
			{
				if (j == 0 ||j == (iCols - 1)) //left or right
				{
					vvStrings[i].push_back(sCharacter);
				}
				else if ((i == 0 || i == (iRows - 1))) // top or bottom
				{
					vvStrings[i].push_back(sCharacter);
				}
				else // inside
				{
					vvStrings[i].push_back(" ");
				}
			}
			else
			{
				vvStrings[i].push_back(sCharacter);
			}
		}	
	}

}

void display (vector<vector<string>> vvStrings)
{
		for (int i = 0; i < vvStrings.size(); i++)
		{		
			for (int j = 0; j < vvStrings[i].size(); j++)
			{
				cout << vvStrings[i][j]; 
			}
			cout << endl;
		}
		cout << endl;
}


	int myInt = 0;


int main ()
{
	string filename;
	cout << "What file should I use? ";
	cin >> filename;

	ifstream myfile;
	myfile.open(filename);

	vector<string> rows;
	vector<string> columns;
	
	string sCharacter;
	bool bAlphabetical = false;
	bool Outter = false;
	bool bAll = false;
	bool bTriangular = false;
	bool bOutter = false;
	vector<vector<string>> vvStrings ;
	int iRows = 0;
	int iCols = 0;

	
	while (myfile.good()) 
	{
		char currentLetter;
		do{
			currentLetter = myfile.get();
		}while(isspace(currentLetter)); //check if the character is a space and will return TRUE if it is a space
		
		myfile.unget();

		
		if (isdigit(currentLetter))
		{ //the current character is an interger
			myfile >> myInt;
		}
		else
		{ //the current character is a letter or character
			string s;
			myfile >> s;
			if (s == "go")
			{
				build (vvStrings, iRows, iCols, bTriangular, bOutter, bAll, bAlphabetical, sCharacter);
				display (vvStrings);
				sCharacter = "*";
				vvStrings.clear();
				vvStrings.resize(0);
				rows.clear();
				rows.resize(0);
				columns.clear();
				columns.resize(0);
				bAlphabetical = false;
				bAll = false;
				bTriangular = false;
				bOutter = false;
				iRows = 0;
				iCols = 0;
			}

			else if (s == "rows")
			{
				iRows = myInt;
			}

			else if (s == "columns")
			{
				iCols = myInt;
			}

			else if (s == "alphabetical")
			{
				bAlphabetical = true;
				sCharacter = "A";
			}

			else if (s == "triangular")
			{
				bTriangular = true;
			}

			else if (s == "outer")
			{
				bOutter = true;
			}

			else if (s == "all")
			{
				bAll = true;
				do
				{
					sCharacter = myfile.get();
					}while(isspace(sCharacter[0]));
			}
		}
	}

	return 0;
}