#include "..\inc\Philosopher.hpp"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <thread>

using namespace std::chrono_literals;

Philosopher::Philosopher(const std::string & name_, int forkIndexLeft_, int forkIndexRight_)
    :
    name_(name_),
    forkIndexLeft_(forkIndexLeft_),
    forkIndexRight_(forkIndexRight_)
{
    lastMeal_ = std::chrono::steady_clock::now();
    generateAnswers();
    std::cout << name_ << " was born\n";
}

Philosopher::~Philosopher() { std::cout << name_ << " died\n"; }

void Philosopher::answer()
{
    std::cout << name_ << " is answering\n";
    std::this_thread::sleep_for(1s);
}

int Philosopher::calculate(const std::string & q, std::string & a)
{
    std::hash<std::string> h;
    std::string tmp = q + a;
    return h(tmp) % 123456789;
}

void Philosopher::eat()
{
    lastMeal_ = std::chrono::steady_clock::now();
}

void Philosopher::generateAnswers()
{
    for (size_t i = 0; i < answers_.size(); i++)
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

bool Philosopher::alive()
{
    auto now = std::chrono::steady_clock::now();
    return ((now - lastMeal_).count() < 5);
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

void Philosopher::live()
{
    while(alive_)
    {
        //eat();
        think();
        write();
        answer();
        alive_ = false;
    }
}

void Philosopher::think()
{
    std::cout << name_ << " is thinking\n";
    std::this_thread::sleep_for(1s);
}

void Philosopher::write()
{
    std::cout << name_ << " is writing\n";
    std::this_thread::sleep_for(1s);
}