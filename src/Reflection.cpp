#include "..\inc\Reflection.hpp"
#include <string>

Reflection::Reflection(const std::string & ph, const std::string & an, int re, std::chrono::seconds pe, bool ch)
        :
        philosopher(ph),
        answer(an),
        result(re),
        period(pe),
        chosen(ch) { }