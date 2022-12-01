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
void blanks(char array[])
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
    printf("Enter new id: ");
    gets(update.id);
    blanks(update.id);
    printf("Enter new name: ");
    gets(update.name);
    blanks(update.name);
    printf("Enter new cnic: ");
    gets(update.cnic);
    blanks(update.cnic);
    printf("Enter new phone number: ");
    gets(update.phone);
    blanks(update.phone);
    printf("Enter diesease: ");
    gets(update.disease);
    blanks(update.disease);
    printf("Enter if patient is admitted: ");
    gets(update.isadmitted);
    blanks(update.isadmitted);
    ptr = fopen("Patient_Records.txt", "r+");
    if (ptr == NULL)
    {
        printf("Could not open file.");
    }
    else
    {
        FILE *fp = fopen("Copy.txt", "w");
        char id[size];
        printf("Enter id of the patient you want to update: ");
        scanf("%s", id);

        char holder[size];
       while (fread(&patient, sizeof(struct client), 1, ptr))
        {
            if (strcmp(patient.id, id) != 0)
            {
               fwrite(&patient, sizeof(struct client), 1, fp);
            }
        }
        fwrite(&update, sizeof(struct client), 1, fp);
        fclose(ptr);
        fclose(fp);
        remove("Patient_Records.txt");
        rename("Copy.txt","Patient_Records.txt");
        printf("Record updated Succssefully.\n");
        
    }
}