//  #40 Level 3  Reverse String

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

string MyReversedWordsInString(string S1)
{
	
	vector<string> vString;
	vString = SplitString (S1 ," "); // full Vector

	string StrWord = "" , Delim = " ";

	for (short i = vString.size(); i > 0; i--)
	{
		StrWord += vString.at(i-1) + Delim;
	}
	return StrWord;
}
string ReversedWordsInString(string S1)
{
	vector<string> vString;
	vString = SplitString(S1, " "); // full Vector

	string StrWord = "";

	vector <string>::iterator iter  = vString.end() ;
	
	while ( iter != vString.begin() )  // while loop that's why Reduced the Iterator in Every Loop
	{
		iter--;  // Or --iter ;
		StrWord += * iter + " " ;
	}
		
	return StrWord;

}
int main() {

	cout<<ReversedWordsInString(ReadString());
	system("pause>0");

}


