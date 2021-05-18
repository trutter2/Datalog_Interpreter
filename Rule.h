//
// Created by Thomas Rutter on 5/12/21.
//

#ifndef DATALOG_INTERPRETER_RULE_H
#define DATALOG_INTERPRETER_RULE_H
#include <vector>

#include "Predicate.h"

using namespace std;

class Rule {
private:
    Predicate headPredicate;
    vector<Predicate> predicates;
public:
    Rule() {};
    ~Rule() {};

    string toString(){
        string output = "";
        output = headPredicate.toString() + " :- ";
        for (unsigned int i = 0; i < predicates.size(); ++i){
            if (i == (predicates.size()-1)){
                output = output + predicates.at(i).toString();
            }
            else {
                output = output + predicates.at(i).toString() + ",";
            }
        }
        return output;
    }
    void setHead(Predicate headPredicate) {
        this->headPredicate = headPredicate;
    }
    void addPredicate(Predicate newPredicate) {
        predicates.push_back(newPredicate);
    }
};
#endif //DATALOG_INTERPRETER_RULE_H
