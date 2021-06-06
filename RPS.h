//
// Created by Ashp1 on 6/1/2021.
//

#ifndef UNTITLED_RPS_H
#define UNTITLED_RPS_H
#include <string>
#include <iostream>
#include <cstdio>
#include <regex>
#include <algorithm>
#include <math.h>
#include "RPSutils.h"

using namespace std;


class RPS {
public:

    // Converts input to index
    int inputToIndex(std::string input) {
        for (int i = 0; i <= InputsIndex.length; ++i) {
            if (input == InputsIndex.rock.input) {
                return InputsIndex.rock.index;
            }
            else if (input == InputsIndex.scissors.input) {
                return InputsIndex.scissors.index;
            }
            else if (input == InputsIndex.paper.input) {
                return InputsIndex.paper.index;
            }
            else {
                return -1;
            }
        }
    }

    // Converts index to input
    string indexToInput(int index) {
        for (int i = 0; i <= InputsIndex.length; ++i) {
            if (index == InputsIndex.rock.index) {
                return InputsIndex.rock.input;
            }
            else if (index == InputsIndex.scissors.index) {
                return InputsIndex.scissors.input;
            }
            else if (index == InputsIndex.paper.index) {
                return InputsIndex.paper.input;
            }
            else {
                return "Null";
            }
        }
    }

    // Randomly picks RPS
    string randomPick() {
        int index = randomNumber(0,2);
        string input = indexToInput(index);

        if (input == "Null") {
            randomPick();
        }
        else {
            return input;
        }
    }

    // Calculates the winner
    int calculate(string User, string Bot) {
        // Converts User Input to Integers
        int UserIndex = inputToIndex(toUpperCase(User));
        int BotIndex = inputToIndex(toUpperCase(Bot));

        /* Testing Purpose
        cout << UserIndex << endl;
        cout << BotIndex << endl;
        */

        // Brain
        if (UserIndex > BotIndex && (UserIndex - BotIndex) == 1 || (BotIndex - UserIndex) == 2) {
            return calculateResult.UserWins;
        }
        else if (BotIndex > UserIndex && (BotIndex - UserIndex) == 1 || (UserIndex - BotIndex) == 2) {
            return calculateResult.BotWins;
        }
        else if (BotIndex == UserIndex) {
            return calculateResult.Draw;
        }
        else {
            return calculateResult.Null;
        }
    }

private:

    struct Inputs {
        struct rock {
            std::string input;
            int index;
        } rock;

        struct scissors {
            std::string input;
            int index;
        } scissors;

        struct paper {
            std::string input;
            int index;
        } paper;
        int length = 3;
    };

    // Dictionary
    Inputs InputsIndex = {
            .rock =  {.input =  "ROCK", .index =  2},
            .scissors =  {.input = "SCISSORS", .index = 1},
            .paper =  {.input = "PAPER", .index = 0}
    };
};

string Inputs[3] = {"ROCK", "SCISSORS", "PAPER"};

#endif //UNTITLED_RPS_H
