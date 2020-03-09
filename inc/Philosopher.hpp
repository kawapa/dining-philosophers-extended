#pragma once
#include "Book.hpp"
#include "Reflection.hpp"
#include <array>
#include <chrono>
#include <string>

using namespace std::chrono_literals;

struct Philosopher
{
    std::string name_ = "";
    int forkIndexLeft_;
    int forkIndexRight_;
    bool hungry_ = true;
    std::chrono::seconds starveToDeath_ = 20s;
    std::array<std::string, 10> answers_;

    Philosopher(std::string, int, int);
    void start();
    void think();
    int calculate(std::string q, std::string a);
    void eat();
    void write();
    void answer();
};