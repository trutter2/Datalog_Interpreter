//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_UNDEFINEDSTRINGAUTOMATA_H
#define DATALOG_INTERPRETER_UNDEFINEDSTRINGAUTOMATA_H
#include "Automaton.h"

class UndefinedStringAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);


public:
    UndefinedStringAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_UNDEFINEDSTRINGAUTOMATA_H
