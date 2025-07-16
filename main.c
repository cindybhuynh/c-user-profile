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

    int numStudents = 0;
    int newStudents = 0;

    // Check if the file exists and read existing student data

    FILE *fp = fopen("student_profiles.txt", "r");
    
    if (fp == NULL) {
        printf("No existing student data. Starting fresh.\n");
    }

    if (fp != NULL) {
        char line[512];
        while (fgets(line, sizeof(line), fp)) {
            if (strncmp(line, "Full Name:", 10) == 0) {
                sscanf(line, "Full Name: %s", students[numStudents].fullName);
                fgets(line, sizeof(line), fp);
                sscanf(line, "Age: %d", &students[numStudents].age);
                fgets(line, sizeof(line), fp);
                sscanf(line, "Gender: %s", students[numStudents].gender);
                fgets(line, sizeof(line), fp);
                sscanf(line, "School Type: %s", students[numStudents].schoolType);
                
                if (strcmp(students[numStudents].schoolType, "K-12") == 0) {
                    fgets(line, sizeof(line), fp);
                    sscanf(line, "Grade Level: %d", &students[numStudents].gradeLevel);
                } else if (strcmp(students[numStudents].schoolType, "College") == 0) {
                    fgets(line, sizeof(line), fp);
                    sscanf(line, "College Level: %s", students[numStudents].schoolLevel);
                } else if (strcmp(students[numStudents].schoolType, "University") == 0) {
                    fgets(line, sizeof(line), fp);
                    sscanf(line, "University Level: %s", students[numStudents].schoolLevel);
                }
                
                fgets(line, sizeof(line), fp);
                sscanf(line, "GPA: %lf", &students[numStudents].gpa);
                fgets(line, sizeof(line), fp);
                sscanf(line, "Favorite Hobbies: %s", students[numStudents].favHobbies);
                
                numStudents++; // moves to the next student
            }
        }
        fclose(fp);
        printf("%d existing student(s) loaded\n", numStudents);
    }

    printf("How many new students do you want to add? ");
    scanf("%d", &newStudents);
    getchar();

    int i;
    for (i = 0; i < newStudents; i++) {
        int idx = numStudents + i;

        printf("\n----- Student %d -----\n", i + 1);

        printf("Enter your full name: ");
        fgets(students[idx].fullName, sizeof(students[idx].fullName), stdin);
        students[idx].fullName[strcspn(students[idx].fullName, "\n")] = '\0';

        printf("Enter your age: ");
        scanf("%d", &students[idx].age);
        getchar();

        printf("Enter your gender: ");
        scanf(" %s", students[idx].gender);

        printf("Enter your school type (K-12, College, University): ");
        scanf(" %s", students[idx].schoolType);
        
        if (strcmp(students[idx].schoolType, "K-12") == 0) {
            printf("Enter your grade level (Ex: 9, 10, 11, 12, etc.): ");
            scanf("%d", &students[idx].gradeLevel);
        } else if (strcmp(students[idx].schoolType, "College") == 0) {
            printf("Enter your college level (Ex: Freshman, Sophomore, etc.): ");
            scanf("%s", students[idx].schoolLevel);
        } else if (strcmp(students[idx].schoolType, "University") == 0) {
            getchar();
            printf("Enter your university level (Ex: First year, Second year, etc.): ");
            fgets(students[idx].schoolLevel, sizeof(students[idx].schoolLevel), stdin);
            students[idx].schoolLevel[strcspn(students[idx].schoolLevel, "\n")] = '\0';
        } else {
            printf("Invalid school type. Enter a valid school type.\n");
        }
        
        printf("Enter your gpa: ");
        scanf("%lf", &students[idx].gpa);
        getchar();

        printf("Enter your favorite hobbies: ");
        fgets(students[idx].favHobbies, sizeof(students[idx].favHobbies), stdin);
        students[idx].favHobbies[strcspn(students[idx].favHobbies, "\n")] = '\0';
    }
    /*
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
    }
    */

    numStudents += newStudents;
    fp = fopen("student_profiles.txt", "w");
    if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
    }

    fprintf(fp, "----- Student Profiles -----\n");

    for (i = 0; i < numStudents; i++) {
        fprintf(fp, "\nFull Name: %s\n", students[i].fullName);
        fprintf(fp, "Age: %d\n", students[i].age);
        fprintf(fp, "Gender: %s\n", students[i].gender);
        fprintf(fp, "School Type: %s\n", students[i].schoolType);
        if (strcmp(students[i].schoolType, "K-12") == 0) {
            fprintf(fp, "Grade Level: %d\n", students[i].gradeLevel);
        } else if (strcmp(students[i].schoolType, "College") == 0) {
            fprintf(fp, "College Level: %s\n", students[i].schoolLevel);
        } else if (strcmp(students[i].schoolType, "University") == 0) {
            fprintf(fp, "University Level: %s\n", students[i].schoolLevel);
        }
        fprintf(fp, "GPA: %.2f\n", students[i].gpa);
        fprintf(fp, "Favorite Hobbies: %s\n", students[i].favHobbies);
    }
    fclose(fp);

    return 0;
}
