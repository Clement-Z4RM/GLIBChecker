/*
** EPITECH PROJECT, 2024
** GLIBChecker
** File description:
** Utilities.hpp
*/

#ifndef GLIBCHECKER_UTILITIES_HPP_
#define GLIBCHECKER_UTILITIES_HPP_

#include <memory>
#include <utility>
#include <string>
#include <vector>

namespace glc {
    class Utilities {
    public:
        static std::pair<std::shared_ptr<std::string>, int> exec(const std::string &cmd);

        static std::string getLastWordAndCut(const std::string &str, char cutChar);

        static std::vector<std::string> split(const std::string &str, char delimiter);
    };
}

#endif /* !GLIBCHECKER_UTILITIES_HPP_ */
