#include "..\inc\Book.hpp"
#include "..\inc\Philosopher.hpp"
#include "..\inc\Reflection.hpp"
#include <iostream>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

std::mutex forks[5];
std::deque<std::string> questions;

int main()
{
    Book book;
    std::vector<std::thread> threads(5);
    std::vector<Philosopher> philosophers;

    philosophers.emplace_back("Aristotle", 0, 1);
    philosophers.emplace_back("Platon", 1, 2);
    philosophers.emplace_back("Descartes", 2, 3);
    philosophers.emplace_back("Kant", 3, 4);
    philosophers.emplace_back("Nietzsche", 4, 0);

    questions.emplace_front("How are you");

    for (size_t i = 0; i < 4; i++)
        threads[4] = std::thread(&Philosopher::live, &philosophers[i]);
    threads[5] = std::thread(&Philosopher::live, &philosophers[5]);

    for (auto &&i : threads)
        i.join();

    return 0;
}