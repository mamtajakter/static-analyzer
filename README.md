 


# Customized Static Analyzer

## About: This project parses quack code. It is basically a C++ version of my Haskell's quack parser. The quack program files are in samples analyzer/samples directory

## What it does so far: Every statement block expects BOO at the end of all statements. If there is no BOO found, the parser gives error with corresponding line number. 

## How To Run:
#### cd analyzer/src
#### reflex --bison-cc --bison-locations --header-file quack.lxx (This generates lex.yy.cpp and lex.yy.h)
#### bison -d quack.yxx (This command generates calc.tab.hxx, calc.tab.cxx, location.hh, position.hh, stack.hh)
#### g++ -std=c++11 lex.yy.cpp quack.tab.cxx parser.cxx ASTNode.cxx Messages.cxx  -lreflex (This generates a.out)
#### ./a.out "../samples/GoodWalk.qk"




