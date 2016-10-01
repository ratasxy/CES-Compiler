//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#ifndef CES_SYMBOLTABLE_H
#define CES_SYMBOLTABLE_H

#include "boost/any.hpp"
#include <unordered_map>
#include <stack>
#include <set>

struct SymbolTableRecord {
    int type;
    int line;
    boost::any value;
};

class SymbolTable {
public:
    explicit SymbolTable();

    void initScope();
    bool addSymbol(const std::string &symbol);
private:
    std::stack<std::set<std::string>> scopes;
    std::unordered_map<std::string, std::stack<SymbolTableRecord>> table;
};


#endif //CES_SYMBOLTABLE_H
