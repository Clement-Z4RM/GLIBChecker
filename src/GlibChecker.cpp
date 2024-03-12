/*
** EPITECH PROJECT, 2024
** GLIBChecker
** File description:
** GlibChecker.cpp
*/

#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <sstream>
#include "Utilities/Utilities.hpp"
#include "GlibChecker.hpp"

int glc::GLIBChecker::run(int argc, const char *argv[]) {
    if (argc == 1) {
        std::cerr << "Usage: " << argv[0] << " <binary>" << std::endl;
        return 1;
    }

    std::pair<std::shared_ptr<std::string>, int> nm_output = Utilities::exec(std::string("nm ") + argv[1]);
    if (nm_output.second)
        return 1;

    const char *glibCheckerIgnore = std::getenv("GLIBCHECKER_IGNORE");
    auto ignoreList = glibCheckerIgnore ? Utilities::split(glibCheckerIgnore, ' ') : std::vector<std::string>();
    std::istringstream iss(*nm_output.first);
    std::string line;
    std::string symbol;
    std::pair<std::shared_ptr<std::string>, int> rg_output;
    std::istringstream rg_iss;
    std::vector<std::string> rg_line;
    int to_return = 0;

    while (std::getline(iss, line)) {
        if (line.find("GLIBC_") == std::string::npos)
            continue;
        symbol = Utilities::getLastWordAndCut(line, '@');
        if (std::find(ignoreList.begin(), ignoreList.end(), symbol) != ignoreList.end())
            continue;
        if (symbol == "exit" || symbol == "_Exit")
            rg_output = Utilities::exec(R"(rg -n -. [^\w])" + symbol += R"(\\\( .)");
        else
            rg_output = Utilities::exec(R"(rg -n -. [^\w:])" + symbol += R"(\\\( .)");
        if (!rg_output.second)
            ++to_return;
        rg_iss = std::istringstream(*rg_output.first);
        while (std::getline(rg_iss, line)) {
            rg_line = Utilities::split(line, ':');
            if (rg_line.size() < 3) {
                std::cout << line << std::endl;
                continue;
            }
            if (std::find(ignoreList.begin(), ignoreList.end(), rg_line[0]) != ignoreList.end() ||
                std::find(ignoreList.begin(), ignoreList.end(), rg_line[0] + ':' + rg_line[1]) != ignoreList.end())
                continue;
            std::cout << "\33[35m" << rg_line[0] << "\33[0m:\33[32m" << rg_line[1] << "\33[0m: \33[31m" << symbol << "\33[0m: ";
            for (std::uint64_t i = 2; i < rg_line.size(); ++i) {
                std::cout << rg_line[i];
                if (i + 1 < rg_line.size())
                    std::cout << ':';
            }
            std::cout << std::endl;
        }
    }
    return to_return;
}
