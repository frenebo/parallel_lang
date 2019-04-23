#ifndef COMPILER_FRONT_END_PARSE_ERROR
#define COMPILER_FRONT_END_PARSE_ERROR

#include <string>

namespace front_end::parser
{
    class ParseError
    {
    public:
        ParseError(std::string message, unsigned long token_position);
        const std::string & message() const;
        unsigned long token_position() const;
    private:
        std::string _message;
        unsigned long _token_position;
    };
}

#endif