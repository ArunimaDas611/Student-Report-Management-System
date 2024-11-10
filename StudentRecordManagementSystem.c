#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int i = 0, max = 700;

struct student
{
    char name[100];
    long long int prn;
    char sem[10];
    char batch[20];
    char sec;
    float cgpa;
    float sgpa1, sgpa2, sgpa3, sgpa4, sgpa5, sgpa6;
}
st[705];

void section(long long int *x, int *i)
{
    float checkroll;
    checkroll = (float) *x/1000000000;

    if(checkroll >= 21.0 && checkroll < 22.0)
    {
        if(st[*i].sec != 'A' && st[*i].sec != 'B')
        {
            printf("This section doesn't exist for Batch 2021-2025\n");
        }
        else
        {
            strcpy(st[*i].batch, "2021-2025");
            strcpy(st[*i].sem, "VII");
        }
    }

    else if((checkroll >= 22.0 && checkroll < 23.0) || (checkroll >= 23.0 && checkroll < 24.0))
    {
        if(st[*i].sec != 'A' && st[*i].sec != 'B' && st[*i].sec != 'C')
        {
           if(checkroll >= 22.0 && checkroll < 23.0)
           {
                printf("This section doesn't exist for Batch 2022-2026\n");
           }
        
            else
           {
                printf("This section doesn't exist for Batch 2023-2027\n");
           }
        }
        else
        {
            if (checkroll >= 22.0 && checkroll < 23.0)
           {
                strcpy(st[*i].batch, "2022-2026");
                strcpy(st[*i].sem, "V");
           }
           else
           {
                strcpy(st[*i].batch, "2023-2027");
                strcpy(st[*i].sem, "III");
           }
        }
    }

    else 
    {
        if(st[*i].sec != 'A' && st[*i].sec != 'B' && st[*i].sec != 'C' && st[*i].sec != 'D')
        {
            printf("This section doesn't exist for Batch 2024-2028\n");
        }
        else
        {
            strcpy(st[*i].batch, "2024-2028");
            strcpy(st[*i].sem, "I");
        }
    }

}

void gpa(long long int *x, int *i)
{
    float checkroll = *x/1000000000;

    if(checkroll >= 24.0 && checkroll < 25.0)
    {
        printf("Enter CGPA : ");
        scanf("%f", &st[*i].cgpa);
    }
    else
    {
        if(checkroll >= 21.0 && checkroll < 22.0)
        {
            printf("Enter SGPA 1: ");
            scanf("%f", &st[*i].sgpa1);
            printf("Enter SGPA 2: ");
            scanf("%f", &st[*i].sgpa2);
            printf("Enter SGPA 3: ");
            scanf("%f", &st[*i].sgpa3);
            printf("Enter SGPA 4: ");
            scanf("%f", &st[*i].sgpa4);
            printf("Enter SGPA 5: ");
            scanf("%f", &st[*i].sgpa5);
            printf("Enter SGPA 6: ");
            scanf("%f", &st[*i].sgpa6);
            printf("Enter CGPA: ");
            scanf("%f", &st[*i].cgpa);
        }

        else if(checkroll >= 22.0 && checkroll < 23.0)
        {
            printf("Enter SGPA 1: ");
            scanf("%f", &st[*i].sgpa1);
            printf("Enter SGPA 2: ");
            scanf("%f", &st[*i].sgpa2);
            printf("Enter SGPA 3: ");
            scanf("%f", &st[*i].sgpa3);
            printf("Enter SGPA 4: ");
            scanf("%f", &st[*i].sgpa4);
            printf("Enter CGPA: ");
            scanf("%f", &st[*i].cgpa);
        }

        else
        {
            printf("Enter SGPA 1: ");
            scanf("%f", &st[*i].sgpa1);
            printf("Enter SGPA 2: ");
            scanf("%f", &st[*i].sgpa2);
            printf("Enter CGPA: ");
            scanf("%f", &st[*i].cgpa);
        }
    }
}

void showgpa(int *j)
{
    if(strcmp(st[*j].sem, "I") == 0)
    {
        printf("CGPA - %.1f\n\n", st[*j].cgpa);
    }
    else if(strcmp(st[*j].sem, "III") == 0)
    {
        printf("SGPA 1 - %.1f\n", st[*j].sgpa1);
        printf("SGPA 2 - %.1f\n", st[*j].sgpa2);
        printf("CGPA - %.1f\n\n", st[*j].cgpa);
    }
    else if(strcmp(st[*j].sem, "V") == 0)
    {
        printf("SGPA 1 - %.1f\n", st[*j].sgpa1);
        printf("SGPA 2 - %.1f\n", st[*j].sgpa2);
        printf("SGPA 3 - %.1f\n", st[*j].sgpa3);
        printf("SGPA 4 - %.1f\n", st[*j].sgpa4);
        printf("CGPA - %.1f\n\n", st[*j].cgpa);
    }
    else
    {
        printf("SGPA 1 - %.1f\n", st[*j].sgpa1);
        printf("SGPA 2 - %.1f\n", st[*j].sgpa2);
        printf("SGPA 3 - %.1f\n", st[*j].sgpa3);
        printf("SGPA 4 - %.1f\n", st[*j].sgpa4);
        printf("SGPA 5 - %.1f\n", st[*j].sgpa5);
        printf("SGPA 6 - %.1f\n", st[*j].sgpa6);
        printf("CGPA - %.1f\n\n", st[*j].cgpa);          
    }
}

void add_student()
{
    float checkroll;
    
    printf("Enter their name: ");
    scanf(" %[^\n]", st[i].name);
    
    printf("Enter their PRN: ");
    scanf("%lld", &st[i].prn);

    checkroll = (float) st[i].prn/1000000000;

    if(checkroll <= 21.07 || checkroll >= 24.08)
    {
        printf("Invalid PRN\n");
    }

    else
    {
        printf("Enter section: ");
        scanf(" %c", &st[i].sec);

        section(&st[i].prn, &i);

        gpa(&st[i].prn, &i);

        i++;
    
        printf("Details of the student have been succesfully added!\n\n");
    }
}

void find_by_roll()
{
    long long int roll;
    int found = 0;
    printf("Enter PRN of student: ");
    scanf(" %lld", &roll);

    for(int j = 0; j < i; j++)
    {
        if(roll == st[j].prn)
        {
            printf("The details of the student with PRN %lld are - \n\n", st[j].prn);
            printf("Name - %s\n", st[j].name);
            printf("PRN - %lld\n", st[j].prn);
            printf("Batch - %s\n", st[j].batch);
            printf("Semester - %s\n", st[j].sem);
            printf("Section - %c\n", st[j].sec);

            showgpa(&j);
            found = 1;
            break;
        }
    }
    if(!found)
    {
        printf("No student found.\n");
    }
}

void find_by_name()
{
    char temp[50];
    int found = 0;
    printf("Enter the name of the student: ");
    scanf(" %[^\n]s", temp);

    for(int j = 0; j <= i; j++)
    {
        if(!strcmp(st[j].name, temp))
        {
            printf("The student details of %s are - \n\n");
            printf("Name - %s\n", st[j].name);
            printf("PRN - %lld\n", st[j].prn);
            printf("Batch - %s\n", st[j].batch);
            printf("Semester - %s\n", st[j].sem);
            printf("Section - %c\n", st[j].sec);

            showgpa(&j);
            found = 1;
            break;
        }
    }
    
    if(!found)
    {
        printf("No student found.\n");
    }
}

void delete()
{
    long long int roll;
    int found = 0;
    printf("Enter the PRN of the student: ");
    scanf("%lld", &roll);

    for(int j = 0; j < i; j++)
    {
        if(roll == st[j].prn)
        {
            for(int k = j; k < i - 1; k++)
            {
                st[k] = st[k+1];
            }
            i--;
            found = 1;
            break;
        }
    }
    
    if(found)
    {
        printf("\nThe details of the student have been successfully deleted!\n\n");
    }
    else
    {
        printf("No student found.\n\n");
    }
}

void update()
{
    long long int roll;
    int found = 0;
    printf("Enter the PRN of the student: ");
    scanf("%lld", &roll);

    for(int j = 0; j < i; j++)
    {
        if(roll == st[j].prn)
        {
            int c;
            float checkroll;
            printf("1. Name\n");
            printf("2. PRN\n");
            printf("3. Section\n");
            printf("4. SGPA and CGPA\n");
            printf("Enter the number for the detail you want to update: ");
            scanf("%d", &c);

            switch(c)
            {
                case 1: printf("Enter their name: ");
                        scanf(" %[^\n]", st[j].name);
                        break;
                
                case 2: printf("Enter their PRN: ");
                        scanf("%lld", &st[j].prn);
                        break;

                case 3: printf("Enter the section they are in: ");
                        scanf(" %c", &st[j].sec);
                        section(&st[j].prn, &j);
                        break;

                case 4: gpa(&st[j].prn, &j);
                        break;
            }
            found = 1;
            break;
        }
    }
    
    if(found)
    {
        printf("The details of the student have been successfully updated\n\n");
    }
    else
    {
        printf("No student found.\n\n");
    }
}
void count()
{
    printf("The total number of students in this database is %d\n", i);
    printf("The maximum amount of students in this database is %d\n", max);

    if(i <= max)
    {
        if(max-i == 0)
        {
            printf("\nThe database is full\n");
        }
        else
        {
            printf("\nThe number of vacancies is %d\n", max-i);
        }
    }

    else
    {
        if(max - i == 1)
        {
            printf("\nThe database is overloaded by %d value. Please delete the extra student detail until the database is full or gets vacancies.\n");
        }
        else
        {
            printf("\nThe database is overloaded by %d values. Please delete the extra student detail until the database is full or gets vacancies.\n");
        }
    }
}

int main()
{
    int choice;
    long long int roll;
    char temp[50];

    printf("This is the student record management system of Symbiosis Institute of Technology, Nagpur. It can perform the following tasks: \n\n");
    
    do
    {
        printf("1. Add a student's details\n");
        printf("2. Find a student's details by their PRN\n");
        printf("3. Find a student's details by their name\n");
        printf("5. Delete a student's details\n");
        printf("6. Update a student's details\n");
        printf("7. Find the total number of students in this database\n");
        printf("8: Exit the program\n");
        printf("\nEnter the number for the task you want to perform: ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1: add_student();
                    break;

            case 2: find_by_roll();
                    break;

            case 3: find_by_name();
                    break;

            case 5: delete();
                    break;

            case 6: update();
                    break;

            case 7: count();
                    break;
        
            case 8: exit(0);
                    break;

        }
    }while(choice != 8);
    
    return 0;
}