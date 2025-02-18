#include<iostream>
#include<string>
using namespace std;
string readTEXT (string message)
{
	string text;
	cout << message << endl;
	getline(cin, text);
	return text;
}
string encryptionText(string text, short key)
{
	
	text.length();
	for (int a = 0; a <= text.length()-1; a++)
	{
		text[a] = char((int)text[a] + key);
	}
	return text;
}
string decryptionText(string text, short key)
{

	for (int a = 0; a <= text.length() - 1; a++)
	{
		text[a] = char((int)text[a] - key);
	}
	return text;
}

int main()
{
	const int key = 2;
	string bfr = readTEXT("enter a text:");

	string afterenceyption = encryptionText(bfr, key);
	string afterdeceyption = decryptionText(afterenceyption, key);
	 
	cout << "\ntext befor encryption : " << bfr << endl;
	cout << "\ntext after encryption : " << afterenceyption << endl;
	cout << "\ntext after decryption : " << afterdeceyption << endl;
	return 0;
}