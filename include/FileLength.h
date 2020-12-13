#ifndef FILE_LENGTH_H
#define FILE_LENGTH_H

#include <string>
#include <vector>

auto count_lines(const std::string&) -> int;
auto count_lines_in_files(const std::vector<std::string>&) -> std::vector<int>;

#endif