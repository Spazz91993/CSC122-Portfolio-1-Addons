/*
Nick Spizzirri
10/19/2024
CSC122
*/

// Libraries + Headers
#include <iostream>
#include <string>
#include "NWDIPT.h"

// Main Space
int main() {
    int choice = 0;
    string theString = "";
    cout << "Hi! Please enter a string to search through: \n" << endl;
    cin >> theString;

    cout << "\nWould you like to search for a... (Enter 1 or 2)\n1. Character\n2. Substring (supports wildcards)\n" << endl;
    cin >> choice;

    bool caseSensitive = true;
    char caseChoice;
    cout << "\nShould the search be case-sensitive? (Y/N): ";
    cin >> caseChoice;
    if (tolower(caseChoice) == 'n') {
        caseSensitive = false;
    }

    int startPos = 0;
    cout << "\nEnter the starting position for the search (default is 0): ";
    cin >> startPos;

    if (choice == 1) {
        char chr = ' ';
        cout << "\nEnter the character to search for: \n" << endl;
        cin >> chr;
        int charIndex = findstuff(theString, chr, caseSensitive, startPos);
        if (charIndex != -1)
            cout << "\nCharacter '" << chr << "' found at index: " << charIndex << endl;
        else
            cout << "\nCharacter '" << chr << "' not found!" << endl;
    }
    else if (choice == 2) {
        string subString = "";
        cout << "\nEnter the substring to search for (supports * and ? wildcards, use \\ to escape * or ?): \n" << endl;
        cin >> subString;
        int charIndex = findstuff(theString, subString, caseSensitive, startPos);
        if (charIndex != -1)
            cout << "\nString '" << subString << "' found at index: " << charIndex << endl;
        else
            cout << "\nString '" << subString << "' not found!" << endl;
    }
    else {
        cout << "\nSorry, your input was not valid. Try again..." << endl;
    }

    return 0;
}