/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 215 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    10,    11,    12,    28,    29,    33,
      35,    43,    44,    45,    46,    56,    57,    58,    59,    69,
      71,    73,    76,    80,    81,    83,    85,    87,    89,    91,
      93,    95,    97,    99,   102,   103,   105,   107,   109,   111,
     113,   115,   117,   119,   121,   123,   125,   127,   129,   131,
     133,   135,   137,   139,   141,   143,   145,   147,   149,   151,
     153,   155,   157,   159,   161,   163,   166,   168,   171,   174,
     175,   176,   184,   187,   188,   192,   193,   197,   198,   202,
     203,   204,   205,   206,   218,   221,   224,   227,   230,   233,
     236,   239,   241,   244,   246,   247,   248,   249,   250,   262,
     265,   268,   271,   274,   277,   280,   283,   285,   288,   291,
     294
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,     3,     4,     5,     6,    57,    -1,    -1,
      -1,    -1,     7,    12,    58,     8,    59,     9,    10,    60,
      11,    12,    73,    11,    12,    61,    11,    -1,    -1,    63,
      62,    61,    -1,    63,    -1,    14,    12,   114,    11,    12,
      73,    11,    -1,    -1,    -1,    -1,    64,    72,    65,    75,
      66,    12,    73,    11,    71,    -1,    -1,    -1,    -1,    67,
      54,    68,    75,    69,    12,    73,    11,    71,    -1,    27,
      -1,    18,    -1,    12,    11,    -1,    12,    61,    11,    -1,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    -1,    53,    -1,     8,    -1,    74,
      73,    -1,    -1,    13,    -1,    15,    -1,    87,    -1,    78,
      -1,    99,    -1,    81,    -1,    85,    -1,    93,    -1,    92,
      -1,    94,    -1,    95,    -1,   116,    -1,   115,    -1,    97,
      -1,    96,    -1,    98,    -1,   100,    -1,   101,    -1,   102,
      -1,   107,    -1,    83,    -1,   109,    -1,   110,    -1,   111,
      -1,   117,    -1,   113,    -1,   112,    -1,   108,    -1,     8,
      -1,     8,    -1,    12,    11,    -1,     8,    -1,    12,    11,
      -1,   114,    11,    -1,    -1,    -1,    19,    12,     8,    79,
       8,    80,    11,    -1,    19,     8,    -1,    -1,    22,    82,
      77,    -1,    -1,    38,    84,    77,    -1,    -1,    23,    86,
      76,    -1,    -1,    -1,    -1,    -1,    21,    12,    18,    88,
      18,    89,    18,    90,    18,    91,    11,    -1,    29,    70,
      -1,    28,    70,    -1,    30,    70,    -1,    31,    70,    -1,
      25,    18,    -1,    24,    18,    -1,    26,    18,    -1,    20,
      -1,    34,    18,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      36,    12,    18,   103,    18,   104,    18,   105,    18,   106,
      11,    -1,    37,    18,    -1,    45,    18,    -1,    39,    77,
      -1,    40,    18,    -1,    41,    18,    -1,    43,    18,    -1,
      44,    18,    -1,    17,    -1,    17,   114,    -1,    33,     8,
      -1,    32,     8,    -1,    42,     8,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,     7,     7,     9,     9,     9,     9,    12,    12,    12,
      14,    15,    15,    15,    15,    16,    16,    16,    16,    19,
      19,    21,    21,    21,    23,    23,    23,    23,    23,    23,
      23,    23,    23,    25,    25,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    29,    29,    31,    31,    33,    35,
      35,    35,    35,    37,    37,    39,    39,    41,    41,    43,
      43,    43,    43,    43,    45,    47,    49,    51,    53,    55,
      57,    59,    61,    63,    65,    65,    65,    65,    65,    67,
      69,    71,    73,    75,    77,    79,    82,    82,    84,    86,
      88
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "VERSION", "HEADER_NAME",
  "CODE_NAME", "FUNCTION", "IDENTIFIER", "LBRA", "RBRA", "RCUR", "LCUR",
  "OPEN", "CODE", "SELECTED", "ANYTHING", "NON_CURLY", "INTEGER", "TYPE",
  "VISIBLE", "XYWH", "LABEL", "CALLBACKF", "LABELSIZE", "TEXTSIZE",
  "ALIGN", "FLOATR", "MAXIMUM", "MINIMUM", "STEP", "VALUE", "BOX",
  "DOWN_BOX", "WHEN", "RESIZABLE", "SIZE_RANGE", "TEXTFONT", "TOOLTIP",
  "CODE0", "COLOR", "LABELCOLOR", "LABELTYPE", "SELECTION_COLOR",
  "TEXTCOLOR", "LABELFONT", "FL_WINDOW", "FL_BUTTON", "FL_INPUT",
  "FL_VALUE_INPUT", "FL_BROWSER", "FL_CHECK_BUTTON", "FL_TEXT_DISPLAY",
  "FL_OUTPUT", "FL_GROUP", "$accept", "start", "function", "@1", "@2",
  "@3", "blocklist", "@4", "block", "@5", "@6", "@7", "@8", "@9", "@10",
  "number", "subwidgetlist", "widget", "attriblist", "attrib",
  "name_or_empty", "name_or_empty_two", "name_or_empty_three", "type",
  "@11", "@12", "label", "@13", "tooltip", "@14", "callbackf", "@15",
  "xywh", "@16", "@17", "@18", "@19", "minimum", "maximum", "step",
  "value", "textsize", "labelsize", "align", "visible", "when",
  "resizable", "size_range", "@20", "@21", "@22", "@23", "textfont",
  "labelfont", "code0", "color", "labelcolor", "selection_color",
  "textcolor", "non_curly", "down_box", "box", "labeltype", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    58,    59,    60,    57,    62,    61,    61,
      63,    64,    65,    66,    63,    67,    68,    69,    63,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    76,    76,    77,    79,
      80,    78,    78,    82,    81,    84,    83,    86,    85,    88,
      89,    90,    91,    87,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   103,   104,   105,   106,   102,   107,
     108,   109,   110,   111,   112,   113,   114,   114,   115,   116,
     117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     0,     0,     0,    15,     0,     3,     1,
       7,     0,     0,     0,     9,     0,     0,     0,     9,     1,
       1,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     0,
       0,     7,     2,     0,     3,     0,     3,     0,     3,     0,
       0,     0,     0,    11,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     1,     0,     0,     0,     0,    11,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     5,     0,     0,    34,    63,    35,
      36,     0,    91,     0,    73,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,    34,    38,
      40,    55,    41,    37,    43,    42,    44,    45,    49,    48,
      50,    39,    51,    52,    53,    54,    62,    56,    57,    58,
      61,    60,    47,    46,    59,    72,     0,     0,     0,     0,
      89,    88,    90,    20,    19,    85,    84,    86,    87,   109,
     108,    92,     0,    99,     0,   106,   101,     0,   102,   103,
     110,   104,   105,   100,     0,    33,    69,    79,    74,    66,
       0,    78,    94,    76,   107,    68,    11,     0,     0,    67,
       0,     0,     0,     7,     0,     0,    70,    80,    95,     0,
       6,    11,    32,    24,    25,    26,    27,    28,    29,    30,
      31,    12,    16,     0,     0,     0,     0,     8,     0,     0,
      71,    81,    96,     0,    64,     0,    13,    17,     0,     0,
      34,    65,     0,     0,    82,    97,     0,    34,    34,     0,
       0,    10,     0,     0,    83,    98,    23,    23,    11,    14,
      18,    21,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    10,    12,    15,   122,   131,   123,   124,
     148,   162,   125,   149,   163,    85,   179,   141,    47,    48,
     156,   111,    96,    49,   117,   143,    50,    78,    51,    94,
      52,    79,    53,   118,   144,   158,   169,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   120,   145,
     159,   170,    65,    66,    67,    68,    69,    70,    71,    97,
      72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -146
static const yytype_int16 yypact[] =
{
      12,    14,    16,    19,  -146,    13,    18,    15,  -146,  -146,
      20,  -146,    17,    21,  -146,    22,    23,    43,  -146,  -146,
    -146,    -1,  -146,    24,  -146,  -146,    11,    34,    35,   -13,
     -13,   -13,   -13,    26,    30,    36,  -146,    27,    37,  -146,
      40,    41,    42,    53,    52,    71,    72,    80,    43,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,    84,    75,    40,     0,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,    76,  -146,    40,    40,  -146,    85,  -146,  -146,
    -146,  -146,  -146,  -146,    83,  -146,  -146,  -146,  -146,  -146,
      86,  -146,  -146,  -146,  -146,  -146,    -4,    90,    81,  -146,
      82,    89,    91,    92,    -6,   -24,  -146,  -146,  -146,    40,
    -146,    -4,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,    93,    87,    88,    96,  -146,     5,     5,
    -146,  -146,  -146,    97,  -146,    99,  -146,  -146,    95,    98,
      43,  -146,   102,   103,  -146,  -146,   100,    43,    43,   106,
     107,  -146,   110,   111,  -146,  -146,   112,   112,    -5,  -146,
    -146,  -146,   114,  -146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,  -146,  -146,  -146,  -146,  -130,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,    -9,  -145,  -146,   -48,  -146,
     -41,  -146,   -74,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   -92,
    -146,  -146,  -146
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int16 yytable[] =
{
     105,   147,   132,   114,   108,    83,   181,    75,   109,   121,
     121,    76,   110,   154,    84,     1,     4,   155,     3,     6,
     113,    86,    87,    88,     5,     7,    13,     9,    11,    80,
     142,    14,   180,    16,    89,    17,    77,   146,    90,    92,
     133,   134,   135,   136,   137,   138,   139,   140,   182,   -15,
     -15,    18,    81,    82,    91,    93,    19,    95,    20,    98,
      99,   100,    21,    22,    23,    24,    25,    26,    27,    28,
     101,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,   102,
     103,   104,   106,   107,   112,   116,   115,   119,   126,   127,
     128,   129,   130,    -9,   150,   151,   152,   153,   157,   160,
     161,   171,   166,   164,   167,   168,   165,   174,   175,   172,
     173,   176,   177,     0,   178,   183
};

static const yytype_int16 yycheck[] =
{
      48,   131,     8,    95,    78,    18,    11,     8,     8,    14,
      14,    12,    12,     8,    27,     3,     0,    12,     4,     6,
      94,    30,    31,    32,     5,     7,     9,    12,     8,    18,
      54,    10,   177,    11,     8,    12,    12,   129,     8,    12,
      46,    47,    48,    49,    50,    51,    52,    53,   178,    54,
      54,     8,    18,    18,    18,    18,    13,    17,    15,    18,
      18,     8,    19,    20,    21,    22,    23,    24,    25,    26,
      18,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    18,
      18,    11,     8,    18,    18,    12,    11,    11,     8,    18,
      18,    12,    11,    11,    11,    18,    18,    11,   149,    12,
      11,    11,   160,    18,    12,    12,    18,    11,    11,   167,
     168,    11,    11,    -1,    12,    11
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    56,     4,     0,     5,     6,     7,    57,    12,
      58,     8,    59,     9,    10,    60,    11,    12,     8,    13,
      15,    19,    20,    21,    22,    23,    24,    25,    26,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    73,    74,    78,
      81,    83,    85,    87,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   107,   108,   109,   110,   111,
     112,   113,   115,   116,   117,     8,    12,    12,    82,    86,
      18,    18,    18,    18,    27,    70,    70,    70,    70,     8,
       8,    18,    12,    18,    84,    17,    77,   114,    18,    18,
       8,    18,    18,    18,    11,    73,     8,    18,    77,     8,
      12,    76,    18,    77,   114,    11,    12,    79,    88,    11,
     103,    14,    61,    63,    64,    67,     8,    18,    18,    12,
      11,    62,     8,    46,    47,    48,    49,    50,    51,    52,
      53,    72,    54,    80,    89,   104,   114,    61,    65,    68,
      11,    18,    18,    11,     8,    12,    75,    75,    90,   105,
      12,    11,    66,    69,    18,    18,    73,    12,    12,    91,
     106,    11,    73,    73,    11,    11,    11,    11,    12,    71,
      71,    11,    61,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 9 "fluid.y"
    {fprintf(gParserOutput, "--function ");}
    break;

  case 4:
#line 9 "fluid.y"
    {fprintf(gParserOutput, yytext);}
    break;

  case 5:
#line 9 "fluid.y"
    {fprintf(gParserOutput, "()\n");}
    break;

  case 6:
#line 9 "fluid.y"
    {fprintf(gParserOutput, "\n--end\n");}
    break;

  case 7:
#line 12 "fluid.y"
    {fprintf(gParserOutput, "\n");}
    break;

  case 11:
#line 15 "fluid.y"
    {ignoreType=0;widgetType[0]='\0';}
    break;

  case 12:
#line 15 "fluid.y"
    {if (widgetType[0]=='\0'){sprintf(widgetType, yytext);}}
    break;

  case 13:
#line 15 "fluid.y"
    {fprintf(gParserOutput, "do %s= fltk:%s(0,0,0,0,\"\")\n", widgetIdentifier, widgetType);}
    break;

  case 14:
#line 15 "fluid.y"
    {fprintf(gParserOutput, "end\n");}
    break;

  case 15:
#line 16 "fluid.y"
    {ignoreType=0;widgetType[0]='\0';}
    break;

  case 16:
#line 16 "fluid.y"
    {if (widgetType[0]=='\0'){sprintf(widgetType, yytext);}}
    break;

  case 17:
#line 16 "fluid.y"
    {fprintf(gParserOutput, "do %s= fltk:%s(0,0,0,0,\"\")\n", widgetIdentifier, widgetType);}
    break;

  case 18:
#line 16 "fluid.y"
    {fprintf(gParserOutput, "Fl_Group:current(Fl_Group:current():parent())\nend\n");}
    break;

  case 24:
#line 23 "fluid.y"
    {ignoreType=1;sprintf(widgetType, "Fl_Double_Window");}
    break;

  case 63:
#line 27 "fluid.y"
    {fprintf(gParserOutput, "--unknown attribute: %s\n", yytext);}
    break;

  case 64:
#line 29 "fluid.y"
    {sprintf(widgetIdentifier, yytext);}
    break;

  case 65:
#line 29 "fluid.y"
    {sprintf(widgetIdentifier, "widget");}
    break;

  case 66:
#line 31 "fluid.y"
    {sprintf(widgetIdentifier2, yytext);}
    break;

  case 67:
#line 31 "fluid.y"
    {widgetIdentifier2[0]='\0';}
    break;

  case 69:
#line 35 "fluid.y"
    {if (!ignoreType){fprintf(gParserOutput, "%s:type(FLUID_%s_", widgetIdentifier, yytext);}}
    break;

  case 70:
#line 35 "fluid.y"
    {if (!ignoreType){fprintf(gParserOutput, "%s)\n", yytext);}}
    break;

  case 72:
#line 35 "fluid.y"
    {if (!ignoreType){fprintf(gParserOutput, "%s:type(FLUID_%s)\n", widgetIdentifier, yytext);}}
    break;

  case 73:
#line 37 "fluid.y"
    {fprintf(gParserOutput, "%s:label(\"", widgetIdentifier);}
    break;

  case 74:
#line 37 "fluid.y"
    {fprintf(gParserOutput, "\")\n");}
    break;

  case 75:
#line 39 "fluid.y"
    {fprintf(gParserOutput, "%s:tooltip(\"", widgetIdentifier);}
    break;

  case 76:
#line 39 "fluid.y"
    {fprintf(gParserOutput, "\")\n");}
    break;

  case 77:
#line 41 "fluid.y"
    {fprintf(gParserOutput, "%s:callback(", widgetIdentifier);}
    break;

  case 78:
#line 41 "fluid.y"
    {fprintf(gParserOutput, "%s)\n", widgetIdentifier2);}
    break;

  case 79:
#line 43 "fluid.y"
    {rectx=atoi(yytext);}
    break;

  case 80:
#line 43 "fluid.y"
    {recty=atoi(yytext);}
    break;

  case 81:
#line 43 "fluid.y"
    {recth=atoi(yytext);}
    break;

  case 82:
#line 43 "fluid.y"
    {rectw=atoi(yytext);}
    break;

  case 83:
#line 43 "fluid.y"
    {fprintf(gParserOutput, "%s:resize(%d,%d,%d,%d)\n", widgetIdentifier, rectx,recty,recth,rectw);}
    break;

  case 84:
#line 45 "fluid.y"
    {fprintf(gParserOutput, "%s:minimum(%s)\n", widgetIdentifier, yytext);}
    break;

  case 85:
#line 47 "fluid.y"
    {fprintf(gParserOutput, "%s:maximum(%s)\n", widgetIdentifier, yytext);}
    break;

  case 86:
#line 49 "fluid.y"
    {fprintf(gParserOutput, "%s:step(%s)\n", widgetIdentifier, yytext);}
    break;

  case 87:
#line 51 "fluid.y"
    {fprintf(gParserOutput, "%s:value(%s)\n", widgetIdentifier, yytext);}
    break;

  case 88:
#line 53 "fluid.y"
    {fprintf(gParserOutput, "%s:textsize(%s)\n", widgetIdentifier, yytext);}
    break;

  case 89:
#line 55 "fluid.y"
    {fprintf(gParserOutput, "%s:labelsize(%s)\n", widgetIdentifier, yytext);}
    break;

  case 90:
#line 57 "fluid.y"
    {fprintf(gParserOutput, "%s:align(%s)\n", widgetIdentifier, yytext);}
    break;

  case 91:
#line 59 "fluid.y"
    {fprintf(gParserOutput, "--%s:show()\n", widgetIdentifier);}
    break;

  case 92:
#line 61 "fluid.y"
    {fprintf(gParserOutput, "%s:when(%s)\n", widgetIdentifier, yytext);}
    break;

  case 93:
#line 63 "fluid.y"
    {fprintf(gParserOutput, "Fl_Group:current():resizable(%s)\n", widgetIdentifier);}
    break;

  case 94:
#line 65 "fluid.y"
    {rectx=atoi(yytext);}
    break;

  case 95:
#line 65 "fluid.y"
    {recty=atoi(yytext);}
    break;

  case 96:
#line 65 "fluid.y"
    {recth=atoi(yytext);}
    break;

  case 97:
#line 65 "fluid.y"
    {rectw=atoi(yytext);}
    break;

  case 98:
#line 65 "fluid.y"
    {fprintf(gParserOutput, "%s:size_range(%d,%d,%d,%d)\n", widgetIdentifier, rectx,recty,recth,rectw);}
    break;

  case 99:
#line 67 "fluid.y"
    {fprintf(gParserOutput, "%s:textfont(%s)\n", widgetIdentifier, yytext);}
    break;

  case 100:
#line 69 "fluid.y"
    {fprintf(gParserOutput, "%s:labelfont(%s)\n", widgetIdentifier, yytext);}
    break;

  case 101:
#line 71 "fluid.y"
    {fprintf(gParserOutput, "\n");}
    break;

  case 102:
#line 73 "fluid.y"
    {fprintf(gParserOutput, "%s:color(%s)\n", widgetIdentifier, yytext);}
    break;

  case 103:
#line 75 "fluid.y"
    {fprintf(gParserOutput, "%s:labelcolor(%s)\n", widgetIdentifier, yytext);}
    break;

  case 104:
#line 77 "fluid.y"
    {fprintf(gParserOutput, "%s:selection_color(%s)\n", widgetIdentifier, yytext);}
    break;

  case 105:
#line 79 "fluid.y"
    {fprintf(gParserOutput, "%s:textcolor(%s)\n", widgetIdentifier, yytext);}
    break;

  case 108:
#line 84 "fluid.y"
    {fprintf(gParserOutput, "%s:down_box(fltk.FL_%s)\n", widgetIdentifier, yytext);}
    break;

  case 109:
#line 86 "fluid.y"
    {fprintf(gParserOutput, "%s:box(fltk.FL_%s)\n", widgetIdentifier, yytext);}
    break;

  case 110:
#line 88 "fluid.y"
    {fprintf(gParserOutput, "%s:labeltype(fltk.FL_%s)\n", widgetIdentifier, yytext);}
    break;


/* Line 1267 of yacc.c.  */
#line 1874 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 89 "fluid.y"



