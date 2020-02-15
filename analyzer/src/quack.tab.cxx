// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "quack.tab.hxx"


// Unqualified %code blocks.
#line 30 "quack.yxx"

    #include "lex.yy.h"
    #undef yylex
    #define yylex lexer.yylex  /* Within bison's parse() we should invoke lexer.yylex(), not the global yylex() */
    void debug(AST::ASTNode* n);


#line 53 "quack.tab.cxx"


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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 144 "quack.tab.cxx"


  /// Build a parser object.
  parser::parser (yy::Lexer& lexer_yyarg, AST::ASTNode** root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value (std::move (that.value))
    , location (std::move (that.location))
  {}
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_type.
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
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
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

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
  case 2:
#line 142 "quack.yxx"
        { (yylhs.value.node) = new AST::Program(*(yystack_[1].value.classes), *(yystack_[0].value.block));
          // std::cerr << "Transmitting root to driver\n";
          *root = (yylhs.value.node); // Transmit tree back to driver
          // std::cerr << "Transmitted root to driver\n";
        }
#line 604 "quack.tab.cxx"
    break;

  case 3:
#line 152 "quack.yxx"
                            {  (yylhs.value.classes) = (yystack_[1].value.classes); (yylhs.value.classes)->append((yystack_[0].value.clas)); }
#line 610 "quack.tab.cxx"
    break;

  case 4:
#line 153 "quack.yxx"
                            {  (yylhs.value.classes) = new AST::Classes(); }
#line 616 "quack.tab.cxx"
    break;

  case 5:
#line 159 "quack.yxx"
                                  { (yylhs.value.block) = (yystack_[1].value.block);
                                    (yylhs.value.block)->append((yystack_[0].value.statement));
                                  }
#line 624 "quack.tab.cxx"
    break;

  case 6:
#line 162 "quack.yxx"
                                  { (yylhs.value.block) = new AST::Block(); }
#line 630 "quack.tab.cxx"
    break;

  case 7:
#line 168 "quack.yxx"
  {  (yylhs.value.block) = (yystack_[2].value.block); }
#line 636 "quack.tab.cxx"
    break;

  case 8:
#line 178 "quack.yxx"
               { (yylhs.value.clas) = new AST::Class(*(yystack_[8].value.ident), *(yystack_[4].value.ident), *(new AST::Method(*(yystack_[8].value.ident), *(yystack_[6].value.formals), *(yystack_[8].value.ident), *(yystack_[2].value.block))), *(yystack_[1].value.methods)); }
#line 642 "quack.tab.cxx"
    break;

  case 9:
#line 181 "quack.yxx"
                               { (yylhs.value.ident) = new AST::Ident(*(yystack_[0].value.ident)); }
#line 648 "quack.tab.cxx"
    break;

  case 10:
#line 182 "quack.yxx"
                             { (yylhs.value.ident) = new AST::Ident("Obj"); }
#line 654 "quack.tab.cxx"
    break;

  case 11:
#line 185 "quack.yxx"
                               { (yylhs.value.formals) = (yystack_[0].value.formals); }
#line 660 "quack.tab.cxx"
    break;

  case 12:
#line 186 "quack.yxx"
                         { (yylhs.value.formals) = new AST::Formals(); }
#line 666 "quack.tab.cxx"
    break;

  case 13:
#line 189 "quack.yxx"
                                                    { (yylhs.value.formals) = (yystack_[2].value.formals); (yylhs.value.formals)->append((yystack_[0].value.formal)); }
#line 672 "quack.tab.cxx"
    break;

  case 14:
#line 190 "quack.yxx"
                              { (yylhs.value.formals) = new AST::Formals(); (yylhs.value.formals) -> append((yystack_[0].value.formal)); }
#line 678 "quack.tab.cxx"
    break;

  case 15:
#line 193 "quack.yxx"
                            { (yylhs.value.formal) = new AST::Formal(*(yystack_[2].value.ident), *(yystack_[0].value.ident)); }
#line 684 "quack.tab.cxx"
    break;

  case 16:
#line 200 "quack.yxx"
                        { (yylhs.value.methods) = (yystack_[1].value.methods); (yylhs.value.methods)->append((yystack_[0].value.method)); }
#line 690 "quack.tab.cxx"
    break;

  case 17:
#line 201 "quack.yxx"
                     { (yylhs.value.methods) = new AST::Methods(); }
#line 696 "quack.tab.cxx"
    break;

  case 18:
#line 205 "quack.yxx"
        { (yylhs.value.method) = new AST::Method(*(yystack_[5].value.ident), *(yystack_[3].value.formals), *(yystack_[1].value.ident), *(yystack_[0].value.block)); }
#line 702 "quack.tab.cxx"
    break;

  case 19:
#line 208 "quack.yxx"
                            { (yylhs.value.ident) = (yystack_[0].value.ident); }
#line 708 "quack.tab.cxx"
    break;

  case 20:
#line 209 "quack.yxx"
                              { (yylhs.value.ident) = new AST::Ident("none"); }
#line 714 "quack.tab.cxx"
    break;

  case 21:
#line 228 "quack.yxx"
             { (yylhs.value.statement) = new AST::If(*(yystack_[2].value.expr), *(yystack_[1].value.block), *(yystack_[0].value.block)); }
#line 720 "quack.tab.cxx"
    break;

  case 22:
#line 230 "quack.yxx"
         { (yylhs.value.statement) = new AST::While(*(yystack_[1].value.expr), *(yystack_[0].value.block)); }
#line 726 "quack.tab.cxx"
    break;

  case 23:
#line 234 "quack.yxx"
             { (yylhs.value.block) = new AST::Block();
               (yylhs.value.block)->append(new AST::If(*(yystack_[2].value.expr), *(yystack_[1].value.block), *(yystack_[0].value.block)));
             }
#line 734 "quack.tab.cxx"
    break;

  case 24:
#line 238 "quack.yxx"
             { (yylhs.value.block) = (yystack_[0].value.block); }
#line 740 "quack.tab.cxx"
    break;

  case 25:
#line 240 "quack.yxx"
             { (yylhs.value.block) = new AST::Block(); }
#line 746 "quack.tab.cxx"
    break;

  case 26:
#line 243 "quack.yxx"
                    { (yylhs.value.statement) = (yystack_[1].value.expr); }
#line 752 "quack.tab.cxx"
    break;

  case 27:
#line 253 "quack.yxx"
     { (yylhs.value.statement) = new AST::Assign(*(yystack_[3].value.l_expr), *(yystack_[1].value.expr)); }
#line 758 "quack.tab.cxx"
    break;

  case 28:
#line 257 "quack.yxx"
    {
      (yylhs.value.statement) = new AST::AssignDeclare(*(yystack_[5].value.l_expr), *(yystack_[1].value.expr), *(yystack_[3].value.ident));
    }
#line 766 "quack.tab.cxx"
    break;

  case 29:
#line 270 "quack.yxx"
              { (yylhs.value.l_expr) =  new AST::Ident((yystack_[0].value.str)); }
#line 772 "quack.tab.cxx"
    break;

  case 30:
#line 271 "quack.yxx"
                       { (yylhs.value.l_expr) = new AST::Dot(*(yystack_[2].value.expr), *(yystack_[0].value.ident)); }
#line 778 "quack.tab.cxx"
    break;

  case 31:
#line 287 "quack.yxx"
             { (yylhs.value.expr) = new AST::Load(*(yystack_[0].value.l_expr)); }
#line 784 "quack.tab.cxx"
    break;

  case 32:
#line 290 "quack.yxx"
                 { (yylhs.value.expr) = new AST::StrConst((yystack_[0].value.str)); }
#line 790 "quack.tab.cxx"
    break;

  case 33:
#line 291 "quack.yxx"
                 { (yylhs.value.expr) = new AST::IntConst((yystack_[0].value.num)); }
#line 796 "quack.tab.cxx"
    break;

  case 34:
#line 301 "quack.yxx"
                       { (yylhs.value.expr) = AST::Call::binop("TIMES", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 802 "quack.tab.cxx"
    break;

  case 35:
#line 302 "quack.yxx"
                       { (yylhs.value.expr) = AST::Call::binop("DIVIDE", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 808 "quack.tab.cxx"
    break;

  case 36:
#line 303 "quack.yxx"
                       { (yylhs.value.expr) = AST::Call::binop("PLUS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 814 "quack.tab.cxx"
    break;

  case 37:
#line 304 "quack.yxx"
                       { (yylhs.value.expr) = AST::Call::binop("MINUS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 820 "quack.tab.cxx"
    break;

  case 38:
#line 305 "quack.yxx"
                            {
                              auto zero = new AST::IntConst(0);
                              (yylhs.value.expr) = AST::Call::binop("MINUS", *zero, *(yystack_[0].value.expr));
                            }
#line 829 "quack.tab.cxx"
    break;

  case 39:
#line 309 "quack.yxx"
                   { (yylhs.value.expr) = (yystack_[1].value.expr); }
#line 835 "quack.tab.cxx"
    break;

  case 40:
#line 311 "quack.yxx"
                             { (yylhs.value.expr) = AST::Call::binop("EQUALS", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 841 "quack.tab.cxx"
    break;

  case 41:
#line 312 "quack.yxx"
                              { (yylhs.value.expr) = AST::Call::binop("ATLEAST", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 847 "quack.tab.cxx"
    break;

  case 42:
#line 313 "quack.yxx"
                             { (yylhs.value.expr) = AST::Call::binop("ATMOST", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 853 "quack.tab.cxx"
    break;

  case 43:
#line 314 "quack.yxx"
                          { (yylhs.value.expr) = AST::Call::binop("<", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 859 "quack.tab.cxx"
    break;

  case 44:
#line 315 "quack.yxx"
                          { (yylhs.value.expr) = AST::Call::binop(">", *(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 865 "quack.tab.cxx"
    break;

  case 45:
#line 318 "quack.yxx"
                          { (yylhs.value.expr) = new AST::And(*(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 871 "quack.tab.cxx"
    break;

  case 46:
#line 319 "quack.yxx"
                         { (yylhs.value.expr) = new AST::Or(*(yystack_[2].value.expr), *(yystack_[0].value.expr)); }
#line 877 "quack.tab.cxx"
    break;

  case 47:
#line 320 "quack.yxx"
                     { (yylhs.value.expr) = new AST::Not(*(yystack_[0].value.expr)); }
#line 883 "quack.tab.cxx"
    break;

  case 48:
#line 338 "quack.yxx"
 { (yylhs.value.expr) = new AST::Call(*(yystack_[5].value.expr), *(yystack_[3].value.ident), *(yystack_[1].value.actuals)); }
#line 889 "quack.tab.cxx"
    break;

  case 49:
#line 340 "quack.yxx"
                        { (yylhs.value.actuals) = new AST::Actuals(); }
#line 895 "quack.tab.cxx"
    break;

  case 50:
#line 341 "quack.yxx"
                          { (yylhs.value.actuals) = (yystack_[0].value.actuals); }
#line 901 "quack.tab.cxx"
    break;

  case 51:
#line 343 "quack.yxx"
                                          { (yylhs.value.actuals) = (yystack_[2].value.actuals); (yylhs.value.actuals)->append((yystack_[0].value.expr)); }
#line 907 "quack.tab.cxx"
    break;

  case 52:
#line 344 "quack.yxx"
                  { (yylhs.value.actuals) = new AST::Actuals(); (yylhs.value.actuals)->append((yystack_[0].value.expr)); }
#line 913 "quack.tab.cxx"
    break;

  case 53:
#line 349 "quack.yxx"
   { (yylhs.value.expr) = new AST::Construct(*(yystack_[3].value.ident), *(yystack_[1].value.actuals)); }
#line 919 "quack.tab.cxx"
    break;

  case 54:
#line 357 "quack.yxx"
                           { (yylhs.value.statement) = new AST::Return(*(yystack_[1].value.expr)); }
#line 925 "quack.tab.cxx"
    break;

  case 55:
#line 358 "quack.yxx"
                      { (yylhs.value.statement) = new AST::Return(*new AST::Ident("none")); }
#line 931 "quack.tab.cxx"
    break;

  case 56:
#line 366 "quack.yxx"
                    { (yylhs.value.statement) = (yystack_[0].value.typecase); }
#line 937 "quack.tab.cxx"
    break;

  case 57:
#line 370 "quack.yxx"
        { (yylhs.value.typecase) = new AST::Typecase(*(yystack_[3].value.expr), *(yystack_[1].value.type_alternatives)); }
#line 943 "quack.tab.cxx"
    break;

  case 58:
#line 373 "quack.yxx"
                                    { (yylhs.value.type_alternatives) = (yystack_[1].value.type_alternatives); (yylhs.value.type_alternatives)->append((yystack_[0].value.type_alternative)); }
#line 949 "quack.tab.cxx"
    break;

  case 59:
#line 374 "quack.yxx"
                          { (yylhs.value.type_alternatives) = new AST::Type_Alternatives();}
#line 955 "quack.tab.cxx"
    break;

  case 60:
#line 378 "quack.yxx"
        { (yylhs.value.type_alternative) = new AST::Type_Alternative(*(yystack_[3].value.ident), *(yystack_[1].value.ident), *(yystack_[0].value.block)); }
#line 961 "quack.tab.cxx"
    break;

  case 61:
#line 386 "quack.yxx"
             { (yylhs.value.ident) = new AST::Ident((yystack_[0].value.str)); }
#line 967 "quack.tab.cxx"
    break;


#line 971 "quack.tab.cxx"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char parser::yypact_ninf_ = -54;

  const signed char parser::yytable_ninf_ = -62;

  const short
  parser::yypact_[] =
  {
     -54,     6,     8,   -54,     7,    27,   -54,   -54,   -16,   313,
     313,   134,   313,   313,     2,   -54,   -54,   313,   313,   -54,
     -10,    40,   -54,     5,     7,   -54,   216,   216,   -54,   121,
     234,   269,    12,   195,     7,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,     7,   -54,   313,
      -1,    -5,   -54,     9,   -54,    11,   -54,   -54,   -54,   -54,
      13,   161,   301,   286,    58,   269,   269,   286,   301,   -19,
     -19,    12,    12,    10,   252,    16,    26,    35,     7,     7,
       3,   313,    31,   -54,   -14,   313,   -54,   313,   -54,   313,
       7,    38,   -54,   -54,    39,   216,   -54,   -54,   -54,    37,
     178,    45,   252,   -54,   -54,   -54,    11,     7,   -54,   -54,
      27,   -54,    31,     0,   -54,     7,   -54,   -54,    41,     7,
      46,    54,     7,    31,   -54,   -54
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     6,     1,     0,     2,     3,    61,     0,     0,
       0,     0,     0,     0,    29,    33,    32,     0,     0,     5,
      31,     0,    56,     0,    12,    31,     0,     0,    55,     0,
       0,    47,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    49,
       0,    11,    14,     0,     6,    25,    22,    54,    59,    39,
       0,     0,    41,    42,    40,    45,    46,    44,    43,    36,
      37,    34,    35,    30,    52,     0,    50,    10,     0,     0,
       0,     0,     0,    21,     0,     0,    27,    49,    53,     0,
       0,     0,    13,    15,     0,     0,    24,    57,    58,     0,
       0,     0,    51,     9,     6,     7,    25,     0,    28,    48,
      17,    23,     0,     0,    60,     0,     8,    16,     0,    12,
       0,    20,     0,     0,    19,    18
  };

  const signed char
  parser::yypgoto_[] =
  {
     -54,   -54,   -54,   -53,   -24,   -54,   -54,   -38,   -54,    14,
     -54,   -54,   -54,   -54,   -15,    -3,    84,    17,   -54,   -54,
     -54,   -54,    -4
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     1,     2,     5,    55,     6,    91,    50,    51,    52,
     113,   117,   123,    19,    83,    25,    21,    75,    76,    22,
      84,    98,    23
  };

  const signed char
  parser::yytable_[] =
  {
       8,    80,    20,    56,   115,     7,     3,    45,    46,     9,
      47,     4,    10,    94,    11,    12,    24,    97,    81,    82,
      53,    13,    14,    15,    16,    34,     7,    35,    17,    78,
      60,   116,    77,     9,   -61,    18,    10,    49,    11,    12,
      90,    47,    87,    73,    79,    13,    14,    15,    16,    88,
      85,   110,    17,    36,    37,    38,    39,    40,    96,    18,
      89,    54,    41,    42,    43,    44,    45,    46,   104,    47,
     105,   106,   107,   119,    53,    93,    48,    20,   109,   121,
      99,   120,    43,    44,    45,    46,   103,    47,   114,   122,
       0,   111,    92,    26,    27,    29,    30,    31,     0,   125,
       0,    32,    33,   112,   101,     0,     0,    20,     0,     0,
       0,   118,     0,     0,     0,    53,     0,     0,   124,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,    74,    36,    37,    38,    39,    40,     0,
       0,     0,     0,    41,    42,    43,    44,    45,    46,     0,
      47,     0,    13,    14,    15,    16,     0,    57,     0,    17,
       0,     0,     0,     0,     0,    95,    18,     0,     0,   100,
      28,    74,     0,   102,    36,    37,    38,    39,    40,     0,
       0,     0,     0,    41,    42,    43,    44,    45,    46,     0,
      47,    36,    37,    38,    39,    40,     0,    86,     0,     0,
      41,    42,    43,    44,    45,    46,     0,    47,    36,    37,
      38,    39,    40,     0,   108,     0,     0,    41,    42,    43,
      44,    45,    46,     0,    47,     0,     0,     0,    59,    36,
      37,    38,    39,    40,     0,     0,     0,     0,    41,    42,
      43,    44,    45,    46,     0,    47,    54,    36,    37,    38,
      39,    40,     0,     0,     0,     0,    41,    42,    43,    44,
      45,    46,     0,    47,    58,    36,    37,    38,    39,    40,
       0,     0,     0,     0,    41,    42,    43,    44,    45,    46,
       0,    47,    36,    37,    38,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    44,    45,    46,     0,    47,    36,
     -62,    38,     0,     0,     0,     0,     0,     0,   -62,    42,
      43,    44,    45,    46,   -62,    47,    38,     0,     0,     0,
       0,     0,     0,     0,   -62,    43,    44,    45,    46,     0,
      47,    13,    14,    15,    16,     0,     0,     0,    17,     0,
       0,     0,     0,     0,     0,    18
  };

  const signed char
  parser::yycheck_[] =
  {
       4,    54,     5,    27,     4,    19,     0,    26,    27,     6,
      29,     3,     9,    10,    11,    12,    32,    31,     7,     8,
      24,    18,    19,    20,    21,    35,    19,    37,    25,    34,
      34,    31,    33,     6,    32,    32,     9,    32,    11,    12,
       5,    29,    32,    47,    35,    18,    19,    20,    21,    33,
      37,   104,    25,    13,    14,    15,    16,    17,    82,    32,
      34,    30,    22,    23,    24,    25,    26,    27,    30,    29,
      31,    95,    35,    32,    78,    79,    36,    80,    33,    33,
      84,   119,    24,    25,    26,    27,    90,    29,   112,    35,
      -1,   106,    78,     9,    10,    11,    12,    13,    -1,   123,
      -1,    17,    18,   107,    87,    -1,    -1,   110,    -1,    -1,
      -1,   115,    -1,    -1,    -1,   119,    -1,    -1,   122,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    49,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    18,    19,    20,    21,    -1,    36,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    81,    32,    -1,    -1,    85,
      36,    87,    -1,    89,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      29,    13,    14,    15,    16,    17,    -1,    36,    -1,    -1,
      22,    23,    24,    25,    26,    27,    -1,    29,    13,    14,
      15,    16,    17,    -1,    36,    -1,    -1,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      -1,    29,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    -1,    29,    13,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    25,    26,    27,    13,    29,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    -1,
      29,    18,    19,    20,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    32
  };

  const signed char
  parser::yystos_[] =
  {
       0,    39,    40,     0,     3,    41,    43,    19,    60,     6,
       9,    11,    12,    18,    19,    20,    21,    25,    32,    51,
      53,    54,    57,    60,    32,    53,    54,    54,    36,    54,
      54,    54,    54,    54,    35,    37,    13,    14,    15,    16,
      17,    22,    23,    24,    25,    26,    27,    29,    36,    32,
      45,    46,    47,    60,    30,    42,    42,    36,    30,    33,
      60,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    60,    54,    55,    56,    33,    34,    35,
      41,     7,     8,    52,    58,    37,    36,    32,    33,    34,
       5,    44,    47,    60,    10,    54,    42,    31,    59,    60,
      54,    55,    54,    60,    30,    31,    42,    35,    36,    33,
      41,    52,    60,    48,    42,     4,    31,    49,    60,    32,
      45,    33,    35,    50,    60,    42
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    38,    39,    40,    40,    41,    41,    42,    43,    44,
      44,    45,    45,    46,    46,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    52,    51,    51,    51,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    54,    51,    51,    51,    57,    58,    58,
      59,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     0,     2,     0,     4,    10,     2,
       0,     1,     0,     3,     1,     3,     2,     0,     7,     2,
       0,     4,     3,     4,     2,     0,     2,     4,     6,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     6,     0,
       1,     3,     1,     4,     3,     2,     1,     5,     2,     0,
       4,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "CLASS", "DEF", "EXTENDS", "IF", "ELIF",
  "ELSE", "WHILE", "BOO", "RETURN", "TYPECASE", "ATLEAST", "ATMOST",
  "EQUALS", "AND", "OR", "NOT", "IDENT", "INT_LIT", "STRING_LIT", "'>'",
  "'<'", "'+'", "'-'", "'*'", "'/'", "NEG", "'.'", "'{'", "'}'", "'('",
  "')'", "','", "':'", "';'", "'='", "$accept", "pgm", "classes",
  "statements", "statement_block", "clas", "opt_cls_extends",
  "formal_args", "formal_args_delim", "formal_arg", "methods", "method",
  "opt_return_ident", "statement", "opt_elif_parts", "l_expr", "expr",
  "actual_args", "actual_args_nonempty", "typecase", "type_alt_opt",
  "type_alt", "ident", YY_NULLPTR
  };


  const short
  parser::yyrline_[] =
  {
       0,   141,   141,   152,   153,   159,   162,   167,   176,   181,
     182,   185,   186,   189,   190,   193,   200,   201,   204,   208,
     209,   227,   229,   233,   237,   240,   243,   252,   256,   270,
     271,   287,   290,   291,   301,   302,   303,   304,   305,   309,
     311,   312,   313,   314,   315,   318,   319,   320,   337,   340,
     341,   343,   344,   348,   357,   358,   366,   369,   373,   374,
     377,   386
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
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

  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    26,    24,    34,    25,    29,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
      23,    37,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    28
    };
    const int user_token_number_max_ = 277;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

} // yy
#line 1440 "quack.tab.cxx"

#line 388 "quack.yxx"


void yy::parser::error(const location_type& loc, const std::string& msg)
{
  report::error_at(loc, msg);
}

void debug(AST::ASTNode* n) {
    std::cout << "*** Building: " << n->str() << std::endl;
    }
