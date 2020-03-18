#pragma once
#include <array>
#include <chrono>
//#include <condition_variable>
#include <mutex>
#include <string>
#include <queue>
#include "Book.hpp"

struct Philosopher
{
    std::string name_;
    std::mutex & forkLeft_;
    std::mutex & forkRight_;
    std::array<std::string, 10> answers_;
    Book & book_;
    std::queue<std::string> & questions_;
    //std::condition_variable cv_;

    bool alive_ = true;
    bool full_ = false;
    bool sleeping = false;
    //std::atomic<bool> sleeping_ {false};
    
    std::chrono::steady_clock::time_point lastMeal_;
    int64_t diesAfter_ = 20;
    int64_t diesAfterWhileSleeping_ = 60;
    int64_t cantEatBefore_ = 3;

    Philosopher(const std::string, std::mutex &, std::mutex &, Book &, std::queue<std::string> &);
    ~Philosopher();

    void dine();
    void eat();
    void think();
    //void write();
    //void answer();

    void generateAnswers();
    std::string getRandomAnswer();
    char getRandomChar();
    int calculate(const std::string &, std::string &);
    void print(std::string str);
    void updateStatus();
    void wait();
};