//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef COMMAAUTOMATON_H
#define COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton
{
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif // COMMAAUTOMATON_H
