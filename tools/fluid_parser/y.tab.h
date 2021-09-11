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
     COMMENT = 258,
     VERSION = 259,
     HEADER_NAME = 260,
     CODE_NAME = 261,
     FUNCTION = 262,
     IDENTIFIER = 263,
     LBRA = 264,
     RBRA = 265,
     RCUR = 266,
     LCUR = 267,
     OPEN = 268,
     CODE = 269,
     SELECTED = 270,
     ANYTHING = 271,
     NON_CURLY = 272,
     INTEGER = 273,
     TYPE = 274,
     VISIBLE = 275,
     XYWH = 276,
     LABEL = 277,
     CALLBACKF = 278,
     LABELSIZE = 279,
     TEXTSIZE = 280,
     ALIGN = 281,
     FLOATR = 282,
     MAXIMUM = 283,
     MINIMUM = 284,
     STEP = 285,
     VALUE = 286,
     BOX = 287,
     DOWN_BOX = 288,
     WHEN = 289,
     RESIZABLE = 290,
     SIZE_RANGE = 291,
     TEXTFONT = 292,
     TOOLTIP = 293,
     CODE0 = 294,
     COLOR = 295,
     LABELCOLOR = 296,
     LABELTYPE = 297,
     SELECTION_COLOR = 298,
     TEXTCOLOR = 299,
     LABELFONT = 300,
     FL_WINDOW = 301,
     FL_BUTTON = 302,
     FL_INPUT = 303,
     FL_VALUE_INPUT = 304,
     FL_BROWSER = 305,
     FL_CHECK_BUTTON = 306,
     FL_TEXT_DISPLAY = 307,
     FL_OUTPUT = 308,
     FL_GROUP = 309
   };
#endif
/* Tokens.  */
#define COMMENT 258
#define VERSION 259
#define HEADER_NAME 260
#define CODE_NAME 261
#define FUNCTION 262
#define IDENTIFIER 263
#define LBRA 264
#define RBRA 265
#define RCUR 266
#define LCUR 267
#define OPEN 268
#define CODE 269
#define SELECTED 270
#define ANYTHING 271
#define NON_CURLY 272
#define INTEGER 273
#define TYPE 274
#define VISIBLE 275
#define XYWH 276
#define LABEL 277
#define CALLBACKF 278
#define LABELSIZE 279
#define TEXTSIZE 280
#define ALIGN 281
#define FLOATR 282
#define MAXIMUM 283
#define MINIMUM 284
#define STEP 285
#define VALUE 286
#define BOX 287
#define DOWN_BOX 288
#define WHEN 289
#define RESIZABLE 290
#define SIZE_RANGE 291
#define TEXTFONT 292
#define TOOLTIP 293
#define CODE0 294
#define COLOR 295
#define LABELCOLOR 296
#define LABELTYPE 297
#define SELECTION_COLOR 298
#define TEXTCOLOR 299
#define LABELFONT 300
#define FL_WINDOW 301
#define FL_BUTTON 302
#define FL_INPUT 303
#define FL_VALUE_INPUT 304
#define FL_BROWSER 305
#define FL_CHECK_BUTTON 306
#define FL_TEXT_DISPLAY 307
#define FL_OUTPUT 308
#define FL_GROUP 309




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

