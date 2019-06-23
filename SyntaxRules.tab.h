/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VARIABLE_NAME = 200,
     DATA_TYPE = 303,
     IF = 201,
     ELSE = 202,
     FOR = 203,
     WHILE = 204,
     BRACKET_START = 101,
     BRACKET_END = 102,
     SBRACKET_START = 105,
     SBRACKET_END = 106,
     PARENTHESIS_START = 103,
     PARENTHESIS_END = 104,
     SUM = 10,
     SUB = 11,
     MUL = 12,
     DIV = 13,
     ASSIGN = 14,
     MINUS = 15,
     MAYUS = 16,
     STRING = 3,
     NUM = 2,
     DECIMAL = 4,
     SEMICOL = 90,
     POINTS = 17,
     FUN = 900,
     COMMA = 305,
     END = 801,
     LOOP = 802,
     RETURN = 803,
     TRUE = 850,
     FALSE = 851,
     AND = 501,
     OR = 502,
     NOT = 503
   };
#endif
/* Tokens.  */
#define VARIABLE_NAME 200
#define DATA_TYPE 303
#define IF 201
#define ELSE 202
#define FOR 203
#define WHILE 204
#define BRACKET_START 101
#define BRACKET_END 102
#define SBRACKET_START 105
#define SBRACKET_END 106
#define PARENTHESIS_START 103
#define PARENTHESIS_END 104
#define SUM 10
#define SUB 11
#define MUL 12
#define DIV 13
#define ASSIGN 14
#define MINUS 15
#define MAYUS 16
#define STRING 3
#define NUM 2
#define DECIMAL 4
#define SEMICOL 90
#define POINTS 17
#define FUN 900
#define COMMA 305
#define END 801
#define LOOP 802
#define RETURN 803
#define TRUE 850
#define FALSE 851
#define AND 501
#define OR 502
#define NOT 503




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

