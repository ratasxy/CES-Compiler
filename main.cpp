#include <iostream>
#include "LexicalAnalyzer.h"
#include "SyntaxRules.tab.c"
//#include "SymTable.cpp"

using namespace std;


int main() {
    LexicalAnalyzer la("/Users/jsantillana/University/compiladores/CES-Compiler/front.in");

    cout << "\n\n-----------Ejecutando Lexico----------\n\n";
    la.parse();
    cout << "\n\n-----------Ejecutando Sintactico----------\n\n";
    yyparse();
    cout << "\n\n-----------Fin de compilación-----------\n\n";

//    SymTable *table;
//    table = new SymTable();
//    data pass;
//
//    table->insert("v1", "float", "");
//    table->insert("v2", "int", "");
//    table->insert("v4", "bool", "");
//    table->insert("v5", "int", "");
//    table->insert("v6", "string", "");

//    cout << "Buscando v1: " << table->getType("v1", pass) << " " << pass.type << "\n";
//    cout << "Buscando v3: " << table->getType("v3", pass) << "\n";
//    cout << "Buscando v5: " << table->getType("v5", pass) << " " << pass.type << "\n";
//    cout << "Buscando v6: " << table->getType("v6", pass) << " " << pass.type << "\n";

//    cout << "Resultado: " << table->test_type(200, 200, "v1", "v1") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v3", "v1") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v1", "v3") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v4", "v1") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v1", "v2") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v2", "v2") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v1", "v1") << "\n";
//    cout << "Resultado: " << table->test_type(200, 200, "v1", "v6") << "\n";


    return 0;
}