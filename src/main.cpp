#include <algorithm>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
#include <vector>
#include "Philosopher.hpp"
#include "Book.hpp"

// number of philosophers and forks
constexpr size_t n = 5;
std::mutex forks[n];

using namespace std::chrono_literals;

int main()
{
    std::vector<std::thread> threads(n);
    std::vector<Philosopher> philosophers;
    philosophers.reserve(n);

    Book book;

    std::queue<std::string> questions;
    questions.push("How are you?");


    std::string names[]{"Arystoteles", "Platon", "Epikur", "Siron",
                        "Demokryt", "Sokrates", "Zenon", "Parmenides", "Heraklit", "Tales"};

    for (size_t i = 0; i < n - 1; i++)
        philosophers.emplace_back(names[i], forks[i], forks[i+1], book, questions);
    philosophers.emplace_back(names[n - 1], forks[n - 1], forks[0], book, questions);

    for (size_t i = 0; i < n; i++)
        threads[i] = std::thread(&Philosopher::dine, &philosophers[i]);

    while (std::any_of(philosophers.begin(), philosophers.end(), [](Philosopher & obj){
        return obj.alive_ == true;
        }))
    {
        std::this_thread::sleep_for(1s);
    }

    for (auto &&i : threads)
        i.join();
    
    return 0;
}