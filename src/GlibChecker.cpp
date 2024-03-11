/*
** EPITECH PROJECT, 2024
** GLIBChecker
** File description:
** GlibChecker.cpp
*/

#include <memory>
#include <utility>
#include <string>
#include <sstream>
#include "Utilities.hpp"
#include "GlibChecker.hpp"

int glc::GLIBChecker::run(int argc, const char *argv[]) {
    if (argc == 1)
        return 84;

    std::pair<std::shared_ptr<std::string>, int> nm_output = Utilities::exec(std::string("nm ") + argv[1]);
    if (nm_output.second)
        return 84;

    std::istringstream iss(*nm_output.first);
    std::string line;
    std::string symbol;

    while (std::getline(iss, line)) {
        if (line.find("GLIBC_") == std::string::npos)
            continue;
        symbol = Utilities::getLastWordAndCut(line, '@');
        if (symbol == "exit" || symbol == "_Exit")
            std::system((R"(rg [^\w])" + symbol += R"(\\\()").c_str());
        else
            std::system((R"(rg [^\w:])" + symbol += R"(\\\()").c_str());
    }
    return 0;
}
