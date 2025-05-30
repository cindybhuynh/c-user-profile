#include <stdio.h>
#include <stdlib.h>

int main (){

    printf("Welcome to the User Profile App! \n");

    // User i/o for full name
    char firstName[30];
    char lastName[30];
    printf("Please enter your first and last name: ");
    scanf("%s%s", firstName, lastName);
    printf("This is your user profile: \n\n");
    printf("Full Name: %s %s \n", firstName, lastName);
    
}