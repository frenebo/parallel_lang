#include "./front_end.hpp"
#include "./lexer/lexer.hpp"
#include "./parser/parser.hpp"

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

        std::vector<token::Token> lexed_tokens = std::get<std::vector<token::Token>>(try_lex);

        parser::ParseResult<syntax_tree::program::ProgramTree> try_parse =
            parser::Parser().parse_program(lexed_tokens);

        if (try_parse.has_error())
        {
            const std::string & error_message = try_parse.get_error().message();
            unsigned long tok_idx = try_parse.get_error().token_position();
            unsigned long text_idx = 0;
            for (unsigned long i = 0; i < tok_idx; i++)
            {
                text_idx += lexed_tokens[i].text().length();
            }

            return CompileError(error_message, text_idx);
        }
        // if (std::ho)

        return CompileError("Unimplemented!", 0);
    }
}
