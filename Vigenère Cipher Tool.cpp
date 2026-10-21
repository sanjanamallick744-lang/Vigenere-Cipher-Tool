
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

// Remove non-alphabetic characters from the key
string cleanKey(string key)
{
    string newKey = "";

    for (int i = 0; i < key.length(); i++)
    {
        unsigned char ch = key[i];

        if (isalpha(ch))
            newKey += toupper(ch);
    }

    return newKey;
}

// Perform encryption or decryption
string processCipher(string message, string key, bool encryptMode)
{
    string output = "";
    int keyIndex = 0;

    for (int i = 0; i < message.length(); i++)
    {
        char ch = message[i];

        if (isalpha(static_cast<unsigned char>(ch)))
        {
            char base = isupper(static_cast<unsigned char>(ch))
                        ? 'A' : 'a';

            int textValue = ch - base;
            int shift = key[keyIndex % key.length()] - 'A';

            int result;

            if (encryptMode)
                result = (textValue + shift) % 26;
            else
                result = (textValue - shift + 26) % 26;

            output += char(result + base);
            keyIndex++;
        }
        else
        {
            output += ch;
        }
    }

    return output;
}

// Display the encryption or decryption result
void runCipher(bool encryptMode)
{
    string message, key;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter your message: ";
    getline(cin, message);

    cout << "Enter your key: ";
    getline(cin, key);

    key = cleanKey(key);

    if (key.empty())
    {
        cout << "\nError: Enter at least one alphabet in the key.\n";
        return;
    }

    string result = processCipher(message, key, encryptMode);

    cout << "\n----------------------------------\n";

    if (encryptMode)
        cout << "Encrypted Message: ";
    else
        cout << "Decrypted Message: ";

    cout << result << endl;
    cout << "Key Length: " << key.length() << endl;
    cout << "----------------------------------\n";
}

// Demonstrate a known-key brute-force limitation
void securityInfo()
{
    cout << "\n========== SECURITY INFORMATION ==========\n";
    cout << "Cipher: Vigenere Cipher\n";
    cout << "Type: Polyalphabetic substitution cipher\n";
    cout << "Key: Repeating alphabetic keyword\n";
    cout << "Limitation: Repeating keys can reveal patterns.\n";
    cout << "Note: This is an educational cipher, not modern security.\n";
    cout << "==========================================\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "       VIGENERE CIPHER SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Encrypt Message\n";
        cout << "2. Decrypt Message\n";
        cout << "3. View Cipher Security Info\n";
        cout << "4. Exit\n";
        cout << "------------------------------------\n";
        cout << "Choose an option: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
            case 1:
                runCipher(true);
                break;

            case 2:
                runCipher(false);
                break;

            case 3:
                securityInfo();
                break;

            case 4:
                cout << "\nThank you for using Vigenere Cipher System!\n";
                break;

            default:
                cout << "Invalid choice! Select 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}
