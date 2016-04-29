#include <iostream>
#include <string>

using namespace std;

string encryption();
string decryption();

int main ()
{
    int choice;
    cout << " Ceasar cipher " <<endl;
    cout << "1.Encryption" << endl;
    cout << "2.Decryption" << endl;
    cout << "Enter your choice : "; cin >> choice; cout <<endl;
    if (choice == 1) cout << "This is your encrypted word: " << encryption();
    else if (choice == 2) cout << "This is your decrypted word: " << decryption();
    else cout  << "That's not a valid choice" ;
    return 0;
}

string encryption()
{
    int number, length;
    string word, encrypted_word;
    cout << "Enter the word you want to encrypt: "; cin >> word;
    cout << "Enter how much letters you want to skip in alphabet: "; cin >> number;
    length = (int)word.length();
    encrypted_word = word;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(encrypted_word[i]))
            {
                word[i] = tolower(word[i]);
                encrypted_word[i] = tolower(encrypted_word[i]);
                for (int ii = 0; ii < number; ii++)
                    {
                        if (encrypted_word[i] == 'z') encrypted_word[i] = 'a';
                        else encrypted_word[i]++;
                    }
            }
    }
    return encrypted_word;
}

string decryption()
{
    int number, length;
    string word, decrypted_word;
    cout << "Enter the word you want to decrypt: "; cin >> word;
    cout << "Enter how much letters were skipped in alphabet: "; cin >> number;
    length = (int)word.length();
    decrypted_word = word;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(decrypted_word[i]))
            {
                word[i] = tolower(word[i]);
                decrypted_word[i] = tolower(decrypted_word[i]);
                for (int ii = 0; ii < number; ii++)
                    {
                        if (decrypted_word[i] == 'a') decrypted_word[i] = 'z';
                        else decrypted_word[i]--;
                    }
            }
    }
    return decrypted_word;
}
