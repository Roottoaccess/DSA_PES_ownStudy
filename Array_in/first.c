// Passing the array as argument

#include<stdio.h>

// Creating another function..
void update(int marks[], int size){
    for(int i = 0; i < size; i++){
        marks[i] += 1;
    }
}

//Declaring the main function
int main(void){

    // Creating the array....
    int marks[] = {97, 98, 99};

    int size = sizeof(marks) / sizeof(marks[0]);

    // Calling the update function
    update(marks, size);

    // print out marks.....
    for(int i = 0; i < size; i++){
        printf("%d\n",marks[i]);
    }

return 0; // Nothing
}
