#include "./program.hpp"

namespace syntax_tree::program
{
    ProgramTree::ProgramTree(statement_sequence::StatementSequence program_body)
    : _program_body(program_body)
    {
    }

    const statement_sequence::StatementSequence & ProgramTree::program_body() const
    {
        return _program_body;
    }
}
