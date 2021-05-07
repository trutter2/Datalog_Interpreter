//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_ADDAUTOMATON_H
#define DATALOG_INTERPRETER_ADDAUTOMATON_H
#include "Automaton.h"

class AddAutomaton : public Automaton
{
public:
    AddAutomaton() : Automaton(TokenType::ADD) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_ADDAUTOMATON_H
