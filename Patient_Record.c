#include <stdio.h>
#include "AddPatient.h"
#include "Delete_Patient.h"
#include "Update_Patient.h"
#include "Search_Patient.h"
unsigned int total_record = 0;
int main()
{
    printf("Welcome to Hospital Patient Record System!\n\n");
    int flag = 1;
    int choice = 0;
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
        case 4:
            searchPatient();
        default:
            flag = 0;
            break;
        }
    }

    return 0;
}