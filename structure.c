#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee{
        int id;
        float marks;
        char name[100];
    };

int main(void){
    struct Employee e1;
    e1.id = 12;
    e1.marks = 34.22;

    printf("Employee ID? %d\n",e1.id);   
    return 0;
}