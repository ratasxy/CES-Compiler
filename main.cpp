#include <iostream>
#include "LexicalAnalyzer.h"

using namespace std;

int main() {
    LexicalAnalyzer la("/Users/jsantillana/University/compilers/CES/front.in");

    std::string a;
    la.getLine(a);

    cout << a << endl;

    return 0;
}