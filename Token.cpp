#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->type = type;
    this->description = description;
    this->line = line;
}

string Token::toString() {
    // (TYPE,"description",lineNumber)
    string printedToken = "(" + enumToString(type) + "\"" + description + "\"," + to_string(line) + ")";
    return printedToken;
}

string Token::enumToString(TokenType token) {
    switch (token) {
        case COMMA: return "COMMA,"; break;
        case PERIOD: return "PERIOD,"; break;
        case Q_MARK: return "Q_MARK,"; break;
        case LEFT_PAREN: return "LEFT_PAREN,"; break;
        case RIGHT_PAREN: return "RIGHT_PAREN,"; break;
        case COLON: return "COLON,"; break;
        case COLON_DASH: return "COLON_DASH,"; break;
        case MULTIPLY: return "MULTIPLY,"; break;
        case ADD: return "ADD,"; break;
        case SCHEMES: return "SCHEMES,"; break;
        case FACTS: return "FACTS,"; break;
        case RULES: return "RULES,"; break;
        case QUERIES: return "QUERIES,"; break;
        case ID: return "ID,"; break;
        case STRING: return "STRING,"; break;
        case COMMENT: return "COMMENT,"; break;
        case UNDEFINED: return "UNDEFINED,"; break;
        case E_OF_FILE: return "EOF,"; break;
    }
    return ("not found!");
}

bool Token::isComment() {
    if (this->type == COMMENT) {
        return true;
    }
    else {
        return false;
    }
}

string Token::getDescription() {
    return this->description;
}
