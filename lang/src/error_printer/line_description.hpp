#ifndef COMPILER_ERROR_PRINTER_LINE_DESCRIPTION
#define COMPILER_ERROR_PRINTER_LINE_DESCRIPTION

#include <string>

namespace compiler::error_printer
{
    class LineDescription
    {
    public:
        LineDescription(std::string line_text, unsigned long line_idx, std::string::size_type line_pos);
        const std::string & line_text() const;
        unsigned long line_idx() const;
        std::string::size_type line_pos() const;
    private:
        std::string _line_text;
        unsigned long _line_idx;
        std::string::size_type _line_pos;
    };
}

#endif