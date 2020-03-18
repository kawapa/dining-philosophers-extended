#include <algorithm>
#include <chrono>
#include <iostream>
#include <sstream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>
#include "Philosopher.hpp"
#include "Book.hpp"
#include "Reflection.hpp"

using namespace std::chrono_literals;

Philosopher::Philosopher(const std::string name, std::mutex & left, std::mutex & right, Book & book, std::queue<std::string> & questions)
    :
    name_(name),
    forkLeft_(left),
    forkRight_(right),
    book_(book),
    questions_(questions)
{
    generateAnswers();
    lastMeal_ = std::chrono::steady_clock::now();
    print("has just born");
}

Philosopher::~Philosopher() {}

void Philosopher::dine()
{
    while (alive_)
    {
        updateStatus();
        eat();
        think(book_);
        //write();
        //answer();
    }
}

void Philosopher::updateStatus()
{
    auto now = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - lastMeal_).count();
    
    if (sleeping)
    {
        if (diff > diesAfterWhileSleeping_)
        {
            alive_ = false;
            print("just died");
        }
        full_ = true;
    }
    else
    {
        if (diff > diesAfter_)
        {
            alive_ = false;
            print("just died");
        }
        if (diff < cantEatBefore_)
            full_ = true;
        else
            full_ = false;
    }
}

void Philosopher::eat()
{
    if (alive_)
    {      
        if (!full_)
        {
        std::scoped_lock l(forkLeft_, forkRight_);
        print("has just picked up both forks and he starts eating");
        wait();
        print("has finished his meal");
        lastMeal_ = std::chrono::steady_clock::now();
        } 
    }
    updateStatus();
}

void Philosopher::think(Book & book)
{
    if (alive_ && !sleeping && full_)
    {
        wait();
        //std::shared_lock l(book.mutexBook_);
        print("accessed the book (for reading");
        for (auto &&i : answers_)
        {
            auto start = std::chrono::steady_clock::now();
            auto tmp = calculate(questions_.front(), i);
            auto end = std::chrono::steady_clock::now();
            auto diff = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
            std::unique_lock l(book.mutexBook_);
            book.reflections_.emplace_back(name_, i, tmp, diff, false);
        }
    }
    updateStatus();
}

void Philosopher::generateAnswers()
{
    size_t n = answers_.size();
    for (size_t i = 0; i < n; i++)
        answers_[i] = getRandomAnswer();
}

std::string Philosopher::getRandomAnswer()
{
    srand(time(NULL));
    std::string answer;
    for (size_t i = 0; i < 6; ++i)
        answer += getRandomChar();

    return answer;
}

char Philosopher::getRandomChar()
{
    const char allChars[] =
    "0123456789"
    "!@#$%^&*"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

    int size = sizeof(allChars) - 1;
    return allChars[rand() % size];
}

int Philosopher::calculate(const std::string & q, std::string & a)
{
    std::hash<std::string> h;
    std::string tmp = q + a;
    return h(tmp) % 123456789;
}

void Philosopher::print(std::string str)
{
    std::stringstream ss;
    ss << name_ << " " << str << std::endl;
    std::cout << ss.str();
}

void Philosopher::wait()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 2000));
}