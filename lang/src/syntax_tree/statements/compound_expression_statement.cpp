#include "./statements.hpp"

namespace syntax_tree::statements
{
    CompoundExpressionStatement::CompoundExpressionStatement(compound_expression::CompoundExpression expression)
    : _expression(expression)
    {
    }

    const compound_expression::CompoundExpression & CompoundExpressionStatement::expression() const
    {
        return _expression;
    }
}
