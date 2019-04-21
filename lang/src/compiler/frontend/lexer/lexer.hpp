#ifndef FRONT_END_LEXER_HPP
#define FRONT_END_LEXER_HPP

#include <string>
#include <variant>
#include <vector>

#include "../token/token.hpp"

namespace front_end::lexer
{
    class LexError
    {
    public:
        LexError(std::string message, unsigned long position);
        const std::string & message() const;
        unsigned long position() const;
    private:
        std::string _message;
        unsigned long _position;
    };

    std::variant<std::vector<token::Token>, LexError> lex_text(const std::string & text);
    std::variant<token::Token, LexError> lex_next_token(const std::string & text, unsigned long start_idx);
    std::variant<token::Token, LexError> lex_keyword_match(const std::string & text, unsigned long start_idx);
}

#endif
