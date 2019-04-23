#ifndef PARSE_RESULT_HPP
#define PARSE_RESULT_HPP

#include <variant>

#include "./parse_error.hpp"

namespace front_end::parser
{
    template <class T>
    class ParseResult
    {
    public:
        ParseResult(ParseError err)
        : _consumed_count(0),
        _contained(err)
        {
        }

        ParseResult(T contained, unsigned long consumed_count)
        : _consumed_count(consumed_count),
        _contained(contained)
        {
        }

        unsigned long consumed_count() const
        {
            return _consumed_count;
        }

        bool contains_result()
        {
            return std::holds_alternative<T>(_contained);
        }

        const T & contained() const
        {
            return std::get<T>(_contained);
        }

        const ParseError & get_error() const
        {
            return std::get<ParseError>(_contained);
        }
    private:
        unsigned long _consumed_count;
        std::variant<T, ParseError> _contained;
    };
}

#endif
