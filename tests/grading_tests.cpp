#include <gtest/gtest.h>
#include <algorithm>
#include <initializer_list>
#include "Student.h"
#include "grading.h"
#include "utilities.h"

TEST(GradingEdgeCases, OneStudentOneAssignment)
{
    Student student{
        "Test",
        {85.0, 85.0, 85.0, 85.0, 85.0}
    };

    EXPECT_DOUBLE_EQ(student_average(student), 85.0);

    double lowest{};
    double highest{};

    find_extremes(student, lowest, highest);

    EXPECT_DOUBLE_EQ(lowest, 85.0);
    EXPECT_DOUBLE_EQ(highest, 85.0);

    EXPECT_FALSE(is_at_risk(student));
    EXPECT_FALSE(has_perfect_score(student));
}

TEST(GradingEdgeCases, OneRowMultipleAssignments)
{
    Student student{
        "Test",
        {100.0, 45.0, 45.0, 90.0, 70.0}
    };

    EXPECT_TRUE(is_at_risk(student));
    EXPECT_TRUE(has_perfect_score(student));
}

TEST(GradingEdgeCases, ZeroesAndNegativeValues)
{
    Student students[]{
        {"A", {0.0, 0.0, 0.0, 0.0, 0.0}},
        {"B", {-10.0, -50.0, -5.0, -10.0, -10.0}}
    };

    double lowest{};
    double highest{};

    find_extremes(students[1], lowest, highest);

    EXPECT_DOUBLE_EQ(lowest, -50.0);
    EXPECT_DOUBLE_EQ(highest, -5.0);

    EXPECT_TRUE(is_at_risk(students[1]));
}

TEST(GradingEdgeCases, AtRiskVariations)
{
    Student students[]{
        {"A", {80.0, 80.0, 80.0, 49.0, 49.0}},
        {"B", {55.0, 55.0, 55.0, 55.0, 55.0}},
        {"C", {40.0, 45.0, 90.0, 90.0, 90.0}},
        {"D", {70.0, 70.0, 70.0, 70.0, 70.0}}
    };

    EXPECT_TRUE(is_at_risk(students[0]));
    EXPECT_TRUE(is_at_risk(students[1]));
    EXPECT_TRUE(is_at_risk(students[2]));
    EXPECT_FALSE(is_at_risk(students[3]));
}

TEST(GradingEdgeCases, PerfectScoreVariations)
{
    Student students[]{
        {"A", {99.9, 99.9, 99.9, 99.9, 99.9}},
        {"B", {100.0, 0.0, 0.0, 0.0, 0.0}},
        {"C", {105.0, 100.0, 102.0, 0.0, 0.0}}
    };

    EXPECT_FALSE(has_perfect_score(students[0]));
    EXPECT_TRUE(has_perfect_score(students[1]));
    EXPECT_TRUE(has_perfect_score(students[2]));
}
