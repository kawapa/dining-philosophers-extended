#pragma once
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <string>

using namespace std::chrono_literals;

struct Philosopher
{
    std::string name_;
    int forkIndexLeft_;
    int forkIndexRight_;
    //int diesAfterSeconds_ = 10;
    std::atomic<bool> alive_ {true};
    std::atomic<bool> sleep_ {false};
    std::chrono::steady_clock::time_point lastMeal_;
    std::array<std::string, 10> answers_;

    Philosopher(const std::string &, int, int);
    ~Philosopher();
    bool alive();
    void answer();
    int calculate(const std::string &, std::string &);
    void eat();
    void generateAnswers();
    std::string getRandomAnswer();
    char getRandomChar();
    void live();
    void think();
    void write();
};