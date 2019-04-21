#ifndef COMPILER_ERROR_PRINTER
#define COMPILER_ERROR_PRINTER

#include "../frontend/frontend.hpp"
#include <iostream>

namespace compiler::error_printer
{
    void print_compiler_error(const std::string & input_text, const front_end::CompileError & compile_error);
}

#endif
