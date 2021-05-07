//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_UNDEFINEDCOMMENTAUTOMATON_H
#define DATALOG_INTERPRETER_UNDEFINEDCOMMENTAUTOMATON_H
#include "Automaton.h"

class UndefinedCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);



public:
    UndefinedCommentAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //DATALOG_INTERPRETER_UNDEFINEDCOMMENTAUTOMATON_H
