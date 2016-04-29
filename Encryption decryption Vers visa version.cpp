#include <iostream>
#include <string>
#include <sstream>
 
using namespace std;
 
string encryption(string text, int key);
string decryption(string text, int key);
 
// sometimes cin behaves weird, reading one line at a time fixes this.
istringstream cin_line() { string line; getline(cin, line); return istringstream(line); }
 
int main ()
{
    int choice, key;
    string text;
    cout << " Ceasar cipher " <<endl;
    cout << "1.Encryption" << endl;
    cout << "2.Decryption" << endl;
    cout << "Enter your choice : ";
    cin_line() >> choice;
    cout << endl;
    if (choice == 1) {
        cout << "Enter the plain text: ";
        getline(cin, text);
        cout << "Enter the key: ";
        cin_line() >> key;
        cout << "This is your encrypted text: " << endl << encryption(text, key) << endl;
    }
    else if (choice == 2) {
        cout << "Enter the cypher text: ";
        getline(cin, text);
        cout << "Enter the key: ";
        cin_line() >> key;
        cout << "This is your decrypted text: " << endl << decryption(text, key) << endl;
    }
    else cout  << "That's not a valid choice" << endl;
    return 0;
}
 
string encryption(string text, int key)
{
    string encrypted_text = text;
    for (int i = 0; i < text.length(); i++)
        if (isalpha(text[i]))
            encrypted_text[i] = (tolower(text[i]) - 'a' + key + 26) % 26 + 'a';
    return encrypted_text;
}
 
string decryption(string text, int key)	//Just uses encryption with a reverse key instead of rewriting whole function for decryption
{
    return encryption(text, -key);
}