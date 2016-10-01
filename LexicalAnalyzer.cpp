//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#include "LexicalAnalyzer.h"

bool isDigit(char c){

}

bool isAlphabetic(char c){

}

LexicalAnalyzer::LexicalAnalyzer(std::string fileName) {
    this->file = new File(fileName);
    lineCount = 0;
    charCount = 0;
    currentLine = "";
}

bool LexicalAnalyzer::parse()
{
    while(this->getLine(this->currentLine)){
        lineCount++;
        this->parseLine();
    }
}

std::vector<std::string> LexicalAnalyzer::parseLine()
{
    std::vector<std::string> tokens;
    char c;
    if(getChar(c)) {
        if (lookup(c) == digit || lookup(c) == alphabetic) {
            std::string token = "";
            while (true) {
                token += c;
                lookup(c);
                if (lookup(c) != digit || lookup(c) != alphabetic)
                    break;
            }
            tokens.push_back(token);
        }else{
            std::string token = "";
            token += c;
            tokens.push_back(token);
        }
    }
}

LexicalAnalyzer::charType LexicalAnalyzer::lookup(char c){
    if("+")
        return sum_op;
    else if("-")
        return sub_op;
    else if("*")
        return mul_op;
    else if("/")
        return div_op;
    else if("=")
        return assignment_op;
    else if(isDigit(c))
        return digit;
    else if(isAlphabetic(c))
        return alphabetic;
    else
        return not_valid;
}

bool LexicalAnalyzer::getChar(char &c){
    if(this->charCount >= this->currentLine.size())
        return false;

    c = this->currentLine[this->charCount++];
}

bool LexicalAnalyzer::getLine(std::string &s){
    s = "";

    std::cout << "read" << std::endl;

    char current;

    do{
        if (not this->file->get(current)) {
            return false;
        }

        s += current;
    }while(current != '\n');

    return true;
}