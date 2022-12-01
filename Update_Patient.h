#include <stdio.h>
#include <string.h>
#define size 30
extern unsigned int total_record;
struct client
{
    char id[size];
    char name[size];
    char cnic[size];
    char phone[size];
    char disease[size];
    char isadmitted[size];
};
void clr(char array[])
{
    int length = strlen(array);
    for (int i = length + 1; i < 30; i++)
    {
        array[i] = ' ';
    }
}
void updatePatient()
{
    FILE *fp = NULL;
    FILE *ptr = NULL;
    struct client patient;
    struct client update;
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        fp = fopen("Copyfile.txt", "a+");
        if (fp == NULL)
        {
            printf("Could not open file.");
        }
        else
        {
            char id[size];
            printf("Enter Patient id: ");
            scanf("%s", id);
            char holder[size];
            int checker = 0;
            while (fread(&patient, sizeof(struct client), 1, ptr))
            {
                if (strcmp(patient.id, id) == 0)
                {
                    printf("Enter Updated Data for the patient: \n");
                    printf("Enter Patient id: ");
                    fgets(update.id, size, stdin);
                    clr(update.id);
                    printf("Enter Patient name: ");
                    fgets(update.name, size, stdin);
                    clr(update.name);
                    printf("Enter Patient cnic: ");
                    fgets(update.cnic, size, stdin);
                    clr(update.cnic);
                    printf("Enter Patient Phone: ");
                    fgets(update.phone, size, stdin);
                    clr(update.phone);
                    printf("Enter Patient's disease: ");
                    fgets(update.disease, size, stdin);
                    clr(update.disease);
                    printf("Enter if patient is admitted: ");
                    fgets(update.isadmitted, size, stdin);
                    clr(update.isadmitted);
                    patient = update;
                }
            }
        }
        fclose(ptr);
        fclose(fp);
        printf("Update Done Succssefully.\n");
    }
}