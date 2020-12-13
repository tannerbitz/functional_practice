#include "FileLength.h"
#include <iostream>
#include <vector>
#include <filesystem>
#include <range/v3/all.hpp>

int main(int argc, char** argv)
{
    // get current path (should be build directory)
    const auto curr_dir = std::filesystem::current_path();
    // specify a couple of expected files in build dir
    const auto filenames = std::vector<std::string>{"CMakeCache.txt", "conaninfo.txt"};

    const auto prepend_curr_dir = [curr_dir](const std::string& filename) -> std::filesystem::path
    {
        return (curr_dir / filename);
    };

    const auto path_to_string = [](const std::filesystem::path& path) -> std::string
    {
        return path.string();
    };

    const auto exists = [](const std::filesystem::path& path) -> bool {return std::filesystem::exists(path);};

    // get existing filepaths
    auto filepaths = filenames | ranges::views::transform(prepend_curr_dir) 
                               | ranges::views::filter(exists)
                               | ranges::views::transform(path_to_string)
                               | ranges::to_vector;

    // get line count for each file
    auto line_counts = count_lines_in_files(filepaths);
    for (size_t i=0; i<filepaths.size(); ++i)
    {
        std::cout << "File: " << filepaths[i] << "\tLines: " << line_counts[i] << std::endl;
    }


    return 0;
}