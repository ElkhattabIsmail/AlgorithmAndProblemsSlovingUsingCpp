//#43 Level 3 Replace Words Without Buil - in Function

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
string JoinString(vector <string> vString, string Delim)
{
	string S1 = "";
	for (string& word : vString)
	{
		S1 = S1 + word + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length()); // rmv last Delimeter/seperator
}
string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}
string ReplacedWordUsingSplit(string S1, string WordToReplace, string ReplaceTo, bool Matchcase = true)
{
	vector <string> VecString;
	VecString = SplitString(S1, " ");

	for (string& W : VecString)
	{
		if (Matchcase)
		{
			if (W == WordToReplace)
			{
				W = ReplaceTo;
				return JoinString(VecString, " ");
			}
			
		}
		else
		{
			if (LowerAllString(W) == LowerAllString(WordToReplace))
			{
				W = ReplaceTo;
			}
		}

	}
	return JoinString(VecString, " ");
}
string ReplaceWord(string S1, string OriginalWord, string ReplaceWord)
{
	short pos = S1.find(OriginalWord);
	while (pos != string::npos)
	{
		S1 = S1.replace(pos, OriginalWord.length(), ReplaceWord);
		pos = S1.find(OriginalWord);
	}
	return S1;
}

int main() {

	string Text = "hello smail or SMAIL";
	cout << "Originale Text = " << Text;
	string WordToReplace = "smail", ReplaceTo = "King";


	cout << "\n\nMatch Case Word Exactly : \n";
	cout << ReplacedWordUsingSplit(Text, WordToReplace, ReplaceTo);  // by def

	cout << "\n\nNot Match Case However Word write : \n";
	cout << ReplacedWordUsingSplit(Text, WordToReplace, ReplaceTo, false);

	system("pause>0");

}


