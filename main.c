#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "schoolstruct.h"
/*int school_count = 0;
student* student_struct_pointer;
course* course_struct_pointer;
school* school_struct_pointer;
student* createstudent()
{
    student *newstudent=(student*)malloc(sizeof(student));
    printf("\nEnter the student name: ");
    scanf("%s",newstudent->student_name);
    printf("\nEnter the student id: ");
    scanf("%d",&newstudent->student_id);
    printf("\nEnter the student grade");
    scanf("%d",&newstudent->mark);
    return newstudent;
}
course* createcourse()
{
    course* newcourse=(course*)malloc(sizeof(course));
    printf("\nEnter the name of the course: ");
    scanf("%s",newcourse->course_name);
    printf("\nEnter the total number of students in the course: ");
    scanf("%d",&newcourse->student_count);
    newcourse->enrolled_list=(student*)malloc(sizeof(student)*newcourse->student_count);
    for(int i=0;i<newcourse->student_count;i++)
    {
        printf("Enter the student details of the %s course #%d:",newcourse->course_name,i+1);
        student* tempschool=createstudent();
        newcourse->enrolled_list[i].student_id=tempschool->student_id;
        strcpy(newcourse->enrolled_list[i].student_name,tempschool->student_name);
        newcourse->enrolled_list[i].mark=tempschool->mark;
    }
    float tempgrade=0.0;
    for(int i=0;i<newcourse->student_count;i++)
    {
        tempgrade+=newcourse->enrolled_list[i].mark;
    }
    newcourse->average_grade=(tempgrade/newcourse->student_count);
    return newcourse;
}
school* createschool()
{
    school* newschool=(school*)malloc(sizeof(school));
    printf("Enter the name of the school");
    scanf("%s",newschool->school_name);
    printf("\nEnter the number of courses in the school");
    scanf("%d",&newschool->num_courses);
    newschool->courses_offered=(course*)malloc(sizeof(course)*newschool->num_courses);
    for(int i=0;i<newschool->num_courses;i++)
    {
        printf("\nEnter the course details of #%d",i+1);
        course* newcourse=createcourse();
        newschool->courses_offered[i]=*newcourse;
    }
    return newschool;
}
void printcoursedetails(course* a,int num)
{
    for(int i=0;i<num;i++)
    {
        printf("the course #%d details:\n",i+1);
        printf("Name: %s\n",a[i].course_name);
        printf("number of students enrolled: %d\n",a[i].student_count);
        printf("The average grade is %f\n",a[i].average_grade);
    }
}
void printstudentdetails(student* a,int num)
{
    for(int i=0;i<num;i++)
    {
        printf("The student name is %s",a[i].student_name);
        printf("\nThe student id is %d",a[i].student_id);
        printf("\nThe grade of the student is %d",a[i].mark);
    }
}
int main() {
    printf("Welcome to the School Management System\n");
    // Initialize the system (add first school and courses)
    //initiate();
    school* a;
    course* b;
    student* c;
    int choice;
    int fail_mark=0;
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
                c=createstudent();
                break;
            case 2:
                // Call function to create a course
                b=createcourse();
                printf("\nthe average grade is %f",b->average_grade);
                //printf("Create a Course function\n");
                break;
            case 3:
                // Call function to create a school
                a=createschool();
                printf("Create a School function\n");
                break;
            case 4:
                // Call function to print student details
                for(int i=0;i<(a->num_courses);i++)
                {
                    printstudentdetails(a->courses_offered[i].enrolled_list,a->courses_offered[i].student_count);
                }
                
                printf("Print Student Details function\n");
                break;
            case 5:
                // Call function to print course details
                printf("Print Course Details function\n");
                printcoursedetails(a->courses_offered,a->num_courses);
                break;
            case 6:
                // Call function to print school details
                printf("\nThe school name is %s\n",a->school_name);
                printf("The courses offered are :\n");
                for(int i=0;i<a->num_courses;i++)
                {
                    printf("#%d:%s\n",i+1,a->courses_offered[i].course_name);
                }
                printf("\nThe students in the school are:\n");
                for(int i=0;i<a->num_courses;i++)
                {
                    for(int j=0;j<a->courses_offered[i].student_count;j++)
                    {
                        printf("#%s\n",a->courses_offered[i].enrolled_list[j].student_name);
                    }
                }
                break;
            case 7:
                // Call function to check if student is in course
                char search_name_course[40];
                int flag_course=1,search_number_course;
                printcoursedetails(a->courses_offered,a->num_courses);
                printf("Enter the course name to be searched: ");
                scanf("%s",search_number_course);
                printf("\nEnter the student name to be searched: ");
                scanf("%s",search_name_course);
                    for(int j=0;j<a->courses_offered[search_number_course-1].student_count;j++)
                    {
                        if(a->courses_offered[search_number_course-1].enrolled_list[j].student_name==search_name_course)
                        {
                            printf("the student is in the school\n");
                            flag_course=0;
                            break;
                        }
                    }
                
                if(flag_course==0)
                {
                    printf("The student is not found\n");
                }   
                break;
            case 8:
                // Call function to check if student is in school
                char search_name_school[40];
                int flag=1;
                printf("Enter the student name to be searched: ");
                scanf("%s",search_name_school);
                for(int i=0;i<a->num_courses;i++)
                {
                    for(int j=0;j<a->courses_offered[i].student_count;j++)
                    {
                        if(a->courses_offered[i].enrolled_list[j].student_name==search_name_school)
                        {
                            printf("the student is in the school\n");
                            flag=0;
                            break;
                        }
                    }
                }
                if(flag==0)
                {
                    printf("The student is not found\n");
                }
                break;
            case 9:
                // Call function to print all student courses
                printf("Print All Student Courses function\n");
                printcoursedetails(a->courses_offered,a->num_courses);
                break;
            case 10:
                // Call function to print all students who failed a course
                printf("Print All Students Who Failed a Course function\n");
                printf("enter the fail marks out of 100");
                scanf("%d",&fail_mark);
                
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
// Function to initialize the first school and courses
void initiate() {
    school_count++;
    school_struct_pointer = (school*)malloc(1 * sizeof(school));
    if (school_struct_pointer == NULL)
    {
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
}*/
// Function to create a student and add to a course
/*void create_student()
{

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
        } 
        else {
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
}*/
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
                printf("Exiting the program...\n");
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