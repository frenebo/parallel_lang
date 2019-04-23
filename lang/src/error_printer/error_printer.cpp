#include <vector>
#include <algorithm>

#include "./colors.hpp"
#include "./error_printer.hpp"
#include "./line_description.hpp"

namespace compiler::error_printer
{
    std::vector<LineDescription> get_text_lines(const std::string & text);

    void print_compiler_error(const std::string & input_text, const front_end::CompileError & compile_error)
    {
        unsigned long problem_pos = compile_error.position();

        std::vector<LineDescription> text_lines = get_text_lines(input_text);

        unsigned long line_idx_of_problem = 0;
        unsigned long problem_idx_in_line = 0;

        for (auto it = text_lines.begin(); it != text_lines.end(); ++it)
        {
            std::string::size_type line_start_pos = it->line_pos();
            std::string::size_type line_end_pos = line_start_pos + it->line_text().length();
            if (line_start_pos <= problem_pos && line_end_pos > problem_pos)
            {
                line_idx_of_problem = it - text_lines.begin();
                problem_idx_in_line = problem_pos - line_start_pos;
                break;
            }
        }

        std::cout <<
            colors::red <<
            "Error on line #" <<
            line_idx_of_problem + 1 <<
            ": " <<
            compile_error.message() <<
            colors::reset <<
            std::endl;

        // print 5 lines before & including the problem line
        unsigned long print_line_start = line_idx_of_problem > 5 ? line_idx_of_problem - 5 : 0;

        // Line numbers to print
        std::vector<std::string> line_num_strings;
        for (unsigned long idx = print_line_start; idx <= line_idx_of_problem; ++idx)
        {
            unsigned long line_num = text_lines[idx].line_idx() + 1;
            std::string line_num_str = std::to_string(line_num);

            // Add spaces to previous line num strings if necessary to make all same length
            if (line_num_strings.size() > 0 && line_num_str.size() > line_num_strings[0].size())
            {
                for (auto it = line_num_strings.begin(); it != line_num_strings.end(); ++it)
                {
                    *it += " ";
                }
            }

            line_num_strings.push_back(line_num_str);
        }


        for (unsigned long idx = print_line_start; idx <= line_idx_of_problem; ++idx)
        {
            std::cout <<
                colors::green <<
                line_num_strings[idx - print_line_start] <<
                " " <<
                colors::white <<
                text_lines[idx].line_text() <<
                colors::reset <<
                std::endl;
        }

        unsigned long arrow_offset = line_num_strings[0].size() + 1 + problem_idx_in_line;

        std::cout << std::string(arrow_offset, ' ') << "^" << std::endl;
    }

    std::vector<LineDescription> get_text_lines(const std::string & text)
    {
        std::vector<LineDescription> lines;

        std::string current_line = "";
        unsigned long line_idx = 0;
        std::string::size_type line_start_pos = 0;
        for (std::string::size_type i = 0; i < text.length(); i++)
        {
            if (text[i] == '\n')
            {
                lines.push_back(LineDescription(
                    current_line,
                    line_idx,
                    line_start_pos
                ));

                current_line = "";
                line_idx++;
                line_start_pos = i + 1;
            }
            else
            {
                current_line += text[i];
            }
        }

        // If the text doesn't end in a return character, there'll be an incomplete line
        // left over after the loop
        if (current_line.size() != 0)
        {
            lines.push_back(LineDescription(
                current_line,
                line_idx,
                line_start_pos
            ));
        }

        return lines;
    }
}