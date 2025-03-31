#ifndef CONTACT_H
#define CONTACT_H


#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact *contacts;
    int contactCount;
} AddressBook;
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void loadContact(AddressBook *addressBook);
void saveContact(AddressBook *addressBook);

#endif
