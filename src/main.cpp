#include "parser.hpp"
#include "lexer.hpp"
#include "evaluator.hpp"
#include "utils.hpp"
#include <regex>
#include <iostream>

int main() {
    std::string input;
    std::vector<std::string> tokens;
    std::smatch match;
    std::unordered_map<std::string, double> vars;

    std::cout << "\"quit\" or \"exit\" to exit repl" << std::endl;
    while (true) {
        std::cout << "> ";
        if (!getline(std::cin, input) || input == "quit" || input == "exit") {
            break;
        }

        if (input == "") {
            continue;
        }

        if (std::regex_match(input, match, std::regex("^([a-zA-Z])\\s*=(.*)"))) {
            try {
                Lexer lexer(match[2]);
                Parser parser(lexer.lex());
                Evaluator eval(parser.parse(), vars);
                vars[match[1]] = eval.evaluate();
                std::cout << match[1] << " = " << vars[match[1]] << std::endl;
            } catch (std::runtime_error &err) {
                std::cout << err.what() << std::endl;
            }
            continue;
        } else if (std::regex_match(input, match, 
            std::regex("^del\\s*([a-zA-Z])$"))) {
            if (vars.count(match[1])) {
                vars.erase(match[1]);
                continue;
            } else {
                std::cout << match[1] << " does not exit" << std::endl;
            }
        } 

        try {
            Lexer lexer(input);
            Parser parser = Parser(lexer.lex());
            Expr* expr = parser.parse();
            Evaluator eval(expr, vars);
            double res = eval.evaluate();
            std::cout << "Result: " << res << std::endl;
            std::cout << "Abstract Syntax Tree: " << std::endl;
            print_ast(expr, "");
        } catch(std::runtime_error &err) {
            std::cout << err.what() << std::endl;
        }
    }
    return 0;
}