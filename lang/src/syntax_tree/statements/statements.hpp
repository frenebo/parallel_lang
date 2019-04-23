#ifndef SYNTAX_TREE_STATEMENTS
#define SYNTAX_TREE_STATEMENTS

#include <variant>

#include "../compound_expression/compound_expression.hpp"

namespace syntax_tree::statements
{
    class CompoundExpressionStatement
    {
    public:
        CompoundExpressionStatement(compound_expression::CompoundExpression expression);
        const compound_expression::CompoundExpression & expression() const;
    private:
        compound_expression::CompoundExpression _expression;
    };

    class StatementContainer
    {
    typedef std::variant<CompoundExpressionStatement> VariantStatement;
    public:
        StatementContainer(VariantStatement contained);
        const VariantStatement & contained() const;
    private:
        VariantStatement _contained;
    };
}

#endif
