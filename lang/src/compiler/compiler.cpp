#include <iostream>

#include "./compiler.hpp"
#include "./frontend/frontend.hpp"
#include "./error_printer/error_printer.hpp"

namespace compiler
{
    void compile_text(std::string text)
	{
		auto parse_result = front_end::parse_text(text);

		if (std::holds_alternative<front_end::CompileError>(parse_result))
		{
			const front_end::CompileError & compile_err = std::get<front_end::CompileError>(parse_result);
			std::cout << "Parse Error:" << std::endl;
			error_printer::print_compiler_error(text, compile_err);

			// std::cout << std::get<front_end::CompileError>(parse_result).message() << std::endl;
		}
	}
}
