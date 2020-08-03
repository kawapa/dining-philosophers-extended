#include "Reflection.hpp"

Reflection::Reflection(std::string philosopher, std::string answer, int result, int64_t period)
    : philosopher_(philosopher),
      answer_(answer),
      result_(result),
      period_(period)
{
        chosen_ = false;
}
