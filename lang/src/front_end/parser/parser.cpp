#include "./parser.hpp"

namespace front_end::parser
{
    Parser::Parser()
    {
    }

    ParseResult<syntax_tree::program::ProgramTree>
    Parser::parse_program(const std::vector<token::Token> & tokens)
    {
        auto statement_sequence_result = parse_statement_sequence(tokens, 0, token::TokenType::END_OF_INPUT);

        if (statement_sequence_result.has_error())
        {
            return statement_sequence_result.get_error();
        }

        return ParseResult<syntax_tree::program::ProgramTree>(
            syntax_tree::program::ProgramTree(statement_sequence_result.contained()),
            statement_sequence_result.consumed_count()
        );
    }
}