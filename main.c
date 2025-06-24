#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char fullName[100];
    int age;
    char gender[50];
    char schoolType[50];
    int gradeLevel;
    char schoolLevel[50];
    double gpa;
    char favHobbies[150];
} Student;


int main (){
    printf("Welcome to the User Profile App! \n");

    Student students[MAX_STUDENTS];

    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();

    int i;
    for (i = 0; i < numStudents; i++) {
        printf("\n----- Student %d -----\n", i + 1);

        printf("Enter your full name: ");
        fgets(students[i].fullName, sizeof(students[i].fullName), stdin);
        students[i].fullName[strcspn(students[i].fullName, "\n")] = '\0';

        printf("Enter your age: ");
        scanf("%d", &students[i].age);
        getchar();

        printf("Enter your gender: ");
        scanf(" %s", students[i].gender);

        printf("Enter your school type (K-12, College, University): ");
        scanf(" %s", students[i].schoolType);
        
        if (strcmp(students[i].schoolType, "K-12") == 0) {
            printf("Enter your grade level (Ex: 9, 10, 11, 12, etc.): ");
            scanf("%d", &students[i].gradeLevel);
        } else if (strcmp(students[i].schoolType, "College") == 0) {
            printf("Enter your college level (Ex: Freshman, Sophomore, etc.): ");
            scanf("%s", students[i].schoolLevel);
        } else if (strcmp(students[i].schoolType, "University") == 0) {
            getchar();
            printf("Enter your university level (Ex: First year, Second year, etc.): ");
            fgets(students[i].schoolLevel, sizeof(students[i].schoolLevel), stdin);
            students[i].schoolLevel[strcspn(students[i].schoolLevel, "\n")] = '\0';
        } else {
            printf("Invalid school type. Enter a valid school type.\n");
        }
        
        printf("Enter your gpa: ");
        scanf("%lf", &students[i].gpa);
        getchar();

        printf("Enter your favorite hobbies: ");
        fgets(students[i].favHobbies, sizeof(students[i].favHobbies), stdin);
        students[i].favHobbies[strcspn(students[i].favHobbies, "\n")] = '\0';
    }

    printf("\n----- Student Profiles -----\n");
    for (i = 0; i < numStudents; i++) {
        printf("\nFull Name: %s\n", students[i].fullName);
        printf("Age: %d\n", students[i].age);
        printf("Gender: %s\n", students[i].gender);
        printf("School Type: %s\n", students[i].schoolType);
        if (strcmp(students[i].schoolType, "K-12") == 0) {
            printf("Grade Level: %d\n", students[i].gradeLevel);
        } else if (strcmp(students[i].schoolType, "College") == 0) {
            printf("College Level: %s\n", students[i].schoolLevel);
        } else if (strcmp(students[i].schoolType, "University") == 0) {
            printf("University Level: %s\n", students[i].schoolLevel);
        }
        printf("GPA: %.2f\n", students[i].gpa);
        printf("Favorite Hobbies: %s\n", students[i].favHobbies);
        // Add the rest of the user input in the summary here
    }

    FILE *file = fopen("student_profiles.txt", "w");
    if (file == NULL) {
            printf("Error opening file.\n");
            return 1;
    }

    fprintf(file, "----- Student Profiles -----\n");

    for (i = 0; i < numStudents; i++) {
        fprintf(file, "\nFull Name: %s\n", students[i].fullName);
        fprintf(file, "Age: %d\n", students[i].age);
        fprintf(file, "Gender: %s\n", students[i].gender);
        fprintf(file, "School Type: %s\n", students[i].schoolType);
        if (strcmp(students[i].schoolType, "K-12") == 0) {
            fprintf(file, "Grade Level: %d\n", students[i].gradeLevel);
        } else if (strcmp(students[i].schoolType, "College") == 0) {
            fprintf(file, "College Level: %s\n", students[i].schoolLevel);
        } else if (strcmp(students[i].schoolType, "University") == 0) {
            fprintf(file, "University Level: %s\n", students[i].schoolLevel);
        }
        fprintf(file, "GPA: %.2f\n", students[i].gpa);
        fprintf(file, "Favorite Hobbies: %s\n", students[i].favHobbies);
        // Add the rest of the user input in the summary here
    }

    fclose(file);

    return 0;
}
