#pragma once
#include "Reflection.hpp"
#include <mutex>
#include <vector>

struct Book
{
    std::mutex mutexBook_;
    std::vector<Reflection> reflections_;
};