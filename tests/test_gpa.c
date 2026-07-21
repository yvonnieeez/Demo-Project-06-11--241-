#include <stdio.h>
#include "course.h"
#include "courseResult.h"
#include "gpa.h"

int testCGPA()
{
    Course courses[3] = {
        createCourse("CSE 4107", "Structured Programming I", 3.0, 1),
        createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1),
        createCourse("CSE 4203", "Discrete Mathematics", 3.0, 2)
    };
    CourseResult results[3] = {
        createCourseResult(&courses[0], 240),
        createCourseResult(&courses[1], 105),
        createCourseResult(&courses[2], -1)
    };
    double cgpa = calculateGPA(results, 3);
    return cgpa > 3.83 && cgpa < 3.84;
}

int testGradePoint()
{
    Course course = createCourse("CSE 4107", "Structured Programming I", 3.0, 1);
    CourseResult result = createCourseResult(&course, 240);
    return getGradePoint(result) == 4.00;
}

int testLetterGrade()
{
    Course course = createCourse("CSE 4108", "Structured Programming I Lab", 1.5, 1);
    CourseResult result = createCourseResult(&course, 105);
    return getLetterGrade(result)[0] == 'A' && getLetterGrade(result)[1] == '-';
}

int testRequiredGPA()
{
    double required = calculateRequiredGPA(3.50, 90, 3.60, 30);
    return required > 3.89 && required < 3.91;
}

int main()
{
    printf("GPA module tests\n");
    int passed = 0;
    int total = 0;

    total++;
    if (testCGPA()) passed++;
    total++;
    if (testGradePoint()) passed++;
    total++;
    if (testLetterGrade()) passed++;
    total++;
    if (testRequiredGPA()) passed++;

    printf("Passed %d/%d tests\n", passed, total);
    if (passed == total) return 0;
    return 1;
}