#pragma once

#include <shared_mutex>
#include <vector>

#include "Reflection.hpp"

struct Book
{
    std::shared_mutex mutexBook_;
    std::vector<Reflection> reflections_;
};
