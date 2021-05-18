//
// Created by Thomas Rutter on 5/12/21.
//

#ifndef DATALOG_INTERPRETER_DATALOGPROGRAM_H
#define DATALOG_INTERPRETER_DATALOGPROGRAM_H

#include <vector>
#include <string>
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <set>

using namespace std;

class DatalogProgram {
private:
    vector<Predicate> schemes;
    vector<Predicate> facts;
    vector<Predicate> queries;
    vector<Rule> rules;
    //declare set of strings called domains
    set<string> domains;
public:
    DatalogProgram() {};
    ~DatalogProgram() {};

    void getScheme();
    void addScheme(Predicate predicateObjectScheme);
    void addFact(Predicate predicateObjectFact);
    void addQuery(Predicate predicateObjectQuery);
    void addRule(Rule ruleObject);
    void addDomain(string newDomain);

    string toString();
};
#endif //DATALOG_INTERPRETER_DATALOGPROGRAM_H
