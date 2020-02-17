//
// The parser driver just glues together a parser object
// and a lexer object.
//

#include "lex.yy.h"
#include "ASTNode.h"
#include "Messages.h"
// #include "staticsemantics.cpp"
#include "CodegenContext.h"

#include <iostream>
#include <unistd.h>  // getopt is here

class Driver {
    int debug_level = 0;
public:
    explicit Driver(const reflex::Input in) : lexer(in), parser(new yy::parser(lexer, &root)) { root = nullptr; }

    ~Driver() { delete parser; }

    void debug() { debug_level = 1; }

    AST::ASTNode *parse() {
        // parser->set_debug_level(debug_level); // 0 = no debugging, 1 = full tracing
        // std::cout << "Running parser\n";
        int result = parser->parse();
        if (result == 0 && report::ok()) {  // 0 == success, 1 == failure
            // std::cout << "Extracting result\n";
            if (root == nullptr) {
                std::cout << "But I got a null result!  How?!\n";
            }
            return root;
        } else {
            // std::cout << "Parse failed, no tree\n";
            return nullptr;
        }
    }

private:
    yy::Lexer lexer;
    yy::parser *parser;
    AST::ASTNode *root;
};

int main(int argc, char **argv) {
    std::string filename;
    char c;
    FILE *f;
    int index;
    int json = 0;
    int debug; // 0 = no debugging, 1 = full tracing

    while ((c = getopt(argc, argv, "t")) != -1) {
        if (c == 't') {
            std::cerr <<  "Debugging mode\n";
            debug = 1;
        }
    }

    for (index = optind; index < argc; ++index) {
        if( !(f = fopen(argv[index], "r"))) {
            perror(argv[index]);
            exit(1);
        }
        Driver driver(f);
        if (debug) driver.debug();
        AST::ASTNode *root = driver.parse();
        if (root != nullptr) {
            std::cout << "Parsed!\n";
            if (json) {
                AST::AST_print_context context;
                root->json(std::cout, context);
                std::cout << std::endl;
            }
/*
            // call static semantic checker, pass in root
            // get a struct full of pointers to tables in return
            StaticSemantics ssc(root);
            // std::cout << "About to call the static semantic checker." << std::flush;
            tablepointers *result = ssc.check(root);
            if (result == nullptr ) {
                std::cout << "Error while doing static semantic check." << std::endl;
            } else {
                std::cout << "Success with the static semantics!!." << std::endl;
                // generate code!

                //void generate_code(AST::ASTNode *root) {
                CodegenContext ctx(std::cout);
                // Prologue
                ctx.emit("#include <stdio.h>");
                ctx.emit("#include \"Builtins.c\"");
                ctx.emit("int main(int argc, char **argv) {");
                // Body of generated code
                std::string target = ctx.alloc_reg();
                root->gen_rvalue(ctx, target);
                // Coda
//                ctx.emit(std::string(R"(printf("-> %d\n",)")
//                         + target + ");");
                ctx.emit("}");
              //  }

            }
*/
        } else {
            std::cout << "No tree produced." << std::endl;
        }
    }

}