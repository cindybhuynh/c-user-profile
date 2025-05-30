#include <stdio.h>
#include <stdlib.h>

int main (){

    printf("Welcome to the User Profile App! \n");
    /*
    // User i/o for full name
    char firstName[30];
    char lastName[30];
    printf("Please enter your first and last name: ");
    scanf("%s%s", firstName, lastName);
    printf("This is your user profile: \n\n");
    printf("Full Name: %s %s \n", firstName, lastName);
    */



    // User i/o for age
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age < 0) {
        printf("Invalid age entered. Please enter a valid age.\n");
        return 1; // Exit the program with an error code
    }
    printf("Age: %d \n", age);


    return 0;
}