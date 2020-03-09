#pragma once
#include "Book.hpp"
#include "Philosopher.hpp"
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

    Reflection(std::string ph, std::string an, int re, std::chrono::seconds pe, bool ch)
        :
        philosopher(ph),
        answer(an),
        result(re),
        period(pe),
        chosen(ch)
        { }
};