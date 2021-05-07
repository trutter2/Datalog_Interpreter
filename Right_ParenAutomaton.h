//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_RIGHT_PARENAUTOMATON_H
#define DATALOG_INTERPRETER_RIGHT_PARENAUTOMATON_H
#include "Automaton.h"

class Right_ParenAutomaton : public Automaton
{
public:
    Right_ParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_RIGHT_PARENAUTOMATON_H
