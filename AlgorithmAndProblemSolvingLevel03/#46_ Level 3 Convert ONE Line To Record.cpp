

#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct stClient
{
	string AccountNumber = "";
	string PinCode = "";
	string ClientName = "";
	string PhoneNumber = "";
	double Balance;         
};


stClient GetClientData()
{
	stClient Data;

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
string ConvertRecordToLine(stClient Data, string seperator = " #//# ")
{
	string stData = "";

	stData += Data.AccountNumber + seperator;
	stData += Data.PinCode + seperator;
	stData += Data.ClientName + seperator;
	stData += Data.PhoneNumber + seperator;
	stData += to_string(Data.Balance) + seperator;

	return stData;
}

vector<string> SplitString(string S1, string Delim = " " )
{

	vector<string> vString;
	short pos = 0;
	string sWord;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

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
stClient ConvertLineToRecord(string Line, string seperator = " #//# ")
{
	stClient Client;
	vector<string> vstring;
	vstring = SplitString(Line , seperator);
			
	Client.AccountNumber = vstring.at(0);
    Client.PinCode = vstring.at(1);
	Client.ClientName = vstring.at(2);
	Client.PhoneNumber = vstring.at(3);
	Client.Balance = stod (vstring.at(4));

	return Client;
}
void PrintClientRecord(stClient Client)
{
	cout << "Client Record \n";

	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nClient name : " << Client.ClientName;
	cout << "\nphone : " << Client.PhoneNumber;
	cout << "\nBalance : " << Client.Balance;
}

int main()
{
	string  Line = "a20 #//# 1234 #//# Ismail #//# 0642981375 #//# 50000";
	stClient  Client;
	Client = ConvertLineToRecord(Line);
	PrintClientRecord(Client);
	system("pause>0");

}
