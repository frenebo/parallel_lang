#include "./lexer.hpp"

namespace front_end::lexer
{
    LexError::LexError(std::string message, unsigned long position)
    : _message(message),
    _position(position)
    {
    }

    const std::string & LexError::message() const
    {
        return _message;
    }

    unsigned long LexError::position() const
    {
        return _position;
    }
}
