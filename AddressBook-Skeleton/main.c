#include<stdio.h>
#include<stdlib.h>
#include "contact.h"

int main()
{
    char ch='y';
    int opt;
    AddressBook addressBook;
    printf("\t\t\t\tCONTACT INFO\n");
    while(ch=='y')
    {
        printf("1.Create contact\n2.Contact list\n3.Edit contact\n4.Delete contact\n5.search contact\n6.Exit\n");
        printf("Enter the option:");
        scanf("%d",&opt);
        getchar();

        switch(opt)
        {
           case 1:
                 createContact(&addressBook);
                 break;
            case 2:
                 listContacts(&addressBook);
                 break;
            case 3:
                 editContact(&addressBook);
                 break;
            case 4:
                 deleteContact(&addressBook, fp);
                 break;
            case 5:
                 searchContact(&addressBook, fp);
                 break;      
            case 6:
                 exit(0);
                 break;
            default:
              printf("Invalid Input! Try with correct Input!\n");               
        }
    }
    printf("Do you want to continue (Y/N): ");
    scanf("%c",&ch);
}