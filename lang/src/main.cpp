#include <iostream>

#include "./frontend/frontend.hpp"
#include "./error_printer/error_printer.hpp"

int main(void)
{
    std::string text =
        "()())\n"
        "asdfasdf asd the quick brown fox\n"
        "((\n"
        "asdfasdf asd the quick brown fox\n"
        "(()))()())\n"
        "asdfasdf asd the quick brown fox\n"
        "five j\n"
        "asdf fasdfdf";

    auto parse_result = front_end::parse_text(text);

    if (std::holds_alternative<front_end::CompileError>(parse_result))
    {
        const front_end::CompileError & compile_err = std::get<front_end::CompileError>(parse_result);
        std::cout << "Parse Error:" << std::endl;
        compiler::error_printer::print_compiler_error(text, compile_err);

        // std::cout << std::get<front_end::CompileError>(parse_result).message() << std::endl;
    }
    // compiler::compile_text(
    //     "()())\n"
    //     "asdfasdf asd the quick brown fox\n"
    //     "((\n"
    //     "asdfasdf asd the quick brown fox\n"
    //     "(()))()())\n"
    //     "asdfasdf asd the quick brown fox\n"
    //     "five j\n"
    //     "asdf! fasdfdf"

    // );
    return 0;
}
