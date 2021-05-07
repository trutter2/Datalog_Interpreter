#include "Lexer.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "Automaton.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "AddAutomaton.h"
#include "MultiplyAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IdAutomaton.h"
#include "LineCommentAutomaton.h"
#include "BlockCommentAutomaton.h"
#include "StringAutomaton.h"
#include "UndefinedStringAutomaton.h"
#include "UndefinedCommentAutomaton.h"


#include <ctype.h>

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
    for (unsigned int i = 0; i < tokens.size(); i++) {
        delete tokens.at(i);
    }
    automata.clear();
}

void Lexer::CreateAutomata() {
    //order you push in gives precedence.
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new LineCommentAutomaton());
    automata.push_back(new UndefinedCommentAutomaton());
    automata.push_back(new BlockCommentAutomaton());
    automata.push_back(new UndefinedStringAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new IdAutomaton());
    //automata push will need for every automaton
    //Add the other needed automata here
}

void Lexer::Run(std::string& input) {
    //set lineNumber to 1
    int lineNumber = 1;
    if (input.size() == 0) {
        Token* eofToken = new Token(E_OF_FILE,"",lineNumber);
        tokens.push_back(eofToken);
        return;
    }
    // While there are more characters to tokenize
    while (input.size() > 0)
    {
        //set maxRead to 0
        int maxRead = 0;
        //set maxAutomaton to the first automaton in automata
        Automaton* maxAutomaton = automata[0];

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        for(Automaton* automaton: automata) {
            //start returns how many characters matched.
            int inputRead = automaton->Start(input);
                if (inputRead > maxRead) {
                    maxRead = inputRead;
                    maxAutomaton = automaton;
                }
                //once we exit we found biggest automaton (maxAutomaton!)
        }
        //if maxRead is greater than zero create new token and pushback the token on to tokens.
        if (maxRead > 0) {
            //make a description string to set as input
            string description = input.substr(0,maxRead);
            Token* newToken = maxAutomaton->CreateToken(description, lineNumber);
            //increment lineNumber by new line read
            lineNumber = lineNumber + maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        //check for white space.
        else if (isspace(input[0])){
            maxRead = 1;
            if (input[0] == '\n'){
                lineNumber++;
            }
            input.erase(0, maxRead);
            //reset maxread to zero.
            maxRead = 0;
        }

        // No automaton accepted (meaning no matching token)
        else {
            maxRead = 1;
            //create a description string of input using maxRead number of inputs.
            string description = input.substr(0, maxRead);
            Token* newToken = new Token(UNDEFINED,description,lineNumber);
            //increment lineNumber by new line read
            lineNumber = lineNumber + maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        input.erase(0, maxRead);
    }
    //add eof token to all tokens
    Token* eofToken = new Token(E_OF_FILE,"",lineNumber);
    tokens.push_back(eofToken);
}

void Lexer::Print(){
    for(Token* t : tokens){
        cout << t->toString() << endl;
    }
    cout << "Total Tokens = " << tokens.size();
}
