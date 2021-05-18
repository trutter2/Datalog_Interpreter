//
// Created by Thomas Rutter on 5/12/21.
//

#ifndef DATALOG_INTERPRETER_PREDICATE_H
#define DATALOG_INTERPRETER_PREDICATE_H
#include "Parameter.h"
#include <string>
#include <vector>

using namespace std;

class Predicate {
private:
    string id;
    vector<Parameter> parameter;
public:
    Predicate() {};
    ~Predicate() {};

    void setName(string name) {
        id = name;
    }
    void addParameter(string param) {
        //make a parameter from param then push back
        Parameter addParam (param);
        parameter.push_back(addParam);
    }
    string toString() {
        //where the syntax id (param,param)
        string predicate = "";
        predicate = id + "(";
        for (unsigned int i = 0; i < parameter.size(); i++){
            //if last one dont add a ,
            if (i == (parameter.size()-1)){
                predicate = predicate + parameter[i].toString();
            }
            else {
                predicate = predicate + parameter[i].toString() + ",";
            }
        }
        predicate = predicate + ")";

        return predicate;
    }
    void clearParams() {
        parameter.clear();
    }
};
#endif //DATALOG_INTERPRETER_PREDICATE_H
