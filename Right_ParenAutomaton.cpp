//
// Created by Thomas Rutter on 5/4/21.
//

#include "Right_ParenAutomaton.h"

void Right_ParenAutomaton::S0(const std::string& input) {
    if (input[index] == ')') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}