#include "./parser.hpp"

namespace front_end::parser
{
    Parser::Parser()
    {
    }

    ParseResult<syntax_tree::program::ProgramTree> Parser::parse_program(std::vector<token::Token> tokens)
    {
        return ParseError("Unimplemented parser", 0);
    }
}