//
// Created by Thomas Rutter on 5/4/21.
//

#include "PeriodAutomaton.h"


void PeriodAutomaton::S0(const std::string& input) {
    if (input[index] == '.') {
        inputRead = 1;
    }
    else {
        Serr();
    }
}