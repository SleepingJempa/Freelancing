#include <stdlib.h>
#include <stdio.h>

typedef struct Courses Courses;
typedef struct student student;

struct Courses
{
    float Math1, Math2, CompProg;
};

struct student
{
    char fullName[30];
    unsigned int st_id;
    float AVG;
    Courses StudentCourses;
};

int main()
{
    int n = 2;
    student std;

    FILE *f = fopen("Summer.dat", "w");

    for (int i = 0; i < n; i++)
    {
        printf("Enter name: ");
        scanf("%s", &std.fullName);
        
        printf("Enter st_id: ");
        scanf("%d", &std.st_id);
        
        printf("Enter Math1: ");
        scanf("%f", &std.StudentCourses.Math1);
        
        printf("Enter Math2: ");
        scanf("%f", &std.StudentCourses.Math2);
        
        printf("Enter CompProg: ");
        scanf("%f", &std.StudentCourses.CompProg);

        std.AVG = std.StudentCourses.Math1 + std.StudentCourses.Math2 + std.StudentCourses.CompProg;
        std.AVG /= 3.0;
        printf("ABV = %.2f\v", std.AVG);

        fprintf(f, "%s\n", std.fullName);
        fprintf(f, "%d\n", std.st_id);
        fprintf(f, "%f %f %f\n", std.StudentCourses.Math1, std.StudentCourses.Math2, std.StudentCourses.CompProg);
        fprintf(f, "%f\n", std.fullName);
    }

    fclose(f);    
}