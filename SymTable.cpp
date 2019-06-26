#include <iostream>
#include <iterator>
#include <map>

using namespace std;

struct data {
    string type;
    string second_type;
};

class SymTable {
    SymTable *father;

    map<string, data> variables;

public:
    SymTable(){
        this->father = nullptr;
    }

    SymTable(SymTable *father){
        this->father = father;
    }

    void insert(string name, string type, string second_type){
        data newd;

        newd.type = type;
        newd.second_type = second_type;
        variables.insert(pair<string, data>(name, newd));
    }

    bool search(string name, data &answer){
        std::map<string,data>::iterator it;
        it = variables.find(name);

        if(it == variables.end())
            return false;

        answer = it->second;
        return true;
    }

    bool getType(string name, data &answer){
        if(this->search(name, answer))
            return true;

        if(this->father != nullptr)
            return this->father->getType(name, answer);

        return false;
    }

    SymTable * createNewScope(){
        SymTable *newd;
        newd = new SymTable(this);
        return newd;
    }

    SymTable * removeScope(){
        return this->father;
    }
};
