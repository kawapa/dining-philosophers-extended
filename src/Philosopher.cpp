#include "..\inc\Philosopher.hpp"
#include <string>

Philosopher::Philosopher(std::string name_, int forkIndexLeft_, int forkIndexRight_)
    :
    name_(name_),
    forkIndexLeft_(forkIndexLeft_),
    forkIndexRight_(forkIndexRight_)
{
    answers_ = {"yo", "yo", "yo", "yo", "yo", "yo", "yo", "yo", "yo", "yo", };
}