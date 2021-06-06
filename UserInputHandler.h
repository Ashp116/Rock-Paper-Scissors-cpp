//
// Created by Ashp1 on 6/2/2021.
//

#ifndef UNTITLED_USERINPUTHANDLER_H
#define UNTITLED_USERINPUTHANDLER_H
#include "RPS.h"
using namespace std;

class UserInputHandler {
public:
    void init(RPS myRPS) {
        this->myRPS = myRPS;

        start_screen();
    }

    void start_screen() {
        string Input;
        cout << WELCOME_MESSAGE << endl;
        cout << CHOOSE_MESSAGE << endl;

        cin >> Input;
        this->check(Input);
    }

    void again_screen() {
        string Input;
        cout << CHOOSE_MESSAGE << endl;

        cin >> Input;
        this->check(Input);
    }

    void end_screen() {
        // End Screen
        string choice;
        cout << END_MESSAGE << endl;
        cin >> choice;

        if (toUpperCase(choice) == "NO") {
            cout << THANK_YOU_MESSAGE << endl;
        }
        else if (toUpperCase(choice) == "YES") {
            again_screen();
        }
        else {
            end_screen();
        }
    }

    void check(string Input) {
        bool proceed;
        proceed = false;

        for (int i = 0; i <= Inputs->length(); ++i) {
            if (toUpperCase(Input) == Inputs[i]) {
                proceed = true;
            }
        }

        if (!proceed) {
            // Invalid Choice
            cout << CHOOSE_MESSAGE << endl;
            cin >> Input;
            this->check(Input);
        }
        else {
            // Win Screen
            string BotChoice = myRPS.randomPick();
            cout << BOT_CHOSE_MESSAGE + BotChoice << endl;
            int result = myRPS.calculate(Input , BotChoice);

            if (result == calculateResult.UserWins) {
                cout << USER_WIN_MESSAGE << endl;
            }
            else if (result == calculateResult.BotWins) {
                cout << BOT_WIN_MESSAGE << endl;
            }
            else if (result == calculateResult.Draw) {
                cout << DRAW_MESSAGE << endl;
            }
            else {
                cout << "NULL" << endl;
            }

            end_screen();
        }
    }
private:
    string WELCOME_MESSAGE = "Welcome to Rock Paper Scissors C++ Game!";
    string END_MESSAGE = "Do you want to play again? (yes/no)";
    string THANK_YOU_MESSAGE = "Thank you for playing Rock Paper Scissors C++ Game!!";
    string CHOOSE_MESSAGE = "ROCK, PAPER, or SCISSORS?";
    string BOT_CHOSE_MESSAGE = "I chose ";

    string USER_WIN_MESSAGE = "You Win >:( !";
    string BOT_WIN_MESSAGE = "I Won >:) !";
    string DRAW_MESSAGE = "Draw (T_T)";

    RPS myRPS;
};

#endif //UNTITLED_USERINPUTHANDLER_H
