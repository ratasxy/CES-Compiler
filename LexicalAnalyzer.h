//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#ifndef CES_LEXICALANALYZER_H
#define CES_LEXICALANALYZER_H

#include <iostream>
#include <vector>
#include <regex>
#include "File.h"

typedef std::pair<std::string, int> pairsi;
typedef std::pair<std::string, std::pair<int, int> > pairspairii;

class LexicalAnalyzer {
public:
    explicit LexicalAnalyzer(std::string fileName);
    bool getLine(std::string &s);
    bool parse();
private:
    File * file;
    int lineCount;
    int charCount;
    std::string currentLine;

    enum charType {
        alphabetic=1, digit=2, alphanumeric=3, decimal=4,
        sum_op=10, sub_op=11, mul_op=12, div_op=13, assignment_op=14, minus_op=15, mayus_op=16, points_op=17,
        quotation=50,
        not_valid=60,
        space=80, end_of_line=81,
        end_instruction=90,
        bracket_start = 101, bracket_end=102, parenthesis_start=103, parenthesis_end=104, sbracket_start = 105, sbracket_end=106,
        variableName = 200, cif=201, celse=202, ifor = 203, iwhile=204, iteration=300, control=301, unary_op=302,
        dataType=303, point=304, comma=305, fun=900, end=801, loop=802, creturn=803, ctrue=850, cfalse=851,
        cand=501, cor=502, cnot=503
    };

    LexicalAnalyzer::charType lookup(char );
    std::vector<pairsi> parseLine();
    bool getChar(char &c);
    std::vector<pairspairii> secondParseLine(std::vector<pairsi> &);
};


#endif //CES_LEXICALANALYZER_H
