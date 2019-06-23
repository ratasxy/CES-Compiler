#include <iostream>
#include "LexicalAnalyzer.h"
#include "SyntaxRules.tab.c"

using namespace std;


int main() {
    LexicalAnalyzer la("/Users/jsantillana/University/compiladores/CES-Compiler/front.in");

    cout << "\n\n-----------Ejecutando Lexico----------\n\n";
    la.parse();
    cout << "\n\n-----------Ejecutando Sintactico----------\n\n";
    yyparse();
    cout << "\n\n-----------Fin de compilación-----------\n\n";

    return 0;
}