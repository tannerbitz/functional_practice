#include "FileLength.h"
#include <fstream>
#include <algorithm>

auto count_lines(const std::string& filename) -> int
{
    std::ifstream in(filename);
    
    return std::count(
        std::istreambuf_iterator<char>(in),
        std::istreambuf_iterator<char>(),
        '\n');
}


auto count_lines_in_files(const std::vector<std::string>& files) -> std::vector<int>
{
    std::vector<int> results;
    for (const auto& file : files)
    {
        results.push_back(count_lines(file));
    }
    return results;
}