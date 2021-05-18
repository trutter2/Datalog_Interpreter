#include <iostream>
#include <fstream>
#include <sstream>

#include "Lexer.h"
#include "Parser.h"

using namespace std;

int main(int argc, char** argv) {
    //should read in a text file from argv[1].
    string line;
    ifstream input(argv[1]);
    stringstream ss;

    if (input.is_open())
    {
        ss << input.rdbuf();
        //the below statement will allow you to see the file
        //cout << ss.str() << endl;
        input.close();
    }
    else cout << "Unable to open file" << endl;


    //creates a lexer object!
    Lexer* lexer = new Lexer();
    //put argv[1] into regular string
    string inputString = ss.str();

    lexer->Run(inputString);

    //let you know if lexer created tokens correctly!
    //cout << "Tokens created successfully!" << endl;

    //creates a parser object! by getting tokens from the lexer
    Parser* parser = new Parser(lexer->GetTokens());

    try {
        parser->parse();
        cout << "Success!" << endl;
        cout << parser->toString();
    }
    catch (string error) {
        cout << "Failure!" << endl;
        cout << "  " << error << endl;
    }
    catch (...){
        cout << "big error. you done messed up big" << endl;
    }






    //this will print out the tokens.
    //lexer->Print();


    delete lexer;
    delete parser;

    return 0;
}