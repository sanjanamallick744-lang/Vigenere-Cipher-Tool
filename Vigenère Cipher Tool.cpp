#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encrypt(string text, string key)
{
    string result = "";
    int j = 0;

    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        if (isalpha(ch))
        {
            char base;

            if (isupper(ch))
                base = 'A';
            else
                base = 'a';

            int textValue = ch - base;
            int keyValue = toupper(key[j % key.length()]) - 'A';

            char encrypted = (textValue + keyValue) % 26 + base;

            result += encrypted;
            j++;
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

string decrypt(string text, string key)
{
    string result = "";
    int j = 0;

    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];

        if (isalpha(ch))
        {
            char base;

            if (isupper(ch))
                base = 'A';
            else
                base = 'a';

            int textValue = ch - base;
            int keyValue = toupper(key[j % key.length()]) - 'A';

            char decrypted = (textValue - keyValue + 26) % 26 + base;

            result += decrypted;
            j++;
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

int main()
{
    int choice;
    string text, key;

    while (true)
    {
        cout << "\n============================\n";
        cout << "     VIGENERE CIPHER TOOL\n";
        cout << "============================\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter message: ";
            getline(cin, text);

            cout << "Enter key: ";
            getline(cin, key);

            if (key.length() == 0)
            {
                cout << "Key cannot be empty!\n";
            }
            else
            {
                cout << "\nEncrypted Message: ";
                cout << encrypt(text, key) << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Enter encrypted message: ";
            getline(cin, text);

            cout << "Enter key: ";
            getline(cin, key);

            if (key.length() == 0)
            {
                cout << "Key cannot be empty!\n";
            }
            else
            {
                cout << "\nDecrypted Message: ";
                cout << decrypt(text, key) << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Program closed.\n";
            break;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
