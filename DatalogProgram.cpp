//
// Created by Thomas Rutter on 5/12/21.
//

#include "DatalogProgram.h"

string DatalogProgram::toString() {
    //go through all vectors and return strings
    string output = "";
    output = output + "Schemes(" + to_string(schemes.size()) + "):" + '\n';
    for (unsigned int i = 0; i < schemes.size(); i++){
        output = output + '\t' + schemes.at(i).toString();
        output = output + "\n";
    }
    output = output + "Facts(" + to_string(facts.size()) + "):" + '\n';
    for (unsigned int i = 0; i < facts.size(); i++){
        output = output + '\t' + facts.at(i).toString();
        output = output + "." + "\n";
    }
    output = output + "Rules(" + to_string(rules.size()) + "):" + '\n';
    for (unsigned int i = 0; i < rules.size(); i++){
        output = output + '\t' + rules.at(i).toString();
        output = output + "." + "\n";
    }
    output = output + "Queries(" + to_string(queries.size()) + "):" + '\n';
    for (unsigned int i = 0; i < queries.size(); i++){
        output = output + '\t' + queries.at(i).toString();
        output = output + "?" + "\n";
    }
    output = output + "Domain(" + to_string(domains.size()) + "):" + '\n';
    for (auto it = domains.begin(); it != domains.end(); ++it){
        output = output + "\t" + *it + "\n";
    }
    //domains are strings in facts
    return output;
}

void DatalogProgram::addScheme(Predicate predicateObjectScheme) {
    schemes.push_back(predicateObjectScheme);
}
void DatalogProgram::addFact(Predicate predicateObjectFact) {
    facts.push_back(predicateObjectFact);
}
void DatalogProgram::addQuery(Predicate predicateObjectQuery) {
    queries.push_back(predicateObjectQuery);
}
void DatalogProgram::addRule(Rule ruleObject) {
    rules.push_back(ruleObject);
}
void DatalogProgram::addDomain(string newDomain) {
    domains.insert(newDomain);
}

