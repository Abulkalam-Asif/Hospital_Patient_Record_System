#include <stdio.h>
#include "AddPatient.h"
#include "Delete_Patient.h"
#include "Update_Patient.h"
#include "Search_Patient.h"
#include "Display_all_Patients.h"
unsigned int total_record;
int main()
{
    printf("Welcome to Hospital Patient Record System!\n\n");
    int flag = 1;
    int choice = 0;
    FILE*fp=NULL;
    fp=fopen("Total_records.txt", "r");
    if(fp==NULL)
    {
        printf("Error in reading file.\n");
    }
    else{
        fscanf(fp,"%u",&total_record);
    }
    fclose(fp);
    printf("%u", total_record);
    while (flag)
    {
        printf("1. Add Patient\n");
        printf("2. Delete Patient\n");
        printf("3. Update Patient\n");
        printf("4. Search Patient\n");
        printf("5. Display all Patients\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        int hold = 0;
        while ((hold = getchar() != '\n' && hold != EOF))
            ;
        switch (choice)
        {
        case 1:
            AddPatient();
            break;
        case 2:
            DeletePatient();
            break;
        case 3:
            updatePatient();
            break;
        case 4:
            searchPatient();
            break;
        case 5:
            DisplayPatient();
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("Wrong input from Manu, Please try again.\n");
            break;
        }
    }
    fp=fopen("Total_records.txt", "w");
    if(fp==NULL)
    {
        printf("Error in reading file.\n");
    }
    else{
        fprintf(fp,"%u",total_record);
    }
    fclose(fp);
    return 0;
}