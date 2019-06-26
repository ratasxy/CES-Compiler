#include <iostream>
#include <iterator>
#include <map>
#include <regex>

using namespace std;

struct inter {
    string type;
    string second_type;
};

class SymTable {
    SymTable *father;

    map<string, inter> variables;

public:
    SymTable(){
        this->father = nullptr;
    }

    SymTable(SymTable *father){
        this->father = father;
    }

    void insert(string name, string type, string second_type){
        cout << "Se declara la variable " << name << " del tipo " << type << " \n";
        inter newd;

        newd.type = type;
        newd.second_type = second_type;
        variables.insert(pair<string, inter>(name, newd));
    }

    bool search(string name, inter &answer){
        std::map<string,inter>::iterator it;
        it = variables.find(name);

        if(it == variables.end())
            return false;

        answer = it->second;
        return true;
    }

    bool getType(string name, inter &answer){
        if(this->search(name, answer))
            return true;

        if(this->father != nullptr)
            return this->father->getType(name, answer);

        return false;
    }

    SymTable * createNewScope(){
        cout << "Creando nuevo scope\n";
        SymTable *newd;
        newd = new SymTable(this);
        return newd;
    }

    SymTable * removeScope(){
        cout << "Terminando nuevo scope\n";
        return this->father;
    }

    int wordToType(string text){
        std::smatch sm;
        if(std::regex_match(text, sm, std::regex("^true$"))) {
            return 850;
        }else if(std::regex_match(text, sm, std::regex("^false$"))){
            return 851;
        }else if(std::regex_search(text, sm, std::regex("^[a-zA-Z_]+.*$"))){
            return 200;
        }else if(std::regex_match(text, sm, std::regex("^\".*\"$"))){
            return 3;
        }else if(std::regex_match(text, sm, std::regex("^[0-9]+\\.[0-9]+$"))){
            return 4;
        }else if(std::regex_match(text, sm, std::regex("^[0-9]+$"))){
            return 2;
        }else if(std::regex_match(text, sm, std::regex("^true$"))){
            return 850;
        }

        cout << "ERROR: No se pudo detectar el tipo para " << text << "\n";
        return 0;
    }

    bool findType(string name, string &type){
        inter p1;
        if(!this->getType(name, p1)){
            type = "error";
            cout << "ERROR: La variable " << name << " no se encuentra declarada.\n";
            return false;
        }

        type = p1.type;
        return true;
    }

    string translate(int v, string var){
        string t;
        if(v == 200){
            this->findType(var, t);
            return t;
        }else{
            if(v == 2)return "int";
            if(v == 4)return "float";
            if(v == 3)return "string";
            if(v == 850)return "bool";
            if(v == 851)return "bool";
        }

        return "error";
    }

    string test_bool(string var1){
        string t1;
        int v1 = this->wordToType(var1);

        t1 = this->translate(v1, var1);

        if(t1 == "bool")
            return var1;

        cout << "ADVERTENCIA: El valor no es boolean\n";
        return "error";
    }

    string test_booleans(string var1, string var2){
        string t1, t2;
        int v1 = this->wordToType(var1);
        int v2 = this->wordToType(var2);

        t1 = this->translate(v1, var1);
        t2 = this->translate(v2, var2);

        if(t1 == "bool" && t2 == "bool")
            return var1;

        cout << "ADVERTENCIA: La operación debe ser con dos booleans\n";
        return "error";
    }

    string test_type(string var1, string var2){
        string t1, t2;
        int v1 = this->wordToType(var1);
        int v2 = this->wordToType(var2);

        t1 = this->translate(v1, var1);
        t2 = this->translate(v2, var2);

        if(t1 == "int" && t2 == "int")return var1;
        if(t1 == "float" && t2 == "float")return var1;
        if(t1 == "string" && t2 == "string")return var1;
        if(t1 == "bool" && t2 == "bool")return var1;
        if((t1 == "int" && t2 == "float") ||  (t1 == "float" && t2 == "int")){
            cout << "ADVERTENCIA: Se convierte int a float\n";
            if(t1 == "float")
                return var1;
            return var2;
        }
        if((t1 == "int" && t2 == "string") ||  (t1 == "string" && t2 == "int")){
            cout << "ERROR: No se puede convertir string a int\n";
            return var1;
        }
        if((t1 == "float" && t2 == "string") ||  (t1 == "string" && t2 == "float")){
            cout << "ERROR: No se puede convertir string a float\n";
            return "error";
        }
        if((t1 == "bool" && t2 == "string") ||  (t1 == "string" && t2 == "bool")){
            cout << "ERROR: No se puede convertir bool a string\n";
            return "error";
        }
        if((t1 == "bool" && t2 == "int") ||  (t1 == "int" && t2 == "bool")){
            cout << "ERROR: No se puede convertir bool a int\n";
            return "error";
        }
        if((t1 == "bool" && t2 == "float") ||  (t1 == "string" && t2 == "float")){
            cout << "ERROR: No se puede convertir bool a float\n";
            return "error";
        }
        if((t1 == "error" || t2 == "error")){
            cout << "ERROR: Alguno de los operandos no tiene tipo definido\n";
            return "error";
        }

        cout << "ERROR: Casteo desconocido\n";
        return "error";
    }
};