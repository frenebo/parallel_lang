#include "./lexer.hpp"
#include <ctype.h>

namespace front_end::lexer
{
    std::variant<std::vector<token::Token>, LexError> lex_text(const std::string & text)
    {
        std::vector<token::Token> tokens;

        unsigned long chars_consumed = 0;

        while (chars_consumed < text.size())
        {
            auto try_lex_next = lex_next_token(text, chars_consumed);

            if (!try_lex_next.has_value())
            {
                return LexError("Could not parse token", chars_consumed);
            }

            token::Token result = *try_lex_next;

            if (result.tok_type() != token::TokenType::WHITESPACE)
            {
                tokens.push_back(result);
            }

            chars_consumed += result.text().length();
        }

        return tokens;
    }

    std::optional<token::Token> lex_next_token(const std::string & text, unsigned long start_idx)
    {
        std::vector<std::optional<token::Token>> lex_results;
        lex_results.push_back(lex_whitespace(text, start_idx));
        lex_results.push_back(lex_keyword_match(text, start_idx));
        lex_results.push_back(lex_identifier(text, start_idx));

        std::optional<token::Token> longest_result;

        for (const std::optional<token::Token> & lex_result : lex_results)
        {
            if (!lex_result.has_value()) continue;

            if (
                !longest_result.has_value() ||
                lex_result->text().length() > longest_result->text().length())
            {
                longest_result = lex_result;
            }
        }

        return longest_result;
    }

    std::optional<token::Token> lex_identifier(const std::string & text, unsigned long start_idx)
    {
        if (!isalpha(text[start_idx]) && text[start_idx] != '_')
        {
            return std::optional<token::Token>();
        }

        unsigned long size = 1;
        while (
            start_idx + size < text.length() &&
            (isalnum(text[start_idx + size]) || text[start_idx + size] == '_'))
        {
            size++;
        }

        return token::Token(token::TokenType::IDENTIFIER, text.substr(start_idx, size));
    }

    std::optional<token::Token> lex_whitespace(const std::string & text, unsigned long start_idx)
    {
        if (!isspace(text[start_idx]))
        {
            return std::optional<token::Token>();
        }

        unsigned long size = 1;
        while (start_idx + size < text.length() && isspace(text[start_idx + size]))
        {
            size++;
        }

        return token::Token(token::TokenType::WHITESPACE, text.substr(start_idx, size));
    }

    std::optional<token::Token> lex_keyword_match(const std::string & text, unsigned long start_idx)
    {
        const std::pair<std::string, token::TokenType> types[] = {
            {"(", token::TokenType::OPEN_PARENTHESIS},
            {")", token::TokenType::CLOSE_PARENTHESIS},
            {"{", token::TokenType::OPEN_BRACE},
            {"}", token::TokenType::CLOSE_BRACE},
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
            return std::optional<token::Token>();
        }
        else
        {
            return token::Token(longest_tok_type, text.substr(start_idx, longest_match_length));
        }
    }
}
