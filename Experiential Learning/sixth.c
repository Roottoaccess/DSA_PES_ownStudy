/* SIXTH PROGRAM */
#include<stdio.h>
#include<string.h>
struct student
{
    /* data */
    char name[20];
    int age;
    float marks;
};

float calculate_average_marks(struct student students[], int size){
    float totalMarks = 0;

    for(int i = 0; i < size; i++){
        totalMarks += students[i].marks;

    }
    return totalMarks / size;
}

int main(void){

    struct student students[3] = {
        {"Jack", 20, 88.5},
        {"Bob", 22, 92.66},
        {"Jimmy", 24, 82.4}
    };

    int size = 3;

    float average_marks = calculate_average_marks(students, size);
    printf("The average marks of the student %.2f\n", average_marks);
    return 0;
}