#include "contact.h"
#include<stdlib.h>
// void initialize(AddressBook *addressbook)
// {
//   addressbook->contacts=NULL;
//   addressbook->contactCount=0;
// }
void loadContact(AddressBook *addressbook)
{
    FILE*file=fopen("Addressbook.csv","r");
    if(file==NULL)
    {
    printf("Error opening file in writing\n" );
    return;
    }
    int i=0,id;
    while(fscanf(file,"#%d# %[^,],%[^,],%*s\n",&id)!=EOF)
    {
    addressbook->contactCount++;
    }
    for(i=0;i<=addressbook->contactCount;i++)
    {
    fscanf(file,"#%d# %[^,],%[^,],%[^\n]",&id,addressbook->contacts[i].name,addressbook->contacts[i].phone, addressbook->contacts[i].email);
    }
    fclose(file);
    } 
void listContacts(AddressBook *addressbook) 
{
       printf("---------------------------------------------------------------------------------\n");
       printf("Name\t\t\tphone number\t\t\tEmail id\n");
       printf("---------------------------------------------------------------------------------\n");
       for(int i=0;i<addressbook->contactCount;i++)
       {
	   printf("%s\t\t%s\t\t%s\n",addressbook->contacts[i].name,addressbook->contacts[i].phone,addressbook->contacts[i].email);
       }
}
void createContact(AddressBook *addressbook) 
 {
   FILE*file=fopen("addressbook.csv","a");
   //int numcontacts;
   //printf("How many contacts you want to create");
   //scanf("%d",numcontacts);
   addressbook->contacts = realloc(addressbook->contacts, 
        (addressbook->contactCount + 1) * sizeof(Contact));
   if(addressbook->contacts==NULL)
   {
    printf("Memory allocation failed!");
    return;
   }
   
    printf("Enter the name :");
    scanf("%s",addressbook->contacts[addressbook->contactCount].name);

    printf("Enter the phone number :");
    scanf("%s",addressbook->contacts[addressbook->contactCount].phone);

    printf("Enter the Email Id :");
    scanf("%s",addressbook->contacts[addressbook->contactCount].email);

    addressbook->contactCount++;
    saveContact(addressbook);
    fclose(file);
   }

void searchContact(AddressBook *addressbook) 
{
    loadContact(addressbook);
    int choice;
    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    char search[100];
    printf("Enter search name: ");
    scanf("%[^\n]", search);
    getchar();

    int found = 0; 

    switch (choice)
    {
        case 1:
            printf("Search Results by Name:\n");
            for (int i = 0; i < addressbook->contactcount; i++) 
	    {
                if (strcmp(search, addressbook->contacts[i].name)==0)
	       	{
                    printf("Name: %s\tPhone: %s\tEmail: %s\n", addressbook->contacts[i].name,
                           addressbook->contacts[i].phone, addressbook->contacts[i].email);
                    found = 1;
                }
            }
            break;
        case 2:
            printf("Search Results by Phone:\n");
            for (int i = 0; i < addressbook->contactcount; i++)
	    {
                if (strcmp(search, addressbook->contacts[i].phone)==0)
	       	{
                    printf("Name: %s\tPhone: %s\tEmail: %s\n", addressbook->contacts[i].name,
                           addressbook->contacts[i].phone, addressbook->contacts[i].email);
                    found = 1; 
                }
            }
            break;
        case 3:
            printf("Search Results by Email:\n");
            for (int i = 0; i < addressbook->contactcount; i++)
	    {
                if (strcmp(search, addressbook->contacts[i].email)==0)
	       	{
                    printf("Name: %s\tPhone: %s\tEmail: %s\n", addressbook->contacts[i].name,
                           addressbook->contacts[i].phone, addressbook->contacts[i].email);
                    found = 1;
                }
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    if (!found)
    {
        printf("No contacts found matching the search criteria.\n");
    }
}

void editContact(AddressBook *addressbook) 
{
    loadContact(addressbook); 
    if (addressbook->contactCount == 0) 
    {
        printf("No contacts available to edit.\n");
        return;
    }
    char contacttoedit[100];
    printf("Enter the name of the contact to edit: ");
    fflush(stdin);
    fgets(contacttoedit, sizeof(contacttoedit), stdin);
    getchar(); 

    int found = 0;
    for (int i = 0; i < addressbook->contactCount; i++) 
    {
        if (strcmp(addressbook->contacts[i].name, contacttoedit) == 0) 
        {
            found = 1;
            int editchoice;
            printf("What do you want to edit?\n");
            printf("1. Name\n");
            printf("2. Phone\n");
            printf("3. Email\n");
            printf("4. All (Name, Phone, and Email)\n");
            printf("Enter your choice: ");
            scanf("%d", &editchoice);
            getchar(); 
            switch (editchoice) 
            {
                case 1:
                    printf("Enter new name: ");
                    scanf("%[^\n]", addressbook->contacts[i].name);
                    getchar();
                    printf("Name updated successfully.\n");
                    break;
                case 2:
                    printf("Enter new phone: ");
                    scanf("%s", addressbook->contacts[i].phone);
                    printf("Phone updated successfully.\n");
                    break;
                case 3:
                    printf("Enter new email: ");
                    scanf("%s", addressbook->contacts[i].email);
                    printf("Email updated successfully.\n");
                    break;
                case 4:
                    printf("Enter new name: ");
                    scanf("%[^\n]", addressbook->contacts[i].name);
                    getchar(); 
                    printf("Enter new phone: ");
                    scanf("%s", addressbook->contacts[i].phone);
                    printf("Enter new email: ");
                    scanf("%s", addressbook->contacts[i].email);
                    printf("Name, Phone, and Email updated successfully.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }
            break;
        }
    }

    if (!found) 
    {
        printf("Contact not found.\n");
    } 
    else 
    {
        saveContact(addressbook); 
    }
}

void deleteContact(AddressBook *addressbook) 
{
    loadContact(addressbook);
    if (addressbook->contactcount == 0) 
    {
        printf("No contacts available to delete.\n");
        return;
    }
    char contacttodelete[100];
    printf("Enter the name of the contact to delete: ");
    scanf("%[^\n]", contacttodelete);
    getchar(); 
    int found = 0;
    for (int i = 0; i < addressbook->contactcount; i++) 
    {
        if (strcmp(addressbook->contacts[i].name, contacttodelete) == 0) 
        {
            found = 1;
            for (int j = i; j < addressbook->contactcount - 1; j++) 
            {
                addressbook->contacts[j] = addressbook->contacts[j + 1];
            }
            addressbook->contactcount--;
            printf("Contact '%s' deleted successfully.\n", contacttodelete);
            break;
        }
    }

    if (!found) 
    {
        printf("Contact '%s' not found.\n", contacttodelete);
    } 
    else 
    {
        saveContact(addressbook);
    }
}
