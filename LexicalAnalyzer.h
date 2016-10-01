//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#ifndef CES_LEXICALANALYZER_H
#define CES_LEXICALANALYZER_H

#include <iostream>
#include <vector>
#include "File.h"

class LexicalAnalyzer {
public:
    explicit LexicalAnalyzer(std::string fileName);
    bool getLine(std::string &s);
    bool parse();
    std::vector<std::string> parseLine();
    bool getChar(char &c);
private:
    File * file;
    int lineCount;
    int charCount;
    std::string currentLine;

    enum charType {alphabetic, digit, sum_op, sub_op, mul_op, div_op, assignment_op, not_valid};

    LexicalAnalyzer::charType lookup(char );
};


#endif //CES_LEXICALANALYZER_H
