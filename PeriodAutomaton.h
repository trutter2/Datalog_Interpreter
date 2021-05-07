//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_PERIODAUTOMATON_H
#define DATALOG_INTERPRETER_PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton
{
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};

#endif //DATALOG_INTERPRETER_PERIODAUTOMATON_H
