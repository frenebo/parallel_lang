#ifndef COMPILER_PARSER_HPP
#define COMPILER_PARSER_HPP

#include <vector>
#include <variant>

#include "../../syntax_tree/program.hpp"
#include "../token/token.hpp"
#include "./parse_result.hpp"

namespace front_end::parser
{

    class Parser
    {
    public:
        // @TODO parser options?
        Parser();

        ParseResult<syntax_tree::program::ProgramTree>
        parse_program(const std::vector<token::Token> & tokens);

        ParseResult<syntax_tree::statement_sequence::StatementSequence>
        parse_statement_sequence(
            const std::vector<token::Token> & tokens,
            unsigned long start_idx,
            token::TokenType end_tok_type);

        ParseResult<syntax_tree::statements::StatementContainer>
        parse_statement_container(
            const std::vector<token::Token> & tokens,
            unsigned long start_idx);
    private:
    };
}

#endif
