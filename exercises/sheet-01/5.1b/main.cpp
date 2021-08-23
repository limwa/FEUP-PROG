#include <iostream>
#include "limwa.h"

using namespace std;

char encrypt_character(char c, int shift) {
    shift %= 26;
    if (shift < 0)
        shift = 26 + shift;

    if (c >= 'A' && c <= 'Z') {
        char letter = c - 'A';
        return ((letter + shift) % 26) + 'A'; 
    } else if (c >= 'a' && c <= 'z') {
        char letter = c - 'a';
        return ((letter + shift) % 26) + 'a';
    } else {
        return c;
    }
}

string encrypt_string(string s, int shift) {
    string res;
    for (size_t i = 0; i < s.length(); i++) {
        res.push_back(encrypt_character(s.at(i), shift));
    }

    return res;
}

int main(int, char**) {
    
    string word;
    int shift;

    if (
        !limwa::read_value<string>("Please insert a word to encrypt: ", "Please insert a word", word)
        || !limwa::read_value<int>("Please provide a shift for the encryption: ", "Please provide a number", shift)
    )
        return 1;

    cout << endl;
    cout << "The encrypted word is: " << encrypt_string(word, shift) << endl;
}
