 # Customized Static Analyzer

## About: 
#### This project parses quack program. It is basically a C++ version of my Haskell's quack parser. The quack program files are in samples analyzer/samples directory

## About Quack Language:
#### Please see quack_grammar.pdf

## What the Static Analyzer does so far: 
#### The parser expects a "BOO" at the end of all statement-block. If there is no BOO found, the parser gives error with the corresponding line number. Otherwise, it gives a feedback "Successfully Parsed". 

## Which files are edited for the quack lexer and parser implementations:
#### src/quack.lxx is for the lexer 
#### src/quack.yxx is for the parser 

## where is the BOO Rules implemented:
#### The rules that "Every Statement block exists BOO", is implemented in both the src/quack.lxx and src/quack.yxx files

## where is the Line number for the Syntax Errors implemented:
#### src/Messages.cxx

## where does it check if its successfully parsed:
#### src/parser.cxx

## What needs to install: 
#### bison and reflex (please see "installing bison and reflex.pdf")

## How To Run:
#### cd analyzer/src
#### reflex --bison-cc --bison-locations --header-file quack.lxx 
##### ------(This generates lex.yy.cpp and lex.yy.h)
#### bison -d quack.yxx 
##### ------(This command generates calc.tab.hxx, calc.tab.cxx, location.hh, position.hh, stack.hh)
#### g++ -std=c++11 lex.yy.cpp quack.tab.cxx parser.cxx ASTNode.cxx Messages.cxx  -lreflex 
##### ------(This generates a.out)
#### ./a.out "../samples/GoodWalk.qk"

## Acknowlegements: 
#### Thanks to Dr. Michal Young and Dewi Yokelson for the starter project with a grammar of a calculator
#### Thanks to Zayd Hammoudeh for figuring out how to install bison and reflex on mac which was quite exhausting. 
