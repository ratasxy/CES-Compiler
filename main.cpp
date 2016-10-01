#include <iostream>
#include "LexicalAnalyzer.h"

using namespace std;

int main() {
    LexicalAnalyzer la("/Users/jsantillana/University/compilers/CES/front.in");

    la.parse();

    return 0;
}