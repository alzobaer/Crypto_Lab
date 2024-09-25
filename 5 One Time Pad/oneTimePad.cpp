#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

// Function to read file content into a string
string readFile(const string& filename) {
    ifstream file(filename, ios::in);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

// Function to write string content to a file
void writeFile(const string& filename, const string& content) {
    ofstream file(filename, ios::out);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    file << content;
    file.close();
}

// Function to perform XOR encryption/decryption
string xorEncryptDecrypt(const string& text, const string& key) {
    if (text.size() != key.size()) {
        cerr << "Error: Text and key must be of the same length." << endl;
        exit(1);
    }

    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        //result += ((text[i] - 'a') % 26 + (key[i] - 'a') % 26) + 'a';
        result += text[i] ^ key[i];
    }
    return result;
}

// Function to generate a random key of a specific length
string generateRandomKey(size_t length) {
    srand(time(0)); // Seed the random number generator
    string key;
    for (size_t i = 0; i < length; ++i) {
        char c = rand() % 256; // Generate a random character
        key += c;
    }
    return key;
}

int main() {
    // Read plaintext from file
    string plaintext = readFile("plain_text.txt");

    // Generate a random key of the same length as the plaintext
    string key = generateRandomKey(plaintext.size());

    // Encrypt the plaintext
    string ciphertext = xorEncryptDecrypt(plaintext, key);

    // Decrypt the ciphertext
    string decryptedText = xorEncryptDecrypt(ciphertext, key);

    // Output the results
    cout << "Plaintext: " << plaintext << endl;
    cout << "Key (in hexadecimal): ";
    for (char c : key) {
        cout << hex << (int)c << " ";
    }
    cout << endl;
    cout << "Ciphertext (in hexadecimal): ";
    for (char c : ciphertext) {
        cout << hex << (int)c << " ";
    }
    cout << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    // Save results to files
    // writeFile("key.txt", key);
    // writeFile("ciphertext.txt", ciphertext);
    // writeFile("decrypted.txt", decryptedText);

    return 0;
}
