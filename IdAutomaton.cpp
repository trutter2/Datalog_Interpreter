//
// Created by Thomas Rutter on 5/4/21.
//

#include "IdAutomaton.h"

void IdAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IdAutomaton::S1(const std::string& input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (isalpha(input[index]) || isdigit(input[index])) {
            inputRead++;
            index++;

        }
        else if (isspace(input[index])){
            break;
        }
    }
}