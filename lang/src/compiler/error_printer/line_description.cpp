#include "./line_description.hpp"

namespace compiler::error_printer
{
    LineDescription::LineDescription(std::string line_text, unsigned long line_idx, std::string::size_type line_pos)
    : _line_text(line_text),
    _line_idx(line_idx),
    _line_pos(line_pos)
    {
    }

    const std::string & LineDescription::line_text() const
    {
        return _line_text;
    }
    unsigned long LineDescription::line_idx() const
    {
        return _line_idx;
    }

    std::string::size_type LineDescription::line_pos() const
    {
        return _line_pos;
    }
}