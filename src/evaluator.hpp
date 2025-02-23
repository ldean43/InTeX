#pragma once
#include "ast.hpp"
#include <unordered_map>

class Evaluator {
    private:
        const Expr* ast_;
        std::unordered_map<std::string, double> vars_;
        double result_;

        double evaluateHelper(const Expr* expr);
    public:
        explicit Evaluator
        (const Expr* expr, std::unordered_map<std::string, double> vars):
        ast_(expr), vars_(vars) {};
        double evaluate();
};