#include <stdio.h>
#include <string.h>
#define size 30
extern unsigned int total_record;
struct display
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};

void DisplayPatient()
{
    struct display required;
    FILE *ptr = NULL;
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        int count=1;
        printf("\nTotal Patient Records: %u\n", total_record);
        printf("All the records of all patients is following: \n");
        while (fread(&required, sizeof(struct display), 1, ptr))
        {
            puts("-----------------------------------------\n");
            printf("The Record of Patient %d is: \n\n",count);
            printf("Patient's ID: %s\n", required.id);
            printf("Patient's Name: %s\n", required.name);
            printf("Patients CNIC: %s\n", required.cnic);
            printf("Patient's Phone number: %s\n", required.phone);
            printf("Patient's disease: %s\n", required.disease);
            printf("Patient is admitted: %s\n", required.isadmitted);
            puts("--------------------------------------------\n");
            count++;
        }

        fclose(ptr);
        printf("Record Searched Succssefully.\n");
    }
}