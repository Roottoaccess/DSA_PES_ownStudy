#include<stdio.h>

// Structure is a user define datatype....
struct Student{
    int id;
    int age;
    float marks;
};
int main(void){
    // Putting the value in the structure.....
    struct Student Harry, Potter, Jimmy;

    Harry.id = 1;
    Harry.age = 22;
    Harry.marks = 66;

    Potter.id = 2;
    Potter.age = 14;
    Potter.marks = 90;

    Jimmy.id = 3;
    Jimmy.age = 32;
    Jimmy.marks = 99.4444;

    printf("student id: %d , student age: %d, student marks: %.2f\n", Harry.id, Harry.age, Harry.marks);
    printf("student id: %d , student age: %d, student marks: %.2f\n", Potter.id, Potter.age, Potter.marks);
    printf("student id: %d , student age: %d, student marks: %.2f\n", Jimmy.id, Jimmy.age, Jimmy.marks);
}