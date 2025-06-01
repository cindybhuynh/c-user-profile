#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    
    printf("Welcome to the User Profile App! \n");
    
    // User I/O for full name
    char firstName[30];
    char lastName[30];
    printf("Please enter your first and last name (Ex: John Smith): ");
    scanf("%s%s", firstName, lastName);

    // User I/O for age
    int age;
    printf("Enter your age (Ex: 17): ");
    scanf("%d", &age);
    if (age < 0) {
        printf("Invalid age entered. Please enter a valid age.\n");
        return 1; // Exit the program with an error code
    }
    
    // Prompting user for school type
    char schoolLevel[12];
    char collegeLevel[20];
    int gradeLevel;
    char universityLevel[10];
    char universityYear[5];
    printf("What type of school are you in? (Ex: K-12, college, university): ");
    scanf(" %s",schoolLevel);
    if (strcmp(schoolLevel, "K-12") == 0) {
        printf("Enter your grade level (9, 10, 11, 12): ");
        scanf("%d", &gradeLevel);
        printf("Grade Level: %d\n", gradeLevel);    
    } else if (strcmp(schoolLevel, "college") == 0) {
        printf("Enter your college level (Freshman, Sophomore, Junior, etc.): ");
        scanf(" %s", collegeLevel);
        printf("College Level: %s\n", collegeLevel);
    } else if (strcmp(schoolLevel, "university") == 0) {
        printf("Enter your university level (First year, Second year, Third year, etc.): ");
        scanf(" %s%s", universityLevel, universityYear);
        printf("University Level: %s %s\n", universityLevel, universityYear);
    } else {
        printf("Please enter a valid type of school: ");
    }
    
    // User profile summary
    printf("This is your user profile: \n");
    printf("Full Name: %s %s\n", firstName, lastName);
    printf("Age: %d\n", age);
    
    return 0;
}