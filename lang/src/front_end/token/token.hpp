#ifndef FRONT_END_TOKENS
#define FRONT_END_TOKENS

#include <string>

namespace front_end::token
{
    enum TokenType {
        // Character series beginning in letter or underscore, followed by alpha-numeric or underscore characters.
        IDENTIFIER,
        // Newlines, spaces, tabs, etc.
        WHITESPACE,
        // For functions
        FUNC_ARROW,
        // Result keyword,
        RESULT_KEYWORD,
        // (
        OPEN_PARENTHESIS,
        // )
        CLOSE_PARENTHESIS,
        // {
        OPEN_BRACE,
        // }
        CLOSE_BRACE,
        // Marks end of program
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
