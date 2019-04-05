#ifndef FRONT_END_TOKENS
#define FRONT_END_TOKENS

#include <string>

namespace front_end::token
{
    enum TokenType {
        IDENTIFIER,
        WHITESPACE,
        END_OF_INPUT,
    };

    class Token
    {
    public:
        Token(TokenType tok_type, std::string text);
        const std::string & text() const;
        TokenType tok_type() const;
    private:
        std::string _text;
        TokenType _tok_type;
    };

    std::string tok_type_to_str(TokenType);
}

#endif
