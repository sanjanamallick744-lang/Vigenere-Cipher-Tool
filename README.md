# 🔐 Vigenère Cipher Toolkit

## 📌 About the Project
The **Vigenère Cipher Toolkit** is a C++ cybersecurity mini-project that demonstrates classical cryptography through message encryption and decryption. It uses a keyword-based substitution technique to transform readable text into ciphertext and recover the original message using the same key.

The project also includes additional utilities for file processing, encryption history, and character frequency analysis.

## ✨ Features
- **Message Encryption:** Converts plaintext into ciphertext using a secret key.
- **Message Decryption:** Recovers the original message using the correct key.
- **Key Validation:** Checks that the encryption key contains valid alphabetic characters.
- **Encryption History:** Keeps track of operations performed during the current session.
- **File Processing:** Supports encrypting and decrypting text files.
- **Character Frequency Analysis:** Counts letter occurrences to help examine message patterns.
- **Input Validation:** Handles invalid menu choices and empty inputs.
- **Interactive Menu:** Provides a simple, user-friendly console interface.

## 🛠️ Technologies Used
- **Programming Language:** C++
- **Libraries:** `iostream`, `string`, `cctype`, `fstream`, and other standard C++ libraries as required.
- **Concepts:** Classical Cryptography, String Manipulation, File Handling, Input Validation, and Frequency Analysis.

## ⚙️ How It Works
The Vigenère cipher uses a repeating alphabetic key to determine how far each letter is shifted through the alphabet.

**Encryption formula:**

`C = (P + K) mod 26`

**Decryption formula:**

`P = (C - K + 26) mod 26`

Where:
- `P` = Plaintext letter value
- `C` = Ciphertext letter value
- `K` = Key letter value

Spaces, numbers, and punctuation are preserved rather than encrypted.

## ▶️ How to Run

### 1. Compile the Program
Install a C++ compiler such as GCC or MinGW and run:

```bash
g++ -std=c++11 vigenere_cipher_toolkit.cpp -o vigenere
```

### 2. Execute the Program

**Windows:**
```bash
.\vigenere.exe
```

**Linux:**
```bash
./vigenere
```

## 💻 Example

**Input:**
```text
Message: HELLO WORLD
Key: KEY
```

**Output:**
```text
Encrypted Message: RIJVS UYVJN
```

Decrypting the ciphertext with the same key restores the original message.

## 🎯 Learning Outcomes
- Understanding the fundamentals of classical encryption.
- Implementing encryption and decryption algorithms in C++.
- Applying string operations and modular arithmetic.
- Working with file input/output.
- Understanding basic cryptanalysis through letter frequency analysis.
- Improving programming structure and input validation.

## 🔒 Security Note
The Vigenère cipher is a historical educational cipher and is **not suitable for modern security**. Repeating-key patterns can make it vulnerable to cryptanalysis. Use established, modern cryptographic algorithms for protecting sensitive information.

## 👩‍💻 Author
**Sanjana Mallick**  
B.Tech Computer Science and Information Technology  
Cybersecurity

## 📜 License
This project is intended for educational and learning purposes.
