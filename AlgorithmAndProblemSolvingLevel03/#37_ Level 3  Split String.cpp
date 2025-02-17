#include<string>
#include<iostream>
#include<vector>

using namespace std;

string  ReadString() {
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

vector<string> SplitString(string S1, string Delim) {

	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "") {
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length() );
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.    
	}
	return vString;
}
vector<string> SplitStringWithoutNops(const string& S1, const string& Delim)
{
	vector<string> vString;
	size_t start = 0;
	size_t end = S1.find(Delim, start);

	while (end != -1) 
	{ // Check if the return value is -1
		if (end != start) 
		{ // Avoid empty substrings
			vString.push_back(S1.substr(start, end - start));
		}
		start = end + Delim.length();
		end = S1.find(Delim, start);
	}

	// Add the last part of the string
	if (start < S1.length()) 
	{
		vString.push_back(S1.substr(start));
	}

	return vString;
}
vector<string> splitString( string S1, string Delim) {
	vector<string> vString;
	size_t start = 0 , end;

	while ((end = S1.find(Delim, start)) != string::npos) {
		if (end != start) { // Avoid empty substrings
			vString.push_back(S1.substr(start, end - start));
		}
		start = end + Delim.length();
	}

	// Add the last part of the string
	if (start < S1.length()) {
		vString.push_back(S1.substr(start));
	}

	return vString;
}
int main() {
	vector<string> vString;
	vString = SplitStringWithoutNops("   alpha extra.   ", " ");

	cout << "\nTokens = " << vString.size() << endl;

	for (string& s : vString)
	{
		cout << s << endl;
	}
	system("pause>0");
}