#include <iostream>
#include <iterator>
#include <map>
#include <regex>

using namespace std;

struct inter {
    string type;
    string second_type;
    string value;
};

class SymTable {
    SymTable *father;

    map<string, inter> variables;

    string colowarn = "\033[1;33m";
    string coloerror = "\033[1;31m";
    string coloinfo = "\033[1;32m";
    string colonorm = "\033[0m";

    bool debug = false;

public:
    SymTable(){
        this->father = nullptr;
    }

    SymTable(SymTable *father){
        this->father = father;
    }

    void insert(string name, string type, string second_type){
        if(this->debug) {
            cout << coloinfo << "Se declara la variable " << name << " del tipo " << type << colonorm << " \n";
        }

        inter noimportant;
        if(this->getType(name, noimportant)){
            cout << coloerror << "La variable " << name << " ya se encuentra declarada y es del tipo " << noimportant.type << colonorm << " \n";
            return;
        }

        inter newd;
        newd.type = type;
        newd.second_type = second_type;
        newd.value = "";
        variables.insert(pair<string, inter>(name, newd));
    }

    bool assign(string name, string value){
        std::map<string,inter>::iterator it;
        it = variables.find(name);

        if(it == variables.end())
            return false;

        it->second.value = value;
        inter tmp = it->second;
        this->variables.erase(it);
        this->variables.insert(pair<string, inter>(name, tmp));
        return true;
    }

    bool assingValue(string name, string value){
        if(this->assign(name, value))
            return true;

        if(this->father != nullptr)
            return this->father->assign(name, value);

        return false;
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
        if(this->debug)
            cout << coloinfo << "Creando ambito" << colonorm << "\n";
        SymTable *newd;
        newd = new SymTable(this);
        return newd;
    }

    SymTable * removeScope(){
        if(this->debug)
            cout << coloinfo << "Eliminando ambito" << colonorm << "\n";
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

        cout << coloerror <<  "ERROR: No se puede detectar el tipo de " << text << colonorm << "\n";
        return 0;
    }

    bool findType(string name, string &type){
        inter p1;
        if(!this->getType(name, p1)){
            type = "error";
            cout << coloerror <<  "ERROR: La variable " << name << " no se encuentra declarada." << colonorm << "\n";
            return false;
        }

        if(p1.value == "")
        {
            cout << colowarn <<  "ADVERTENCIA: La variable " << name << " no ha sido asignada" << colonorm << "\n";
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

        cout << coloerror <<  "ERROR: El valor no es booleano" << colonorm << "\n";
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

        cout << coloerror <<  "ERROR: la operacion es solo para booleanos" << colonorm << "\n";
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
            cout << colowarn <<  "Advertencia: Se convierte int a float" << colonorm << "\n";
            if(t1 == "float")
                return var1;
            return var2;
        }
        if((t1 == "int" && t2 == "string") ||  (t1 == "string" && t2 == "int")){
            cout << coloerror <<  "ERROR: No se puede convertir string a int" << colonorm << "\n";
            return var1;
        }
        if((t1 == "float" && t2 == "string") ||  (t1 == "string" && t2 == "float")){
            cout << coloerror <<  "ERROR: No se puede convertir string a float" << colonorm << "\n";
            return "error";
        }
        if((t1 == "bool" && t2 == "string") ||  (t1 == "string" && t2 == "bool")){
            cout << coloerror <<  "ERROR: No se puede convertir bool a string" << colonorm << "\n";
            return "error";
        }
        if((t1 == "bool" && t2 == "int") ||  (t1 == "int" && t2 == "bool")){
            cout << coloerror <<  "ERROR: No se puede convertir bool a int" << colonorm << "\n";
            return "error";
        }
        if((t1 == "bool" && t2 == "float") ||  (t1 == "string" && t2 == "float")){
            cout << coloerror <<  "ERROR: No se puede convertir bool a flota" << colonorm << "\n";
            return "error";
        }
        if((t1 == "error" || t2 == "error")){
            cout << coloerror <<  "ERROR: Algunos operadores no tienen tipo definifo" << colonorm << "\n";
            return "error";
        }

        cout << coloerror <<  "ERROR: Casteo desconocido" << colonorm << "\n";
        return "error";
    }
};