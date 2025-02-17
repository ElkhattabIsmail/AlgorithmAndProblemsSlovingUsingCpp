#include<string>
#include<iostream>
#include<vector>

using namespace std;

string  ReadString() {
	string S1;
	cout << "Please Enter a String?\n";
	getline(cin, S1);
	return S1;
}

vector<string> SplitString(string S1, string Delim) {

	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.    
	}
	return vString;
}
string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if  (S1[i] != ' ')
		{
			return S1.substr (i, S1.length() - i);
		}
	}
	return "";
	
}
      
string TrimRight (string S1)
{
	for (short i = S1.length(); i > 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr( 0 , i );
		}
	}
	return "";

}
string Trim(string S1)
{
	return TrimLeft(TrimRight(S1));
}
int main() {
	
	/*cout <<"Trim Left : " << TrimLeft(ReadString()) << "\n";

	cout <<"Trim Right : " <<TrimRight(ReadString()) << "\n";*/

	cout << "Trim Right & Left : " << Trim(ReadString()) << "\n";
	
	system("pause>0");

}
