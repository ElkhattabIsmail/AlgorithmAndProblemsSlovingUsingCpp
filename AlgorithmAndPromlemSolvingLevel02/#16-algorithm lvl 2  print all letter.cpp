#include<iostream>
#include<string>
using namespace std;
void PrintAAAtoZZZ()
{
	cout << "\n";
	string word = "";
	for (int i = 65; i <= 90 ; i++)
	{
		for (int j =i ; j<=90 ; j++)               
		{   
			for (int h = 65; h <= 90; h++)
			{
				word = word+char(i);
				word = word + char(j);
				word = word + char(h);
				cout << word<<endl;
				word = "";
			}
		}
		
	}
}
int main()
{
	PrintAAAtoZZZ();
	return 0;
}