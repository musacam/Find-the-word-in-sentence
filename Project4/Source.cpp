#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

void readfunc(fstream& a, fstream& b) {
	ifstream scriptf, statementf;
	string scriptfilename;
	string statementsfilename;
	string fullscript;
	string script[15000];																			//Script array will store the words from "the_truman_show_script.txt"
	string statementlines[1000];
	string statements[1000];																		//Statements array will store the words from "statements.txt"
	scriptf.open(scriptfilename);
	getline(scriptf, fullscript);
	scriptf.close();

	istringstream ss(fullscript);

	int i = 0; //script word number
	int j = 0; //statement line number

	do
	{
		ss >> script[i];
		i++;
	} while (ss);																					//Fetching the words in script file to the array.

	statementf.open(statementsfilename);
	while (!statementf.eof())
	{
		getline(statementf, statementlines[j]);
		j++;																						//Determines line number in statements file.
	}
	statementf.close();

	int s = 0; //Amount of word in statements file.

	for (int o = 0; o < j; o++)
	{
		istringstream ssstatements(statementlines[o]);
		while (ssstatements)
		{
			ssstatements >> statements[s];														//Fetching the words in statements file to the array.
			s++;
		}
	}

	int counter = 0; //Statement not found counter.
	int backup = 0;	//Number of word in one sentence in statements file.


	/*	Within nested for loops we are trying to match the words between two arrays.
		If words are matched it will iterate to the next/back words to see statements are also matched.
		Within 4 if else situation it will check and print the output of statements
			and real sentence/phrase in script.
	*/
	for (int wordcount = 0; wordcount < i; wordcount++)
	{
		for (int z = 0; z < s; z++)
		{
			if (statements[z] == script[wordcount] && statements[z + 1] == script[wordcount + 1] && statements[z + 2] == script[wordcount + 2] && statements[z + 3] == script[wordcount + 3])
			{
				backup = z;
				while (statements[z] != "")
				{
					cout << statements[z] << " ";
					z++;
				}
				z = backup;
				cout << endl;
				while (statements[z] != "")
				{
					cout << script[wordcount] << " ";
					z++;
					wordcount++;
				}
				counter++;
				if (wordcount != i - 1) {
					cout << endl;
				}
			}

			else if ((statements[z] == script[wordcount] && statements[z - 1] == script[wordcount - 1] && statements[z - 2] == script[wordcount - 2] && statements[z + 2] == script[wordcount + 2]))
			{
				backup = z;
				while (statements[z] != "")
				{
					cout << statements[z] << " ";
					z++;
				}
				cout << endl;
				z = backup;
				while (statements[z] != "")
				{
					cout << script[wordcount - 3] << " ";
					z++;
					wordcount++;
				}
				counter++;
				if (wordcount != i - 1) {
					cout << endl;

				}
			}
			else if (statements[z] == "___" && statements[z + 1] == script[wordcount + 1] && statements[z + 2] == script[wordcount + 2] && statements[z + 3] == script[wordcount + 3]) {
				backup = z;
				while (statements[z] != "")
				{
					cout << statements[z] << " ";
					z++;
				}
				z = backup;
				cout << endl;
				while (statements[z] != "")
				{
					cout << script[wordcount] << " ";
					z++;
					wordcount++;
				}
				counter++;
				if (wordcount != i - 1) {
					cout << endl;
				}
			}

			else if (statements[z + 1] == "___" && statements[z] == script[wordcount] && statements[z + 2] == script[wordcount + 2] && statements[z + 3] == script[wordcount + 3]) {
				backup = z;
				while (statements[z] != "")
				{
					cout << statements[z] << " ";
					z++;
				}
				z = backup;
				cout << endl;
				while (statements[z] != "")
				{
					cout << script[wordcount] << " ";
					z++;
					wordcount++;
				}
				counter++;
				if (wordcount != i - 1) {
					cout << endl;
				}
			}
		}
	}

	while (counter - 1 < j) {
		cout << "Statement NOT found" << endl;
		counter++;
	}

}

int main() {
	int start_clock = clock();

	//Everytime statement sentence matched counter will increase in order to increasing number of lines.
	//If statement sentence doesn't matched with any senetence from script counter will not increase
	//		and due to line increasement it will print statement not found.

	readfunc("the_truman_show_script.txt", "statements.txt");

	//TIME

	int stop_clock = clock();
	double time = (((stop_clock - start_clock) / double(CLOCKS_PER_SEC) * 1000) * ((16667 / 10000) * (0.00001)));
	cout << endl;
	cout << "Total Elapsed Time : " << time * 60 << " seconds";
	return 0;
}