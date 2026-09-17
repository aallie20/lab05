// src/grading.cpp
#include "grading.h"

#include <algorithm>
#include "Student.h"
#include "utilities.h"

double student_average(const Student& student){
    double total{};

    // Total the assignment scores for this student
    for (double score : student.score) {
        total += score;
    }

    return total / student.scores.size;
}
 double assignment_average(const Student students[], int assignment_index, int num_students){

    double total{};

    // Total this assignment's score down every student row
    for (int i{}; i < num_students; i++) {
        total += students[i].scores[assignments_index];
    }

    return total / num_students;
}

double class_average(const Student students[], int num_students);

    double total{};

    for (int i{}; i < num_students; i++) {
        for (double score : students[i].scores) {
            total += score;
        }
    }

    return total / (num_students * students[0].scores.size());
}

(const Student& student,
 double& lowest,
 double& highest);
    // Start from a real score so the result is correct for any range of
    // values, including all-negative ones

    lowest = student.scores[0];
    highest = student.scores[0];

    for (std::size_t i{1}; i < student.scores.size(); i++){
        lowest = std::min(lowest,
        student.scores[i]);
        highest = std::max(highest,
        student.scores[i]);

    }
}
int count_grade(const Student students[], char target, int num_students){
    int count{};

    for (int i {}; i < num_students; i++) {
       
       if (letter_grade(student_average(student[i])) == target) {
            count++;
        }
    }

    return count;
}

bool has_perfect_score(const Student& student);
    for (double score : student.scores) {
        if (score >= 100.0) {
            return true;
        }
    }

    return false;
}

bool is_at_risk(const Student& student);
    if (student_average(student) < 70.0) {
        return true;
    }

    for (double score : student.scores) {
        if (score < 50.0) {
            return true;
        }
    }

    return false;
}
