#include "../parser.hpp"

namespace front_end::parser
{
    ParseResult<syntax_tree::statement_sequence::StatementSequence>
    Parser::parse_statement_sequence(
        const std::vector<token::Token> & tokens,
        unsigned long start_idx,
        token::TokenType end_tok_type)
    {
        unsigned long consumed_count = 0;
        std::vector<syntax_tree::statements::StatementContainer> statements;

        while (start_idx + consumed_count < tokens.size())
        {
            if (tokens[start_idx + consumed_count].tok_type() == end_tok_type)
            {
                break;
            }

            auto statement_parse_result = parse_statement_container(tokens, start_idx);

            if (statement_parse_result.has_error())
            {
                return statement_parse_result.get_error();
            }

            const syntax_tree::statements::StatementContainer statement = statement_parse_result.contained();

            statements.push_back(statement);
            consumed_count += statement_parse_result.consumed_count();
        }

        return ParseResult<syntax_tree::statement_sequence::StatementSequence>(
            syntax_tree::statement_sequence::StatementSequence(statements),
            consumed_count
        );
    }
}