//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_Q_MARKAUTOMATON_H
#define DATALOG_INTERPRETER_Q_MARKAUTOMATON_H
#include "Automaton.h"

class Q_MarkAutomaton : public Automaton
{
public:
    Q_MarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //DATALOG_INTERPRETER_Q_MARKAUTOMATON_H
