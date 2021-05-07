//
// Created by Thomas Rutter on 5/4/21.
//

#include "BlockCommentAutomaton.h"

void BlockCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void BlockCommentAutomaton::S1(const std::string& input){
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}


void BlockCommentAutomaton::S2(const std::string& input) {
    //if is first char in |#
    if ((input[index] == '|')) {
        if (input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S3(input);

    }
    //we dont care what character
    else {
        if ((index + 1) >= (int)(input.size())) {
            Serr();
            return;
        }
        if (input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }

}

void BlockCommentAutomaton::S3(const std::string& input) {

    if (input[index] == '#') {
        inputRead++;
        return;
    }
    else {
        if (input[index] == '\n'){
            newLines++;
        }
        S2(input);
    }
}
