
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

vector<string> SplitString(string S1, string Delim)
{
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
string ReplacedWord01(string S1 , string OriginalWord , string ReplaceWord)
{
	vector <string> VecString;
	VecString = SplitString(S1, " ");

	string WholeText = "";
	for (string& W : VecString)
	{
		OriginalWord = ReplaceWord;

	}
	return S1;
}
string ReplacedWord(string S1, string OriginalWord, string ReplaceWord)
{
	short pos = S1.find(OriginalWord);
	while (pos != string::npos)
	{
		S1 = S1.replace (pos, OriginalWord.length(), ReplaceWord);
		pos = S1.find(OriginalWord);
	}
	return S1;
}

int main() {

	cout << ReplacedWord(ReadString(), "smail", "Ali");
	system("pause>0");

}


