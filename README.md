 


# Customized Static Analyzer

### To Run:
#### cd analyzer/src
#### reflex --bison-cc --bison-locations --header-file quack.lxx (This generates lex.yy.cpp and lex.yy.h)
#### bison -d quack.yxx (This command generates calc.tab.hxx, calc.tab.cxx, location.hh, position.hh, stack.hh)
#### g++ -std=c++11 lex.yy.cpp quack.tab.cxx parser.cxx ASTNode.cxx Messages.cxx  -lreflex (This generates a.out)
#### ./a.out "../samples/GoodWalk.qk"



