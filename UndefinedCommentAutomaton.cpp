//
// Created by Thomas Rutter on 5/4/21.
//

#include "UndefinedCommentAutomaton.h"

void UndefinedCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void UndefinedCommentAutomaton::S1(const std::string& input){
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}


void UndefinedCommentAutomaton::S2(const std::string& input) {
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
        if ((index + 1) > (int)(input.size())) {
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

void UndefinedCommentAutomaton::S3(const std::string& input) {

    if (input[index] == '#') {
        //we recieved a vaild block comment
        Serr();
        return;
    }
    else{
        S2(input);
    }
}
