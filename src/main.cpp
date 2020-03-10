#include "..\inc\Book.hpp"
#include "..\inc\Philosopher.hpp"
#include "..\inc\Reflection.hpp"
#include <iostream>
#include <chrono>
#include <mutex>
#include <string>
#include <thread>

using namespace std::chrono_literals;

std::mutex forks[5];

int main()
{
    Book book;
    std::string question = "How are you?";

    Philosopher p1("Bobek", 1, 2);

    p1.live();

    return 0;
}