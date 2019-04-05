#include "./statement_sequence.hpp"

namespace syntax_tree::statement_sequence
{

    StatementSequence::StatementSequence(std::vector<statements::StatementContainer> statements)
    : _statements(statements)
    {
    }

    const std::vector<statements::StatementContainer> & StatementSequence::statements() const
    {
        return _statements;
    }
}
