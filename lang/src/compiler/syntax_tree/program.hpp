#ifndef SYNTAX_TREE_PROGRAM_HPP
#define SYNTAX_TREE_PROGRAM_HPP

#include "./statement_sequence/statement_sequence.hpp"

namespace syntax_tree::program
{
    class ProgramTree
    {
    public:
        ProgramTree(statement_sequence::StatementSequence program_body);
        const statement_sequence::StatementSequence & program_body() const;
    private:
        statement_sequence::StatementSequence _program_body;
    };
}

#endif
