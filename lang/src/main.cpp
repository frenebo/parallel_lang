#include "./compiler/compiler.hpp"

int main(void)
{
    compiler::compile_text("hello\nasdf\nline\nhmm");
    return 0;
}
