
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
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - i);
		}
	}
	return "";

}

string TrimRight(string S1)
{
	for (short i = S1.length(); i > 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i);
		}
	}
	return "";
}

string Trim(string S1)
{
	return TrimLeft(TrimRight(S1));
}


string JoinString(vector <string> vString, string Delim)
{
	string S1 = "";
	for (string& word : vString)
	{
		S1 = S1 + word + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}
string Join_Str(vector <string> VectorElement, string Delim)
{
	string S1 = "";
	for (short i = 0; i < VectorElement.size(); i++)
	{
		if (i != VectorElement.size() - 1)
		{
			S1 = S1 + VectorElement[i] + Delim;
		}
		else
			S1 += VectorElement[i];

	}
	return S1;
}
string JoinString(string arr[], short Length, string Delim)
{
	string S1 = "";
	for (short i = 0; i < Length; i++)
	{
		S1 = S1 + arr[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}



int main() {

	vector <string> S1 = { "Mohammed","Fahd","Ali","Maher" };
	string arr[] = { "Mohammed","Fahd","Ali","Maher" };

	cout << "\nVector after Join : " << JoinString(S1, "  ");

	cout << "\nArrays after Join : " << JoinString(arr, 4, " , ");

	system("pause>0");

}


