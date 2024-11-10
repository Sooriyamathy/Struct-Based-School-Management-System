#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "schoolstruct.h"
int school_count = 0;
student* student_struct_pointer;
course* course_struct_pointer;
school* school_struct_pointer;

// Function to initialize the first school and courses
void initiate() {
    school_count++;
    school_struct_pointer = (school*)malloc(1 * sizeof(school));

    if (school_struct_pointer == NULL) {
        printf("Memory allocation failed for school.\n");
        exit(1);  // Exit if memory allocation fails
    }

    printf("Enter the name of the first school: ");
    scanf("%s", school_struct_pointer->school_name);
    printf("\nEnter the number of courses offered in %s school: ", school_struct_pointer->school_name);
    scanf("%d", &school_struct_pointer->num_courses);

    // Allocate memory for courses
    school_struct_pointer->courses_offered = (course*)malloc(school_struct_pointer->num_courses * sizeof(course));
    if (school_struct_pointer->courses_offered == NULL) {
        printf("Memory allocation failed for courses.\n");
        exit(1);  // Exit if memory allocation fails
    }

    // Input courses
    for (int i = 0; i < school_struct_pointer->num_courses; i++) {
        printf("Enter the course %d details:\n", i + 1);
        printf("Enter the course name: ");
        scanf("%29s", school_struct_pointer->courses_offered[i].course_name);
        school_struct_pointer->courses_offered[i].student_count = 0;  // Initialize student count to 0
        school_struct_pointer->courses_offered[i].enrolled_list = NULL; // Initialize to NULL
    }
}

// Function to create a student and add to a course
void create_student() {
    char student_name_temp[40], y_or_n;
    int data1, data2;

    printf("Enter the student name: ");
    scanf("%s", student_name_temp);

    // Ask if student should be added to a school and course
    printf("Do you want to add a student to a school and course? (Y/N): ");
    scanf(" %c", &y_or_n);  // Add a space before %c to clear any leftover newlines

    if (y_or_n == 'Y' || y_or_n == 'y') {
        // Display list of schools
        for (int i = 0; i < school_count; i++) {
            printf("%d: %s\n", i + 1, school_struct_pointer[i].school_name);
        }

        // Input school number
        printf("Enter the school number you want to add the student to: ");
        scanf("%d", &data1);

        // Display courses in the selected school
        printf("Enter the course in %s you want the student %s to enroll in:\n", 
                school_struct_pointer[data1 - 1].school_name, student_name_temp);
        for (int i = 0; i < school_struct_pointer[data1 - 1].num_courses; i++) {
            printf("%d: %s\n", i + 1, school_struct_pointer[data1 - 1].courses_offered[i].course_name);
        }

        // Input course number
        printf("Enter the course number you want the student to enroll in: ");
        scanf("%d", &data2);

        // Allocate memory for the student in the selected course
        if (school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list == NULL) {
            // For first student in the course, allocate space
            school_struct_pointer[data1 - 1].courses_offered[data2 - 1].student_count = 1;
            school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list = (student*)malloc(sizeof(student));
        } else {
            // Reallocate memory to accommodate the new student
            school_struct_pointer[data1 - 1].courses_offered[data2 - 1].student_count++;
            school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list = 
                realloc(school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list,
                        school_struct_pointer[data1 - 1].courses_offered[data2 - 1].student_count * sizeof(student));
        }

        // Check if memory allocation failed
        if (school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list == NULL) {
            printf("Memory allocation failed for student enrollment list.\n");
            return;  // Exit the function if memory allocation fails
        }

        // Add student information
        strcpy(school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list[
               school_struct_pointer[data1 - 1].courses_offered[data2 - 1].student_count - 1
        ].student_name, student_name_temp);

        // Input student ID
        printf("Enter the student ID: ");
        scanf("%d", &school_struct_pointer[data1 - 1].courses_offered[data2 - 1].enrolled_list[
               school_struct_pointer[data1 - 1].courses_offered[data2 - 1].student_count - 1
        ].student_id);
    }
}

int main() {
    printf("Welcome to the School Management System\n");

    // Initialize the system (add first school and courses)
    initiate();

    int choice;
    do {
        // Display the main menu
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

        // Handle menu choices
        switch (choice) {
            case 1:
                // Call function to create a student
                create_student();
                break;
            case 2:
                // Call function to create a course
                printf("Create a Course function\n");
                break;
            case 3:
                // Call function to create a school
                printf("Create a School function\n");
                break;
            case 4:
                // Call function to print student details
                printf("Print Student Details function\n");
                break;
            case 5:
                // Call function to print course details
                printf("Print Course Details function\n");
                break;
            case 6:
                // Call function to print school details
                printf("Print School Details function\n");
                break;
            case 7:
                // Call function to check if student is in course
                printf("Check if Student is in Course function\n");
                break;
            case 8:
                // Call function to check if student is in school
                printf("Check if Student is in School function\n");
                break;
            case 9:
                // Call function to print all student courses
                printf("Print All Student Courses function\n");
                break;
            case 10:
                // Call function to print all students who failed a course
                printf("Print All Students Who Failed a Course function\n");
                break;
            case 11:
                // Call function to print all students who passed a course
                printf("Print All Students Who Passed a Course function\n");
                break;
            case 12:
                // Call function to print all courses with passed average grade
                printf("Print All Courses with Passed Average Grade function\n");
                break;
            case 13:
                // Call function to print all courses with failed average grade
                printf("Print All Courses with Failed Average Grade function\n");
                break;
            case 14:
                // Call function to print average grade across all courses
                printf("Print the Average Grade Across All Courses function\n");
                break;
            case 15:
                // Call function to print the course with the highest average grade
                printf("Print the Course with the Highest Average Grade function\n");
                break;
            case 0:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 0 and 15.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
