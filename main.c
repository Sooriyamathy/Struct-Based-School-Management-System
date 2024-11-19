#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "schoolstruct.h"
// Function prototypes
student *createstudent();
course *createcourse();
school *createschool();
void printcoursedetails(course *a, int num);
void printstudentdetails(student *a, int num);
float calculateaverage(course *c);
void checkstudentincourse(course *c, int num);
void checkstudentinschool(school *s);
void printstudentsfailed(course *c, int fail_mark);
void printstudentspassed(course *c, int pass_mark);
void printcoursesaboveaverage(course *c, int num, float threshold);
void printcoursesbelowaverage(course *c, int num, float threshold);
void printaverageacrosscourses(course *c, int num);
void printcoursehighestaverage(course *c, int num);
void free_memory(school *a);

int main() {
    school *a = NULL;
    course *b = NULL;
    student *c = NULL;
    int choice, fail_mark, pass_mark;
    do {
        printf("\n==== Main Menu ====\n");
        printf("1. Create a Student\n");
        printf("2. Create a Course\n");
        printf("3. Create a School\n");
        printf("4. Print Student Details\n");
        printf("5. Print Course Details\n");
        printf("6. Print School Details\n");
        printf("7. Check if Student is in Course\n");
        printf("8. Check if Student is in School\n");
        printf("9. Print All Student Courses\n");
        printf("10. Print All Students Who Failed a Course\n");
        printf("11. Print All Students Who Passed a Course\n");
        printf("12. Print All the Courses with Passed Average Grade\n");
        printf("13. Print All the Courses with Failed Average Grade\n");
        printf("14. Print the Average Grade Across All Courses\n");
        printf("15. Print the Course with the Highest Average Grade\n");
        printf("0. Exit\n");
        printf("Enter your choice (0-15): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                c = createstudent();
                break;
            case 2:
                b = createcourse();
                break;
            case 3:
                a = createschool();
                break;
            case 4:
                if (a != NULL) {
                    for (int i = 0; i < a->num_courses; i++) {
                        printstudentdetails(a->courses_offered[i].enrolled_list, a->courses_offered[i].student_count);
                    }
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 5:
                if (a != NULL) {
                    printcoursedetails(a->courses_offered, a->num_courses);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 6:
                if (a != NULL) {
                    printf("School Name: %s\n", a->school_name);
                    printf("Courses Offered:\n");
                    for (int i = 0; i < a->num_courses; i++) {
                        printf("  %d. %s\n", i + 1, a->courses_offered[i].course_name);
                    }
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 7:
                if (a != NULL) {
                    checkstudentincourse(a->courses_offered, a->num_courses);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 8:
                if (a != NULL) {
                    checkstudentinschool(a);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 9:
                if (a != NULL) {
                    for (int i = 0; i < a->num_courses; i++) {
                        printf("Course: %s\n", a->courses_offered[i].course_name);
                    }
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 10:
                printf("Enter the fail mark threshold: ");
                scanf("%d", &fail_mark);
                for (int i = 0; i < a->num_courses; i++) {
                    printstudentsfailed(&a->courses_offered[i], fail_mark);
                }
                break;
            case 11:
                printf("Enter the pass mark threshold: ");
                scanf("%d", &pass_mark);
                for (int i = 0; i < a->num_courses; i++) {
                    printstudentspassed(&a->courses_offered[i], pass_mark);
                }
                break;
            case 12:
                if (a != NULL) {
                    printcoursesaboveaverage(a->courses_offered, a->num_courses, 50.0);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 13:
                if (a != NULL) {
                    printcoursesbelowaverage(a->courses_offered, a->num_courses, 50.0);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 14:
                if (a != NULL) {
                    printaverageacrosscourses(a->courses_offered, a->num_courses);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 15:
                if (a != NULL) {
                    printcoursehighestaverage(a->courses_offered, a->num_courses);
                } else {
                    printf("No school created yet.\n");
                }
                break;
            case 0:
                free_memory(a);  // Free the allocated memory before exiting
                printf("Memory freed. Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 0 and 15.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

// Definitions of functions
student *createstudent() {
    student *newstudent = (student*)malloc(sizeof(student));
    printf("Enter the student name: ");
    scanf("%s", newstudent->student_name);
    printf("Enter the student ID: ");
    scanf("%d", &newstudent->student_id);
    printf("Enter the student grade: ");
    scanf("%d", &newstudent->mark);
    return newstudent;
}

course *createcourse() {
    course *newcourse = (course*)malloc(sizeof(course));
    printf("Enter the course name: ");
    scanf("%s", newcourse->course_name);
    printf("Enter the number of students in the course: ");
    scanf("%d", &newcourse->student_count);
    newcourse->enrolled_list = (student*)malloc(newcourse->student_count * sizeof(student));

    for (int i = 0; i < newcourse->student_count; i++) {
        printf("Enter details for student %d:\n", i + 1);
        student *tempstudent = createstudent();
        newcourse->enrolled_list[i] = *tempstudent;
        free(tempstudent);
    }

    newcourse->average_grade = calculateaverage(newcourse);
    return newcourse;
}

school *createschool() {
    school *newschool = (school *)malloc(sizeof(school));
    printf("Enter the school name: ");
    scanf("%s", newschool->school_name);
    printf("Enter the number of courses: ");
    scanf("%d", &newschool->num_courses);
    newschool->courses_offered = (course *)malloc(newschool->num_courses * sizeof(course));

    for (int i = 0; i < newschool->num_courses; i++) {
        printf("Creating course %d:\n", i + 1);
        newschool->courses_offered[i] = *createcourse();
    }

    return newschool;
}

float calculateaverage(course *c) {
    float sum = 0.0;
    for (int i = 0; i < c->student_count; i++) {
        sum += c->enrolled_list[i].mark;
    }
    return sum / c->student_count;
}

void printstudentdetails(student *a, int num) {
    for (int i = 0; i < num; i++) {
        printf("Name: %s, ID: %d, Mark: %d\n", a[i].student_name, a[i].student_id, a[i].mark);
    }
}

void printcoursedetails(course *a, int num) {
    for (int i = 0; i < num; i++) {
        printf("Course: %s, Students: %d, Average Grade: %.2f\n", a[i].course_name, a[i].student_count, a[i].average_grade);
    }
}

void checkstudentincourse(course *c, int num) {
    char name[50];
    printf("Enter student name: ");
    scanf("%s", name);

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < c[i].student_count; j++) {
            if (strcmp(name, c[i].enrolled_list[j].student_name) == 0) {
                printf("%s is enrolled in %s\n", name, c[i].course_name);
                return;
            }
        }
    }
    printf("%s is not enrolled in any course.\n", name);
}

void checkstudentinschool(school *s) {
    char name[50];
    printf("Enter student name: ");
    scanf("%s", name);

    for (int i = 0; i < s->num_courses; i++) {
        for (int j = 0; j < s->courses_offered[i].student_count; j++) {
            if (strcmp(name, s->courses_offered[i].enrolled_list[j].student_name) == 0) {
                printf("%s is enrolled in the school.\n", name);
                return;
            }
        }
    }
    printf("%s is not enrolled in the school.\n", name);
}

void printstudentsfailed(course *c, int fail_mark) {
    printf("Students who failed in %s:\n", c->course_name);
    for (int i = 0; i < c->student_count; i++) {
        if (c->enrolled_list[i].mark < fail_mark) {
            printf("  %s (ID: %d, Mark: %d)\n", c->enrolled_list[i].student_name, c->enrolled_list[i].student_id, c->enrolled_list[i].mark);
        }
    }
}

void printstudentspassed(course *c, int pass_mark) {
    printf("Students who passed in %s:\n", c->course_name);
    for (int i = 0; i < c->student_count; i++) {
        if (c->enrolled_list[i].mark >= pass_mark) {
            printf("  %s (ID: %d, Mark: %d)\n", c->enrolled_list[i].student_name, c->enrolled_list[i].student_id, c->enrolled_list[i].mark);
        }
    }
}

void printcoursesaboveaverage(course *c, int num, float threshold) {
    printf("Courses with an average grade above %.2f:\n", threshold);
    for (int i = 0; i < num; i++) {
        if (c[i].average_grade > threshold) {
            printf("  %s\n", c[i].course_name);
        }
    }
}

void printcoursesbelowaverage(course *c, int num, float threshold) {
    printf("Courses with an average grade below %.2f:\n", threshold);
    for (int i = 0; i < num; i++) {
        if (c[i].average_grade < threshold) {
            printf("  %s\n", c[i].course_name);
        }
    }
}

void printaverageacrosscourses(course *c, int num) {
    float total = 0.0;
    for (int i = 0; i < num; i++) {
        total += c[i].average_grade;
    }
    printf("Average grade across all courses: %.2f\n", total / num);
}

void printcoursehighestaverage(course *c, int num) {
    int index = 0;
    for (int i = 1; i < num; i++) {
        if (c[i].average_grade > c[index].average_grade) {
            index = i;
        }
    }
    printf("Course with the highest average grade: %s (%.2f)\n", c[index].course_name, c[index].average_grade);
}
// Free function to deallocate all dynamically allocated memory
void free_memory(school *a) {
    if (a != NULL) {
        // Free each course's enrolled student list
        for (int i = 0; i < a->num_courses; i++) {
            free(a->courses_offered[i].enrolled_list);
        }
        // Free the courses array
        free(a->courses_offered);
        // Free the school object itself
        free(a);
    }
}
