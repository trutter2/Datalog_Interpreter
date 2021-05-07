//
// Created by Thomas Rutter on 5/4/21.
//

#include "UndefinedStringAutomaton.h"


void UndefinedStringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void UndefinedStringAutomaton::S1(const std::string& input) {
    //reads in everything that is not a '
    if ((input[index] != '\'') && ((index + 1) <= ((int)(input.size())))) {
        if (input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
    //end of the string '
    else if (input[index] == '\'') {
        index++;
        inputRead++;
        S2(input);

    }
}


void UndefinedStringAutomaton::S2(const std::string& input) {
    //double quotes
    if (input[index] == '\'') {
        index++;
        inputRead++;
        S1(input);
    }
    //complete string. the next character after ' was not another ' the string ended.
    else {
        Serr();
    }
}
