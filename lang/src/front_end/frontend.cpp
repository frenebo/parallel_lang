#include "./frontend.hpp"
#include "./lexer/lexer.hpp"

namespace front_end
{
    CompileError::CompileError(std::string message, unsigned long position)
    : _message(message),
    _position(position)
    {
    }

    const std::string & CompileError::message() const
    {
        return _message;
    }

    unsigned long CompileError::position() const
    {
        return _position;
    }

    std::variant<syntax_tree::program::ProgramTree, CompileError>
    parse_text(const std::string & text)
    {
        auto try_lex = lexer::lex_text(text);

        if (std::holds_alternative<lexer::LexError>(try_lex))
        {
            const lexer::LexError lex_err = std::get<lexer::LexError>(try_lex);

            return CompileError(
                lex_err.message(),
                lex_err.position()
            );
        }

        // if (std::ho)

        return CompileError("Unimplemented!", 0);
    }
}
