//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_IDAUTOMATON_H
#define DATALOG_INTERPRETER_IDAUTOMATON_H
#include "Automaton.h"

class IdAutomaton : public Automaton
{
private:
    void S1(const std::string& input);


public:
    IdAutomaton() : Automaton(TokenType::ID) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_IDAUTOMATON_H
