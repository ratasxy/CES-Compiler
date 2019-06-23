%{
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

union DATA{
  int num;
  char *str;
};

#define YYSTYPE DATA

ifstream inputFile("lexout.txt");
ifstream valFile("lexvalue.txt");
ifstream lineFile("lexline.txt");

#include "SyntaxRules.tab.h"

int yylex(){
    char tmp[4];
    char tmpval[256];
    char tmpline[8];

    if(!inputFile.getline(tmp, 4)){
        return false;
    }
    valFile.getline(tmpval, 256);

    lineFile.getline(tmpline, 4);


    yylval.num = stoi(tmpline);
    yylval.str = strdup(tmpval);
    cout << stoi(tmp) << "\n";
    return stoi(tmp);
}

void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}
%}

%token VARIABLE_NAME 200
%token DATA_TYPE 303
%token IF 201
%token ELSE 202
%token FOR 203
%token WHILE 204
%token BRACKET_START 101
%token BRACKET_END 102
%token SBRACKET_START 105
%token SBRACKET_END 106
%token PARENTHESIS_START 103
%token PARENTHESIS_END 104
%token SUM 10
%token SUB 11
%token MUL 12
%token DIV 13
%token ASSIGN 14
%token MINUS 15
%token MAYUS 16
%token STRING 3
%token NUM 2
%token DECIMAL 4
%token SEMICOL 90
%token POINTS 17
%token FUN 900
%token COMMA 305
%token END 801
%token LOOP 802
%token RETURN 803
%token TRUE 850
%token FALSE 851
%token AND 501
%token OR 502
%token NOT 503

%%

programa: declarations { cout << "\nFin de programa\n"; } ;

declarations: declarations declarations;
    | decl;
;

decl: funcion
    | global
;

global: declvar;

funcion: FUN VARIABLE_NAME PARENTHESIS_START params PARENTHESIS_END funcion_tipo bloco END;

funcion_tipo:
    | POINTS tipo
;

bloco: bloco bloco
    | line
;

line: declvar | comando;

tipo: tipobase |
    SBRACKET_START SBRACKET_END tipo
;

tipobase: DATA_TYPE;

params:
    | params COMMA params
    | parametro
;

parametro: VARIABLE_NAME POINTS tipo;

declvar: VARIABLE_NAME POINTS tipo;

comando: cmdif | cmdwhile | cmdatrib | cmdreturn | chamada;

cmdif: IF exp bloco cmdelse END;

cmdelse:
    | ELSE IF exp bloco
    | ELSE bloco
;

cmdwhile: WHILE exp bloco LOOP;

cmdatrib: var ASSIGN exp;

chamada: VARIABLE_NAME PARENTHESIS_START listaexp PARENTHESIS_END;

listaexp:
   | exp COMMA exp
   | exp
;

cmdreturn: RETURN exp | RETURN;

var: VARIABLE_NAME | var SBRACKET_START exp SBRACKET_END;

exp: NUM
    | DECIMAL
    | TRUE
    | FALSE
    | var
    | PARENTHESIS_START exp PARENTHESIS_END
    | chamada
    | exp SUM exp { cout << $$.str << " " << $1.str << " " << $3.str << "\n"; }
    | exp SUB exp
    | exp MUL exp
    | exp DIV exp
    | exp MINUS exp
    | exp MAYUS exp
    | exp AND exp
    | exp OR exp
    | NOT exp
    | SUB exp
;