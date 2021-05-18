#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>
using namespace std;

enum TokenType {
    //grabbing the first thing in this line
    PERIOD,
    COMMA,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    E_OF_FILE,
};



class Token
{
private:
    // TODO: add member variables for information needed by Token
    //what type of token it is
    TokenType type;
    //description
    string description;
    //what line the token is on.
    int line;
    //allow parser private access?
    friend class Parser;
public:
    Token(TokenType type, string description, int line);
    string toString();
    string enumToString(TokenType token);
    string getDescription();
    //take care of comments
    bool isComment();

    // TODO: add other needed methods
};

#endif // TOKEN_H

