//
// Created by Thomas Rutter on 5/12/21.
//

#ifndef DATALOG_INTERPRETER_PARAMETER_H
#define DATALOG_INTERPRETER_PARAMETER_H
#include <string>
using namespace std;
class Parameter {
private:
    //can be an id or a string or int
    string param;
public:
    Parameter(string param) {
        this->param = param;
    };
    ~Parameter() {};
    string toString() {
        return param;
    }

};
#endif //DATALOG_INTERPRETER_PARAMETER_H
