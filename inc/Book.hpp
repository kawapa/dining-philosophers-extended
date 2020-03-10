#pragma once
#include "Reflection.hpp"
#include <mutex>
#include <vector>

struct Book
{
    std::mutex m_;
    std::vector<Reflection> reflections_;

    void addReflection(const std::string & ref);
};