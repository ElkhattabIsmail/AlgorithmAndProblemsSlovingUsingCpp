#include <iostream>
#include <string>

using namespace std;

string ReadName() {
    string name;
    cout << "enter your name : ";
    getline(cin, name);
    return name;
}
void PrintName(string name) {
    cout << "your name is " << name << endl;
};

int main() {
    PrintName(ReadName());
    return 0;
}