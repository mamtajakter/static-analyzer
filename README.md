# Lexer & Parser


A special thanks to Dewi Yokelson for the lexer and parser. 


## Mamtaj Akter - Customized Static Analyzer

# To Run:
cd analyzer/src
# The following command generates lex.yy.cpp and lex.yy.h
reflex --bison-cc --bison-locations --header-file quack.lxx
# The followng command generates calc.tab.hxx, calc.tab.cxx, location.hh, position.hh, stack.hh
bison -d quack.yxx
# The following command generates a.out
g++ -std=c++11 lex.yy.cpp quack.tab.cxx parser.cxx ASTNode.cxx Messages.cxx  -lreflex
# Finally run
./a.out "../samples/bad_escape.qk"
