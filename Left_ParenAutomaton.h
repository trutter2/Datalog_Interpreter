//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_LEFT_PARENAUTOMATON_H
#define DATALOG_INTERPRETER_LEFT_PARENAUTOMATON_H
#include "Automaton.h"

class Left_ParenAutomaton : public Automaton
{
public:
    Left_ParenAutomaton() : Automaton(TokenType::LEFT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_LEFT_PARENAUTOMATON_H
