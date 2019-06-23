//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#include "LexicalAnalyzer.h"

bool isDigit(char c){
    return c >= '0' and c <= '9';
}

bool isAlphabetic(char c){
    return (c >= 'A' and c <= 'Z') or
           (c >= 'a' and c <= 'z') or
           c == '_';
}

LexicalAnalyzer::LexicalAnalyzer(std::string fileName) {
    this->file = new File(fileName);
    lineCount = 0;
    charCount = 0;
    currentLine = "";
}

bool LexicalAnalyzer::parse()
{
    std::ofstream outfile ("lexout.txt");
    std::ofstream outval ("lexvalue.txt");
    std::ofstream outline ("lexline.txt");
    while(this->getLine(this->currentLine)){
        this->lineCount++;
        std::vector<pairsi> tokens = this->parseLine();

        std::vector<pairspairii> tokenst = this->secondParseLine(tokens);

        for(int i=0;i<tokenst.size();i++) {
            std::cout << tokenst[i].first << " - " << tokenst[i].second.first << " - "  << tokenst[i].second.second << std::endl;
            outfile << tokenst[i].second.first << std::endl;
            outval << tokenst[i].first << std::endl;
            outline << tokenst[i].second.second << std::endl;
        }
    }

    outfile.close();
    return true;
}

std::vector<pairspairii> LexicalAnalyzer::secondParseLine(std::vector<pairsi> &tokens){
    std::vector<pairspairii> stokens;

    for(int i=0;i<tokens.size();i++){
        std::string token = tokens[i].first;
        std::smatch sm;
        int line = tokens[i].second;

        if(lookup(token[0]) == digit || lookup(token[0]) == alphabetic || lookup(token[0]) == quotation) {

            if(std::regex_search(token, sm, std::regex("^fun$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(fun, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^end$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(end, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^loop$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(loop, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^true$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(ctrue, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^false$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(cfalse, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^return$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(creturn, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^for$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(ifor, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^while$"))) {
                stokens.push_back(
                        make_pair(token, std::make_pair(iwhile, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^int|float|string|char|bool$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(dataType, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^if$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(cif, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^else$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(celse, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^and$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(cand, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^or$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(cor, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^not$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(cnot, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^[a-zA-Z_]+.*$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(variableName, line))
                );
            }else if(std::regex_search(token, sm, std::regex("^[a-zA-Z_]+.*$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(variableName, line))
                );
            }else if(std::regex_match(token, sm, std::regex("^\".*\"$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(alphanumeric, line))
                );
            }else if(std::regex_match(token, sm, std::regex("^[0-9]+\\.[0-9]+$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(decimal, line))
                );
            }else if(std::regex_match(token, sm, std::regex("^[0-9]+$"))){
                stokens.push_back(
                        make_pair(token, std::make_pair(digit, line))
                );
            }else{
                stokens.push_back(
                        make_pair(token, std::make_pair(not_valid, line))
                );
            }

        }else if(token.size() > 1 && (lookup(token[0]) > 9 && lookup(token[0]) < 20)){
            if(lookup(token[0]) > 9 && lookup(token[0]) < 20){
                if(std::regex_match(token, sm, std::regex("\\+|\\+\\+|\\+=|\\-|\\-\\-|\\-=|\\*|\\*|<<|>>"))){
                    stokens.push_back(
                            make_pair(token, std::make_pair(unary_op, line))
                    );
                }
            }else{
                stokens.push_back(
                        make_pair(token, std::make_pair(not_valid, line))
                );
            }
        }else{
            stokens.push_back(
                    make_pair(token, std::make_pair(lookup(token[0]), line))
            );
        }
    }

    return stokens;
}


std::vector<pairsi> LexicalAnalyzer::parseLine()
{
    charCount = 0;

    std::vector<pairsi> tokens;
    char c;

    while(getChar(c)){
        if (lookup(c) == digit || lookup(c) == alphabetic) {
            std::string token = "";
            while (true) {
                token += c;
                getChar(c);
                lookup(c);
                if (lookup(c) != digit && lookup(c) != alphabetic && lookup(c) != point)
                    break;
            }


            tokens.push_back(std::make_pair(token, this->lineCount));
        }

        if(lookup(c) == quotation){
            std::string token = "";
            while (true) {
                token += c;
                getChar(c);
                lookup(c);
                if (lookup(c) == quotation) {
                    token += c;
                    break;
                }
            }
            tokens.push_back(std::make_pair(token, this->lineCount));
            continue;
        }

        if(lookup(c) > 9 && lookup(c) < 20){
            std::string token = "";
            token += c;
            getChar(c);
            lookup(c);
            if(lookup(c) > 9 && lookup(c) < 20){
                token += c;
                tokens.push_back(std::make_pair(token, this->lineCount));
                continue;
            }else{
                tokens.push_back(std::make_pair(token, this->lineCount));
                this->charCount--;
                continue;
            }
        }

        // Removing space characters
        if(lookup(c) > 79 && lookup(c) < 90)
            continue;

        std::string token = "";
        token += c;
        tokens.push_back(std::make_pair(token, this->lineCount));
    }

    return tokens;
}

LexicalAnalyzer::charType LexicalAnalyzer::lookup(char c){
    if(c == '+')
        return sum_op;
    else if(c == '-')
        return sub_op;
    else if(c =='*')
        return mul_op;
    else if(c == '/')
        return div_op;
    else if(c == ':')
        return points_op;
    else if(c == '=')
        return assignment_op;
    else if(c == '"')
        return quotation;
    else if(c == ';')
        return end_instruction;
    else if(c == '<')
        return minus_op;
    else if(c == '>')
        return mayus_op;
    else if(c == '{')
        return bracket_start;
    else if(c == '}')
        return bracket_end;
    else if(c == '[')
        return sbracket_start;
    else if(c == ']')
        return sbracket_end;
    else if(c == '(')
        return parenthesis_start;
    else if(c == ')')
        return parenthesis_end;
    else if(c == ',')
        return comma;
    else if(c == '.')
        return point;
    else if(c == '\n')
        return end_of_line;
    else if(isDigit(c))
        return digit;
    else if(isAlphabetic(c))
        return alphabetic;
    else if(c == ' ')
        return space;
    else
        return not_valid;
}

bool LexicalAnalyzer::getChar(char &c){
    if(this->charCount >= this->currentLine.size())
        return false;

    c = this->currentLine[this->charCount++];

    return true;
}

bool LexicalAnalyzer::getLine(std::string &s){
    s = "";

    char current;

    do{
        if (not this->file->get(current)) {

            return false;
        }
        s += current;
    }while(current != '\n');

    return true;
}