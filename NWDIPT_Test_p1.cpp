/*
Nick Spizzirri
10/19/2024
CSC122
*/

// Libraries + Headers
#include <iostream>
#include <string>
#include "NWDIPT.h"
#include<cassert>

int findstuff(string str, char chr, bool caseSensitive = true, int startPos = 0);
int findstuff(string str, string pattern, bool caseSensitive = true, int startPos = 0);

int main() {
    assert(findstuff("hello", 'h') == 0);
    assert(findstuff("hello", 'o') == 4);
    assert(findstuff("hello", 'x') == -1);
    assert(findstuff("hello", 'H', true) == -1);
    assert(findstuff("hello", 'H', false) == 0);
    assert(findstuff("hello", 'l', true, 3) == 3);
    assert(findstuff("hello", 'l', true, 4) == -1);
    assert(findstuff("hello world", "hello") == 0);
    assert(findstuff("hello world", "world") == 6);
    assert(findstuff("hello world", "xyz") == -1);
    assert(findstuff("Hello World", "hello", true) == -1);
    assert(findstuff("Hello World", "hello", false) == 0);
    assert(findstuff("hello world", "world", true, 6) == 6);
    assert(findstuff("hello world", "world", true, 7) == -1);
    assert(findstuff("hello world", "h?llo") == 0);
    assert(findstuff("hello world", "w?rld") == 6);
    assert(findstuff("hello world", "h*o") == 0);
    assert(findstuff("hello world", "h*d") == 0);
    assert(findstuff("hello world", "h*world") == 0);
    assert(findstuff("hello world", "*") == 0);
    assert(findstuff("hello world", "*w*o*") == 0);
    assert(findstuff("hello*world", "hello\\*world") == 0);
    assert(findstuff("hello?world", "hello\\?world") == 0);
    assert(findstuff("hello\\world", "hello\\\\world") == 0);
    assert(findstuff("", 'h') == -1);
    assert(findstuff("", "hello") == -1);
    assert(findstuff("hello", "") == 0);
    assert(findstuff("hello", "hello", true, 100) == -1);
    assert(findstuff("a*b", "a\\*b") == 0);
    cout << "All tests passed successfully!" << endl;
}