#include <stdio.h>
#include <string.h>
#include "course.h"
#include "courseResult.h"
#include "student.h"

int testRankingFirstStudent()
{
    Course course = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Student students[2] = {
        createStudent("2", "Low"),
        createStudent("1", "High")
    };

    addCourseResultToStudent(&students[0], createCompletedCourseResult(&course, 210));
    addCourseResultToStudent(&students[1], createCompletedCourseResult(&course, 270));

    sortStudentsByCGPA(students, 2);
    return strcmp(students[0].id, "1") == 0;
}

int testRankingOrder()
{
    Course course = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    Student students[2] = {
        createStudent("2", "Low"),
        createStudent("1", "High")
    };

    addCourseResultToStudent(&students[0], createCompletedCourseResult(&course, 210));
    addCourseResultToStudent(&students[1], createCompletedCourseResult(&course, 270));

    sortStudentsByCGPA(students, 2);
    return students[0].cgpa > students[1].cgpa;
}

int main()
{
    printf("Student module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testRankingFirstStudent()) passed++;
    total++;
    if (testRankingOrder()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}