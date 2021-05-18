//
// Created by Thomas Rutter on 5/11/21.
//

#ifndef DATALOG_INTERPRETER_PARSER_H
#define DATALOG_INTERPRETER_PARSER_H
#pragma once
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"


class Parser {
private:
    vector<Token*> tokens;
    int index;
    DatalogProgram datalogObject;
    vector<Predicate> tempPredicates;
    //different functions to call to edit vector for that scheme

public:
    Parser(vector<Token*> parseTokens);
    ~Parser();


    void parse();
    void parseTerminal(TokenType);
    bool checkTerminal(TokenType);
    //datalog parse();

    //functions for every part of grammar
    //in each function you are either checking for token type or calling a function.
    void datalogProgram();
    void schemeList();
    void factList();
    void ruleList();
    void queryList();

    void scheme();
    void fact();
    void rule();
    void query();

    Predicate headPredicate(Predicate* headPredicateObjectScheme);
    Predicate predicate(Predicate* predicateObject);

    void predicateList(Predicate* predicateObject);
    void parameterList(Predicate* addParam);
    void stringList(Predicate* addString);
    void idList(Predicate* addParam);
    void parameter(Predicate* addParam);

    string toString() {
        return datalogObject.toString();
    }
};

#endif //DATALOG_INTERPRETER_PARSER_H
