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
        auto keyword_match = lex_keyword_match(text, start_idx);

        return keyword_match;
    }

    std::variant<token::Token, LexError> lex_keyword_match(const std::string & text, unsigned long start_idx)
    {
        const std::pair<std::string, token::TokenType> types[] = {
            {"(", token::TokenType::OPEN_PARENTHESIS},
            {")", token::TokenType::CLOSE_PARENTHESIS},
        };

        unsigned long longest_match_length = 0;
        token::TokenType longest_tok_type;

        for (const auto & type_pair : types)
        {
            const std::string & match_str = type_pair.first;

            // If this match wouldn't be longer than the current longest match, no point in testing
            if (match_str.length() <= longest_match_length)
            {
                continue;
            }

            // If there isn't enough space left in the text for this to fit
            if (match_str.length() > text.length() - start_idx)
            {
                continue;
            }

            int text_compare = text.compare(start_idx, match_str.length(), match_str);

            if (text_compare == 0)
            {
                longest_match_length = match_str.length();
                longest_tok_type = type_pair.second;
            }
        }

        if (longest_match_length == 0)
        {
            return LexError("Could not parse token.", start_idx);
        }
        else
        {
            return token::Token(longest_tok_type, text.substr(start_idx, longest_match_length));
        }
    }
}
