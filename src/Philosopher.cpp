#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
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
std::condition_variable cv_;

Philosopher::Philosopher(const std::string name, std::mutex & left, std::mutex & right, Book & book,
            std::queue<std::string> & questions)
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

Philosopher::Philosopher(Philosopher&& obj) :
    name_(std::move(obj.name_)),
    forkLeft_(obj.forkLeft_),
    forkRight_(obj.forkRight_),
    book_(obj.book_),
    questions_(obj.questions_)
    { }

void Philosopher::dine()
{
    while (alive_)
    {
        updateStatus();
        eat();
        think();
        //chooseAndAnswer();
    }
}

void Philosopher::updateStatus()
{
    auto now = std::chrono::steady_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds>(now - lastMeal_).count();
    
    if (sleeping_)
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

void Philosopher::think()
{
    if (alive_ && !sleeping_ && full_)
    {
        wait();
        print("accessed the book (for reading)");
        for (size_t i = 0; i < 10; i++)
        {
            updateStatus();
            if (!alive_)
                break;
            auto start = std::chrono::steady_clock::now();

            std::shared_lock<std::shared_mutex> lock(book_.mutexBook_);
            auto tmpResult = calculate("How are you", answers_[i]);
            lock.unlock();
            wait();

            //auto tmp = calculate(questions_.front(), answers_[i]);
            auto end = std::chrono::steady_clock::now();
            auto tmpPeriod = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
            write(name_, answers_[i], tmpResult, tmpPeriod, i);
        }
    }
    updateStatus();
}

void Philosopher::write(std::string & name, std::string & answer, int result, int64_t period, int i)
{
    std::lock_guard<std::shared_mutex> lock(book_.mutexBook_);
    book_.reflections_.emplace_back(name, answer, result, period, false);
    print("writes down his", i);
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

void Philosopher::print(std::string str, int i)
{
    std::stringstream ss;
    ss << name_ << " " << str << " " << i + 1 << " answer" << std::endl;
    std::cout << ss.str();
}

void Philosopher::wait()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 4000));
}