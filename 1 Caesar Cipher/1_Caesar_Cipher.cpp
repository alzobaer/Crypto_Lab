#include <iostream>
#include <string>
using namespace std;

string encryptCaesarCipher(string plaintext, int shift) {
    string ciphertext = "";
    
    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';  // Shifting modulo 26 for uppercase
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';  // Shifting modulo 26 for lowercase
        }

        ciphertext += ch;  // Append the encrypted character to the ciphertext
    }
    return ciphertext;
}

string decryptCaesarCipher(string ciphertext, int shift) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';  // Shifting modulo 26 for uppercase
        }
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';  // Shifting modulo 26 for lowercase
        }
        plaintext += ch;  // Append the decrypted character to the plaintext
    }
    return plaintext;
}

int main() {
    string plaintext, ciphertext;
    int shift = 3;  // Caesar Cipher shift (3 positions to the right)

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    ciphertext = encryptCaesarCipher(plaintext, shift);
    cout << "Encrypted Text (Caesar Cipher): " << ciphertext << endl;

    string decryptedText = decryptCaesarCipher(ciphertext, shift);
    cout << "Decrypted Text (Original Plaintext): " << decryptedText << endl;

    return 0;
}
