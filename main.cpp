#include <iostream>
#include <fstream>
#include <sstream>

#include "Lexer.h"
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
    lexer->Print();

    // TODO

    delete lexer;

    return 0;
}