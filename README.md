# Description

*Dining philosophers - extended version* is one of the two final projects which conclude the course "Multithreading in C++" from Coders School (https://coders.school/).

## Objective

Implement a solution for a more advanced dining philosophers problem.

## Detailed requirements

* A peasant ask an existential question to 5 philosophers (the user types in the question in the console)
    * Questions for the philosophers can be implemented as a thread pool
* Each philosopher has its own set of 10 answers
* Each philosopher uses different algorithm when thinking through all possible answers 
* Algorithm for thinking returns an integer and requires two arguments
    * A question (`std::string`)
    * An answer (`std::string`)
* All philosophers, when thinking, use special Book which gives them a wisdom and inspiration
* All philosophers can use the Book simultaneously for reading
* A philosopher needs to think over all his/her answers before he decides on the final answer
* A philosopher must be full before he start thinking
* In order to start a meal, a philosopher needs to collect two forks
    * Number of forks corresponds to the number of philosophers (this requirement comes from the original [dining-philosopher problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem))
* A philosopher, after thinking over each answer writes down his/her thoughts in the Book
* Writing in the Book requires an exclusive access
* A single thought/reflection in the Book has the following format:

```cpp
struct {
    string philosopher,
    string answer,
    int result,
    chrono::duration period,
    bool chosen = false,
}
```

* A philosopher needs to wait 3 seconds before he can start a new meal
* A philosopher starve to death after 20 seconds from the last meal
* During the program, the user can put a philosopher to sleep and wake him/her up (using a special command)
* A sleeping philosopher cannot think nor eat and dies after 60 seconds
* Each philosopher, once all answers are studied:
    * Returns the final answer for a question
    * Makes `chosen = true`
* The final answer for a question is the maximum product of `result * period` of all answers