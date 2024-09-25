#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to read the substitution mapping from sub.txt
unordered_map<string, string> createSubstitutionMapping(const string& filename) {
    unordered_map<string, string> mapping;
    ifstream file(filename);
    if (file.is_open()) {
        string key, value;
        while (file >> key >> value) {
            mapping[key] = value;
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return mapping;
}

// Function to perform substitution cipher
string applyCipher(const string& plaintext, const unordered_map<string, string>& mapping, int blockSize) {
    string cipherText;
    for (size_t i = 0; i < plaintext.size(); i += blockSize) {
        string block = plaintext.substr(i, blockSize);
        if (mapping.find(block) != mapping.end()) {
            cipherText += mapping.at(block);  // Substitute if block is found
        } else {
            cipherText += block;  // Leave unchanged if block not found
        }
    }
    return cipherText;
}

// Function to reverse the substitution cipher
string reverseCipher(const string& ciphertext, const unordered_map<string, string>& mapping, int blockSize) {
    unordered_map<string, string> reverseMapping;
    for (const auto& pair : mapping) {
        reverseMapping[pair.second] = pair.first;  // Reverse the mapping
    }

    string originalText;
    for (size_t i = 0; i < ciphertext.size(); i += blockSize) {
        string block = ciphertext.substr(i, blockSize);
        if (reverseMapping.find(block) != reverseMapping.end()) {
            originalText += reverseMapping[block];  // Reverse substitute if block found
        } else {
            originalText += block;  // Leave unchanged if block not found
        }
    }
    return originalText;
}

// Main function to handle the process
int main() {
    string plaintext;
    int block_size = 3;
    // Read the substitution mapping from sub.txt
    unordered_map<string, string> mapping = createSubstitutionMapping("sub.txt");

    // Read the input text from input.txt
    ifstream inputFile("input.txt");
    
    if (inputFile.is_open()) {
        getline(inputFile, plaintext);  // Read the whole line
        inputFile.close();
    } else {
        cerr << "Unable to open file: input.txt" << endl;
        return 1;
    }

    string encryptedText = applyCipher(plaintext, mapping, block_size);

    string decryptedText = reverseCipher(encryptedText, mapping, block_size);

    // Step 5: Write the result to output.txt
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Encrypted Text: " << encryptedText << endl;
        outputFile << "Decrypted Text: " << decryptedText << endl;
        outputFile.close();
    } else {
        cerr << "Unable to open file: output.txt" << endl;
        return 1;
    }

    cout << "Encryption and Decryption process completed successfully." << endl;
    return 0;
}
