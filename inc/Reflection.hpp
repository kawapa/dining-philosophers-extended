#pragma once
#include <chrono>
#include <string>

using namespace std::chrono_literals;

struct Reflection
{
    std::string philosopher;
    std::string answer;
    int result;
    std::chrono::seconds period;
    bool chosen = false;

    Reflection(const std::string &, const std::string &, int re, std::chrono::seconds pe, bool ch);
};