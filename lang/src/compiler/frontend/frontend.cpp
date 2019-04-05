#include "./frontend.hpp"
#include "./lexer/lexer.hpp"

namespace front_end
{
    CompileError::CompileError(std::string message)
    : _message(message)
    {
    }

    const std::string & CompileError::message() const
    {
        return _message;
    }


    std::variant<syntax_tree::program::ProgramTree, CompileError>
    parse_text(const std::string & text)
    {
        auto try_lex = lexer::lex_text(text);
        // if (std::ho)

        return CompileError("Unimplemented!");
    }
}
