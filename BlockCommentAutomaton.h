//
// Created by Thomas Rutter on 5/4/21.
//

#ifndef DATALOG_INTERPRETER_BLOCKCOMMENTAUTOMATON_H
#define DATALOG_INTERPRETER_BLOCKCOMMENTAUTOMATON_H
#include "Automaton.h"

class BlockCommentAutomaton : public Automaton
{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);


public:
    BlockCommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);
};
#endif //DATALOG_INTERPRETER_BLOCKCOMMENTAUTOMATON_H
