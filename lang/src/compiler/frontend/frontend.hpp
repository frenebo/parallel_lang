#ifndef FRONT_END_HPP
#define FRONT_END_HPP

#include <string>
#include <variant>

#include "../syntax_tree/program.hpp"


namespace front_end
{
    class CompileError
    {
    public:
        CompileError(std::string message, unsigned long position);
        const std::string & message() const;
        unsigned long position() const;
    private:
        std::string _message;
        unsigned long _position;
    };

    std::variant<syntax_tree::program::ProgramTree, CompileError>
    parse_text(const std::string & text);
}

#endif
