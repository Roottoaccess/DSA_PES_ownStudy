/* performing the linear search algorithm */

#include<stdio.h>
/* Function Defination */
void LinearSearch(int lmt, int arr[], int key);

/* Function Description */
void LinearSearch(int lmt, int arr[], int key){
    int count = 0;
    for(int i = 0;i < lmt; i++){
        if(arr[i] == key){
            count++;
        }
    }
    if(count > 0){
        printf("The elements %d has been found %d times\n",key,count);
    } else{
        printf("Sorry we couldn't found the value....\n");
    }
}

int main(void){
    int lmt; // Taking the size of the array from the user..

    printf("What's the limit? ");
    scanf("%d",&lmt);

    /* Defining the array */ 
    int arr[lmt];

    /* Importing the data inside the array */
    printf("Enter the value one by one....\n");

// Putting the elements inside the array..
    for(int i = 0; i < lmt; i++){
        scanf("%d",&arr[i]);
    }

// Displaying the array....
    for(int i = 0; i < lmt; i++){
        printf("%d\t",arr[i]);
    }
printf("\n");
int key;
    printf("Enter the value you want to search? ");
        scanf("%d",&key);
// Calling the function....
    LinearSearch(lmt, arr, key);
    return 0;
}