#ifndef STUDENT_H
#define STUDENT_H
#include <array>
#include <string>

 constexpr int num_assignments{5};
 
    struct Student{
          std::string name;
          std:: array<double, num_assignments> scores;
    };

#endif
