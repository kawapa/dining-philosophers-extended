#pragma once
#include "Philosopher.hpp"
#include "Reflection.hpp"
#include <mutex>
#include <vector>

struct Book
{
    std::mutex m_;
    std::vector<Reflection> reflections_;
};