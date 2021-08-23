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

int main(int, char**) {
    
    char c;
    int shift;

    if (
        !limwa::read_value<char>("Please insert a character to encrypt: ", "Please insert a character", c)
        || !limwa::read_value<int>("Please provide a shift for the encryption: ", "Please provide a number", shift)
    )
        return 1;

    cout << endl;
    cout << "The encrypted character is: " << encrypt_character(c, shift) << endl;
}
