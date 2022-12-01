#include <stdio.h>
#include <string.h>
#define size 30
extern unsigned int total_record;
struct Patient
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};
void spaces(char array[])
{
    int length = strlen(array);
    for (int i = length + 1; i < 30; i++)
    {
        array[i] = ' ';
    }
}
void AddPatient()
{
    FILE *ptr = NULL;
    struct Patient patient;
    ptr = fopen("Patient_Records.txt", "a");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        printf("Enter Patient id: ");
        gets(patient.id);
        spaces(patient.id);
        printf("Enter Patient name: ");
        gets(patient.name);
        spaces(patient.name);
        printf("Enter Patient cnic: ");
        gets(patient.cnic);
        spaces(patient.cnic);
        printf("Enter Patient Phone: ");
        gets(patient.phone);
        spaces(patient.phone);
        printf("Enter Patient's disease: ");
        gets(patient.disease);
        spaces(patient.disease);
        printf("Enter if patient is admitted: ");
        gets(patient.isadmitted);
        spaces(patient.isadmitted);
        //rewind(ptr);
        fwrite(&patient, sizeof(struct Patient), 1, ptr);
        fclose(ptr);
        total_record++;
    }
}