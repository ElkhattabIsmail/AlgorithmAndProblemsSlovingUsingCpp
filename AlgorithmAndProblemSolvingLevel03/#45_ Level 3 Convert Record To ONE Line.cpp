//#45 Level 3 Convert Record To ONE Line


#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct stData
{
	string AccountNumber = "";
	string PinCode = "";
	string ClientName = "";
	string PhoneNumber = "";
	double Balance ;
};


stData GetClientData()
{
	stData Data;

	cout << "Enter Your Account Number please : ";
	getline(cin, Data.AccountNumber);
	cout << "Enter Pin Code: ";
	getline(cin, Data.PinCode);
	cout << "Enter Your Name : ";
	getline(cin, Data.ClientName);
	cout << "Phone Number : ";
	getline(cin, Data.PhoneNumber);
	cout << "Enter Your Balance : ";
	cin >> Data.Balance;

	return Data;
}
string ConvertRecordToLine(stData Data , string seperator = " #//# " )
{
	string stData = "";

	stData += Data.AccountNumber + seperator;
	stData += Data.PinCode + seperator;
	stData += Data.ClientName + seperator;
	stData += Data.PhoneNumber + seperator;
	stData += to_string(Data.Balance) + seperator;

	return stData;
}
vector<string> SplitString(string S1, string Delim)
{

	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos) ;

		if (sWord != "") 
		{
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
string ReplacedWord01(string S1, string OriginalWord, string ReplaceWord)
{
	vector <string> VecString;
	VecString = SplitString(S1, " ");

	string WholeText = "";
	for (string& W : VecString)
	{
		if (W == OriginalWord)
			W = ReplaceWord;

	}
	return S1;
}
string ReplacedWord(string S1, string OriginalWord, string ReplaceWord)
{
	short pos = S1.find(OriginalWord);
	while (pos != string::npos)
	{
		S1 = S1.replace(pos, OriginalWord.length(), ReplaceWord);
		pos = S1.find(OriginalWord);
	}
	return S1;
}

int main() 
{
	stData Data;
	Data = GetClientData();
	cout << ConvertRecordToLine(Data);
	system("pause>0");

}
