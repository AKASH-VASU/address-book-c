#ifndef UNIQUE_H
#define UNIQUE_H

#include "addressbook.h"


int validate_phone(char *,struct AddressBook *addressBook);
int validate_email(char *,struct AddressBook *addressBook);

void display_contact(int,struct AddressBook *addressBook);
int unique_number(char *,struct AddressBook *addressBook);
int unique_email(char *,struct AddressBook *addressBook);

void search_by_name(struct AddressBook *addressBook);
void search_by_phone(struct AddressBook *addressBook);
void search_by_email(struct AddressBook *addressBook);

void edit_name(int,struct AddressBook *addressBook);
void edit_phone(int,struct AddressBook *addressBook);
void edit_email(int,struct AddressBook *addressBook);

void deletion_contact(int,struct AddressBook *addressBook);
void sortContacts(struct AddressBook *addressBook);
void showProgressBar();

#endif