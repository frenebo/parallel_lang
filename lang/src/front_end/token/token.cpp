#include "./token.hpp"

namespace front_end::token
{
    Token::Token(TokenType tok_type, std::string text)
    : _text(text),
    _tok_type(tok_type)
    {
    }

    const std::string & Token::text() const
    {
        return _text;
    }

    TokenType Token::tok_type() const
    {
        return _tok_type;
    }

    std::string tok_type_to_str(TokenType tok_type)
    {
        switch (tok_type)
        {
        case TokenType::IDENTIFIER:
            return "Identifier";
        case TokenType::END_OF_INPUT:
            return "End of Input";
        case TokenType::WHITESPACE:
            return "Whitespace";
        case TokenType::OPEN_PARENTHESIS:
            return "Open Parenthesis";
        case TokenType::CLOSE_PARENTHESIS:
            return "Close Parenthesis";
        default:
            return "Unimplemented token type to string";
        }
    }
}
