#include "..\inc\Philosopher.hpp"
#include <iostream>
#include <string>

Philosopher::Philosopher(const std::string & name_, int forkIndexLeft_, int forkIndexRight_)
    :
    name_(name_),
    forkIndexLeft_(forkIndexLeft_),
    forkIndexRight_(forkIndexRight_)
{
    generateAnswers();
    std::cout << name_ << " was born\n";
}

Philosopher::~Philosopher() { std::cout << name_ << " died\n"; }

void Philosopher::answer()
{

}

int Philosopher::calculate(const std::string & q, std::string & a)
{
    return 1;
}

void Philosopher::eat()
{

}

void Philosopher::start()
{
    while(1)
    {
        eat();
        think();
        write();
        answer();
    }
}

void Philosopher::think()
{

}

void Philosopher::write()
{

}

void Philosopher::generateAnswers()
{
    for (size_t i = 0; i < answers_.size(); i++)
        answers_[i] = getRandomAnswer();
    //for (auto &&i : answers_)
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