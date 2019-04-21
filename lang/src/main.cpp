#include "./compiler/compiler.hpp"

int main(void)
{
    compiler::compile_text(
        "((\n"
        "asdfasdf asd the quick brown fox\n"
        "((\n"
        "asdfasdf asd the quick brown fox\n"
        "((\n"
        "asdfasdf asd the quick brown fox\n"
        "five j\n"
        "asdf! fdf"

    );
    return 0;
}
