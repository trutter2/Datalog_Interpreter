//
// Created by Thomas Rutter on 5/4/21.
//

#include "LineCommentAutomaton.h"

void LineCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        if (input[index + 1] == '|') {
            Serr();
            return;
        }
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void LineCommentAutomaton::S1(const std::string& input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        if (input[index] != '\n') {
            inputRead++;
            index++;

        }
        else if (input[index] == '\n'){
            break;
        }
        else {
            Serr();
        }
    }
}