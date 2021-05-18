//
// Created by Thomas Rutter on 5/11/21.
//

#include "Parser.h"

Parser::Parser(vector<Token*> parseTokens) {
    index = 0;
    tokens = parseTokens;
}
Parser::~Parser() {

}
void Parser::parse() {
    datalogProgram();
}

void Parser::datalogProgram() {
    parseTerminal(SCHEMES);
    parseTerminal(COLON);
    scheme();
    schemeList();
    parseTerminal(FACTS);
    parseTerminal(COLON);
    factList();
    parseTerminal(RULES);
    parseTerminal(COLON);
    ruleList();
    parseTerminal(QUERIES);
    parseTerminal(COLON);
    query();
    queryList();
    parseTerminal(E_OF_FILE);
}
void Parser::schemeList() {
    if (checkTerminal(ID) == true){
        scheme();
        schemeList();
    }
    else {
        //do nothing
    }
}
void Parser::factList() {
    if (checkTerminal(ID) == true){
        fact();
        factList();
    }
    else {
        //do nothing
    }
}
void Parser::ruleList() {
    if (checkTerminal(ID) == true){
        rule();
        ruleList();
    }
    else {
        //do nothing
    }
}
void Parser::queryList(){
    if (checkTerminal(ID) == true){
        query();
        queryList();
    }
    else {
        //do nothing
    }
}
/* -------------------------------------- */
void Parser::scheme() {
    Predicate* predicateObjectScheme = new Predicate;
    //snap(S,N,A,P) id(param,param,param,param)
    parseTerminal(ID);
    predicateObjectScheme->setName(tokens[index - 1]->getDescription());
    parseTerminal(LEFT_PAREN);
    parseTerminal(ID);
    predicateObjectScheme->addParameter(tokens[index - 1]->getDescription());
    idList(predicateObjectScheme);
    parseTerminal(RIGHT_PAREN);
    //add predicate scheme object to list.
    datalogObject.addScheme(*predicateObjectScheme);
}
void Parser::fact() {
    // snap('12345','C. Brown','12 Apple','555-1234'). id(param,param,param,param)
    Predicate* predicateObjectFact = new Predicate;
    parseTerminal(ID);
    predicateObjectFact->setName(tokens[index - 1]->getDescription());
    parseTerminal(LEFT_PAREN);
    parseTerminal(STRING);
    predicateObjectFact->addParameter(tokens[index - 1]->getDescription());
    datalogObject.addDomain(tokens[index - 1]->getDescription());
    stringList(predicateObjectFact);
    parseTerminal(RIGHT_PAREN);
    parseTerminal(PERIOD);
    datalogObject.addFact(*predicateObjectFact);
}
void Parser::rule() {
    Rule* ruleObject = new Rule;
    Predicate* predicateObjectRule = new Predicate;
    //set rule head predicate
    ruleObject->setHead(headPredicate(predicateObjectRule));
    parseTerminal(COLON_DASH);
    predicateObjectRule->clearParams();
    predicate(predicateObjectRule);
    ruleObject->addPredicate(*predicateObjectRule);
    predicateList(predicateObjectRule);
    parseTerminal(PERIOD);
    for (unsigned int i = 0; i < tempPredicates.size(); ++i){
        ruleObject->addPredicate(tempPredicates.at(i));
    }
    tempPredicates.clear();
    datalogObject.addRule(*ruleObject);
    predicateObjectRule->clearParams();

}
void Parser::query() {
    //NameHasID('Snoopy',Id)? id(param,param)?
    Predicate* predicateObjectQuery = new Predicate;
    if(checkTerminal(ID) == true){
        predicate(predicateObjectQuery);
        parseTerminal(Q_MARK);
    }
    datalogObject.addQuery(*predicateObjectQuery);
    predicateObjectQuery->clearParams();
}
/* -------------------------------------- */
Predicate Parser::headPredicate(Predicate* headPredicateObjectScheme){
    parseTerminal(ID);
    headPredicateObjectScheme->setName(tokens[index - 1]->getDescription());
    parseTerminal(LEFT_PAREN);
    parseTerminal(ID);
    headPredicateObjectScheme->addParameter(tokens[index - 1]->getDescription());
    idList(headPredicateObjectScheme);
    parseTerminal(RIGHT_PAREN);
    return *headPredicateObjectScheme;
}
Predicate Parser::predicate(Predicate* predicateObject){
    predicateObject->clearParams();
    parseTerminal(ID);
    predicateObject->setName(tokens[index - 1]->getDescription());
    parseTerminal(LEFT_PAREN);
    parameter(predicateObject);
    parameterList(predicateObject);
    parseTerminal(RIGHT_PAREN);
    return *predicateObject;
}
/* -------------------------------------- */
void Parser::predicateList(Predicate* predicateObject){
    if (checkTerminal(COMMA) == true){
        //only parse if it is a comma
        parseTerminal(COMMA);
        //random vector of predicates.
        tempPredicates.push_back(predicate(predicateObject));
        predicateList(predicateObject);
    }
    else {
       //do nothing
    }

}
void Parser::parameterList(Predicate* addParam){
    if (checkTerminal(COMMA) == true){
        //only parse if it is a comma
        parseTerminal(COMMA);
        parameter(addParam);
        parameterList(addParam);
    }
    else {
        //do nothing
    }
}
void Parser::stringList(Predicate* addString){
    if (checkTerminal(COMMA) == true){
        //only parse if it is a comma
        parseTerminal(COMMA);
        parseTerminal(STRING);
        addString->addParameter(tokens[index - 1]->getDescription());
        //also add string to domains set
        datalogObject.addDomain(tokens[index - 1]->getDescription());
        stringList(addString);
    }
    else {
        //do nothing
    }
}
void Parser::idList(Predicate* addParam){
    if (checkTerminal(COMMA) == true){
        //only parse if it is a comma
        parseTerminal(COMMA);
        parseTerminal(ID);
        addParam->addParameter(tokens[index - 1]->getDescription());
        idList(addParam);
    }
    else {
        //do nothing
    }
}
void Parser::parameter(Predicate* addParam){
    if (checkTerminal(STRING)){
        parseTerminal(STRING);
        addParam->addParameter(tokens[index - 1]->getDescription());
    }
    else if (checkTerminal(ID)){
        parseTerminal(ID);
        addParam->addParameter(tokens[index - 1]->getDescription());
    }
    else {
        throw tokens[index]->toString();
    }
}

void Parser::parseTerminal(TokenType token) {
    if (tokens[index]->type == token) {
        //keep going!
        index++;
    }
    else {
        //if false throw an error;
        throw tokens[index]->toString();
    }
}

bool Parser::checkTerminal(TokenType token) {
    if (tokens[index]->type == token){
        return true;
        //dont move pass;
    }
    else {
        return false;
    }
}