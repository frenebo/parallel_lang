#include "./parser.hpp"

namespace front_end::parser
{
    ParseError::ParseError(std::string message, unsigned long token_position)
    : _message(message),
    _token_position(token_position)
    {
    }

    const std::string & ParseError::message() const
    {
        return _message;
    }

    unsigned long ParseError::token_position() const
    {
        return _token_position;
    }
}