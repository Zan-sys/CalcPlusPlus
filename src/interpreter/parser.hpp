// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file parser.hpp
 ** Define the CalcPlusPlus::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 37 ".\\_parser_bison.y"

    //
    // Модуль описывает синтаксическое дерево
    //
    #include "action_tree.hpp"
    //
    // Пространство имён в котором находится класс лексического анализатора (сканера)
    //
    namespace CalcPlusPlus
    {
        class TScanner; // Объявляем класс лексического анализатора
    }
    //
    // Отключение предупреждений компилятора для WINDOWS
    //
#ifdef WINDOWS
    #pragma warning(disable:4065)
#endif

#line 69 "parser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hpp"


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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

#line 6 ".\\_parser_bison.y"
namespace CalcPlusPlus {
#line 205 "parser.hpp"




  /// A Bison parser.
  class TParser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "double constant"
      char dummy1[sizeof (double)];

      // "true"
      // "false"
      // "ErrorValue"
      // "IsErrorValue"
      // options
      // option
      // function_declarations
      // function_declaration_arguments
      // function_declaration
      // variables
      // variable
      // program_expression
      // if_expression
      // if_block_expression
      // loop_expression
      // block_expression
      // one_block_expression
      // identifier_operation
      // math_expression
      // math_and_or
      // math_compare
      // plus_minus
      // multiplication_division
      // variable_function
      // function_argument
      // function_arguments
      // build_in_function
      // result_array_functions
      // void_array_function
      // invoke_user_functions
      char dummy2[sizeof (std::shared_ptr<TActionNode>)];

      // "Identifier"
      char dummy3[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_YYEMPTY = -2,
    TOKEN_EOF = 0,                 // "end of file"
    TOKEN_YYerror = 256,           // error
    TOKEN_YYUNDEF = 257,           // "invalid token"
    TOKEN_NUMBER = 258,            // "double constant"
    TOKEN_IDENTIFIER = 259,        // "Identifier"
    TOKEN_TRUE_CONST = 260,        // "true"
    TOKEN_FALSE_CONST = 261,       // "false"
    TOKEN_FUNCTION = 262,          // "function"
    TOKEN_VAR = 263,               // "var"
    TOKEN_IF = 264,                // "if"
    TOKEN_ELSE = 265,              // "else"
    TOKEN_WHILE = 266,             // "while"
    TOKEN_DO_WHILE = 267,          // "do"
    TOKEN_FOR = 268,               // "for"
    TOKEN_BREAK = 269,             // "break"
    TOKEN_OPT_ERRORVALUE = 270,    // "error_value"
    TOKEN_OPT_LOOPLIMIT = 271,     // "loop_limit"
    TOKEN_BF_PI = 272,             // "Pi"
    TOKEN_BF_ERRORVALUE = 273,     // "ErrorValue"
    TOKEN_BF_ISERRORVALUE = 274,   // "IsErrorValue"
    TOKEN_BF_IFERRORVALUEDEF = 275, // "IfErrorValueDef"
    TOKEN_BF_LN = 276,             // "Ln"
    TOKEN_BF_LG = 277,             // "Lg"
    TOKEN_BF_SIN = 278,            // "Sin"
    TOKEN_BF_COS = 279,            // "Cos"
    TOKEN_BF_TAN = 280,            // "Tan"
    TOKEN_BF_COTAN = 281,          // "CoTan"
    TOKEN_BF_SEC = 282,            // "Sec"
    TOKEN_BF_CSC = 283,            // "Csc"
    TOKEN_BF_ASIN = 284,           // "ASin"
    TOKEN_BF_ACOS = 285,           // "ACos"
    TOKEN_BF_ATAN = 286,           // "ATan"
    TOKEN_BF_ACOTAN = 287,         // "ACoTan"
    TOKEN_BF_ASEC = 288,           // "ASec"
    TOKEN_BF_ACSC = 289,           // "ACsc"
    TOKEN_BF_SINH = 290,           // "SinH"
    TOKEN_BF_COSH = 291,           // "CosH"
    TOKEN_BF_TANH = 292,           // "TanH"
    TOKEN_BF_ASINH = 293,          // "ASinH"
    TOKEN_BF_ACOSH = 294,          // "ACosH"
    TOKEN_BF_ATANH = 295,          // "ATanH"
    TOKEN_BF_ABS = 296,            // "Abs"
    TOKEN_BF_SQRT = 297,           // "Sqrt"
    TOKEN_BF_INT = 298,            // "Int"
    TOKEN_BF_FRAC = 299,           // "Frac"
    TOKEN_BF_SQR = 300,            // "Sqr"
    TOKEN_BF_CUBE = 301,           // "Cube"
    TOKEN_BF_ROUND = 302,          // "Round"
    TOKEN_BF_FACT = 303,           // "Fact"
    TOKEN_BF_POW = 304,            // "Pow"
    TOKEN_BF_INC = 305,            // "Inc"
    TOKEN_BF_DEC = 306,            // "Dec"
    TOKEN_BF_SUM = 307,            // "Sum"
    TOKEN_BF_MAX = 308,            // "Max"
    TOKEN_BF_MIN = 309,            // "Min"
    TOKEN_BF_AVG = 310,            // "Avg"
    TOKEN_BF_PROD = 311,           // "Prod"
    TOKEN_BF_POLY = 312,           // "Poly"
    TOKEN_EQ = 313,                // "=="
    TOKEN_NE = 314,                // "!="
    TOKEN_LE = 315,                // "<="
    TOKEN_GE = 316,                // ">="
    TOKEN_AND = 317,               // "&&"
    TOKEN_OR = 318,                // "||"
    TOKEN_PP = 319,                // "++"
    TOKEN_NN = 320,                // "--"
    TOKEN_PA = 321,                // "+="
    TOKEN_NA = 322,                // "-="
    TOKEN_MA = 323,                // "*="
    TOKEN_DA = 324,                // "/="
    TOKEN_VOID_ARRAY_INIT = 325,   // "void_ArrayInit"
    TOKEN_VOID_ARRAY_INIT_IF_EMPTY = 326, // "ArrayInitIfEmpty"
    TOKEN_ARRAY_SIZE = 327,        // "ArraySize"
    TOKEN_VOID_ARRAY_CLEAR = 328,  // "void_ArrayClear"
    TOKEN_VOID_ARRAY_PUSH_BACK = 329, // "void_ArrayPushBack"
    TOKEN_VOID_ARRAY_PUSH_FRONT = 330, // "void_ArrayPushFront"
    TOKEN_VOID_ARRAY_POP_BACK = 331, // "void_ArrayPopBack"
    TOKEN_VOID_ARRAY_POP_FRONT = 332, // "void_ArrayPopFront"
    TOKEN_VOID_ARRAY_AT = 333,     // "void_ArrayAt"
    TOKEN_ARRAY_AT = 334,          // "ArrayAt"
    TOKEN_ARRAY_FRONT = 335,       // "ArrayFront"
    TOKEN_ARRAY_BACK = 336,        // "ArrayBack"
    TOKEN_VOID_ARRAY_INSERT = 337, // "void_ArrayInsert"
    TOKEN_VOID_ARRAY_ERASE = 338,  // "void_ArrayErase"
    TOKEN_VOID_ARRAY_ERASE_VALUE = 339, // "void_ArrayEraseValue"
    TOKEN_VOID_ARRAY_RESIZE = 340, // "void_ArrayResize"
    TOKEN_VOID_ARRAY_SORT = 341,   // "void_ArraySort"
    TOKEN_VOID_ARRAY_UNIQUE = 342, // "void_ArrayUnique"
    TOKEN_VOID_ARRAY_REVERSE = 343, // "void_ArrayReverse"
    TOKEN_ARRAY_PROD = 344,        // "ArrayProd"
    TOKEN_ARRAY_AVG = 345,         // "ArrayAvg"
    TOKEN_ARRAY_MIN = 346,         // "ArrayMin"
    TOKEN_ARRAY_MAX = 347,         // "ArrayMax"
    TOKEN_ARRAY_SUM = 348,         // "ArraySum"
    TOKEN_ARRAY_POLY = 349         // "ArrayPoly"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 109, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_NUMBER = 3,                            // "double constant"
        S_IDENTIFIER = 4,                        // "Identifier"
        S_5_ = 5,                                // '+'
        S_6_ = 6,                                // '-'
        S_7_ = 7,                                // '*'
        S_8_ = 8,                                // '/'
        S_9_ = 9,                                // ';'
        S_10_ = 10,                              // '('
        S_11_ = 11,                              // ')'
        S_12_ = 12,                              // '#'
        S_TRUE_CONST = 13,                       // "true"
        S_FALSE_CONST = 14,                      // "false"
        S_FUNCTION = 15,                         // "function"
        S_VAR = 16,                              // "var"
        S_IF = 17,                               // "if"
        S_ELSE = 18,                             // "else"
        S_WHILE = 19,                            // "while"
        S_DO_WHILE = 20,                         // "do"
        S_FOR = 21,                              // "for"
        S_BREAK = 22,                            // "break"
        S_OPT_ERRORVALUE = 23,                   // "error_value"
        S_OPT_LOOPLIMIT = 24,                    // "loop_limit"
        S_BF_PI = 25,                            // "Pi"
        S_BF_ERRORVALUE = 26,                    // "ErrorValue"
        S_BF_ISERRORVALUE = 27,                  // "IsErrorValue"
        S_BF_IFERRORVALUEDEF = 28,               // "IfErrorValueDef"
        S_BF_LN = 29,                            // "Ln"
        S_BF_LG = 30,                            // "Lg"
        S_BF_SIN = 31,                           // "Sin"
        S_BF_COS = 32,                           // "Cos"
        S_BF_TAN = 33,                           // "Tan"
        S_BF_COTAN = 34,                         // "CoTan"
        S_BF_SEC = 35,                           // "Sec"
        S_BF_CSC = 36,                           // "Csc"
        S_BF_ASIN = 37,                          // "ASin"
        S_BF_ACOS = 38,                          // "ACos"
        S_BF_ATAN = 39,                          // "ATan"
        S_BF_ACOTAN = 40,                        // "ACoTan"
        S_BF_ASEC = 41,                          // "ASec"
        S_BF_ACSC = 42,                          // "ACsc"
        S_BF_SINH = 43,                          // "SinH"
        S_BF_COSH = 44,                          // "CosH"
        S_BF_TANH = 45,                          // "TanH"
        S_BF_ASINH = 46,                         // "ASinH"
        S_BF_ACOSH = 47,                         // "ACosH"
        S_BF_ATANH = 48,                         // "ATanH"
        S_BF_ABS = 49,                           // "Abs"
        S_BF_SQRT = 50,                          // "Sqrt"
        S_BF_INT = 51,                           // "Int"
        S_BF_FRAC = 52,                          // "Frac"
        S_BF_SQR = 53,                           // "Sqr"
        S_BF_CUBE = 54,                          // "Cube"
        S_BF_ROUND = 55,                         // "Round"
        S_BF_FACT = 56,                          // "Fact"
        S_BF_POW = 57,                           // "Pow"
        S_BF_INC = 58,                           // "Inc"
        S_BF_DEC = 59,                           // "Dec"
        S_BF_SUM = 60,                           // "Sum"
        S_BF_MAX = 61,                           // "Max"
        S_BF_MIN = 62,                           // "Min"
        S_BF_AVG = 63,                           // "Avg"
        S_BF_PROD = 64,                          // "Prod"
        S_BF_POLY = 65,                          // "Poly"
        S_EQ = 66,                               // "=="
        S_NE = 67,                               // "!="
        S_LE = 68,                               // "<="
        S_GE = 69,                               // ">="
        S_AND = 70,                              // "&&"
        S_OR = 71,                               // "||"
        S_PP = 72,                               // "++"
        S_NN = 73,                               // "--"
        S_PA = 74,                               // "+="
        S_NA = 75,                               // "-="
        S_MA = 76,                               // "*="
        S_DA = 77,                               // "/="
        S_VOID_ARRAY_INIT = 78,                  // "void_ArrayInit"
        S_VOID_ARRAY_INIT_IF_EMPTY = 79,         // "ArrayInitIfEmpty"
        S_ARRAY_SIZE = 80,                       // "ArraySize"
        S_VOID_ARRAY_CLEAR = 81,                 // "void_ArrayClear"
        S_VOID_ARRAY_PUSH_BACK = 82,             // "void_ArrayPushBack"
        S_VOID_ARRAY_PUSH_FRONT = 83,            // "void_ArrayPushFront"
        S_VOID_ARRAY_POP_BACK = 84,              // "void_ArrayPopBack"
        S_VOID_ARRAY_POP_FRONT = 85,             // "void_ArrayPopFront"
        S_VOID_ARRAY_AT = 86,                    // "void_ArrayAt"
        S_ARRAY_AT = 87,                         // "ArrayAt"
        S_ARRAY_FRONT = 88,                      // "ArrayFront"
        S_ARRAY_BACK = 89,                       // "ArrayBack"
        S_VOID_ARRAY_INSERT = 90,                // "void_ArrayInsert"
        S_VOID_ARRAY_ERASE = 91,                 // "void_ArrayErase"
        S_VOID_ARRAY_ERASE_VALUE = 92,           // "void_ArrayEraseValue"
        S_VOID_ARRAY_RESIZE = 93,                // "void_ArrayResize"
        S_VOID_ARRAY_SORT = 94,                  // "void_ArraySort"
        S_VOID_ARRAY_UNIQUE = 95,                // "void_ArrayUnique"
        S_VOID_ARRAY_REVERSE = 96,               // "void_ArrayReverse"
        S_ARRAY_PROD = 97,                       // "ArrayProd"
        S_ARRAY_AVG = 98,                        // "ArrayAvg"
        S_ARRAY_MIN = 99,                        // "ArrayMin"
        S_ARRAY_MAX = 100,                       // "ArrayMax"
        S_ARRAY_SUM = 101,                       // "ArraySum"
        S_ARRAY_POLY = 102,                      // "ArrayPoly"
        S_103_ = 103,                            // ','
        S_104_ = 104,                            // '{'
        S_105_ = 105,                            // '}'
        S_106_ = 106,                            // '='
        S_107_ = 107,                            // '>'
        S_108_ = 108,                            // '<'
        S_YYACCEPT = 109,                        // $accept
        S_program = 110,                         // program
        S_options = 111,                         // options
        S_option = 112,                          // option
        S_function_declarations = 113,           // function_declarations
        S_function_declaration_arguments = 114,  // function_declaration_arguments
        S_function_declaration = 115,            // function_declaration
        S_variables = 116,                       // variables
        S_variable = 117,                        // variable
        S_program_expression = 118,              // program_expression
        S_if_expression = 119,                   // if_expression
        S_if_block_expression = 120,             // if_block_expression
        S_loop_expression = 121,                 // loop_expression
        S_block_expression = 122,                // block_expression
        S_one_block_expression = 123,            // one_block_expression
        S_identifier_operation = 124,            // identifier_operation
        S_math_expression = 125,                 // math_expression
        S_math_and_or = 126,                     // math_and_or
        S_math_compare = 127,                    // math_compare
        S_plus_minus = 128,                      // plus_minus
        S_multiplication_division = 129,         // multiplication_division
        S_variable_function = 130,               // variable_function
        S_function_argument = 131,               // function_argument
        S_function_arguments = 132,              // function_arguments
        S_build_in_function = 133,               // build_in_function
        S_result_array_functions = 134,          // result_array_functions
        S_void_array_function = 135,             // void_array_function
        S_invoke_user_functions = 136            // invoke_user_functions
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.move< double > (std::move (that.value));
        break;

      case symbol_kind::S_TRUE_CONST: // "true"
      case symbol_kind::S_FALSE_CONST: // "false"
      case symbol_kind::S_BF_ERRORVALUE: // "ErrorValue"
      case symbol_kind::S_BF_ISERRORVALUE: // "IsErrorValue"
      case symbol_kind::S_options: // options
      case symbol_kind::S_option: // option
      case symbol_kind::S_function_declarations: // function_declarations
      case symbol_kind::S_function_declaration_arguments: // function_declaration_arguments
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_variables: // variables
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_program_expression: // program_expression
      case symbol_kind::S_if_expression: // if_expression
      case symbol_kind::S_if_block_expression: // if_block_expression
      case symbol_kind::S_loop_expression: // loop_expression
      case symbol_kind::S_block_expression: // block_expression
      case symbol_kind::S_one_block_expression: // one_block_expression
      case symbol_kind::S_identifier_operation: // identifier_operation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_math_and_or: // math_and_or
      case symbol_kind::S_math_compare: // math_compare
      case symbol_kind::S_plus_minus: // plus_minus
      case symbol_kind::S_multiplication_division: // multiplication_division
      case symbol_kind::S_variable_function: // variable_function
      case symbol_kind::S_function_argument: // function_argument
      case symbol_kind::S_function_arguments: // function_arguments
      case symbol_kind::S_build_in_function: // build_in_function
      case symbol_kind::S_result_array_functions: // result_array_functions
      case symbol_kind::S_void_array_function: // void_array_function
      case symbol_kind::S_invoke_user_functions: // invoke_user_functions
        value.move< std::shared_ptr<TActionNode> > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, double&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const double& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<TActionNode>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<TActionNode>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.template destroy< double > ();
        break;

      case symbol_kind::S_TRUE_CONST: // "true"
      case symbol_kind::S_FALSE_CONST: // "false"
      case symbol_kind::S_BF_ERRORVALUE: // "ErrorValue"
      case symbol_kind::S_BF_ISERRORVALUE: // "IsErrorValue"
      case symbol_kind::S_options: // options
      case symbol_kind::S_option: // option
      case symbol_kind::S_function_declarations: // function_declarations
      case symbol_kind::S_function_declaration_arguments: // function_declaration_arguments
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_variables: // variables
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_program_expression: // program_expression
      case symbol_kind::S_if_expression: // if_expression
      case symbol_kind::S_if_block_expression: // if_block_expression
      case symbol_kind::S_loop_expression: // loop_expression
      case symbol_kind::S_block_expression: // block_expression
      case symbol_kind::S_one_block_expression: // one_block_expression
      case symbol_kind::S_identifier_operation: // identifier_operation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_math_and_or: // math_and_or
      case symbol_kind::S_math_compare: // math_compare
      case symbol_kind::S_plus_minus: // plus_minus
      case symbol_kind::S_multiplication_division: // multiplication_division
      case symbol_kind::S_variable_function: // variable_function
      case symbol_kind::S_function_argument: // function_argument
      case symbol_kind::S_function_arguments: // function_arguments
      case symbol_kind::S_build_in_function: // build_in_function
      case symbol_kind::S_result_array_functions: // result_array_functions
      case symbol_kind::S_void_array_function: // void_array_function
      case symbol_kind::S_invoke_user_functions: // invoke_user_functions
        value.template destroy< std::shared_ptr<TActionNode> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return TParser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, double v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const double& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::shared_ptr<TActionNode> v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::shared_ptr<TActionNode>& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    TParser (CalcPlusPlus::TScanner& lexer_yyarg, CalcPlusPlus::TActionNode& root_yyarg, std::string& error_msg_yyarg);
    virtual ~TParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    TParser (const TParser&) = delete;
    /// Non copyable.
    TParser& operator= (const TParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EOF (location_type l)
      {
        return symbol_type (token::TOKEN_EOF, std::move (l));
      }
#else
      static
      symbol_type
      make_EOF (const location_type& l)
      {
        return symbol_type (token::TOKEN_EOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOKEN_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (double v, location_type l)
      {
        return symbol_type (token::TOKEN_NUMBER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMBER (const double& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_NUMBER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v, location_type l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE_CONST (std::shared_ptr<TActionNode> v, location_type l)
      {
        return symbol_type (token::TOKEN_TRUE_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE_CONST (const std::shared_ptr<TActionNode>& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_TRUE_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE_CONST (std::shared_ptr<TActionNode> v, location_type l)
      {
        return symbol_type (token::TOKEN_FALSE_CONST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE_CONST (const std::shared_ptr<TActionNode>& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_FALSE_CONST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNCTION (location_type l)
      {
        return symbol_type (token::TOKEN_FUNCTION, std::move (l));
      }
#else
      static
      symbol_type
      make_FUNCTION (const location_type& l)
      {
        return symbol_type (token::TOKEN_FUNCTION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR (location_type l)
      {
        return symbol_type (token::TOKEN_VAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VAR (const location_type& l)
      {
        return symbol_type (token::TOKEN_VAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::TOKEN_IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::TOKEN_IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::TOKEN_ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::TOKEN_ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::TOKEN_WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::TOKEN_WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO_WHILE (location_type l)
      {
        return symbol_type (token::TOKEN_DO_WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_DO_WHILE (const location_type& l)
      {
        return symbol_type (token::TOKEN_DO_WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::TOKEN_FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::TOKEN_FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::TOKEN_BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::TOKEN_BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPT_ERRORVALUE (location_type l)
      {
        return symbol_type (token::TOKEN_OPT_ERRORVALUE, std::move (l));
      }
#else
      static
      symbol_type
      make_OPT_ERRORVALUE (const location_type& l)
      {
        return symbol_type (token::TOKEN_OPT_ERRORVALUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OPT_LOOPLIMIT (location_type l)
      {
        return symbol_type (token::TOKEN_OPT_LOOPLIMIT, std::move (l));
      }
#else
      static
      symbol_type
      make_OPT_LOOPLIMIT (const location_type& l)
      {
        return symbol_type (token::TOKEN_OPT_LOOPLIMIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_PI (location_type l)
      {
        return symbol_type (token::TOKEN_BF_PI, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_PI (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_PI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ERRORVALUE (std::shared_ptr<TActionNode> v, location_type l)
      {
        return symbol_type (token::TOKEN_BF_ERRORVALUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ERRORVALUE (const std::shared_ptr<TActionNode>& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ERRORVALUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ISERRORVALUE (std::shared_ptr<TActionNode> v, location_type l)
      {
        return symbol_type (token::TOKEN_BF_ISERRORVALUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ISERRORVALUE (const std::shared_ptr<TActionNode>& v, const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ISERRORVALUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_IFERRORVALUEDEF (location_type l)
      {
        return symbol_type (token::TOKEN_BF_IFERRORVALUEDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_IFERRORVALUEDEF (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_IFERRORVALUEDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_LN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_LN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_LN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_LN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_LG (location_type l)
      {
        return symbol_type (token::TOKEN_BF_LG, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_LG (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_LG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_SIN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_SIN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_SIN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_SIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_COS (location_type l)
      {
        return symbol_type (token::TOKEN_BF_COS, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_COS (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_COS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_TAN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_TAN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_TAN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_TAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_COTAN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_COTAN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_COTAN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_COTAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_SEC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_SEC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_SEC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_SEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_CSC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_CSC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_CSC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_CSC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ASIN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ASIN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ASIN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ASIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ACOS (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ACOS, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ACOS (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ACOS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ATAN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ATAN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ATAN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ATAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ACOTAN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ACOTAN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ACOTAN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ACOTAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ASEC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ASEC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ASEC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ASEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ACSC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ACSC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ACSC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ACSC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_SINH (location_type l)
      {
        return symbol_type (token::TOKEN_BF_SINH, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_SINH (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_SINH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_COSH (location_type l)
      {
        return symbol_type (token::TOKEN_BF_COSH, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_COSH (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_COSH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_TANH (location_type l)
      {
        return symbol_type (token::TOKEN_BF_TANH, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_TANH (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_TANH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ASINH (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ASINH, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ASINH (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ASINH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ACOSH (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ACOSH, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ACOSH (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ACOSH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ATANH (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ATANH, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ATANH (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ATANH, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ABS (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ABS, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ABS (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ABS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_SQRT (location_type l)
      {
        return symbol_type (token::TOKEN_BF_SQRT, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_SQRT (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_SQRT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_INT (location_type l)
      {
        return symbol_type (token::TOKEN_BF_INT, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_INT (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_INT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_FRAC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_FRAC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_FRAC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_FRAC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_SQR (location_type l)
      {
        return symbol_type (token::TOKEN_BF_SQR, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_SQR (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_SQR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_CUBE (location_type l)
      {
        return symbol_type (token::TOKEN_BF_CUBE, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_CUBE (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_CUBE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_ROUND (location_type l)
      {
        return symbol_type (token::TOKEN_BF_ROUND, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_ROUND (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_ROUND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_FACT (location_type l)
      {
        return symbol_type (token::TOKEN_BF_FACT, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_FACT (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_FACT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_POW (location_type l)
      {
        return symbol_type (token::TOKEN_BF_POW, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_POW (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_POW, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_INC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_INC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_INC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_INC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_DEC (location_type l)
      {
        return symbol_type (token::TOKEN_BF_DEC, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_DEC (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_DEC, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_SUM (location_type l)
      {
        return symbol_type (token::TOKEN_BF_SUM, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_SUM (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_SUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_MAX (location_type l)
      {
        return symbol_type (token::TOKEN_BF_MAX, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_MAX (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_MAX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_MIN (location_type l)
      {
        return symbol_type (token::TOKEN_BF_MIN, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_MIN (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_MIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_AVG (location_type l)
      {
        return symbol_type (token::TOKEN_BF_AVG, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_AVG (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_AVG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_PROD (location_type l)
      {
        return symbol_type (token::TOKEN_BF_PROD, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_PROD (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_PROD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BF_POLY (location_type l)
      {
        return symbol_type (token::TOKEN_BF_POLY, std::move (l));
      }
#else
      static
      symbol_type
      make_BF_POLY (const location_type& l)
      {
        return symbol_type (token::TOKEN_BF_POLY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ (location_type l)
      {
        return symbol_type (token::TOKEN_EQ, std::move (l));
      }
#else
      static
      symbol_type
      make_EQ (const location_type& l)
      {
        return symbol_type (token::TOKEN_EQ, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE (location_type l)
      {
        return symbol_type (token::TOKEN_NE, std::move (l));
      }
#else
      static
      symbol_type
      make_NE (const location_type& l)
      {
        return symbol_type (token::TOKEN_NE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE (location_type l)
      {
        return symbol_type (token::TOKEN_LE, std::move (l));
      }
#else
      static
      symbol_type
      make_LE (const location_type& l)
      {
        return symbol_type (token::TOKEN_LE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE (location_type l)
      {
        return symbol_type (token::TOKEN_GE, std::move (l));
      }
#else
      static
      symbol_type
      make_GE (const location_type& l)
      {
        return symbol_type (token::TOKEN_GE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::TOKEN_AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::TOKEN_AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::TOKEN_OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::TOKEN_OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PP (location_type l)
      {
        return symbol_type (token::TOKEN_PP, std::move (l));
      }
#else
      static
      symbol_type
      make_PP (const location_type& l)
      {
        return symbol_type (token::TOKEN_PP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NN (location_type l)
      {
        return symbol_type (token::TOKEN_NN, std::move (l));
      }
#else
      static
      symbol_type
      make_NN (const location_type& l)
      {
        return symbol_type (token::TOKEN_NN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PA (location_type l)
      {
        return symbol_type (token::TOKEN_PA, std::move (l));
      }
#else
      static
      symbol_type
      make_PA (const location_type& l)
      {
        return symbol_type (token::TOKEN_PA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NA (location_type l)
      {
        return symbol_type (token::TOKEN_NA, std::move (l));
      }
#else
      static
      symbol_type
      make_NA (const location_type& l)
      {
        return symbol_type (token::TOKEN_NA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MA (location_type l)
      {
        return symbol_type (token::TOKEN_MA, std::move (l));
      }
#else
      static
      symbol_type
      make_MA (const location_type& l)
      {
        return symbol_type (token::TOKEN_MA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DA (location_type l)
      {
        return symbol_type (token::TOKEN_DA, std::move (l));
      }
#else
      static
      symbol_type
      make_DA (const location_type& l)
      {
        return symbol_type (token::TOKEN_DA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_INIT (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_INIT, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_INIT (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_INIT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_INIT_IF_EMPTY (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_INIT_IF_EMPTY, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_INIT_IF_EMPTY (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_INIT_IF_EMPTY, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_SIZE (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_SIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_CLEAR (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_CLEAR, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_CLEAR (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_CLEAR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_PUSH_BACK (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_PUSH_BACK, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_PUSH_BACK (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_PUSH_BACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_PUSH_FRONT (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_PUSH_FRONT, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_PUSH_FRONT (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_PUSH_FRONT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_POP_BACK (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_POP_BACK, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_POP_BACK (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_POP_BACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_POP_FRONT (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_POP_FRONT, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_POP_FRONT (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_POP_FRONT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_AT (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_AT, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_AT (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_AT (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_AT, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_AT (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_AT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_FRONT (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_FRONT, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_FRONT (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_FRONT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_BACK (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_BACK, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_BACK (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_BACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_INSERT (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_INSERT, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_INSERT (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_INSERT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_ERASE (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_ERASE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_ERASE (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_ERASE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_ERASE_VALUE (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_ERASE_VALUE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_ERASE_VALUE (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_ERASE_VALUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_RESIZE (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_RESIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_RESIZE (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_RESIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_SORT (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_SORT, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_SORT (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_SORT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_UNIQUE (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_UNIQUE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_UNIQUE (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_UNIQUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID_ARRAY_REVERSE (location_type l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_REVERSE, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID_ARRAY_REVERSE (const location_type& l)
      {
        return symbol_type (token::TOKEN_VOID_ARRAY_REVERSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_PROD (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_PROD, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_PROD (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_PROD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_AVG (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_AVG, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_AVG (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_AVG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_MIN (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_MIN, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_MIN (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_MIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_MAX (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_MAX, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_MAX (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_MAX, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_SUM (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_SUM, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_SUM (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_SUM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ARRAY_POLY (location_type l)
      {
        return symbol_type (token::TOKEN_ARRAY_POLY, std::move (l));
      }
#else
      static
      symbol_type
      make_ARRAY_POLY (const location_type& l)
      {
        return symbol_type (token::TOKEN_ARRAY_POLY, l);
      }
#endif


    class context
    {
    public:
      context (const TParser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const TParser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    TParser (const TParser&);
    /// Non copyable.
    TParser& operator= (const TParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const unsigned char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const unsigned char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 1307,     ///< Last index in yytable_.
      yynnts_ = 28,  ///< Number of nonterminal symbols.
      yyfinal_ = 7 ///< Termination state number.
    };


    // User arguments.
    CalcPlusPlus::TScanner& lexer;
    CalcPlusPlus::TActionNode& root;
    std::string& error_msg;

  };

  inline
  TParser::symbol_kind_type
  TParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    12,     2,     2,     2,     2,
      10,    11,     7,     5,   103,     6,     2,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     9,
     108,   106,   107,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   104,     2,   105,     2,     2,     2,     2,
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
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102
    };
    // Last valid token kind.
    const int code_max = 349;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  TParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.copy< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TRUE_CONST: // "true"
      case symbol_kind::S_FALSE_CONST: // "false"
      case symbol_kind::S_BF_ERRORVALUE: // "ErrorValue"
      case symbol_kind::S_BF_ISERRORVALUE: // "IsErrorValue"
      case symbol_kind::S_options: // options
      case symbol_kind::S_option: // option
      case symbol_kind::S_function_declarations: // function_declarations
      case symbol_kind::S_function_declaration_arguments: // function_declaration_arguments
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_variables: // variables
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_program_expression: // program_expression
      case symbol_kind::S_if_expression: // if_expression
      case symbol_kind::S_if_block_expression: // if_block_expression
      case symbol_kind::S_loop_expression: // loop_expression
      case symbol_kind::S_block_expression: // block_expression
      case symbol_kind::S_one_block_expression: // one_block_expression
      case symbol_kind::S_identifier_operation: // identifier_operation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_math_and_or: // math_and_or
      case symbol_kind::S_math_compare: // math_compare
      case symbol_kind::S_plus_minus: // plus_minus
      case symbol_kind::S_multiplication_division: // multiplication_division
      case symbol_kind::S_variable_function: // variable_function
      case symbol_kind::S_function_argument: // function_argument
      case symbol_kind::S_function_arguments: // function_arguments
      case symbol_kind::S_build_in_function: // build_in_function
      case symbol_kind::S_result_array_functions: // result_array_functions
      case symbol_kind::S_void_array_function: // void_array_function
      case symbol_kind::S_invoke_user_functions: // invoke_user_functions
        value.copy< std::shared_ptr<TActionNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  TParser::symbol_kind_type
  TParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  TParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  TParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.move< double > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_TRUE_CONST: // "true"
      case symbol_kind::S_FALSE_CONST: // "false"
      case symbol_kind::S_BF_ERRORVALUE: // "ErrorValue"
      case symbol_kind::S_BF_ISERRORVALUE: // "IsErrorValue"
      case symbol_kind::S_options: // options
      case symbol_kind::S_option: // option
      case symbol_kind::S_function_declarations: // function_declarations
      case symbol_kind::S_function_declaration_arguments: // function_declaration_arguments
      case symbol_kind::S_function_declaration: // function_declaration
      case symbol_kind::S_variables: // variables
      case symbol_kind::S_variable: // variable
      case symbol_kind::S_program_expression: // program_expression
      case symbol_kind::S_if_expression: // if_expression
      case symbol_kind::S_if_block_expression: // if_block_expression
      case symbol_kind::S_loop_expression: // loop_expression
      case symbol_kind::S_block_expression: // block_expression
      case symbol_kind::S_one_block_expression: // one_block_expression
      case symbol_kind::S_identifier_operation: // identifier_operation
      case symbol_kind::S_math_expression: // math_expression
      case symbol_kind::S_math_and_or: // math_and_or
      case symbol_kind::S_math_compare: // math_compare
      case symbol_kind::S_plus_minus: // plus_minus
      case symbol_kind::S_multiplication_division: // multiplication_division
      case symbol_kind::S_variable_function: // variable_function
      case symbol_kind::S_function_argument: // function_argument
      case symbol_kind::S_function_arguments: // function_arguments
      case symbol_kind::S_build_in_function: // build_in_function
      case symbol_kind::S_result_array_functions: // result_array_functions
      case symbol_kind::S_void_array_function: // void_array_function
      case symbol_kind::S_invoke_user_functions: // invoke_user_functions
        value.move< std::shared_ptr<TActionNode> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  TParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  TParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  TParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  TParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  TParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  TParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  TParser::symbol_kind_type
  TParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  TParser::symbol_kind_type
  TParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 6 ".\\_parser_bison.y"
} // CalcPlusPlus
#line 3123 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
