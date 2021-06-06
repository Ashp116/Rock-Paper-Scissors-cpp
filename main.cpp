#include <iostream>
#include "RPS.h"
#include "UserInputHandler.h"
using namespace std;

int main() {
    RPS myRPS;
    UserInputHandler UIHandler;
    UIHandler.init(myRPS);
    return 0;
}
