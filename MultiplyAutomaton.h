//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_MULTIPLYAUTOMATON_H
#define DATALOG_INTERPRETER_MULTIPLYAUTOMATON_H
#include "Automaton.h"

class MultiplyAutomaton : public Automaton
{
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_MULTIPLYAUTOMATON_H
