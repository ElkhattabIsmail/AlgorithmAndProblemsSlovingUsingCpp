
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string UpperString(string text)
{
	for (short i = 0; i < text.length(); i++)
		text[i] = toupper(text[i]);
	return text;
}

string LowerString(string text)
{
	for (short i = 0; i < text.length(); i++)
		text[i] = tolower(text[i]);
	return text;
}

int main()
{
	string text;
	cout << "Please enter your string:\n";
	getline(cin, text);
	cout << "\nString after upper:\n";
	cout << UpperString(text) << endl;
	cout << "\nString after lower:\n";
	cout << LowerString(text) << endl;
	return 0;
}