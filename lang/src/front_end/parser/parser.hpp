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
        ParseResult<syntax_tree::program::ProgramTree> parse_program(std::vector<token::Token> tokens);
    private:
    };
}

#endif
