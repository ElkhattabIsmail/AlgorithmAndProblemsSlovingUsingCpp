#include<iostream>
#include<string>
using namespace std;
string readPassword(string message)
{
	string password;
	cout << message<<endl;
	cin >> password;
	return password;
}
bool PrintAAAtoZZZ(string password)
{
	cout << "\n";
	string word = "";
	
	int count = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int h = 65; h <= 90; h++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(h);
				count++;
				cout << "Trial[" << count << "] :" << word << "\n";
				if (word == password)
				{
					cout << "password is " << password << endl;
					cout << "found after " << count << " Trial(s)" << endl;
					return true;
				}
				else
					word = "";
				    
				

			}
		}
	}
	return false;
}
int main()
{
	PrintAAAtoZZZ(readPassword("enter 3 capital letter:"));
	
	return 0;
}