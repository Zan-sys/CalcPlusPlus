// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 61 "./_parser_bison.y"

    //
    // Заголовочный файл с вспомогательными шаблонами и функциями
    //
    #include <fw_base.hpp>
    //
    // Заголовочный файл лексического анализатора (сканера)
    //
    #include "scanner.hpp"
    //
    // Главная функция лексического анализатора, которая возвращает описание токена с его положением во входном потоке символов
    // Ссылаемся на метод lex класса класса lexer. Имя класса указывается в директиве %parse-param {CalcPlusPlus::TScanner& lexer} (!!должны совпадать!!!)
    //
    #undef yylex
    #define yylex lexer.lex

#line 63 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "./_parser_bison.y"
namespace CalcPlusPlus {
#line 156 "parser.cpp"

  /// Build a parser object.
  TParser::TParser (CalcPlusPlus::TScanner& lexer_yyarg, CalcPlusPlus::TActionNode& root_yyarg, std::string& error_msg_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      root (root_yyarg),
      error_msg (error_msg_yyarg)
  {}

  TParser::~TParser ()
  {}

  TParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  TParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  TParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  TParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  TParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  TParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  TParser::symbol_kind_type
  TParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  TParser::stack_symbol_type::stack_symbol_type ()
  {}

  TParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::shared_ptr<TActionNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  TParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.move< double > (YY_MOVE (that.value));
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
        value.move< std::shared_ptr<TActionNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  TParser::stack_symbol_type&
  TParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.copy< double > (that.value);
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
        value.copy< std::shared_ptr<TActionNode> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  TParser::stack_symbol_type&
  TParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_NUMBER: // "double constant"
        value.move< double > (that.value);
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
        value.move< std::shared_ptr<TActionNode> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  TParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  TParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  TParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  TParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  TParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  TParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  TParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  TParser::debug_level_type
  TParser::debug_level () const
  {
    return yydebug_;
  }

  void
  TParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  TParser::state_type
  TParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  TParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  TParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  TParser::operator() ()
  {
    return parse ();
  }

  int
  TParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_NUMBER: // "double constant"
        yylhs.value.emplace< double > ();
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
        yylhs.value.emplace< std::shared_ptr<TActionNode> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "Identifier"
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: options function_declarations variables program_expression
#line 220 "./_parser_bison.y"
                                                                        {
                                                                            if (yystack_[3].value.as < std::shared_ptr<TActionNode> > ()) root.AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                            if (yystack_[2].value.as < std::shared_ptr<TActionNode> > ()) root.AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                            if (yystack_[1].value.as < std::shared_ptr<TActionNode> > ()) root.AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                            root.AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                        }
#line 762 "parser.cpp"
    break;

  case 3: // options: %empty
#line 231 "./_parser_bison.y"
                                {}
#line 768 "parser.cpp"
    break;

  case 4: // options: option ';' options
#line 232 "./_parser_bison.y"
                                {
                                    if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                    {
                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Options);
                                    }
                                    else
                                    {
                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                    }
                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > (), false);
                                }
#line 784 "parser.cpp"
    break;

  case 5: // option: '#' "error_value" "double constant"
#line 248 "./_parser_bison.y"
                                        {
                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::OptErrorValue);
                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(yystack_[0].value.as < double > ()));
                                        }
#line 793 "parser.cpp"
    break;

  case 6: // option: '#' "error_value" '-' "double constant"
#line 252 "./_parser_bison.y"
                                        {
                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::OptErrorValue);
                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(yystack_[0].value.as < double > () * -1));
                                        }
#line 802 "parser.cpp"
    break;

  case 7: // option: '#' "loop_limit" "double constant"
#line 256 "./_parser_bison.y"
                                        {
                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::OptLoopLimit);
                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(yystack_[0].value.as < double > ()));
                                        }
#line 811 "parser.cpp"
    break;

  case 8: // function_declarations: %empty
#line 265 "./_parser_bison.y"
                                                                        {}
#line 817 "parser.cpp"
    break;

  case 9: // function_declarations: function_declaration function_declarations
#line 266 "./_parser_bison.y"
                                                                        {
                                                                            if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                            {
                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Functions);
                                                                            }
                                                                            else
                                                                            {
                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                            }
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                        }
#line 833 "parser.cpp"
    break;

  case 10: // function_declaration_arguments: function_declaration_arguments ',' "Identifier"
#line 281 "./_parser_bison.y"
                                                                                {
                                                                                    if (yystack_[2].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                                    {
                                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[2].value.as < std::shared_ptr<TActionNode> > ();
                                                                                    }
                                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[0].value.as < std::string > ()));
                                                                                }
#line 849 "parser.cpp"
    break;

  case 11: // function_declaration_arguments: "Identifier"
#line 292 "./_parser_bison.y"
                                                                                {
                                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[0].value.as < std::string > ()));
                                                                                }
#line 858 "parser.cpp"
    break;

  case 12: // function_declaration: "function" "Identifier" '(' ')' '{' variables program_expression '}'
#line 301 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Function, yystack_[6].value.as < std::string > ());
                                                                                                                                if (yystack_[2].value.as < std::shared_ptr<TActionNode> > ()) yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                            }
#line 868 "parser.cpp"
    break;

  case 13: // function_declaration: "function" "Identifier" '(' function_declaration_arguments ')' '{' variables program_expression '}'
#line 306 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Function, yystack_[7].value.as < std::string > ());
                                                                                                                                if (yystack_[5].value.as < std::shared_ptr<TActionNode> > ()) yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[5].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                if (yystack_[2].value.as < std::shared_ptr<TActionNode> > ()) yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                            }
#line 879 "parser.cpp"
    break;

  case 14: // variables: %empty
#line 317 "./_parser_bison.y"
                                        {}
#line 885 "parser.cpp"
    break;

  case 15: // variables: variable ';' variables
#line 318 "./_parser_bison.y"
                                        {
                                            if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                            {
                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Variables);
                                            }
                                            else
                                            {
                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                            }
                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > (), false);
                                        }
#line 901 "parser.cpp"
    break;

  case 16: // variable: "var" "Identifier"
#line 334 "./_parser_bison.y"
                                                    {
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Var);
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[0].value.as < std::string > ()));
                                                    }
#line 910 "parser.cpp"
    break;

  case 17: // variable: "var" "Identifier" '=' math_expression
#line 338 "./_parser_bison.y"
                                                    {
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Var);
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[2].value.as < std::string > ()));
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                    }
#line 920 "parser.cpp"
    break;

  case 18: // program_expression: math_expression ';'
#line 348 "./_parser_bison.y"
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Main);
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                    }
#line 929 "parser.cpp"
    break;

  case 19: // program_expression: identifier_operation ';' program_expression
#line 352 "./_parser_bison.y"
                                                                    {
                                                                        if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                        }
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                    }
#line 945 "parser.cpp"
    break;

  case 20: // program_expression: void_array_function ';' program_expression
#line 363 "./_parser_bison.y"
                                                                    {
                                                                        if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                        }
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                    }
#line 961 "parser.cpp"
    break;

  case 21: // program_expression: if_expression program_expression
#line 374 "./_parser_bison.y"
                                                                    {
                                                                        if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                        }
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                    }
#line 977 "parser.cpp"
    break;

  case 22: // program_expression: loop_expression program_expression
#line 385 "./_parser_bison.y"
                                                                    {
                                                                        if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Main);
                                                                        }
                                                                        else
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                        }
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                    }
#line 993 "parser.cpp"
    break;

  case 23: // if_expression: "if" '(' math_expression ')' if_block_expression
#line 401 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::If);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yystack_[0].value.as < std::shared_ptr<TActionNode> > ()->Set(TActionType::TrueBlock);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1004 "parser.cpp"
    break;

  case 24: // if_expression: "if" '(' math_expression ')' if_block_expression "else" if_block_expression
#line 407 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::If);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[4].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yystack_[2].value.as < std::shared_ptr<TActionNode> > ()->Set(TActionType::TrueBlock);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yystack_[0].value.as < std::shared_ptr<TActionNode> > ()->Set(TActionType::FalseBlock);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1017 "parser.cpp"
    break;

  case 25: // if_expression: "if" '(' math_expression ')' if_block_expression "else" if_expression
#line 415 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::If);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[4].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yystack_[2].value.as < std::shared_ptr<TActionNode> > ()->Set(TActionType::TrueBlock);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1029 "parser.cpp"
    break;

  case 26: // if_block_expression: '{' block_expression '}'
#line 427 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[1].value.as < std::shared_ptr<TActionNode> > (); }
#line 1035 "parser.cpp"
    break;

  case 27: // if_block_expression: one_block_expression
#line 428 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1041 "parser.cpp"
    break;

  case 28: // loop_expression: "while" '(' math_expression ')' '{' block_expression '}'
#line 434 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::While);
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[4].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                            }
#line 1051 "parser.cpp"
    break;

  case 29: // loop_expression: "do" '{' block_expression '}' "while" '(' math_expression ')'
#line 439 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::DoWhile);
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[5].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                            }
#line 1061 "parser.cpp"
    break;

  case 30: // loop_expression: "for" '(' identifier_operation ';' math_expression ';' identifier_operation ')' '{' block_expression '}'
#line 444 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::For);
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[8].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[6].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[4].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                            }
#line 1073 "parser.cpp"
    break;

  case 31: // loop_expression: "for" '(' ';' math_expression ';' identifier_operation ')' '{' block_expression '}'
#line 451 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::For);
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Empty));
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[6].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[4].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                            }
#line 1085 "parser.cpp"
    break;

  case 32: // loop_expression: "for" '(' ';' math_expression ';' ')' '{' block_expression '}'
#line 458 "./_parser_bison.y"
                                                                                                                            {
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::For);
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Empty));
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[5].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Empty));
                                                                                                                            }
#line 1097 "parser.cpp"
    break;

  case 33: // block_expression: %empty
#line 470 "./_parser_bison.y"
                                                                {
                                                                    if (yylhs.value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                }
#line 1108 "parser.cpp"
    break;

  case 34: // block_expression: one_block_expression block_expression
#line 476 "./_parser_bison.y"
                                                                {
                                                                    if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                    else
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                    }
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNodes(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes, false);
                                                                }
#line 1124 "parser.cpp"
    break;

  case 35: // block_expression: if_expression block_expression
#line 487 "./_parser_bison.y"
                                                                {
                                                                    if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                    else
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                    }
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                }
#line 1140 "parser.cpp"
    break;

  case 36: // block_expression: loop_expression block_expression
#line 498 "./_parser_bison.y"
                                                                {
                                                                    if (yystack_[0].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                                    }
                                                                    else
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > ();
                                                                    }
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                                }
#line 1156 "parser.cpp"
    break;

  case 37: // one_block_expression: "break" ';'
#line 514 "./_parser_bison.y"
                                                    {
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Break), false);
                                                    }
#line 1165 "parser.cpp"
    break;

  case 38: // one_block_expression: identifier_operation ';'
#line 518 "./_parser_bison.y"
                                                    {
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                    }
#line 1174 "parser.cpp"
    break;

  case 39: // one_block_expression: void_array_function ';'
#line 522 "./_parser_bison.y"
                                                    {
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::BlockCode);
                                                        yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > (), false);
                                                    }
#line 1183 "parser.cpp"
    break;

  case 40: // identifier_operation: "Identifier" '=' math_expression
#line 531 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Assignment);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[2].value.as < std::string > ()));
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                            }
#line 1193 "parser.cpp"
    break;

  case 41: // identifier_operation: "Identifier" "++"
#line 536 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::PlusPlus);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[1].value.as < std::string > ()));
                                                            }
#line 1202 "parser.cpp"
    break;

  case 42: // identifier_operation: "Identifier" "--"
#line 540 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::MinusMinus);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[1].value.as < std::string > ()));
                                                            }
#line 1211 "parser.cpp"
    break;

  case 43: // identifier_operation: "Identifier" "+=" math_expression
#line 544 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::PlusAssignment);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[2].value.as < std::string > ()));
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                            }
#line 1221 "parser.cpp"
    break;

  case 44: // identifier_operation: "Identifier" "-=" math_expression
#line 549 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::MinusAssignment);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[2].value.as < std::string > ()));
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                            }
#line 1231 "parser.cpp"
    break;

  case 45: // identifier_operation: "Identifier" "*=" math_expression
#line 554 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::MultAssignment);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[2].value.as < std::string > ()));
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                            }
#line 1241 "parser.cpp"
    break;

  case 46: // identifier_operation: "Identifier" "/=" math_expression
#line 559 "./_parser_bison.y"
                                                            {
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::DivisionAssignment);
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[2].value.as < std::string > ()));
                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                            }
#line 1251 "parser.cpp"
    break;

  case 47: // math_expression: math_and_or
#line 569 "./_parser_bison.y"
                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1257 "parser.cpp"
    break;

  case 48: // math_and_or: math_compare "&&" math_and_or
#line 575 "./_parser_bison.y"
                                            {
                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::And);
                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                            }
#line 1267 "parser.cpp"
    break;

  case 49: // math_and_or: math_compare "||" math_and_or
#line 580 "./_parser_bison.y"
                                            {
                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Or);
                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                            }
#line 1277 "parser.cpp"
    break;

  case 50: // math_and_or: math_compare
#line 585 "./_parser_bison.y"
                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1283 "parser.cpp"
    break;

  case 51: // math_compare: plus_minus '>' math_compare
#line 591 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Bigger);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                }
#line 1293 "parser.cpp"
    break;

  case 52: // math_compare: plus_minus '<' math_compare
#line 596 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Smaller);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                }
#line 1303 "parser.cpp"
    break;

  case 53: // math_compare: plus_minus "==" math_compare
#line 601 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::EqualEqual);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                }
#line 1313 "parser.cpp"
    break;

  case 54: // math_compare: plus_minus "!=" math_compare
#line 606 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::NotEqual);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                }
#line 1323 "parser.cpp"
    break;

  case 55: // math_compare: plus_minus "<=" math_compare
#line 611 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::LessOrEqual);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                }
#line 1333 "parser.cpp"
    break;

  case 56: // math_compare: plus_minus ">=" math_compare
#line 616 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::GreatOrEqual);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                }
#line 1343 "parser.cpp"
    break;

  case 57: // math_compare: plus_minus
#line 621 "./_parser_bison.y"
                                                {   yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1349 "parser.cpp"
    break;

  case 58: // plus_minus: multiplication_division '+' plus_minus
#line 627 "./_parser_bison.y"
                                                        {
                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Plus);
                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                        }
#line 1359 "parser.cpp"
    break;

  case 59: // plus_minus: multiplication_division '-' plus_minus
#line 632 "./_parser_bison.y"
                                                        {
                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Minus);
                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                        }
#line 1369 "parser.cpp"
    break;

  case 60: // plus_minus: multiplication_division
#line 637 "./_parser_bison.y"
                                                        {   yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1375 "parser.cpp"
    break;

  case 61: // multiplication_division: variable_function '*' multiplication_division
#line 643 "./_parser_bison.y"
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Multiplication);
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                        }
#line 1385 "parser.cpp"
    break;

  case 62: // multiplication_division: variable_function '/' multiplication_division
#line 648 "./_parser_bison.y"
                                                                        {
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Division);
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[2].value.as < std::shared_ptr<TActionNode> > ());
                                                                            yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                        }
#line 1395 "parser.cpp"
    break;

  case 63: // multiplication_division: variable_function
#line 653 "./_parser_bison.y"
                                                                        {   yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1401 "parser.cpp"
    break;

  case 64: // variable_function: '(' math_expression ')'
#line 659 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[1].value.as < std::shared_ptr<TActionNode> > (); }
#line 1407 "parser.cpp"
    break;

  case 65: // variable_function: build_in_function
#line 660 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1413 "parser.cpp"
    break;

  case 66: // variable_function: result_array_functions
#line 661 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1419 "parser.cpp"
    break;

  case 67: // variable_function: invoke_user_functions
#line 662 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1425 "parser.cpp"
    break;

  case 68: // variable_function: '-' "double constant"
#line 663 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(yystack_[0].value.as < double > () * -1); }
#line 1431 "parser.cpp"
    break;

  case 69: // variable_function: "double constant"
#line 664 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(yystack_[0].value.as < double > ()); }
#line 1437 "parser.cpp"
    break;

  case 70: // variable_function: '-' "Identifier"
#line 665 "./_parser_bison.y"
                                                {
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Multiplication);
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(double(-1)));
                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(std::make_shared<TActionNode>(TActionType::Identifier, yystack_[0].value.as < std::string > ()));
                                                }
#line 1447 "parser.cpp"
    break;

  case 71: // variable_function: "Identifier"
#line 670 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Identifier, yystack_[0].value.as < std::string > ()); }
#line 1453 "parser.cpp"
    break;

  case 72: // variable_function: "true"
#line 671 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::True); }
#line 1459 "parser.cpp"
    break;

  case 73: // variable_function: "false"
#line 672 "./_parser_bison.y"
                                                { yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::False); }
#line 1465 "parser.cpp"
    break;

  case 74: // function_argument: math_expression
#line 678 "./_parser_bison.y"
                                        { yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[0].value.as < std::shared_ptr<TActionNode> > (); }
#line 1471 "parser.cpp"
    break;

  case 75: // function_arguments: function_arguments ';' math_expression
#line 684 "./_parser_bison.y"
                                                                {
                                                                    if (yystack_[2].value.as < std::shared_ptr<TActionNode> > () == nullptr)
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                    }
                                                                    else
                                                                    {
                                                                        yylhs.value.as < std::shared_ptr<TActionNode> > () = yystack_[2].value.as < std::shared_ptr<TActionNode> > ();
                                                                    }
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                }
#line 1487 "parser.cpp"
    break;

  case 76: // function_arguments: math_expression
#line 695 "./_parser_bison.y"
                                                                {
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::FunctionArguments);
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[0].value.as < std::shared_ptr<TActionNode> > ());
                                                                }
#line 1496 "parser.cpp"
    break;

  case 77: // build_in_function: "Pi" '(' ')'
#line 704 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Pi); }
#line 1502 "parser.cpp"
    break;

  case 78: // build_in_function: "ErrorValue" '(' ')'
#line 705 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ErrorValue); }
#line 1508 "parser.cpp"
    break;

  case 79: // build_in_function: "IsErrorValue" '(' function_argument ')'
#line 706 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::IsErrorValue);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1517 "parser.cpp"
    break;

  case 80: // build_in_function: "IfErrorValueDef" '(' function_argument ';' function_argument ')'
#line 710 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::IfErrValueDef);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1527 "parser.cpp"
    break;

  case 81: // build_in_function: "Ln" '(' function_argument ')'
#line 715 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Ln);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1536 "parser.cpp"
    break;

  case 82: // build_in_function: "Lg" '(' function_argument ')'
#line 719 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Lg);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1545 "parser.cpp"
    break;

  case 83: // build_in_function: "Sin" '(' function_argument ')'
#line 723 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Sin);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1554 "parser.cpp"
    break;

  case 84: // build_in_function: "Cos" '(' function_argument ')'
#line 727 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Cos);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1563 "parser.cpp"
    break;

  case 85: // build_in_function: "Tan" '(' function_argument ')'
#line 731 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Tan);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1572 "parser.cpp"
    break;

  case 86: // build_in_function: "CoTan" '(' function_argument ')'
#line 735 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::CoTan);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1581 "parser.cpp"
    break;

  case 87: // build_in_function: "Sec" '(' function_argument ')'
#line 739 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Sec);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1590 "parser.cpp"
    break;

  case 88: // build_in_function: "Csc" '(' function_argument ')'
#line 743 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Csc);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1599 "parser.cpp"
    break;

  case 89: // build_in_function: "ASin" '(' function_argument ')'
#line 747 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ASin);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1608 "parser.cpp"
    break;

  case 90: // build_in_function: "ACos" '(' function_argument ')'
#line 751 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ACos);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1617 "parser.cpp"
    break;

  case 91: // build_in_function: "ATan" '(' function_argument ')'
#line 755 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ATan);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1626 "parser.cpp"
    break;

  case 92: // build_in_function: "ACoTan" '(' function_argument ')'
#line 759 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ACoTan);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1635 "parser.cpp"
    break;

  case 93: // build_in_function: "ASec" '(' function_argument ')'
#line 763 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ASec);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1644 "parser.cpp"
    break;

  case 94: // build_in_function: "ACsc" '(' function_argument ')'
#line 767 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ACsc);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1653 "parser.cpp"
    break;

  case 95: // build_in_function: "SinH" '(' function_argument ')'
#line 771 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::SinH);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1662 "parser.cpp"
    break;

  case 96: // build_in_function: "CosH" '(' function_argument ')'
#line 775 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::CosH);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1671 "parser.cpp"
    break;

  case 97: // build_in_function: "TanH" '(' function_argument ')'
#line 779 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::TanH);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1680 "parser.cpp"
    break;

  case 98: // build_in_function: "ASinH" '(' function_argument ')'
#line 783 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ASinH);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1689 "parser.cpp"
    break;

  case 99: // build_in_function: "ACosH" '(' function_argument ')'
#line 787 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ACosH);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1698 "parser.cpp"
    break;

  case 100: // build_in_function: "ATanH" '(' function_argument ')'
#line 791 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ATanH);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1707 "parser.cpp"
    break;

  case 101: // build_in_function: "Abs" '(' function_argument ')'
#line 795 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Abs);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1716 "parser.cpp"
    break;

  case 102: // build_in_function: "Sqrt" '(' function_argument ')'
#line 799 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Sqrt);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1725 "parser.cpp"
    break;

  case 103: // build_in_function: "Int" '(' function_argument ')'
#line 803 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Int);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1734 "parser.cpp"
    break;

  case 104: // build_in_function: "Frac" '(' function_argument ')'
#line 807 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Frac);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1743 "parser.cpp"
    break;

  case 105: // build_in_function: "Sqr" '(' function_argument ')'
#line 811 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Sqr);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1752 "parser.cpp"
    break;

  case 106: // build_in_function: "Cube" '(' function_argument ')'
#line 815 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Cube);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1761 "parser.cpp"
    break;

  case 107: // build_in_function: "Round" '(' function_argument ')'
#line 819 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Round);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1770 "parser.cpp"
    break;

  case 108: // build_in_function: "Fact" '(' function_argument ')'
#line 823 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Fact);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1779 "parser.cpp"
    break;

  case 109: // build_in_function: "Pow" '(' function_argument ';' function_argument ')'
#line 827 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Pow);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1789 "parser.cpp"
    break;

  case 110: // build_in_function: "Inc" '(' function_argument ';' function_argument ')'
#line 832 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Inc);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1799 "parser.cpp"
    break;

  case 111: // build_in_function: "Dec" '(' function_argument ';' function_argument ')'
#line 837 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Dec);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 1809 "parser.cpp"
    break;

  case 112: // build_in_function: "Sum" '(' function_arguments ')'
#line 842 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Sum);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1818 "parser.cpp"
    break;

  case 113: // build_in_function: "Max" '(' function_arguments ')'
#line 846 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Max);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1827 "parser.cpp"
    break;

  case 114: // build_in_function: "Min" '(' function_arguments ')'
#line 850 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Min);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1836 "parser.cpp"
    break;

  case 115: // build_in_function: "Avg" '(' function_arguments ')'
#line 854 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Avg);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1845 "parser.cpp"
    break;

  case 116: // build_in_function: "Prod" '(' function_arguments ')'
#line 858 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Prod);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1854 "parser.cpp"
    break;

  case 117: // build_in_function: "Poly" '(' function_arguments ')'
#line 862 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Poly);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1863 "parser.cpp"
    break;

  case 118: // result_array_functions: "ArraySize" '(' ')'
#line 871 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArraySize); }
#line 1869 "parser.cpp"
    break;

  case 119: // result_array_functions: "ArrayAt" '(' function_argument ')'
#line 872 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayAt);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1878 "parser.cpp"
    break;

  case 120: // result_array_functions: "ArrayFront" '(' ')'
#line 876 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayFront); }
#line 1884 "parser.cpp"
    break;

  case 121: // result_array_functions: "ArrayBack" '(' ')'
#line 877 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayBack); }
#line 1890 "parser.cpp"
    break;

  case 122: // result_array_functions: "ArrayProd" '(' ')'
#line 878 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayProd); }
#line 1896 "parser.cpp"
    break;

  case 123: // result_array_functions: "ArrayProd" '(' function_argument ';' function_argument ')'
#line 879 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayProd);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1906 "parser.cpp"
    break;

  case 124: // result_array_functions: "ArrayAvg" '(' ')'
#line 884 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayAvg); }
#line 1912 "parser.cpp"
    break;

  case 125: // result_array_functions: "ArrayAvg" '(' function_argument ';' function_argument ')'
#line 885 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayAvg);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1922 "parser.cpp"
    break;

  case 126: // result_array_functions: "ArrayMin" '(' ')'
#line 890 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayMin); }
#line 1928 "parser.cpp"
    break;

  case 127: // result_array_functions: "ArrayMin" '(' function_argument ';' function_argument ')'
#line 891 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayMin);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1938 "parser.cpp"
    break;

  case 128: // result_array_functions: "ArrayMax" '(' ')'
#line 896 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayMax); }
#line 1944 "parser.cpp"
    break;

  case 129: // result_array_functions: "ArrayMax" '(' function_argument ';' function_argument ')'
#line 897 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayMax);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1954 "parser.cpp"
    break;

  case 130: // result_array_functions: "ArraySum" '(' ')'
#line 902 "./_parser_bison.y"
                                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArraySum); }
#line 1960 "parser.cpp"
    break;

  case 131: // result_array_functions: "ArraySum" '(' function_argument ';' function_argument ')'
#line 903 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArraySum);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1970 "parser.cpp"
    break;

  case 132: // result_array_functions: "ArrayPoly" '(' function_argument ')'
#line 908 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayPoly);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1979 "parser.cpp"
    break;

  case 133: // result_array_functions: "ArrayPoly" '(' function_argument ';' function_argument ';' function_argument ')'
#line 912 "./_parser_bison.y"
                                                                                                            {
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::ArrayPoly);
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[5].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                            }
#line 1990 "parser.cpp"
    break;

  case 134: // void_array_function: "void_ArrayInit" '(' function_arguments ')'
#line 923 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayInit);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 1999 "parser.cpp"
    break;

  case 135: // void_array_function: "ArrayInitIfEmpty" '(' function_arguments ')'
#line 927 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayInitIfEmpty);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 2008 "parser.cpp"
    break;

  case 136: // void_array_function: "void_ArrayClear" '(' ')'
#line 931 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayClear); }
#line 2014 "parser.cpp"
    break;

  case 137: // void_array_function: "void_ArrayPushBack" '(' function_arguments ')'
#line 932 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayPushBack);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 2023 "parser.cpp"
    break;

  case 138: // void_array_function: "void_ArrayPushFront" '(' function_arguments ')'
#line 936 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayPushFront);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 2032 "parser.cpp"
    break;

  case 139: // void_array_function: "void_ArrayPopBack" '(' ')'
#line 940 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayPopBack); }
#line 2038 "parser.cpp"
    break;

  case 140: // void_array_function: "void_ArrayPopFront" '(' ')'
#line 941 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayPopFront); }
#line 2044 "parser.cpp"
    break;

  case 141: // void_array_function: "void_ArrayAt" '(' function_argument ';' function_argument ')'
#line 942 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayAt);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2054 "parser.cpp"
    break;

  case 142: // void_array_function: "void_ArrayInsert" '(' function_argument ';' function_arguments ')'
#line 947 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayInsert);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNodes(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 2064 "parser.cpp"
    break;

  case 143: // void_array_function: "void_ArrayErase" '(' function_argument ')'
#line 952 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayErase);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2073 "parser.cpp"
    break;

  case 144: // void_array_function: "void_ArrayErase" '(' function_argument ';' function_argument ')'
#line 956 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayErase);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2083 "parser.cpp"
    break;

  case 145: // void_array_function: "void_ArrayEraseValue" '(' function_arguments ')'
#line 961 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayEraseValue);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                                            }
#line 2092 "parser.cpp"
    break;

  case 146: // void_array_function: "void_ArrayResize" '(' function_argument ')'
#line 965 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayResize);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2101 "parser.cpp"
    break;

  case 147: // void_array_function: "void_ArrayResize" '(' function_argument ';' function_argument ')'
#line 969 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayResize);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2111 "parser.cpp"
    break;

  case 148: // void_array_function: "void_ArraySort" '(' ')'
#line 974 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArraySort); }
#line 2117 "parser.cpp"
    break;

  case 149: // void_array_function: "void_ArraySort" '(' function_argument ';' function_argument ')'
#line 975 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArraySort);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2127 "parser.cpp"
    break;

  case 150: // void_array_function: "void_ArrayReverse" '(' ')'
#line 980 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayReverse); }
#line 2133 "parser.cpp"
    break;

  case 151: // void_array_function: "void_ArrayReverse" '(' function_argument ';' function_argument ')'
#line 981 "./_parser_bison.y"
                                                                                            {
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayReverse);
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[3].value.as < std::shared_ptr<TActionNode> > ());
                                                                                                yylhs.value.as < std::shared_ptr<TActionNode> > ()->AddNode(yystack_[1].value.as < std::shared_ptr<TActionNode> > ());
                                                                                            }
#line 2143 "parser.cpp"
    break;

  case 152: // void_array_function: "void_ArrayUnique" '(' ')'
#line 986 "./_parser_bison.y"
                                                                                            {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::Void_ArrayUnique); }
#line 2149 "parser.cpp"
    break;

  case 153: // invoke_user_functions: "Identifier" '(' ')'
#line 992 "./_parser_bison.y"
                                                                {   yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::InvokeFunction, yystack_[2].value.as < std::string > ()); }
#line 2155 "parser.cpp"
    break;

  case 154: // invoke_user_functions: "Identifier" '(' function_arguments ')'
#line 993 "./_parser_bison.y"
                                                                {
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > () = std::make_shared<TActionNode>(TActionType::InvokeFunction, yystack_[3].value.as < std::string > ());
                                                                    yylhs.value.as < std::shared_ptr<TActionNode> > ()->Nodes = std::move(yystack_[1].value.as < std::shared_ptr<TActionNode> > ()->Nodes);
                                                                }
#line 2164 "parser.cpp"
    break;


#line 2168 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  TParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  TParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  TParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // TParser::context.
  TParser::context::context (const TParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  TParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  TParser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  TParser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short TParser::yypact_ninf_ = -337;

  const signed char TParser::yytable_ninf_ = -1;

  const short
  TParser::yypact_[] =
  {
      51,    59,    67,    64,    86,     4,    96,  -337,    99,    91,
      64,    51,  -337,   126,  -337,   155,   197,   425,   175,  -337,
    -337,  -337,    49,    97,  -337,    60,   112,  1165,  -337,  -337,
     195,   201,   103,   204,   205,   206,   207,   208,   210,   211,
     213,   214,   217,   218,   221,   228,   229,   230,   231,   232,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   259,   260,   262,   265,   275,   277,   278,   279,   282,
     292,   293,   294,   302,   303,   304,   306,   308,   314,   315,
     316,   318,   319,   320,   321,   322,   326,   327,   328,   329,
    -337,   425,   425,   216,   324,  -337,    68,    75,   150,   189,
    -337,  -337,   331,  -337,    91,  -337,   245,    -6,  1165,   525,
    -337,  -337,  1165,  1165,  1165,  1165,  1165,  -337,  -337,   332,
     330,  1165,  1165,   215,    50,   333,   335,  1165,  1165,  1165,
    1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,
    1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,
    1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,
    1165,  1165,  1165,  1165,  1165,  1165,  1165,  1165,   345,   346,
    1165,  1165,   347,   355,  1165,  1165,   356,   357,  1165,  1165,
    1165,  1165,   605,   358,   685,   765,   845,   925,  1005,  1085,
    1165,  -337,  -337,   425,  -337,  1165,  1165,  1165,  1165,  1165,
    1165,  1165,  1165,  1165,  1165,  1165,  1165,   425,  -337,    91,
     266,   367,  -337,  -337,  -337,     0,  -337,  -337,  -337,  -337,
    -337,  -337,   361,   363,   -25,   366,   215,   215,   271,   215,
     368,   369,  1165,   370,  -337,  -337,  -337,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   382,   384,   386,
     392,   399,   400,   401,   409,   410,   412,   413,   419,   421,
     422,   423,   426,   429,   430,   432,   436,   427,   439,   440,
      69,    85,    89,    93,   142,   143,   160,   161,  -337,  -337,
     164,   165,  -337,  -337,   482,   481,  -337,  -337,   484,   169,
     170,   176,  -337,   485,  -337,  -337,   486,  -337,   487,  -337,
     488,  -337,   489,  -337,   490,  -337,   491,   180,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,   425,    91,  -337,  1165,  -337,   323,   397,  -337,
    -337,  -337,   364,  -337,  -337,  -337,   493,  1165,  -337,  1165,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  1165,  1165,
    1165,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  1165,  -337,  1165,  1165,  -337,  -337,  1165,  -337,  1165,
    1165,  1165,  1165,  1165,  1165,  1165,  1165,  -337,   428,   425,
    -337,   215,   512,  -337,   215,   522,    53,   528,   523,   529,
     530,   531,   532,   184,   533,   534,   535,   536,   537,   538,
     580,   581,   582,   585,  -337,   492,   494,   269,   495,  1165,
     497,   584,   592,  -337,  -337,  -337,  -337,  -337,  -337,  -337,
    -337,  -337,  -337,  -337,  -337,  -337,  -337,  -337,  1165,  -337,
    -337,  -337,  -337,  -337,   587,   215,   498,   593,   595,  -337,
     502,   215,   499,  -337,  -337,   505,   215,  -337,   515,  -337
  };

  const unsigned char
  TParser::yydefact_[] =
  {
       3,     0,     0,     8,     0,     0,     0,     1,     0,    14,
       8,     3,     5,     0,     7,     0,     0,     0,     0,     9,
       4,     6,     0,    16,    69,    71,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     0,    47,    50,    57,    60,    63,
      65,    66,     0,    67,    14,    11,     0,     0,     0,     0,
      41,    42,     0,     0,     0,     0,     0,    68,    70,    71,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,    22,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,    14,
       0,     0,    17,   153,    76,     0,    43,    44,    45,    46,
      40,    64,     0,     0,     0,     0,    33,    33,     0,    33,
       0,     0,     0,     0,    77,    78,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   136,
       0,     0,   139,   140,     0,     0,   120,   121,     0,     0,
       0,     0,   148,     0,   152,   150,     0,   122,     0,   124,
       0,   126,     0,   128,     0,   130,     0,     0,    19,    48,
      49,    53,    54,    55,    56,    51,    52,    58,    59,    61,
      62,    20,     0,    14,    10,     0,   154,     0,     0,    37,
      35,    36,     0,    34,    38,    39,     0,     0,    79,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   134,   135,   137,
     138,     0,   119,     0,     0,   143,   145,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,   132,     0,     0,
      75,    33,    23,    27,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,    80,   109,   110,   111,   141,   142,   144,
     147,   149,   151,   123,   125,   127,   129,   131,     0,    13,
      26,    25,    24,    28,     0,    33,     0,     0,     0,    29,
       0,    33,     0,   133,    32,     0,    33,    31,     0,    30
  };

  const short
  TParser::yypgoto_[] =
  {
    -337,  -337,   606,  -337,   611,  -337,  -337,  -111,  -337,   -89,
     -15,   191,   -11,  -181,  -336,   -17,   -13,    -7,   -62,    -4,
      -3,  -337,  -123,   -50,  -337,  -337,    -9,  -337
  };

  const short
  TParser::yydefgoto_[] =
  {
       0,     2,     3,     4,     9,   117,    10,    17,    18,   100,
     236,   412,   237,   238,   239,   240,   246,   105,   106,   107,
     108,   109,   247,   225,   110,   111,   241,   113
  };

  const short
  TParser::yytable_[] =
  {
     103,   413,   101,   218,   104,   220,   102,    12,   112,   335,
      13,   336,   201,   202,   130,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   120,   121,   122,
     123,   124,   125,   115,   234,   340,   341,   234,   343,   242,
     116,   294,   295,     1,   440,   298,   299,     7,   301,   303,
     119,   306,   308,   310,   312,   314,   316,   317,   335,     8,
     381,   126,     5,     6,   103,   103,   101,   101,   104,   104,
     102,   102,   112,   112,   335,    11,   382,   221,   335,    14,
     383,   413,   335,    15,   384,   222,   224,    16,   332,   226,
     227,   228,   229,   230,   318,   127,   128,   243,   232,   233,
     280,   281,   282,   283,   284,   285,   286,   287,   331,    21,
     290,   291,   120,   121,   122,   123,   124,   125,   205,   206,
     300,   207,   208,   209,   210,   321,   322,   323,   324,   325,
     326,   335,   335,   385,   386,   213,   214,   224,   224,   224,
     224,   224,   224,   224,   224,    22,   126,   224,   224,   335,
     335,   387,   388,   335,   335,   389,   390,   224,   394,   335,
     395,   396,   211,   212,   114,   397,   103,   398,   101,   406,
     104,   407,   102,   335,   112,   448,   215,   216,   319,   320,
     103,    23,   101,   118,   104,   131,   102,   133,   112,   327,
     328,   132,   329,   330,   134,   135,   136,   137,   138,   234,
     139,   140,   409,   141,   142,   203,   418,   143,   144,   346,
     436,   145,    30,   438,    31,    32,    33,   235,   146,   147,
     148,   149,   150,   408,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   419,   420,   421,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   422,   172,
     173,   424,   174,   234,   425,   175,   426,   427,   428,   429,
     430,   431,   432,   433,   470,   176,    30,   177,   178,   179,
     475,   235,   180,    75,    76,   478,    78,    79,    80,    81,
      82,    83,   181,   182,   183,    87,    88,    89,    90,    91,
      92,    93,   184,   185,   186,   103,   187,   101,   188,   104,
     435,   102,   410,   112,   189,   190,   191,   234,   192,   193,
     194,   195,   196,   204,   417,   468,   197,   198,   199,   200,
     217,   231,   119,   423,   244,   235,   245,    75,    76,   219,
      78,    79,    80,    81,    82,    83,   288,   289,   292,    87,
      88,    89,    90,    91,    92,    93,   293,   296,   297,   304,
     333,   334,   337,   411,   338,   339,   342,   344,   345,   347,
     224,   349,   348,   415,   350,   351,   352,   353,   354,   355,
     356,   357,   103,   358,   101,   359,   104,   360,   102,   441,
     112,    75,    76,   361,    78,    79,    80,    81,    82,    83,
     362,   363,   364,    87,    88,    89,    90,    91,    92,    93,
     365,   366,   461,   367,   368,   467,   464,   411,    24,    25,
     369,    26,   370,   371,   372,    27,   378,   373,    28,    29,
     374,   375,    30,   376,    31,    32,    33,   377,   379,   380,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   391,   392,   393,   399,   400,   401,   402,   403,   404,
     405,   414,   416,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,    24,   129,
     437,    26,   439,   434,   443,    27,   223,   442,    28,    29,
     444,   445,   446,   447,   449,   450,   451,   452,   453,   454,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   455,   456,   457,   458,   466,   234,   459,   469,   460,
     463,   465,   471,   476,   472,    77,   473,   474,    24,   129,
     477,    26,    84,    85,    86,    27,   302,    20,    28,    29,
     479,    19,    94,    95,    96,    97,    98,    99,   462,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,   305,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,   307,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,   309,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,   311,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,   313,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,   315,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,    24,   129,
       0,    26,    84,    85,    86,    27,     0,     0,    28,    29,
       0,     0,    94,    95,    96,    97,    98,    99,     0,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99
  };

  const short
  TParser::yycheck_[] =
  {
      17,   337,    17,   114,    17,    11,    17,     3,    17,     9,
       6,    11,   101,   102,    27,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,    72,    73,    74,
      75,    76,    77,     4,     4,   236,   237,     4,   239,     9,
      11,   184,   185,    12,    11,   188,   189,     0,   191,   192,
      10,   194,   195,   196,   197,   198,   199,   200,     9,    15,
      11,   106,    23,    24,   101,   102,   101,   102,   101,   102,
     101,   102,   101,   102,     9,     9,    11,   103,     9,     3,
      11,   437,     9,     4,    11,   118,   119,    16,   219,   122,
     123,   124,   125,   126,   203,     3,     4,   134,   131,   132,
     170,   171,   172,   173,   174,   175,   176,   177,   217,     3,
     180,   181,    72,    73,    74,    75,    76,    77,    70,    71,
     190,    66,    67,    68,    69,   207,   208,   209,   210,   211,
     212,     9,     9,    11,    11,     5,     6,   170,   171,   172,
     173,   174,   175,   176,   177,    10,   106,   180,   181,     9,
       9,    11,    11,     9,     9,    11,    11,   190,     9,     9,
      11,    11,   107,   108,     9,     9,   203,    11,   203,     9,
     203,    11,   203,     9,   203,    11,     7,     8,   205,   206,
     217,     4,   217,   106,   217,    10,   217,   104,   217,   213,
     214,    10,   215,   216,    10,    10,    10,    10,    10,     4,
      10,    10,   333,    10,    10,     9,   349,    10,    10,   242,
     411,    10,    17,   414,    19,    20,    21,    22,    10,    10,
      10,    10,    10,   332,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,   378,   379,   380,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,   391,    10,
      10,   394,    10,     4,   397,    10,   399,   400,   401,   402,
     403,   404,   405,   406,   465,    10,    17,    10,    10,    10,
     471,    22,    10,    78,    79,   476,    81,    82,    83,    84,
      85,    86,    10,    10,    10,    90,    91,    92,    93,    94,
      95,    96,    10,    10,    10,   332,    10,   332,    10,   332,
     409,   332,   335,   332,    10,    10,    10,     4,    10,    10,
      10,    10,    10,     9,   347,   458,    10,    10,    10,    10,
       9,    11,    10,   393,    11,    22,    11,    78,    79,   104,
      81,    82,    83,    84,    85,    86,    11,    11,    11,    90,
      91,    92,    93,    94,    95,    96,    11,    11,    11,    11,
     104,     4,    11,   104,    11,     9,   105,     9,     9,     9,
     393,     9,    11,    19,    11,    11,    11,    11,    11,    11,
      11,    11,   409,    11,   409,    11,   409,    11,   409,   416,
     409,    78,    79,    11,    81,    82,    83,    84,    85,    86,
      11,    11,    11,    90,    91,    92,    93,    94,    95,    96,
      11,    11,   437,    11,    11,   442,   439,   104,     3,     4,
      11,     6,    11,    11,    11,    10,     9,    11,    13,    14,
      11,    11,    17,    11,    19,    20,    21,    11,     9,     9,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     9,    11,     9,     9,     9,     9,     9,     9,     9,
       9,   104,     9,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     3,     4,
      18,     6,    10,   105,    11,    10,    11,     9,    13,    14,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    11,    11,    11,     9,    11,     4,   105,    11,   105,
     105,   104,   104,   104,    11,    80,    11,   105,     3,     4,
     105,     6,    87,    88,    89,    10,    11,    11,    13,    14,
     105,    10,    97,    98,    99,   100,   101,   102,   437,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    11,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    11,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    11,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    11,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    11,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    11,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
      -1,     6,    87,    88,    89,    10,    -1,    -1,    13,    14,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102
  };

  const unsigned char
  TParser::yystos_[] =
  {
       0,    12,   110,   111,   112,    23,    24,     0,    15,   113,
     115,     9,     3,     6,     3,     4,    16,   116,   117,   113,
     111,     3,    10,     4,     3,     4,     6,    10,    13,    14,
      17,    19,    20,    21,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     118,   119,   121,   124,   125,   126,   127,   128,   129,   130,
     133,   134,   135,   136,     9,     4,    11,   114,   106,    10,
      72,    73,    74,    75,    76,    77,   106,     3,     4,     4,
     125,    10,    10,   104,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,    10,    10,
      10,   118,   118,     9,     9,    70,    71,    66,    67,    68,
      69,   107,   108,     5,     6,     7,     8,     9,   116,   104,
      11,   103,   125,    11,   125,   132,   125,   125,   125,   125,
     125,    11,   125,   125,     4,    22,   119,   121,   122,   123,
     124,   135,     9,   124,    11,    11,   125,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   132,    11,    11,
     132,   132,    11,    11,   131,   131,    11,    11,   131,   131,
     132,   131,    11,   131,    11,    11,   131,    11,   131,    11,
     131,    11,   131,    11,   131,    11,   131,   131,   118,   126,
     126,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   118,   116,   104,     4,     9,    11,    11,    11,     9,
     122,   122,   105,   122,     9,     9,   125,     9,    11,     9,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,     9,     9,
       9,    11,    11,    11,    11,    11,    11,    11,    11,    11,
      11,     9,    11,     9,     9,    11,    11,     9,    11,     9,
       9,     9,     9,     9,     9,     9,     9,    11,   118,   116,
     125,   104,   120,   123,   104,    19,     9,   125,   131,   131,
     131,   131,   131,   132,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   105,   118,   122,    18,   122,    10,
      11,   124,     9,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    11,    11,    11,    11,    11,    11,     9,   105,
     105,   119,   120,   105,   125,   104,    11,   124,   131,    11,
     122,   104,    11,    11,   105,   122,   104,   105,   122,   105
  };

  const unsigned char
  TParser::yyr1_[] =
  {
       0,   109,   110,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   119,   119,   119,   120,   120,   121,   121,
     121,   121,   121,   122,   122,   122,   122,   123,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   125,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   127,   128,   128,
     128,   129,   129,   129,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   136,   136
  };

  const signed char
  TParser::yyr2_[] =
  {
       0,     2,     4,     0,     3,     3,     4,     3,     0,     2,
       3,     1,     8,     9,     0,     3,     2,     4,     2,     3,
       3,     2,     2,     5,     7,     7,     3,     1,     7,     8,
      11,    10,     9,     0,     2,     2,     2,     2,     2,     2,
       3,     2,     2,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     3,     1,     3,     3,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     4,     4,     4,     4,     4,     4,     3,     4,
       3,     3,     3,     6,     3,     6,     3,     6,     3,     6,
       3,     6,     4,     8,     4,     4,     3,     4,     4,     3,
       3,     6,     6,     4,     6,     4,     4,     6,     3,     6,
       3,     6,     3,     3,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const TParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"double constant\"",
  "\"Identifier\"", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "'#'",
  "\"true\"", "\"false\"", "\"function\"", "\"var\"", "\"if\"", "\"else\"",
  "\"while\"", "\"do\"", "\"for\"", "\"break\"", "\"error_value\"",
  "\"loop_limit\"", "\"Pi\"", "\"ErrorValue\"", "\"IsErrorValue\"",
  "\"IfErrorValueDef\"", "\"Ln\"", "\"Lg\"", "\"Sin\"", "\"Cos\"",
  "\"Tan\"", "\"CoTan\"", "\"Sec\"", "\"Csc\"", "\"ASin\"", "\"ACos\"",
  "\"ATan\"", "\"ACoTan\"", "\"ASec\"", "\"ACsc\"", "\"SinH\"", "\"CosH\"",
  "\"TanH\"", "\"ASinH\"", "\"ACosH\"", "\"ATanH\"", "\"Abs\"", "\"Sqrt\"",
  "\"Int\"", "\"Frac\"", "\"Sqr\"", "\"Cube\"", "\"Round\"", "\"Fact\"",
  "\"Pow\"", "\"Inc\"", "\"Dec\"", "\"Sum\"", "\"Max\"", "\"Min\"",
  "\"Avg\"", "\"Prod\"", "\"Poly\"", "\"==\"", "\"!=\"", "\"<=\"",
  "\">=\"", "\"&&\"", "\"||\"", "\"++\"", "\"--\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"void_ArrayInit\"", "\"ArrayInitIfEmpty\"",
  "\"ArraySize\"", "\"void_ArrayClear\"", "\"void_ArrayPushBack\"",
  "\"void_ArrayPushFront\"", "\"void_ArrayPopBack\"",
  "\"void_ArrayPopFront\"", "\"void_ArrayAt\"", "\"ArrayAt\"",
  "\"ArrayFront\"", "\"ArrayBack\"", "\"void_ArrayInsert\"",
  "\"void_ArrayErase\"", "\"void_ArrayEraseValue\"",
  "\"void_ArrayResize\"", "\"void_ArraySort\"", "\"void_ArrayUnique\"",
  "\"void_ArrayReverse\"", "\"ArrayProd\"", "\"ArrayAvg\"", "\"ArrayMin\"",
  "\"ArrayMax\"", "\"ArraySum\"", "\"ArrayPoly\"", "','", "'{'", "'}'",
  "'='", "'>'", "'<'", "$accept", "program", "options", "option",
  "function_declarations", "function_declaration_arguments",
  "function_declaration", "variables", "variable", "program_expression",
  "if_expression", "if_block_expression", "loop_expression",
  "block_expression", "one_block_expression", "identifier_operation",
  "math_expression", "math_and_or", "math_compare", "plus_minus",
  "multiplication_division", "variable_function", "function_argument",
  "function_arguments", "build_in_function", "result_array_functions",
  "void_array_function", "invoke_user_functions", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  TParser::yyrline_[] =
  {
       0,   220,   220,   231,   232,   248,   252,   256,   265,   266,
     281,   292,   301,   306,   317,   318,   334,   338,   348,   352,
     363,   374,   385,   401,   407,   415,   427,   428,   434,   439,
     444,   451,   458,   470,   476,   487,   498,   514,   518,   522,
     531,   536,   540,   544,   549,   554,   559,   569,   575,   580,
     585,   591,   596,   601,   606,   611,   616,   621,   627,   632,
     637,   643,   648,   653,   659,   660,   661,   662,   663,   664,
     665,   670,   671,   672,   678,   684,   695,   704,   705,   706,
     710,   715,   719,   723,   727,   731,   735,   739,   743,   747,
     751,   755,   759,   763,   767,   771,   775,   779,   783,   787,
     791,   795,   799,   803,   807,   811,   815,   819,   823,   827,
     832,   837,   842,   846,   850,   854,   858,   862,   871,   872,
     876,   877,   878,   879,   884,   885,   890,   891,   896,   897,
     902,   903,   908,   912,   923,   927,   931,   932,   936,   940,
     941,   942,   947,   952,   956,   961,   965,   969,   974,   975,
     980,   981,   986,   992,   993
  };

  void
  TParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  TParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 6 "./_parser_bison.y"
} // CalcPlusPlus
#line 3099 "parser.cpp"

#line 998 "./_parser_bison.y"



//
// Функция обработки ошибок
//
void CalcPlusPlus::TParser::error(const location& loc, const std::string& msg)
{
    if (std::string matcher_line(lexer.matcher().line()); matcher_line.empty())
    {
        Framework::String::TStringFormater::VoidFormat(error_msg, "Ошибка ({0}:{1}): {2}.",
                        loc.begin.line,
                        loc.begin.column,
                        msg);
    }
    else
    {
        std::string match_error("");

        for (int i = 0; i < loc.begin.column; ++i) match_error += " ";

        for (int i = loc.begin.column; i <= loc.end.column; ++i) match_error += "~";

        Framework::String::TStringFormater::VoidFormat(error_msg, "Ошибка ({0}:{1}): {2}.\n\t{3}\n\t{4}",
                        loc.begin.line,
                        loc.begin.column,
                        msg,
                        matcher_line,
                        match_error);
    }

    VOID_AUTO_ENCODING(std::string, error_msg);
}
