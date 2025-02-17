

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt"; 

struct str_Client 
{ 
	string AccountNumber; 
	string PinCode; string 
		Name; string Phone; 
	double AccountBalance; 
}; 

vector<string> SplitString(string S1, string Delim) {

	vector<string> vString; 
	short pos = 0; 
	string sWord; 
	while ((pos = S1.find(Delim)) != std::string::npos)   
	{         
		sWord = S1.substr(0, pos); // store the word   
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
	
str_Client ConvertLineToRecord (string Line, string Seperator = "#//#")
{
		str_Client Client; 
		vector<string> vClientData;

		vClientData = SplitString(Line, Seperator); 

		Client.AccountNumber = vClientData[0];     
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);//cast string to double

		return Client; 
} 

vector <str_Client> LoadCleintsDataFromFile(string FileName) { 
	vector <str_Client> vClients; 
	fstream MyFile;  
	MyFile.open(FileName, ios::in);//readMode 

	if (MyFile.is_open())    
	{
		string Line; 
		str_Client Client;
		while (getline(MyFile, Line))      
		{   
			Client = ConvertLineToRecord(Line);  
			vClients.push_back(Client);         
		}       
		MyFile.close();     
	} 
	return vClients; 
} 
void PrintClientCard(str_Client Client) 
{ 
	cout << "\nThe following are the client details:\n";    
	cout << "\nAccount Number: " << Client.AccountNumber;    
	cout << "\nPin Code     : " << Client.PinCode;   
	cout << "\nName         : " << Client.Name;     
	cout << "\nPhone        : " << Client.Phone;    
	cout << "\nAccount Balance: " << Client.AccountBalance;
} 

bool FindClientByAccountNumber(string AccountNumber, str_Client & Client)
{ 

	vector <str_Client> vClients = LoadCleintsDataFromFile(ClientsFileName);

	for (str_Client C : vClients) 
	{ 
		if (C.AccountNumber == AccountNumber)
		{ 
			Client = C; 
			return true;
		} 
	} 
	return false;
} 
string ReadClientAccountNumber(str_Client Client ) 
{
	string InputAccountNumber = "";   

	cout << "\nPlease enter AccountNumber? ";
	cin >> InputAccountNumber;
	return InputAccountNumber;
}
void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}
str_Client ReadNewClient() {
	str_Client Client;
	cout << "Enter Account Number? "; // Usage of std::ws will extract allthe whitespace character    
	getline(cin >> ws, Client.AccountNumber);
	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}
string ConvertRecordToLine(str_Client Client, string Seperator = "#//#") {
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}
void AddNewClient()
{
	str_Client Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}
void AddClients() {
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
int main() { 
	str_Client Client; 
	string AccountNumber = ReadClientAccountNumber(Client);

	if (FindClientByAccountNumber(AccountNumber, Client)) 
	{ 
		PrintClientCard(Client); 
	} 
	else { 
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}     
	//AddClients();
	system("pause>0"); return 0; 
}