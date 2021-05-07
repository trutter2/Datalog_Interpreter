//
// Created by Thomas Rutter on 5/4/21.
//

#include "StringAutomaton.h"


void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    //reads in everything that is not a '
    if ((input[index] != '\'')) {
        if (input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
    //checks for end quote and end of file.
    else if ((index + 1) > (int)(input.size())) {
        Serr();
    }
    //end of the string '
    else if (input[index] == '\'') {
        index++;
        inputRead++;
        S2(input);
    } else {
        Serr();
    }
}


void StringAutomaton::S2(const std::string& input) {
    //double quotes
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
    //complete string. the next character after ' was not another '
    else {
        return;
    }
}