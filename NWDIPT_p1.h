/*
Nick Spizzirri
10/19/2024
CSC122
*/

// Libraries + Headers
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Functions
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool charMatch(char strChar, char patChar, bool caseSensitive) {
    if (patChar == '?') {
        return true;
    }
    if (!caseSensitive) {
        strChar = tolower(strChar);
        patChar = tolower(patChar);
    }
    return strChar == patChar;
}

int findstuff(string str, char chr, bool caseSensitive, int startPos) {
    if (!caseSensitive) {
        str = toLowerCase(str);
        chr = tolower(chr);
    }
    for (int i = startPos; i < str.length(); i++) {
        if (str[i] == chr) {
            return i;
        }
    }
    return -1;
}

int findstuff(string str, string pattern, bool caseSensitive, int startPos) {
    if (!caseSensitive) {
        str = toLowerCase(str);
        pattern = toLowerCase(pattern);
    }

    int strLen = str.length();
    int patLen = pattern.length();

    for (int i = startPos; i <= strLen; i++) {
        int j = 0;
        int k = i;

        while (j < patLen) {
            if (pattern[j] == '\\') {
                j++;
                if (j < patLen && !charMatch(str[k], pattern[j], caseSensitive)) {
                    break;
                }
            }
            else if (pattern[j] == '*') {
                if (j == patLen - 1) {
                    return i;
                }
                for (int x = k; x <= strLen; x++) {
                    if (findstuff(str.substr(x), pattern.substr(j + 1), caseSensitive, 0) != -1) {
                        return i;
                    }
                }
                break;
            }
            else if (!charMatch(str[k], pattern[j], caseSensitive)) {
                break;
            }

            k++;
            j++;

            if (k > strLen) break;
        }

        if (j == patLen) {
            return i;
        }
    }

    return -1;
}