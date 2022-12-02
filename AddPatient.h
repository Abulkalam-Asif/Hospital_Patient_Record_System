#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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
int cnic_checker(char array[])
{
    int check = 1;
    if (strlen(array) > 17)
    {
        return 0;
    }

    for (size_t i = 0; i < strlen(array); i++)
    {

        if (i == 5 || i == 13)
        {
            if (array[i] != '-')
            {
                return 0;
            }
        }
        char num = array[i];
        if ((num >= 48 && num <= 57) || num == 45)
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}
int name_checker(char array[])
{
    int check = 1;
    for (size_t i = 0; i < strlen(array); i++)
    {
        char num = array[i];
        if ((num >= 65 && num <= 90) || (num >= 97 && num <= 122))
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}
int repeat_check(char id[])
{
    int check = 1;
    struct Patient p1;
    FILE *fp = NULL;
    fp = fopen("Patient_Records.txt", "r");
    while (fread(&p1, sizeof(struct Patient), 1, fp))
    {
        if (strcmp(p1.id, id) == 0)
        {
            check = 0;
            break;
        }
    }
    fclose(fp);

    return check;
}
int id_checker(char array[])
{
    int check = 1;
    int repeat = repeat_check(array);
    if (repeat == 0)
    {
        return 2;
    }
    for (size_t i = 0; i < strlen(array); i++)
    {
        char num = array[i];
        if (num >= 48 && num <= 57)
        {
            check = 1;
        }
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}

struct Patient input(struct Patient patient)
{
    int validation = 1;
    while (validation)
    {
        printf("Enter Patient id (Any integer): ");
        gets(patient.id);
        spaces(patient.id);
        int check = id_checker(patient.id);
        if (check == 0)
        {
            printf("Wrong input of ID. ID can only be an integer. Try again\n");
            continue;
        }
        else if (check == 2)
        {
            printf("ID already Exists. Input Record again.\n");
            continue;
        }
        printf("Enter Patient name (In alphabets): ");
        gets(patient.name);
        spaces(patient.name);
        check = name_checker(patient.name);
        if (check == 0)
        {
            printf("Wrong input of Name. Name can only be a String. Try again\n");
            continue;
        }
        printf("Enter Patient cnic (Format : nnnn-nnnnnnn-n): ");
        gets(patient.cnic);
        spaces(patient.cnic);
        check = cnic_checker(patient.cnic);
        if (check == 0)
        {
            printf("Wrong input of CNIC. Please follow the format of CNIC. Try again\n");
            continue;
        }
        printf("Enter Patient Phone: ");
        gets(patient.phone);
        spaces(patient.phone);
        printf("Enter Patient's disease: ");
        gets(patient.disease);
        spaces(patient.disease);
        printf("Enter if patient is admitted: ");
        gets(patient.isadmitted);
        spaces(patient.isadmitted);
        validation = 0;
    }
    return patient;
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
        patient = input(patient);
        fwrite(&patient, sizeof(struct Patient), 1, ptr);
        fclose(ptr);
        total_record++;
    }
}