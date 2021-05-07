//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_LINECOMMENTAUTOMATON_H
#define DATALOG_INTERPRETER_LINECOMMENTAUTOMATON_H
#include "Automaton.h"

class LineCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);


public:
    LineCommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_LINECOMMENTAUTOMATON_H
