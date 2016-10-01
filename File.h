//
// Created by Juan Alfredo Salas Santillana on 10/1/16.
//

#ifndef CES_FILE_H
#define CES_FILE_H

#include <fstream>
class File {
public:
    explicit File(std::string);
    bool get(char &c);
private:
    std::string data;
    int count;
};


#endif //CES_FILE_H
