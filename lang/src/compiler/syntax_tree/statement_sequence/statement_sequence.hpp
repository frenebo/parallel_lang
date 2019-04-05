#ifndef SYNTAX_TREE_STATEMENT_SEQUENCE
#define SYNTAX_TREE_STATEMENT_SEQUENCE

#include <vector>

#include "../statements/statements.hpp"

namespace syntax_tree::statement_sequence
{
    class StatementSequence
    {
    public:
        StatementSequence(std::vector<statements::StatementContainer> statements);
        const std::vector<statements::StatementContainer> & statements() const;
    private:
        std::vector<statements::StatementContainer> & _statements;
    };
}

#endif
