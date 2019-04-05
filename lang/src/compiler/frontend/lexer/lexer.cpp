#include "./lexer.hpp"

namespace front_end::lexer
{
    std::variant<std::vector<token::Token>, LexError> lex_text(const std::string & text)
    {
        std::vector<token::Token> tokens;

        unsigned long chars_consumed = 0;

        while (chars_consumed < text.size())
        {
            auto try_lex_next = lex_next_token(text, chars_consumed);

            if (std::holds_alternative<LexError>(try_lex_next))
            {
                return std::get<LexError>(try_lex_next);
            }
        }

        return tokens;
    }

    std::variant<token::Token, LexError> lex_next_token(const std::string & text, unsigned long start_idx)
    {

    }
}
