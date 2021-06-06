//
// Created by Ashp1 on 6/2/2021.
//

#ifndef UNTITLED_RPSUTILS_H
#define UNTITLED_RPSUTILS_H
#include <string>
#include <iostream>
#include <cstdio>
#include <regex>
#include <algorithm>

using namespace std;

// changes lowercase characters to uppercase characters
string toUpperCase(string myStr) {
    for_each(myStr.begin(), myStr.end(), [](char & c) {
        c = ::toupper(c);
    });
    return myStr;
}

// generates a number randomly with min and max
double randomNumber(int min, int max) {
    if (max == min ) return min;

    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < 5; index++) {
        randomNumber = (rand() % (max + 1)) + min;
    }

    return randomNumber;

}

// struct variable calculate result
struct calculateResult {
    int Null = -1;
    int UserWins = 1;
    int BotWins = 2;
    int Draw = 3;
} calculateResult;

#endif //UNTITLED_RPSUTILS_H
