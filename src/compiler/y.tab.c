/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "tree.hpp"
// #include "tree.cpp"
#include "MSpace.cpp"
int yylex();
void yyerror(const char*);

#line 83 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Size = 258,
    T_Split = 259,
    T_Merge = 260,
    T_Swap = 261,
    T_Slice = 262,
    T_Reverse = 263,
    T_Balance_split = 264,
    T_Auto_split = 265,
    T_Greedy_split = 266,
    T_Volume = 267,
    T_Has = 268,
    T_Tuple = 269,
    T_For = 270,
    T_In = 271,
    T_Len = 272,
    T_TaskIPoint = 273,
    T_TaskISpace = 274,
    T_TaskParent = 275,
    T_TaskProcessor = 276,
    T_SingleTaskMap = 277,
    T_Reverse_Dimension = 278,
    T_Positive_Dimension = 279,
    T_AOS = 280,
    T_SOA = 281,
    T_Compact = 282,
    T_Align = 283,
    T_Exact = 284,
    T_CPU = 285,
    T_GPU = 286,
    T_IO = 287,
    T_PY = 288,
    T_PROC = 289,
    T_OMP = 290,
    T_SYSMEM = 291,
    T_FBMEM = 292,
    T_RDMEM = 293,
    T_ZCMEM = 294,
    T_SOCKMEM = 295,
    T_VIRTUAL = 296,
    T_SAMENODE = 297,
    T_ANYNODE = 298,
    T_Int = 299,
    T_Bool = 300,
    T_IPoint = 301,
    T_ISpace = 302,
    T_MSpace = 303,
    T_Def = 304,
    T_Return = 305,
    T_True = 306,
    T_False = 307,
    T_Task = 308,
    T_Region = 309,
    T_Layout = 310,
    T_IndexTaskMap = 311,
    T_Print = 312,
    T_Instance = 313,
    T_Collect = 314,
    T_ControlReplicate = 315,
    T_TaskSteal = 316,
    T_Le = 317,
    T_Ge = 318,
    T_Eq = 319,
    T_Ne = 320,
    T_And = 321,
    T_Or = 322,
    T_Identifier = 323,
    T_StringConstant = 324,
    T_IntConstant = 325
  };
#endif
/* Tokens.  */
#define T_Size 258
#define T_Split 259
#define T_Merge 260
#define T_Swap 261
#define T_Slice 262
#define T_Reverse 263
#define T_Balance_split 264
#define T_Auto_split 265
#define T_Greedy_split 266
#define T_Volume 267
#define T_Has 268
#define T_Tuple 269
#define T_For 270
#define T_In 271
#define T_Len 272
#define T_TaskIPoint 273
#define T_TaskISpace 274
#define T_TaskParent 275
#define T_TaskProcessor 276
#define T_SingleTaskMap 277
#define T_Reverse_Dimension 278
#define T_Positive_Dimension 279
#define T_AOS 280
#define T_SOA 281
#define T_Compact 282
#define T_Align 283
#define T_Exact 284
#define T_CPU 285
#define T_GPU 286
#define T_IO 287
#define T_PY 288
#define T_PROC 289
#define T_OMP 290
#define T_SYSMEM 291
#define T_FBMEM 292
#define T_RDMEM 293
#define T_ZCMEM 294
#define T_SOCKMEM 295
#define T_VIRTUAL 296
#define T_SAMENODE 297
#define T_ANYNODE 298
#define T_Int 299
#define T_Bool 300
#define T_IPoint 301
#define T_ISpace 302
#define T_MSpace 303
#define T_Def 304
#define T_Return 305
#define T_True 306
#define T_False 307
#define T_Task 308
#define T_Region 309
#define T_Layout 310
#define T_IndexTaskMap 311
#define T_Print 312
#define T_Instance 313
#define T_Collect 314
#define T_ControlReplicate 315
#define T_TaskSteal 316
#define T_Le 317
#define T_Ge 318
#define T_Eq 319
#define T_Ne 320
#define T_And 321
#define T_Or 322
#define T_Identifier 323
#define T_StringConstant 324
#define T_IntConstant 325

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "parser.y"

    const char* string;
    int intVal;

    class ProgramNode* program;
    class StmtNode* stmt;
    class ProcLstNode* proclst;
    class ProcNode* proc;
    class MemLstNode* memlst;
    class MemNode* mem;
    class ProcCustomNode* proccustom;
    class RegionCustomNode* regioncustom;
    class LayoutCustomNode* layoutcustom;
    class ConstraintsNode* constraints;
    class MemoryCollectNode* memorycollect;
    class ArgTypeNode* argtype;
    class AssignNode* assign;
    class ExprNode* expr;
    class IndexTaskMapNode* indextaskmap;
    class SingleTaskMapNode* singletaskmap;
    class ControlReplicateNode* controlreplicate;
    class TaskStealNode* tasksteal;
    class FuncDefNode* funcdef;
    class ArgLstNode* args;
    class TupleExprNode* exprn;
    class SliceExprNode* sliceexpr;
    class APINode* prop;
    class PrintArgsNode* printargs;
    class PrintNode* printstmt;
    class ReturnNode* returnstmt;
    class FuncStmtsNode* funcstmt;
    class ObjectInvokeNode* objinvoke;
    class InstanceLimitNode* instancelimit;
    class IdentifierLstNode* stringlist;

#line 311 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   637

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  274

#define YYUNDEFTOK  2
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,     2,     2,     2,    81,     2,     2,
      85,    86,    79,    77,    72,    78,    87,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    88,
      75,    71,    76,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    83,     2,    84,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,    90,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   118,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   137,   138,   142,   143,
     144,   147,   148,   152,   156,   160,   161,   165,   166,   170,
     171,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   191,   194,   195,   196,   197,   198,
     202,   203,   204,   205,   206,   210,   211,   215,   216,   219,
     223,   224,   228,   229,   230,   234,   238,   242,   243,   247,
     248,   252,   256,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   298,   299,   300,   301,   304,   305,   308,
     309,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   333,   334,   335,
     336,   337,   338,   342,   343,   347,   348,   352,   353,   354,
     355,   356,   357,   362,   363,   364,   365,   366,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Size", "T_Split", "T_Merge", "T_Swap",
  "T_Slice", "T_Reverse", "T_Balance_split", "T_Auto_split",
  "T_Greedy_split", "T_Volume", "T_Has", "T_Tuple", "T_For", "T_In",
  "T_Len", "T_TaskIPoint", "T_TaskISpace", "T_TaskParent",
  "T_TaskProcessor", "T_SingleTaskMap", "T_Reverse_Dimension",
  "T_Positive_Dimension", "T_AOS", "T_SOA", "T_Compact", "T_Align",
  "T_Exact", "T_CPU", "T_GPU", "T_IO", "T_PY", "T_PROC", "T_OMP",
  "T_SYSMEM", "T_FBMEM", "T_RDMEM", "T_ZCMEM", "T_SOCKMEM", "T_VIRTUAL",
  "T_SAMENODE", "T_ANYNODE", "T_Int", "T_Bool", "T_IPoint", "T_ISpace",
  "T_MSpace", "T_Def", "T_Return", "T_True", "T_False", "T_Task",
  "T_Region", "T_Layout", "T_IndexTaskMap", "T_Print", "T_Instance",
  "T_Collect", "T_ControlReplicate", "T_TaskSteal", "T_Le", "T_Ge", "T_Eq",
  "T_Ne", "T_And", "T_Or", "T_Identifier", "T_StringConstant",
  "T_IntConstant", "'='", "','", "'?'", "':'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'['", "']'", "'('", "')'", "'.'", "';'",
  "'{'", "'}'", "$accept", "Program", "Stmt", "Identifier_star",
  "Identifier_star_num", "Identifier_List", "InstanceLimit",
  "MemoryCollect", "ProcCustom", "RegionCustom", "LayoutCustom",
  "Constraints", "FuncDef", "IndexTaskMap", "SingleTaskMap",
  "ControlReplicate", "TaskSteal", "Assign_Stmt", "Func_Stmts",
  "Func_Stmt", "Return_Stmt", "Print_Stmt", "Print_Args", "ArgLst",
  "ArgLst_", "Expr", "SliceExpr", "ExprN_1", "ExprN", "Prop", "TYPE",
  "ProcLst", "MemLst", "Mem", "Proc", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    61,    44,    63,    58,    60,    62,    43,    45,    42,
      47,    37,    33,    91,    93,    40,    41,    46,    59,   123,
     125
};
# endif

#define YYPACT_NINF (-213)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     240,     7,   -28,   -56,    41,    41,    66,   -75,   -27,    41,
      -4,   -56,   -55,   130,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,    19,    24,    25,
      28,  -213,    27,   -51,    31,   205,   253,  -213,   101,    41,
      49,    51,    54,    73,   100,    78,    72,    41,   -63,   -58,
     205,   253,   182,  -213,  -213,    85,    86,    87,    83,    90,
      93,   114,    21,  -213,  -213,  -213,  -213,  -213,  -213,   -57,
    -213,   -52,  -213,  -213,  -213,   213,   189,   104,   112,   117,
     118,   119,  -213,   120,   121,  -213,  -213,   111,   168,   147,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
     182,   239,   182,   254,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,   155,
     177,   183,   205,  -213,  -213,   274,   274,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,   -64,  -213,  -213,   166,   167,   182,
      63,    63,   308,     5,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   125,   182,
     601,  -213,   169,    21,  -213,  -213,     0,  -213,     1,    56,
      79,   182,   171,  -213,  -213,    48,   182,  -213,   182,  -213,
     503,   503,   516,   516,   490,   464,   334,   503,   503,   477,
     477,    63,    63,    63,   182,   360,   172,    65,   412,    46,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   -44,   195,   274,
    -213,  -213,  -213,  -213,  -213,  -213,  -213,   561,  -213,  -213,
    -213,   412,  -213,   197,   412,   412,   182,   412,   182,  -213,
     182,  -213,  -213,   182,  -213,   174,  -213,  -213,  -213,  -213,
    -213,   196,   212,   232,   233,   234,   235,   290,   438,   412,
     412,   281,  -213,  -213,  -213,  -213,  -213,  -213,  -213,  -213,
     182,  -213,   386,  -213
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     7,     8,     4,     5,     6,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
      16,    17,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     3,     0,     0,     0,     0,     0,
       0,     0,    69,   143,   144,   145,   146,   147,   148,     0,
     133,     0,    18,    20,    19,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,    55,    56,     0,     0,     0,
     137,   138,   139,   140,   141,   142,    93,    94,    95,    92,
       0,    90,     0,     0,    98,    97,    52,    53,    54,    21,
      50,    51,    22,   127,   128,   129,   130,   131,   132,     0,
      70,     0,     0,    25,    26,     0,     0,    31,    31,    47,
      48,    49,    45,    46,     0,    23,    24,     0,     0,     0,
      91,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,     0,     0,    71,   134,     0,   135,     0,     0,
       0,     0,     0,    57,    58,     0,     0,    80,     0,    96,
      82,    81,    83,    84,    86,    85,     0,    79,    78,    73,
      74,    75,    76,    77,   106,   107,     0,     0,   107,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,    99,     0,     0,     0,
      28,    27,    32,    33,    34,    35,    36,     0,    37,    30,
      29,    68,    66,     0,   109,   110,     0,   104,   105,    88,
       0,    89,    87,     0,    62,     0,    60,    63,    64,    72,
     136,     0,     0,     0,     0,     0,     0,     0,   100,   103,
     108,     0,    44,    61,    39,    41,    42,    43,    38,    40,
       0,    65,     0,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -213,  -213,   309,    23,  -213,   191,  -213,  -213,  -213,  -213,
    -213,   198,  -213,  -213,  -213,  -213,  -213,  -212,  -213,    91,
    -213,  -210,  -213,  -213,  -213,  -100,  -213,   164,  -213,  -213,
     165,   302,   214,   -65,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    32,    75,    33,    15,    16,    17,    18,
      19,   169,    20,    21,    22,    23,    24,    25,   245,   246,
     247,    26,   134,   119,   120,   103,   196,   197,   143,   216,
     121,    69,   166,   104,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   141,   142,    70,    70,   244,   243,   248,   171,    58,
      45,   128,    30,     7,    61,   122,    52,    60,    87,    88,
     122,    61,   172,    31,    12,    85,    35,    38,    39,    43,
      86,   123,    47,   244,    50,   248,   124,    27,    28,   175,
      34,    46,    29,   126,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   195,   198,
     167,   167,    76,   233,    48,   113,   114,   115,   116,   117,
      84,   231,   219,   219,   118,    30,   234,   178,   235,   222,
     223,   224,   225,   226,   227,   228,    31,    55,   220,   221,
     165,   179,    56,    57,   237,    59,    40,    41,   125,   127,
      58,    42,   222,   223,   224,   225,   226,   227,   228,    37,
     144,   145,   146,   147,   148,   149,    62,    77,   240,    78,
      31,   150,    79,   151,   152,   153,   154,   155,   156,   157,
      53,   158,   242,   159,    30,   160,   258,   240,   259,    89,
     260,    80,    83,   261,   229,    31,   158,    82,   159,   241,
     160,   109,     1,   137,   250,    63,    64,    65,    66,    67,
      68,    90,    91,    92,    93,    94,    95,   230,    81,    72,
     272,    73,    61,   106,   107,   108,    96,    97,   110,     2,
      74,   111,   112,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   129,    98,    36,    99,    89,    44,    12,   194,
     130,    49,    51,   100,   101,   131,   132,   133,   135,   136,
     102,   138,    63,    64,    65,    66,    67,    68,    90,    91,
      92,    93,    94,    95,   243,    90,    91,    92,    93,    94,
      95,     7,   139,    96,    97,    63,    64,    65,    66,    67,
      68,   162,    12,    63,    64,    65,    66,    67,    68,   163,
      98,   164,    99,    89,   173,   174,   239,    37,   217,   232,
     100,   101,     1,   249,   262,   257,   264,   102,    31,    63,
      64,    65,    66,    67,    68,    90,    91,    92,    93,    94,
      95,    37,   265,    63,    64,    65,    66,    67,    68,     2,
      96,    97,    31,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   266,   267,   268,   269,   270,    98,    12,    99,
      90,    91,    92,    93,    94,    95,   144,   145,   146,   147,
     148,   149,    54,   199,   102,    61,   170,   150,   218,   151,
     152,   153,   154,   155,   156,   157,   263,   158,    71,   159,
     168,   160,   161,   144,   145,   146,   147,   148,   149,     0,
       0,     0,     0,     0,   150,     0,   151,   152,   153,   154,
     155,   156,   157,     0,   158,     0,   159,     0,   160,   271,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
     176,   150,     0,   151,   152,   153,   154,   155,   156,   157,
       0,   158,     0,   159,   177,   160,   144,   145,   146,   147,
     148,   149,     0,     0,     0,     0,     0,   150,   236,   151,
     152,   153,   154,   155,   156,   157,     0,   158,     0,   159,
       0,   160,   144,   145,   146,   147,   148,   149,     0,     0,
       0,     0,     0,   150,   238,   151,   152,   153,   154,   155,
     156,   157,     0,   158,     0,   159,     0,   160,   144,   145,
     146,   147,   148,   149,     0,     0,     0,     0,     0,   150,
       0,   151,   152,   153,   154,   155,   156,   157,     0,   158,
       0,   159,   273,   160,   144,   145,   146,   147,   148,   149,
       0,     0,     0,     0,     0,   150,     0,   151,   152,   153,
     154,   155,   156,   157,     0,   158,     0,   159,     0,   160,
     144,   145,   146,   147,   148,   149,     0,     0,     0,     0,
       0,     0,     0,   151,   152,   153,   154,   155,   156,   157,
       0,   158,     0,   159,     0,   160,   144,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   157,     0,   158,     0,   159,
       0,   160,   144,   145,   146,   147,   155,   156,   157,     0,
     158,     0,   159,     0,   160,   151,   152,   153,   154,   155,
     156,   157,     0,   158,     0,   159,     0,   160,   144,   145,
     153,   154,   155,   156,   157,     0,   158,     0,   159,     0,
     160,   151,   152,   153,   154,   155,   156,   157,     0,   158,
       0,   159,     0,   160,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,     0,     0,   211,   212,
     213,   214,   215,   251,   252,   253,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,   256
};

static const yytype_int16 yycheck[] =
{
     100,   101,   102,    35,    36,   217,    50,   217,    72,    72,
      85,    76,    68,    57,    72,    72,    71,    68,    50,    51,
      72,    72,    86,    79,    68,    88,     3,     4,     5,     6,
      88,    88,     9,   245,    11,   245,    88,    30,    31,   139,
      68,    68,    35,    75,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     125,   126,    39,    15,    68,    44,    45,    46,    47,    48,
      47,   171,    72,    72,    53,    68,   176,    72,   178,    23,
      24,    25,    26,    27,    28,    29,    79,    68,    88,    88,
     122,    86,    68,    68,   194,    68,    30,    31,    75,    76,
      72,    35,    23,    24,    25,    26,    27,    28,    29,    68,
      62,    63,    64,    65,    66,    67,    85,    68,    72,    68,
      79,    73,    68,    75,    76,    77,    78,    79,    80,    81,
       0,    83,    86,    85,    68,    87,   236,    72,   238,    14,
     240,    68,    70,   243,    88,    79,    83,    69,    85,    84,
      87,    68,    22,    42,   219,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    88,    68,    68,
     270,    70,    72,    88,    88,    88,    51,    52,    88,    49,
      79,    88,    68,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    88,    68,     3,    70,    14,     6,    68,    74,
      88,    10,    11,    78,    79,    88,    88,    88,    88,    88,
      85,    43,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    50,    36,    37,    38,    39,    40,
      41,    57,    85,    51,    52,    30,    31,    32,    33,    34,
      35,    86,    68,    30,    31,    32,    33,    34,    35,    72,
      68,    68,    70,    14,    88,    88,    84,    68,    89,    88,
      78,    79,    22,    68,    90,    68,    70,    85,    79,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    68,    70,    30,    31,    32,    33,    34,    35,    49,
      51,    52,    79,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    70,    70,    70,    70,    16,    68,    68,    70,
      36,    37,    38,    39,    40,    41,    62,    63,    64,    65,
      66,    67,    13,   159,    85,    72,   128,    73,   163,    75,
      76,    77,    78,    79,    80,    81,   245,    83,    36,    85,
     126,    87,    88,    62,    63,    64,    65,    66,    67,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    81,    -1,    83,    -1,    85,    -1,    87,    88,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      72,    73,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    -1,    85,    86,    87,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    -1,    85,
      -1,    87,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    85,    -1,    87,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,    85,    86,    87,    62,    63,    64,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    76,    77,
      78,    79,    80,    81,    -1,    83,    -1,    85,    -1,    87,
      62,    63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      -1,    83,    -1,    85,    -1,    87,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    -1,    85,
      -1,    87,    62,    63,    64,    65,    79,    80,    81,    -1,
      83,    -1,    85,    -1,    87,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    85,    -1,    87,    62,    63,
      77,    78,    79,    80,    81,    -1,    83,    -1,    85,    -1,
      87,    75,    76,    77,    78,    79,    80,    81,    -1,    83,
      -1,    85,    -1,    87,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    20,    21,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    49,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    68,    92,    93,    97,    98,    99,   100,   101,
     103,   104,   105,   106,   107,   108,   112,    30,    31,    35,
      68,    79,    94,    96,    68,    94,    96,    68,    94,    94,
      30,    31,    35,    94,    96,    85,    68,    94,    68,    96,
      94,    96,    71,     0,    93,    68,    68,    68,    72,    68,
      68,    72,    85,    30,    31,    32,    33,    34,    35,   122,
     125,   122,    68,    70,    79,    95,    94,    68,    68,    68,
      68,    68,    69,    70,    94,    88,    88,   125,   125,    14,
      36,    37,    38,    39,    40,    41,    51,    52,    68,    70,
      78,    79,    85,   116,   124,   125,    88,    88,    88,    68,
      88,    88,    68,    44,    45,    46,    47,    48,    53,   114,
     115,   121,    72,    88,    88,    94,   125,    94,   124,    88,
      88,    88,    88,    88,   113,    88,    88,    42,    43,    85,
     116,   116,   116,   119,    62,    63,    64,    65,    66,    67,
      73,    75,    76,    77,    78,    79,    80,    81,    83,    85,
      87,    88,    86,    72,    68,   125,   123,   124,   123,   102,
     102,    72,    86,    88,    88,   116,    72,    86,    72,    86,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,    74,   116,   117,   118,   116,   118,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    17,    18,    19,    20,    21,   120,    89,   121,    72,
      88,    88,    23,    24,    25,    26,    27,    28,    29,    88,
      88,   116,    88,    15,   116,   116,    74,   116,    74,    84,
      72,    84,    86,    50,   108,   109,   110,   111,   112,    68,
     124,    62,    63,    64,    65,    75,    76,    68,   116,   116,
     116,   116,    90,   110,    70,    70,    70,    70,    70,    70,
      16,    88,   116,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94,    95,    95,
      95,    96,    96,    97,    98,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   106,   106,   107,   107,   108,
     109,   109,   110,   110,   110,   111,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     124,   124,   124,   125,   125,   125,   125,   125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     4,     4,     6,     6,     6,
       6,     0,     2,     2,     2,     2,     2,     2,     4,     4,
       4,     4,     4,     4,     8,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     3,     5,     5,     4,
       1,     2,     1,     1,     1,     3,     6,     0,     3,     0,
       1,     2,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     4,
       1,     2,     1,     1,     1,     1,     3,     1,     1,     3,
       5,     2,     8,     3,     2,     2,     1,     1,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 117 "parser.y"
                        { root = new ProgramNode(); root->stmt_list.push_back((yyvsp[0].stmt)); (yyval.program) = root; }
#line 1765 "y.tab.c"
    break;

  case 3:
#line 118 "parser.y"
                        { (yyvsp[-1].program)->stmt_list.push_back((yyvsp[0].stmt)); (yyval.program) = (yyvsp[-1].program); }
#line 1771 "y.tab.c"
    break;

  case 4:
#line 122 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].proccustom); }
#line 1777 "y.tab.c"
    break;

  case 5:
#line 123 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].regioncustom); }
#line 1783 "y.tab.c"
    break;

  case 6:
#line 124 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].layoutcustom); }
#line 1789 "y.tab.c"
    break;

  case 7:
#line 125 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].instancelimit); }
#line 1795 "y.tab.c"
    break;

  case 8:
#line 126 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].memorycollect); }
#line 1801 "y.tab.c"
    break;

  case 9:
#line 127 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].funcdef); }
#line 1807 "y.tab.c"
    break;

  case 10:
#line 128 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].indextaskmap); }
#line 1813 "y.tab.c"
    break;

  case 11:
#line 129 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].singletaskmap); }
#line 1819 "y.tab.c"
    break;

  case 12:
#line 130 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].controlreplicate); }
#line 1825 "y.tab.c"
    break;

  case 13:
#line 131 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].tasksteal); }
#line 1831 "y.tab.c"
    break;

  case 14:
#line 132 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].assign); }
#line 1837 "y.tab.c"
    break;

  case 15:
#line 133 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].printstmt); }
#line 1843 "y.tab.c"
    break;

  case 16:
#line 137 "parser.y"
                    { (yyval.string) = (yyvsp[0].string); }
#line 1849 "y.tab.c"
    break;

  case 17:
#line 138 "parser.y"
                    { (yyval.string) = "*"; }
#line 1855 "y.tab.c"
    break;

  case 18:
#line 142 "parser.y"
                    { (yyval.string) = (yyvsp[0].string); }
#line 1861 "y.tab.c"
    break;

  case 19:
#line 143 "parser.y"
                    { (yyval.string) = "*"; }
#line 1867 "y.tab.c"
    break;

  case 20:
#line 144 "parser.y"
                    { char s[8]; sprintf(s,"%d", (yyvsp[0].intVal)); (yyval.string) = s; }
#line 1873 "y.tab.c"
    break;

  case 21:
#line 147 "parser.y"
                                     { (yyval.stringlist) = new IdentifierLstNode((yyvsp[-2].string), (yyvsp[0].string)); }
#line 1879 "y.tab.c"
    break;

  case 22:
#line 148 "parser.y"
                                     { (yyvsp[-2].stringlist)->append((yyvsp[0].string)); }
#line 1885 "y.tab.c"
    break;

  case 23:
#line 152 "parser.y"
                                              { (yyval.instancelimit) = new InstanceLimitNode((yyvsp[-2].string), (yyvsp[-1].intVal)); }
#line 1891 "y.tab.c"
    break;

  case 24:
#line 156 "parser.y"
                                                  { (yyval.memorycollect) = new MemoryCollectNode((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 1897 "y.tab.c"
    break;

  case 25:
#line 160 "parser.y"
                                         { (yyval.proccustom) = new ProcCustomNode((yyvsp[-2].string), (yyvsp[-1].proclst)); }
#line 1903 "y.tab.c"
    break;

  case 26:
#line 161 "parser.y"
                                         { (yyval.proccustom) = new ProcCustomNode((yyvsp[-2].stringlist), (yyvsp[-1].proclst)); }
#line 1909 "y.tab.c"
    break;

  case 27:
#line 165 "parser.y"
                                                                 { (yyval.regioncustom) = new RegionCustomNode((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-2].proc), (yyvsp[-1].memlst)); }
#line 1915 "y.tab.c"
    break;

  case 28:
#line 166 "parser.y"
                                                                             { assert(strcmp((yyvsp[-2].string), "*") == 0); (yyval.regioncustom) = new RegionCustomNode((yyvsp[-4].string), (yyvsp[-3].string), new ProcNode(ALLPROC), (yyvsp[-1].memlst)); }
#line 1921 "y.tab.c"
    break;

  case 29:
#line 170 "parser.y"
                                                                   { (yyval.layoutcustom) = new LayoutCustomNode((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-2].mem), (yyvsp[-1].constraints)); }
#line 1927 "y.tab.c"
    break;

  case 30:
#line 171 "parser.y"
                                                                               { assert(strcmp((yyvsp[-2].string), "*") == 0); (yyval.layoutcustom) = new LayoutCustomNode((yyvsp[-4].string), (yyvsp[-3].string), new MemNode(ALLMEM), (yyvsp[-1].constraints)); }
#line 1933 "y.tab.c"
    break;

  case 31:
#line 175 "parser.y"
                                            { (yyval.constraints) = new ConstraintsNode(); }
#line 1939 "y.tab.c"
    break;

  case 32:
#line 176 "parser.y"
                                            { (yyvsp[-1].constraints)->update("reverse"); (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1945 "y.tab.c"
    break;

  case 33:
#line 177 "parser.y"
                                            { (yyvsp[-1].constraints)->update("positive"); (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1951 "y.tab.c"
    break;

  case 34:
#line 178 "parser.y"
                                            { (yyvsp[-1].constraints)->update("aos"); (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1957 "y.tab.c"
    break;

  case 35:
#line 179 "parser.y"
                                            { (yyvsp[-1].constraints)->update("soa"); (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1963 "y.tab.c"
    break;

  case 36:
#line 180 "parser.y"
                                            { (yyvsp[-1].constraints)->update("compact"); (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1969 "y.tab.c"
    break;

  case 37:
#line 181 "parser.y"
                                            { (yyvsp[-1].constraints)->update("exact"); (yyval.constraints) = (yyvsp[-1].constraints); }
#line 1975 "y.tab.c"
    break;

  case 38:
#line 182 "parser.y"
                                            { (yyvsp[-3].constraints)->update(SMALLER, (yyvsp[0].intVal)); (yyval.constraints) = (yyvsp[-3].constraints); }
#line 1981 "y.tab.c"
    break;

  case 39:
#line 183 "parser.y"
                                            { (yyvsp[-3].constraints)->update(LE, (yyvsp[0].intVal)); (yyval.constraints) = (yyvsp[-3].constraints); }
#line 1987 "y.tab.c"
    break;

  case 40:
#line 184 "parser.y"
                                            { (yyvsp[-3].constraints)->update(BIGGER, (yyvsp[0].intVal)); (yyval.constraints) = (yyvsp[-3].constraints); }
#line 1993 "y.tab.c"
    break;

  case 41:
#line 185 "parser.y"
                                            { (yyvsp[-3].constraints)->update(GE, (yyvsp[0].intVal)); (yyval.constraints) = (yyvsp[-3].constraints); }
#line 1999 "y.tab.c"
    break;

  case 42:
#line 186 "parser.y"
                                            { (yyvsp[-3].constraints)->update(EQ, (yyvsp[0].intVal)); (yyval.constraints) = (yyvsp[-3].constraints); }
#line 2005 "y.tab.c"
    break;

  case 43:
#line 187 "parser.y"
                                            { (yyvsp[-3].constraints)->update(NEQ, (yyvsp[0].intVal)); (yyval.constraints) = (yyvsp[-3].constraints); }
#line 2011 "y.tab.c"
    break;

  case 44:
#line 191 "parser.y"
                                                         { (yyval.funcdef) = new FuncDefNode((yyvsp[-6].string), (yyvsp[-4].args), (yyvsp[-1].funcstmt)); }
#line 2017 "y.tab.c"
    break;

  case 45:
#line 194 "parser.y"
                                                    { (yyval.indextaskmap) = new IndexTaskMapNode((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 2023 "y.tab.c"
    break;

  case 46:
#line 195 "parser.y"
                                                    { (yyval.indextaskmap) = new IndexTaskMapNode((yyvsp[-2].stringlist), (yyvsp[-1].string)); }
#line 2029 "y.tab.c"
    break;

  case 47:
#line 196 "parser.y"
                                                    { (yyval.indextaskmap) = new IndexTaskMapNode("CPU", (yyvsp[-1].string)); }
#line 2035 "y.tab.c"
    break;

  case 48:
#line 197 "parser.y"
                                                    { (yyval.indextaskmap) = new IndexTaskMapNode("GPU", (yyvsp[-1].string)); }
#line 2041 "y.tab.c"
    break;

  case 49:
#line 198 "parser.y"
                                                    { (yyval.indextaskmap) = new IndexTaskMapNode("OMP", (yyvsp[-1].string)); }
#line 2047 "y.tab.c"
    break;

  case 50:
#line 202 "parser.y"
                                                     { (yyval.singletaskmap) = new SingleTaskMapNode((yyvsp[-2].string), (yyvsp[-1].string)); }
#line 2053 "y.tab.c"
    break;

  case 51:
#line 203 "parser.y"
                                                     { (yyval.singletaskmap) = new SingleTaskMapNode((yyvsp[-2].stringlist), (yyvsp[-1].string)); }
#line 2059 "y.tab.c"
    break;

  case 52:
#line 204 "parser.y"
                                                     { (yyval.singletaskmap) = new SingleTaskMapNode("CPU", (yyvsp[-1].string)); }
#line 2065 "y.tab.c"
    break;

  case 53:
#line 205 "parser.y"
                                                     { (yyval.singletaskmap) = new SingleTaskMapNode("GPU", (yyvsp[-1].string)); }
#line 2071 "y.tab.c"
    break;

  case 54:
#line 206 "parser.y"
                                                     { (yyval.singletaskmap) = new SingleTaskMapNode("OMP", (yyvsp[-1].string)); }
#line 2077 "y.tab.c"
    break;

  case 55:
#line 210 "parser.y"
                                           { (yyval.controlreplicate) = new ControlReplicateNode((yyvsp[-1].string)); }
#line 2083 "y.tab.c"
    break;

  case 56:
#line 211 "parser.y"
                                           { (yyval.controlreplicate) = new ControlReplicateNode((yyvsp[-1].stringlist)); }
#line 2089 "y.tab.c"
    break;

  case 57:
#line 215 "parser.y"
                                                    { (yyval.tasksteal) = new TaskStealNode((yyvsp[-3].string), (yyvsp[-2].proc), true); }
#line 2095 "y.tab.c"
    break;

  case 58:
#line 216 "parser.y"
                                                    { (yyval.tasksteal) = new TaskStealNode((yyvsp[-3].stringlist), (yyvsp[-2].proc), false); }
#line 2101 "y.tab.c"
    break;

  case 59:
#line 219 "parser.y"
                                { (yyval.assign) = new AssignNode((yyvsp[-3].string), (yyvsp[-1].expr)); }
#line 2107 "y.tab.c"
    break;

  case 60:
#line 223 "parser.y"
                            { FuncStmtsNode* fs = new FuncStmtsNode(); fs->stmtlst.push_back((yyvsp[0].stmt)); (yyval.funcstmt) = fs; }
#line 2113 "y.tab.c"
    break;

  case 61:
#line 224 "parser.y"
                            { (yyvsp[-1].funcstmt)->stmtlst.push_back((yyvsp[0].stmt)); }
#line 2119 "y.tab.c"
    break;

  case 62:
#line 228 "parser.y"
                  { (yyval.stmt) = (yyvsp[0].assign); }
#line 2125 "y.tab.c"
    break;

  case 63:
#line 229 "parser.y"
                  { (yyval.stmt) = (yyvsp[0].returnstmt); }
#line 2131 "y.tab.c"
    break;

  case 64:
#line 230 "parser.y"
                  { (yyval.stmt) = (yyvsp[0].printstmt); }
#line 2137 "y.tab.c"
    break;

  case 65:
#line 234 "parser.y"
                           { (yyval.returnstmt) = new ReturnNode((yyvsp[-1].expr)); }
#line 2143 "y.tab.c"
    break;

  case 66:
#line 238 "parser.y"
                                                       { (yyval.printstmt) = new PrintNode((yyvsp[-3].string), (yyvsp[-2].printargs)); }
#line 2149 "y.tab.c"
    break;

  case 67:
#line 242 "parser.y"
                                { (yyval.printargs) = new PrintArgsNode(); }
#line 2155 "y.tab.c"
    break;

  case 68:
#line 243 "parser.y"
                                { (yyvsp[-2].printargs)->printargs.push_back((yyvsp[0].expr)); }
#line 2161 "y.tab.c"
    break;

  case 69:
#line 247 "parser.y"
                            { (yyval.args) = new ArgLstNode(); }
#line 2167 "y.tab.c"
    break;

  case 70:
#line 248 "parser.y"
                            { (yyval.args) = (yyvsp[0].args); }
#line 2173 "y.tab.c"
    break;

  case 71:
#line 252 "parser.y"
                           { ArgNode* a = new ArgNode((yyvsp[-1].argtype), (yyvsp[0].string));
                             ArgLstNode* b = new ArgLstNode(); 
                             b->arg_lst.push_back(a);
                             (yyval.args) = b; }
#line 2182 "y.tab.c"
    break;

  case 72:
#line 257 "parser.y"
                           { ArgNode* c = new ArgNode((yyvsp[-1].argtype), (yyvsp[0].string));
                             (yyvsp[-3].args)->arg_lst.push_back(c);
                             (yyval.args) = (yyvsp[-3].args); }
#line 2190 "y.tab.c"
    break;

  case 73:
#line 264 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), PLUS, (yyvsp[0].expr)); }
#line 2196 "y.tab.c"
    break;

  case 74:
#line 265 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), MINUS, (yyvsp[0].expr)); }
#line 2202 "y.tab.c"
    break;

  case 75:
#line 266 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), MULTIPLY, (yyvsp[0].expr)); }
#line 2208 "y.tab.c"
    break;

  case 76:
#line 267 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), DIVIDE, (yyvsp[0].expr)); }
#line 2214 "y.tab.c"
    break;

  case 77:
#line 268 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), MOD, (yyvsp[0].expr)); }
#line 2220 "y.tab.c"
    break;

  case 78:
#line 269 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), BIGGER, (yyvsp[0].expr)); }
#line 2226 "y.tab.c"
    break;

  case 79:
#line 270 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), SMALLER, (yyvsp[0].expr)); }
#line 2232 "y.tab.c"
    break;

  case 80:
#line 271 "parser.y"
                            { (yyval.expr) = (yyvsp[-1].expr); }
#line 2238 "y.tab.c"
    break;

  case 81:
#line 272 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), GE, (yyvsp[0].expr)); }
#line 2244 "y.tab.c"
    break;

  case 82:
#line 273 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), LE, (yyvsp[0].expr)); }
#line 2250 "y.tab.c"
    break;

  case 83:
#line 274 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), EQ, (yyvsp[0].expr)); }
#line 2256 "y.tab.c"
    break;

  case 84:
#line 275 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), NEQ, (yyvsp[0].expr)); }
#line 2262 "y.tab.c"
    break;

  case 85:
#line 276 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), OR, (yyvsp[0].expr)); }
#line 2268 "y.tab.c"
    break;

  case 86:
#line 277 "parser.y"
                            { (yyval.expr) = new BinaryExprNode((yyvsp[-2].expr), AND, (yyvsp[0].expr)); }
#line 2274 "y.tab.c"
    break;

  case 87:
#line 278 "parser.y"
                            { (yyval.expr) = new FuncInvokeNode((yyvsp[-3].expr), (yyvsp[-1].exprn)); }
#line 2280 "y.tab.c"
    break;

  case 88:
#line 279 "parser.y"
                            { (yyval.expr) = new IndexExprNode((yyvsp[-3].expr), (yyvsp[-1].sliceexpr)); }
#line 2286 "y.tab.c"
    break;

  case 89:
#line 280 "parser.y"
                            { (yyval.expr) = new IndexExprNode((yyvsp[-3].expr), (yyvsp[-1].exprn)); }
#line 2292 "y.tab.c"
    break;

  case 90:
#line 281 "parser.y"
                            { (yyval.expr) = new StarExprNode(); }
#line 2298 "y.tab.c"
    break;

  case 91:
#line 282 "parser.y"
                            { (yyval.expr) = new NegativeExprNode((yyvsp[0].expr)); }
#line 2304 "y.tab.c"
    break;

  case 92:
#line 284 "parser.y"
                            { (yyval.expr) = new IntValNode((yyvsp[0].intVal)); }
#line 2310 "y.tab.c"
    break;

  case 93:
#line 285 "parser.y"
                            { (yyval.expr) = new BoolValNode(true); }
#line 2316 "y.tab.c"
    break;

  case 94:
#line 286 "parser.y"
                            { (yyval.expr) = new BoolValNode(false); }
#line 2322 "y.tab.c"
    break;

  case 95:
#line 287 "parser.y"
                            { if (!strcmp((yyvsp[0].string), "Machine")) (yyval.expr) = new MSpace(); else (yyval.expr) = new IdentifierExprNode((yyvsp[0].string)); }
#line 2328 "y.tab.c"
    break;

  case 96:
#line 288 "parser.y"
                            { (yyval.expr) = (yyvsp[-1].exprn)->Convert2TupleInt(); }
#line 2334 "y.tab.c"
    break;

  case 97:
#line 289 "parser.y"
                            { (yyval.expr) = (yyvsp[0].proc); }
#line 2340 "y.tab.c"
    break;

  case 98:
#line 290 "parser.y"
                            { (yyval.expr) = (yyvsp[0].mem); }
#line 2346 "y.tab.c"
    break;

  case 99:
#line 291 "parser.y"
                            { (yyval.expr) = new ObjectInvokeNode((yyvsp[-2].expr), (yyvsp[0].prop)); }
#line 2352 "y.tab.c"
    break;

  case 100:
#line 292 "parser.y"
                                     { (yyval.expr) = new TenaryExprNode((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2358 "y.tab.c"
    break;

  case 101:
#line 293 "parser.y"
                            { (yyval.expr) = new UnpackExprNode((yyvsp[0].expr)); }
#line 2364 "y.tab.c"
    break;

  case 102:
#line 294 "parser.y"
                                                      { (yyval.expr) = new ForTupleExprNode((yyvsp[-5].expr), (yyvsp[-3].string), (yyvsp[-1].expr)); }
#line 2370 "y.tab.c"
    break;

  case 103:
#line 298 "parser.y"
                            { (yyval.sliceexpr) = new SliceExprNode((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2376 "y.tab.c"
    break;

  case 104:
#line 299 "parser.y"
                            { (yyval.sliceexpr) = new SliceExprNode(NULL, (yyvsp[0].expr)); }
#line 2382 "y.tab.c"
    break;

  case 105:
#line 300 "parser.y"
                            { (yyval.sliceexpr) = new SliceExprNode((yyvsp[-1].expr), NULL); }
#line 2388 "y.tab.c"
    break;

  case 106:
#line 301 "parser.y"
                            { (yyval.sliceexpr) = new SliceExprNode(NULL, NULL); }
#line 2394 "y.tab.c"
    break;

  case 107:
#line 304 "parser.y"
                             { TupleExprNode* t = new TupleExprNode(); t->exprlst.push_back((yyvsp[0].expr)); (yyval.exprn) = t; }
#line 2400 "y.tab.c"
    break;

  case 108:
#line 305 "parser.y"
                             { (yyvsp[-2].exprn)->exprlst.push_back((yyvsp[0].expr)); (yyval.exprn) = (yyvsp[-2].exprn); }
#line 2406 "y.tab.c"
    break;

  case 109:
#line 308 "parser.y"
                            { TupleExprNode* t = new TupleExprNode(); t->exprlst.push_back((yyvsp[-2].expr)); t->exprlst.push_back((yyvsp[0].expr)); (yyval.exprn) = t; }
#line 2412 "y.tab.c"
    break;

  case 110:
#line 309 "parser.y"
                            { (yyvsp[-2].exprn)->exprlst.push_back((yyvsp[0].expr)); (yyval.exprn) = (yyvsp[-2].exprn); }
#line 2418 "y.tab.c"
    break;

  case 111:
#line 313 "parser.y"
                            { (yyval.prop) = new APINode(SIZE); }
#line 2424 "y.tab.c"
    break;

  case 112:
#line 314 "parser.y"
                            { (yyval.prop) = new APINode(SPLIT); }
#line 2430 "y.tab.c"
    break;

  case 113:
#line 315 "parser.y"
                            { (yyval.prop) = new APINode(MERGE); }
#line 2436 "y.tab.c"
    break;

  case 114:
#line 316 "parser.y"
                            { (yyval.prop) = new APINode(SWAP); }
#line 2442 "y.tab.c"
    break;

  case 115:
#line 317 "parser.y"
                            { (yyval.prop) = new APINode(SLICE); }
#line 2448 "y.tab.c"
    break;

  case 116:
#line 318 "parser.y"
                            { (yyval.prop) = new APINode(REVERSE); }
#line 2454 "y.tab.c"
    break;

  case 117:
#line 319 "parser.y"
                            { (yyval.prop) = new APINode(BALANCE_SPLIT); }
#line 2460 "y.tab.c"
    break;

  case 118:
#line 320 "parser.y"
                            { (yyval.prop) = new APINode(AUTO_SPLIT); }
#line 2466 "y.tab.c"
    break;

  case 119:
#line 321 "parser.y"
                            { (yyval.prop) = new APINode(GREEDY_SPLIT); }
#line 2472 "y.tab.c"
    break;

  case 120:
#line 322 "parser.y"
                            { (yyval.prop) = new APINode(VOLUME); }
#line 2478 "y.tab.c"
    break;

  case 121:
#line 323 "parser.y"
                            { (yyval.prop) = new APINode(HAS); }
#line 2484 "y.tab.c"
    break;

  case 122:
#line 324 "parser.y"
                            { (yyval.prop) = new APINode(LEN); }
#line 2490 "y.tab.c"
    break;

  case 123:
#line 325 "parser.y"
                            { (yyval.prop) = new APINode(TASKIPOINT); }
#line 2496 "y.tab.c"
    break;

  case 124:
#line 326 "parser.y"
                            { (yyval.prop) = new APINode(TASKISPACE); }
#line 2502 "y.tab.c"
    break;

  case 125:
#line 327 "parser.y"
                            { (yyval.prop) = new APINode(TASKPARENT); }
#line 2508 "y.tab.c"
    break;

  case 126:
#line 328 "parser.y"
                            { (yyval.prop) = new APINode(TASKPROCESSOR); }
#line 2514 "y.tab.c"
    break;

  case 127:
#line 333 "parser.y"
                            { (yyval.argtype) = new ArgTypeNode(INT); }
#line 2520 "y.tab.c"
    break;

  case 128:
#line 334 "parser.y"
                            { (yyval.argtype) = new ArgTypeNode(BOOL); }
#line 2526 "y.tab.c"
    break;

  case 129:
#line 335 "parser.y"
                            { (yyval.argtype) = new ArgTypeNode(IPOINT); }
#line 2532 "y.tab.c"
    break;

  case 130:
#line 336 "parser.y"
                            { (yyval.argtype) = new ArgTypeNode(ISPACE); }
#line 2538 "y.tab.c"
    break;

  case 131:
#line 337 "parser.y"
                            { (yyval.argtype) = new ArgTypeNode(MSPACE); }
#line 2544 "y.tab.c"
    break;

  case 132:
#line 338 "parser.y"
                            { (yyval.argtype) = new ArgTypeNode(TASK); }
#line 2550 "y.tab.c"
    break;

  case 133:
#line 342 "parser.y"
                            { ProcLstNode* b = new ProcLstNode(); b->proc_type_lst.push_back((yyvsp[0].proc)->proc_type); (yyval.proclst) = b; }
#line 2556 "y.tab.c"
    break;

  case 134:
#line 343 "parser.y"
                            { (yyvsp[-2].proclst)->proc_type_lst.push_back((yyvsp[0].proc)->proc_type); (yyval.proclst) = (yyvsp[-2].proclst); }
#line 2562 "y.tab.c"
    break;

  case 135:
#line 347 "parser.y"
                            { MemLstNode* m = new MemLstNode(); m->mem_type_lst.push_back((yyvsp[0].mem)->mem_type); (yyval.memlst) = m; }
#line 2568 "y.tab.c"
    break;

  case 136:
#line 348 "parser.y"
                            { (yyvsp[-2].memlst)->mem_type_lst.push_back((yyvsp[0].mem)->mem_type); (yyval.memlst) = (yyvsp[-2].memlst); }
#line 2574 "y.tab.c"
    break;

  case 137:
#line 352 "parser.y"
                            { (yyval.mem) = new MemNode(SYSMEM); }
#line 2580 "y.tab.c"
    break;

  case 138:
#line 353 "parser.y"
                            { (yyval.mem) = new MemNode(FBMEM); }
#line 2586 "y.tab.c"
    break;

  case 139:
#line 354 "parser.y"
                            { (yyval.mem) = new MemNode(RDMEM); }
#line 2592 "y.tab.c"
    break;

  case 140:
#line 355 "parser.y"
                            { (yyval.mem) = new MemNode(ZCMEM); }
#line 2598 "y.tab.c"
    break;

  case 141:
#line 356 "parser.y"
                            { (yyval.mem) = new MemNode(SOCKMEM); }
#line 2604 "y.tab.c"
    break;

  case 142:
#line 357 "parser.y"
                            { (yyval.mem) = new MemNode(VIRTUAL); }
#line 2610 "y.tab.c"
    break;

  case 143:
#line 362 "parser.y"
                            { (yyval.proc) = new ProcNode(CPU); }
#line 2616 "y.tab.c"
    break;

  case 144:
#line 363 "parser.y"
                            { (yyval.proc) = new ProcNode(GPU); }
#line 2622 "y.tab.c"
    break;

  case 145:
#line 364 "parser.y"
                            { (yyval.proc) = new ProcNode(IO); }
#line 2628 "y.tab.c"
    break;

  case 146:
#line 365 "parser.y"
                            { (yyval.proc) = new ProcNode(PY); }
#line 2634 "y.tab.c"
    break;

  case 147:
#line 366 "parser.y"
                            { (yyval.proc) = new ProcNode(PROC); }
#line 2640 "y.tab.c"
    break;

  case 148:
#line 367 "parser.y"
                            { (yyval.proc) = new ProcNode(OMP); }
#line 2646 "y.tab.c"
    break;


#line 2650 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 370 "parser.y"



/* int main()
{
    extern FILE* yyin;
    yyin = fopen("in.py", "r");
    if (yyin == NULL)
    {
        std::cout << "Mapping policy file does not exist" << std::endl;
        assert(false);
    }
    yyparse();
    std::cout << root->stmt_list.size() << std::endl;
    // root->print();
    root->run();
} */

// flex scanner.l; bison -vdty parser.y;
