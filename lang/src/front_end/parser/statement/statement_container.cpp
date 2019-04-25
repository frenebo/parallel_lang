#include "../parser.hpp"

namespace front_end::parser
{
    ParseResult<syntax_tree::statements::StatementContainer>
    Parser::parse_statement_container(const std::vector<token::Token> & tokens, unsigned long start_idx)
    {
        return ParseError("Unimplemented statementcontainer parse", start_idx);
        // syntax_tree::statements::CompoundExpressionStatement
    }
}