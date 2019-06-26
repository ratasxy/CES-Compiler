#include <iostream>
#include "LexicalAnalyzer.h"
#include "SyntaxRules.tab.c"
#include "SymTable.cpp"

using namespace std;


int main() {
//    LexicalAnalyzer la("/Users/jsantillana/University/compiladores/CES-Compiler/front.in");
//
//    cout << "\n\n-----------Ejecutando Lexico----------\n\n";
//    la.parse();
//    cout << "\n\n-----------Ejecutando Sintactico----------\n\n";
//    yyparse();
//    cout << "\n\n-----------Fin de compilación-----------\n\n";

    SymTable *table;
    table = new SymTable();
    data pass;

    table->insert("v1", "float", "");
    table->insert("v2", "int", "");
    table->insert("v4", "int", "");

    table = table->createNewScope();

    table->insert("v5", "int", "");

    table = table->createNewScope();

    table->insert("v6", "string", "");

    cout << "Buscando v1: " << table->getType("v1", pass) << " " << pass.type << "\n";
    cout << "Buscando v3: " << table->getType("v3", pass) << "\n";
    cout << "Buscando v5: " << table->getType("v5", pass) << " " << pass.type << "\n";
    cout << "Buscando v6: " << table->getType("v6", pass) << " " << pass.type << "\n";

    table = table->removeScope();
    cout << "Cerrado ambito\n";

    cout << "Buscando v1: " << table->getType("v1", pass) << " " << pass.type << "\n";
    cout << "Buscando v3: " << table->getType("v3", pass) << "\n";
    cout << "Buscando v5: " << table->getType("v5", pass) << " " << pass.type << "\n";
    cout << "Buscando v6: " << table->getType("v6", pass) << "\n";

    table = table->removeScope();
    cout << "Cerrado ambito\n";

    cout << "Buscando v1: " << table->getType("v1", pass) << " " << pass.type << "\n";
    cout << "Buscando v3: " << table->getType("v3", pass) << "\n";
    cout << "Buscando v5: " << table->getType("v5", pass) << "\n";
    cout << "Buscando v6: " << table->getType("v6", pass) << "\n";
    return 0;
}