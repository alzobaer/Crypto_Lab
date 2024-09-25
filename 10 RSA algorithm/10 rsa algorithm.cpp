#include <iostream>
#include <cmath>
using namespace std;

// Function to compute modular exponentiation (base^exponent % mod)
long long modExp(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

int main() {
    // RSA parameters
    long long p = 61;
    long long q = 53;
    long long n = p * q; // Modulus
    long long phi = (p - 1) * (q - 1); // Euler's totient function
    long long e = 17; // Public exponent
    long long d = 2753; // Private exponent

    // Plaintext character to encrypt (ASCII value of 'A')
    long long plaintext = 65;

    // Encryption
    long long ciphertext = modExp(plaintext, e, n);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decryption
    long long decryptedText = modExp(ciphertext, d, n);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    // Convert decrypted number back to character
    char decryptedChar = static_cast<char>(decryptedText);
    cout << "Decrypted Character: " << decryptedChar << endl;

    return 0;
}
