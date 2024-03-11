/*
** EPITECH PROJECT, 2024
** GLIBChecker
** File description:
** Utilities.cpp
*/

#include "Utilities.hpp"

std::pair<std::shared_ptr<std::string>, int> glc::Utilities::exec(const std::string &cmd) {
    std::array<char, 128> buffer{};
    std::shared_ptr<std::string> result = std::make_shared<std::string>();
    std::FILE *pipe = popen(cmd.c_str(), "r");

    if (!pipe)
        throw std::runtime_error("popen failed!");
    while (!std::feof(pipe))
        if (std::fgets(buffer.data(), 128, pipe) != nullptr)
            *result += buffer.data();
    return std::make_pair(result, WEXITSTATUS(pclose(pipe)));
}

std::string glc::Utilities::getLastWordAndCut(const std::string &str, char cutChar) {
    size_t lastSpace = str.find_last_of(' ');
    if (lastSpace == std::string::npos)
        return str;

    std::string lastWord = str.substr(lastSpace + 1);
    size_t cutIndex = lastWord.find(cutChar);
    if (cutIndex != std::string::npos)
        lastWord.erase(cutIndex);
    return lastWord;
}
