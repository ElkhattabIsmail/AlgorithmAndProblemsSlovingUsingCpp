


#include<iostream>
#include<vector>
#include<string>

using namespace std;

string RemovePauncuationFromString(string S1)
{
	string S2 = "";
	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
			S2 += S1[i];
	}
	return S2;
}

int main() {

	string Text = "hello world , i'm smail el khattab. what you waiting for !?";
	cout << RemovePauncuationFromString(Text);
	system("pause>0");

}


