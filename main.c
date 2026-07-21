#include "course.h"

int main()
{
    Course courses[1000];
    int n_courses = 0;

    courses[n_courses++] = createCourse("CSE 4107", "Structured Programming I", 3.0);
    courses[n_courses++] = createCourse("CSE 4108", "Structured Programming I Lab", 1.5);
    courses[n_courses++] = createCourse("CSE 4203", "Discrete Mathematics", 3.0);
    courses[n_courses++] = createCourse("CSE 4205", "Digital Logic Design", 3.0);
    courses[n_courses++] = createCourse("Hum 4244", "English II", 2.0);
    courses[n_courses++] = createCourse("Phy 4242", "Physics II Lab", 1.5);

    for (int i = 0; i < n_courses; i++)
    {
        viewCourse(courses[i]);
    }

    return 0;
}