#pragma once
#include <array>
#include <atomic>
#include <chrono>
#include <string>

using namespace std::chrono_literals;

struct Philosopher
{
    std::string name_;
    int forkIndexLeft_;
    int forkIndexRight_;
    bool hungry_ = true;
    std::atomic<bool> alive {true};
    std::atomic<bool> sleeps {false};
    std::chrono::seconds starveToDeath_ = 20s;
    std::array<std::string, 10> answers_;

    Philosopher(const std::string &, int, int);
    ~Philosopher();
    void answer();
    int calculate(const std::string &, std::string &);
    void eat();
    void generateAnswers();
    std::string getRandomAnswer();
    char getRandomChar();
    void start();
    void think();
    void write();
};