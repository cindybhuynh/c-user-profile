#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STUDENTS 100


typedef struct {
   char firstName[50];
   char lastName[50];
   int age;
   char schoolType[50];
   int gradeLevel;
   char schoolLevel[50];
   double gpa;
   char favHobbies[100];
} Student;


int main (){
  
   printf("Welcome to the User Profile App! \n");


   Student students[MAX_STUDENTS];


   int numStudents;
   printf("Enter the number of students: ");
   scanf("%d", &numStudents);


   for (int i = 0; i < numStudents; i++) {
       printf("\n----- Student %d -----\n", i + 1);
       printf("Enter your First name: ");
       scanf("%s", students[i].firstName);


       printf("Enter your Last name: ");
       scanf("%s", students[i].lastName);


       printf("Enter your age (Ex: 17): ");
       scanf(" %d", &students[i].age);


       printf("Enter your school type (Ex: K-12, College, University): ");
       scanf(" %s", students[i].schoolType);
       // Add the rest of the user input here!
      
       /*
       if (strcmp(students[i].schoolType, "K-12") == 0) {
           printf("Enter your grade level (Ex: 9, 10, 11, 12, etc.): ");
           scanf("%s", students[i].gradeLevel);
       } else if (strcmp(students[i].schoolType, "College") == 0) {
           printf("Enter your college level (Ex: Freshman, Sophomore, etc.): ");
           scanf("%s", students[i].schoolLevel);
       } else if (strcmp(students[i].schoolType, "University") == 0) {
           printf("Enter your university level (Ex: First year, Second year, etc.): ");
           scanf("%s", students[i].schoolLevel);
       } else {
           printf("Invalid school type. Enter a valid school type.\n");
       }
       */
   }


   printf("\n----- Student Profiles -----\n");


   int i;
   for (i = 0; i < numStudents; i++) {
       printf("First Name: %s\n", students[i].firstName);
       printf("Last Name: %s\n", students[i].lastName);
       printf("Age: %d\n", students[i].age);
       printf("School Type: %s\n", students[i].schoolType);
       // Add the rest of the user input in the summary here
   }


   /*
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
       printf("Enter your grade level (9, 10, 11, 12, etc.): ");
       scanf("%d", &gradeLevel); 
   } else if (strcmp(schoolLevel, "college") == 0) {
       printf("Enter your college level (Freshman, Sophomore, Junior, etc.): ");
       scanf(" %s", collegeLevel);
   } else if (strcmp(schoolLevel, "university") == 0) {
       printf("Enter your university level (First year, Second year, Third year, etc.): ");
       scanf(" %s%s", universityLevel, universityYear);
   } else {
       printf("Invalid school type entered. Please enter a valid school type.\n");
       return 1; // Exit the program
   }
  
   // User I/O for gpa
   double gpa;
   printf("Enter your current gpa (Ex: 3.973): ");
   scanf("%lf", &gpa);


   // User I/O for favorite hobbies
   char favHobbies[50];
   printf("Enter your favorite hobby (Reading, Learning languages, Dancing, etc.): ");
   scanf(" %s", favHobbies);


   // User profile summary
   printf("This is your user profile: \n");
   printf("Full Name: %s %s\n", firstName, lastName);
   printf("Age: %d\n", age);
   if (strcmp(schoolLevel, "K-12") == 0) {
       printf("Grade Level: %d\n", gradeLevel);
   } else if (strcmp(schoolLevel, "college") == 0) {
       printf("College Year: %s\n", collegeLevel);
   } else if (strcmp(schoolLevel, "university") == 0) {
       printf("University Year: %s %s\n", universityLevel, universityYear);
   }
   printf("GPA: %.3f\n", gpa);
   printf("Favorite Hobby: %s\n", favHobbies);
   */


   return 0;
}
