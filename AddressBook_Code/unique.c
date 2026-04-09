#include "addressbook.h"
#include "unique.h"

// display contact
void display_contact(int i,struct AddressBook *addressBook)
{
    printf("%-50s %11s %-40s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
}

// **Number validate**
int validate_phone(char PHONE[],struct AddressBook *addressBook)
{
    // length  is 10 or not
    if(strlen(PHONE) != 10)  
        return 0;

    // is all char is digit
    for(int i = 0 ; i < strlen(PHONE) ; i++ ) 
    {
        if(!(isdigit(PHONE[i])))
            return 0;
    }
    
    return 1;
}


// ** Email validate **
int validate_email(char EMAIL[],struct AddressBook *addressBook)
{
    char gmail[]={"@gmail.com"};

    // checking does email id ends with @gmail.com
    char * str = strstr(EMAIL,"@");

    if(str == NULL)
        return 1 ;
    if(strcmp(str,gmail))
        return 1;

    int atleast_one_char = 0;
    // Checking Whether the email is in lower case or numbers only till @gmail.com  
    for(int i = 0 ; EMAIL[i] != '@' ; i++)
    {
        if(islower(EMAIL[i]))
            atleast_one_char = 1;
        if(!(islower(EMAIL[i]) || isdigit(EMAIL[i]) || EMAIL[i] == '.'))
            return 1;
        
    }
    
    if(atleast_one_char != 1)
        return 1;

    return 0;
}

// Unique Number
int unique_number(char PHONE[],struct AddressBook *addressBook)
{
    // does already exist or unique
        for(int i = 0 ; i < addressBook->contactCount ; i++)
        {
            if( !(strcmp(PHONE,addressBook->contacts[i].phone)) )
            {
                printf("Phone Number Already Exist!!\n");
                return 1;
            }
        }
        return 0;
}

// unique Email

int unique_email(char EMAIL[],struct AddressBook *addressBook)
{
    // does already exist or unique
        for(int i = 0 ; i < addressBook->contactCount ; i++)
        {
            if( !(strcmp(EMAIL,addressBook->contacts[i].email)) )
            {
                printf("Email Already Exist!!\n");
                return 1;
            }
        }
        return 0;
}

//search by name

void search_by_name(struct AddressBook *addressBook )
{
    char NAME[50];
    int i = 0 , j = 0 ;
    char check = 0; // checkes atleast 1 contact found
    printf("Enter the Name: \n");
    scanf(" %[^\n]",NAME);

    addressBook->ir_size = 0 ;
    // print out the matching contact and saving index into index record
    printf("%-2s  %-20s %-15s %-40s\n", "Sl", "NAME", "Phone number", "Email");
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {   
        if(strcmp(addressBook->contacts[i].name , NAME) == 0)
        {
            printf("%2d) %-20s %-15s %-40s\n",j+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            addressBook->index_record[j] = i;
            check = 1 ;
            j++;
            addressBook->ir_size++;
        }
    }
    if(check == 0)
        printf("\n    !!!!...No Contact Found based on search...!!!!\n");

}

//search_by phone

void search_by_phone(struct AddressBook *addressBook)
{
    char PHONE[15];
    int valid_ret;
    char check = 0; // checkes atleast 1 contact found
    addressBook->ir_size = 0 ;
    int i, j = 0;

    // do-while loop runs until entered phone number is valid
    do{

    printf("Phone No.: ");
    scanf(" %[^\n]",PHONE);

    valid_ret = validate_phone(PHONE,addressBook);

    if(valid_ret == 0)
        printf("Phone Number is Invalid!!\n");

    }while(valid_ret == 0 );

    // print out the matching contact and saving index into index record
    printf("%-2s  %-20s %-15s %-40s\n", "Sl", "NAME", "Phone number", "Email");
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(addressBook->contacts[i].phone , PHONE) == 0)
        {
            printf("%2d) %-20s %-15s %-40s\n",j+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            addressBook->index_record[j] = i;
            check = 1 ;
            j++;
            addressBook->ir_size++;
        }
    }  
    if(check == 0)
        printf("\n    !!!!...No Contact Found based on search...!!!!\n");

}

//search by email
void search_by_email(struct AddressBook *addressBook)
{
    char EMAIL[50];
    int valid_ret;
    char check = 0; // checkes atleast 1 contact found
    addressBook->ir_size = 0 ;
    int i, j = 0;

    // do-while loop runs until entered EMAIL id is valid
    do
    {
        printf("Email ID: ");
        scanf(" %s",EMAIL);
        valid_ret = validate_email(EMAIL,addressBook);
        if(valid_ret == 1)
            printf("Email Id is Invalid\n");

    } while (valid_ret == 1);

    // print out the matching contact and saving index into index record
    printf("%-2s  %-20s %-15s %-40s\n", "Sl", "NAME", "Phone number", "Email");
    for(i = 0 ; i < addressBook->contactCount ; i++)
    {
        if(strcmp(addressBook->contacts[i].email , EMAIL) == 0)
        {
            printf("%2d) %-20s %-15s %-40s\n",j+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            addressBook->index_record[j] = i;
            check = 1 ;
            j++;
            addressBook->ir_size++;
        }
    } 
    if(check == 0)
        printf("\n    !!!!...No Contact Found based on search...!!!!\n");

}

// name_edit
void edit_name(int option,struct AddressBook *addressBook)
{

    char NAME[50];
    char ch;
    do{
        printf("Enter the Name: \n");
        scanf(" %[^\n]",NAME);

        printf("You Entered: \n\n");
        printf("%-20s %-15s %-40s\n", "NAME", "Phone number", "Email");            
        printf("%-20s %-15s %-40s\n",NAME,addressBook->contacts[option].phone,addressBook->contacts[option].email);

                    
        printf("Do You Want to Save the Contact \" ( Y / N ) \": \n");
        scanf(" %c",&ch);
    }while(ch == 'N');
    
    // saving to be done
    strcpy(addressBook->contacts[option].name,NAME);
    
}
 
// edit_phone
void edit_phone(int option,struct AddressBook *addressBook)
{
    char PHONE[15];
    char ch;
    int valid_ret;
    do{
        do{

            printf("Phone No.: ");
            scanf(" %[^\n]",PHONE);

            valid_ret = validate_phone(PHONE,addressBook);

            if(valid_ret == 0)
                printf("Phone Number is Invalid!!\n");

                // Checking Number is Unique or not
            if(unique_number(PHONE,addressBook) == 1)
                valid_ret = 0;

        }while(valid_ret == 0 );

        printf("You Entered: \n\n");
        printf("%-20s %-15s %-40s\n",  "NAME", "Phone number", "Email");
        printf("%-20s %-15s %-40s\n",addressBook->contacts[option].name,PHONE,addressBook->contacts[option].email);

        printf("Do you Want to save the Contact \" ( Y / N ) \": \n ");
        scanf(" %c",&ch);
    }while(ch == 'N');
    
    // Saving to be done

    strcpy(addressBook->contacts[option].phone,PHONE);

}

//edit email
void edit_email(int option,struct AddressBook *addressBook)
{

    char EMAIL[50];
    char ch;
    int valid_ret;   
    do{
        do
        {
            printf("Email ID: \n");
            scanf(" %s",EMAIL);
            valid_ret = validate_email(EMAIL,addressBook);
            if(valid_ret == 1)
                printf("Email Id is Invalid\n");

            if(unique_email(EMAIL,addressBook))
                valid_ret == 1 ;
        } while (valid_ret == 1);   
        
        printf("You Entered: \n\n");
        printf("%-20s %-15s %-40s\n",  "NAME", "Phone number", "Email");
        printf("%-20s %-15s %-40s\n",addressBook->contacts[option].name,addressBook->contacts[option].phone,EMAIL);

        printf("Do you Want to save the Contact \" ( Y / N ) \": \n ");
        scanf(" %c",&ch);
        
    }while(ch == 'N');

    // saving to be done

    strcpy(addressBook->contacts[option].email,EMAIL);

}

// deletion of contact
void deletion_contact(int option,struct AddressBook *addressBook)
{

    // shifts the contacts
    for(int i = option ; i < addressBook->ir_size ; i++)
    {
        strcpy(addressBook->contacts[option].name,addressBook->contacts[option + 1].name);
        strcpy(addressBook->contacts[option].phone,addressBook->contacts[option + 1].phone);
        strcpy(addressBook->contacts[option].email,addressBook->contacts[option + 1].email);
    }

    // delete the contact count
    addressBook->contactCount--;
    printf("Contact Deleted!!");
}

//sorting the list

void sortContacts(struct AddressBook *addressBook) 
{
    int i, j;
    struct Contact temp;

    for (i = 0; i < addressBook->contactCount - 1; i++) {
        for (j = 0; j < addressBook->contactCount - i - 1; j++) {

            if (strcasecmp(addressBook->contacts[j].name,
                           addressBook->contacts[j + 1].name) > 0) {

                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                addressBook->contacts[j + 1] = temp;
            }
        }
    }
}

// Loading Bar

void showProgressBar() {
    int total = 20;  // reduced so it fits nicely

    for (int percent = 0; percent <= 100; percent++) {
        int filled = (percent * total) / 100;

        printf("\rSaving [");  

        for (int i = 0; i < filled; i++) {
            printf("-->");
        }

        for (int i = filled; i < total; i++) {
            printf("   ");
        }

        printf("] %3d%%", percent);

        fflush(stdout);
        
        usleep(25000);
    }

    printf("\nDone!\n");
    
}