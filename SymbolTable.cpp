//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    initScope();
}


void SymbolTable::initScope() {
    scopes.push({});
}

bool SymbolTable::addSymbol(const std::string &symbol) {
    if (scopes.top().find(symbol) != scopes.top().end())
        return false;

    scopes.top().insert(symbol);
    table[symbol].push(SymbolTableRecord{});
    return true;
}