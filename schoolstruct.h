#ifndef SCHOOLSTRUCT_H
#define SCHOOLSTRUCT_H
typedef struct student_struct
{
    char student_name[30];
    int student_id;
    int mark;
}student;
typedef struct course_struct
{
    char course_name[30];
    float average_grade;
    student* enrolled_list;
    int student_count;
}course;
typedef struct school_struct
{
    char school_name[50];
    int num_courses;
    course* courses_offered;
}school;
#endif