//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#include "File.h"
#include <iostream>

File::File(std::string fileName) {
    std::ifstream file(fileName);
    data = std::string((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

    data += "\n";

    count = 0;
}

bool File::get(char &c) {
    if(count >= data.size())
        return false;

    c = data[count++];

    return true;
}
