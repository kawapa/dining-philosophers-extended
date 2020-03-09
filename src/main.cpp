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
    std::string question;
    Book book;

    Philosopher p1("Bobek", 1, 2);

    std::cout << p1.name_;

    return 0;
}