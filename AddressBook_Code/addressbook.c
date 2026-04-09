#include "addressbook.h"
#include "unique.h"

void add_contact(struct AddressBook *addressBook)
{

    char NAME[50];
    char PHONE[15];
    char EMAIL[50];
    int i = addressBook->contactCount;
    int valid_ret;
    char ch;

    do{
        // ********* NAME *************
        printf("Name: ");
        scanf(" %[^\n]",NAME);

        // ********* PHONE ************
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
        
        // ************ Email ***************

        do
        {
            printf("Email ID: ");
            scanf("%s",EMAIL);
            valid_ret = validate_email(EMAIL,addressBook);
            if(valid_ret == 1)
                printf("Email Id is Invalid\n");

            if(unique_email(EMAIL,addressBook))
                valid_ret == 1 ;
        } while (valid_ret == 1);

        printf("Do you want to Save the Contact ( Y / N ): \n");
        scanf(" %c",&ch);
    }while(ch == 'N');

    // saving to the structure

    strcpy(addressBook->contacts[addressBook->contactCount].name,NAME);
    strcpy(addressBook->contacts[addressBook->contactCount].phone,PHONE);
    strcpy(addressBook->contacts[addressBook->contactCount].email,EMAIL);
    addressBook->contactCount++;
  
}
void search_contact(struct AddressBook *addressBook)
{
    int option;

    printf("Choose Search Criteria:\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email Id\n");

    scanf("%d",&option);

    switch (option)
    {
    case 1:
        search_by_name(addressBook);
        break;
    case 2:
        search_by_phone(addressBook);
        break;
    case 3:
        search_by_email(addressBook);
        break;
    default:
        printf("Invalid Input !!!\n");
        break;
    }


}
void edit_contact(struct AddressBook *addressBook)
{

    int option;
    int contact_edit_op;
    
    printf("Choose Search Criteria to Edit Contact:\n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email Id\n");

    scanf("%d",&option);

    switch (option)
    {
    case 1:
        search_by_name(addressBook);
        option = 1;
        if(addressBook->ir_size > 0)
        {
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&option);
        }

        option = addressBook->index_record[option-1]; // acessing the index value

        printf("Enter Option to edit: \n");
        printf("1.Name \n2.Phone Number \n3.Email\n");
        scanf("%d",&contact_edit_op);

        switch(contact_edit_op)
        {
            //Editing Name
            case 1: 
                edit_name(option,addressBook);
                break;
            // Editing Phone Number
            case 2:
                edit_phone(option,addressBook);
                break;
                // Email update
            case 3: 
                edit_email(option,addressBook);
                break;
        }

        break;
    case 2:
        search_by_phone(addressBook);
        option = 1;
        if(addressBook->ir_size > 0)
        {
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&option);
        }

        option = addressBook->index_record[option-1]; // acessing the index value

        printf("Enter Option to edit: \n");
        printf("1.Name \n2.Phone Number \n3.Email\n");
        scanf("%d",&contact_edit_op);

        switch(contact_edit_op)
        {
            //Editing Name
            case 1: 
                edit_name(option,addressBook);
                break;
            // Editing Phone Number
            case 2:
                edit_phone(option,addressBook);
                break;
                // Email update
            case 3: 
                edit_email(option,addressBook);
                break;
        }
        break;
    case 3:
        search_by_email(addressBook);
        option = 1;
        if(addressBook->ir_size > 0)
        {
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&option);
        }

        option = addressBook->index_record[option-1]; // acessing the index value

        printf("Enter Option to edit: \n");
        printf("1.Name \n2.Phone Number \n3.Email\n");
        scanf("%d",&contact_edit_op);

        switch(contact_edit_op)
        {
            //Editing Name
            case 1: 
                edit_name(option,addressBook);
                break;
            // Editing Phone Number
            case 2:
                edit_phone(option,addressBook);
                break;
                // Email update
            case 3: 
                edit_email(option,addressBook);
                break;
            default:
            printf("Invalid Input !!!\n");
            break;
        }
        break;
    default:
        printf("Invalid Input !!!\n");
        break;
    }
}
void delete_contact(struct AddressBook *addressBook)
{
    int option;

    printf("Choose Search Criteria to Delete Contact: \n");
    printf("1.Name\n");
    printf("2.Phone Number\n");
    printf("3.Email\n");

    scanf("%d",&option);

    switch (option)
    {
        // using name
    case 1:
        search_by_name(addressBook);

        option = 1;
        
        
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&option);


        option = addressBook->index_record[option-1]; // acessing the index value

        deletion_contact(option,addressBook);
        break;
        //using phone
    case 2:
        search_by_phone(addressBook);

        option = 1;
       
        
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&option);
        

        option = addressBook->index_record[option-1]; // acessing the index value

        deletion_contact(option,addressBook);

        break;
        // search by email
    case 3:
        search_by_email(addressBook);

        option = 1;
        
        
            printf("Choose the Contact to Edit:\n");
            scanf("%d",&option);
        

        option = addressBook->index_record[option-1]; // acessing the index value

        deletion_contact(option,addressBook);
        
    default:
        break;
    }

}
void list_contacts(struct AddressBook *addressBook)
{

    sortContacts(addressBook);
    printf("%-2s  %-20s %-15s %-40s\n", "Sl", "NAME", "Phone number", "Email");
    for(int i = 0 ; i < addressBook->contactCount ; i++)
    {
        printf("%2d) %-20s %-15s %-40s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}

void load_contact(struct AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("database.csv","r");
	if(fp == NULL)
	{
		perror("Database not Found unable to Load");
		return ;
	}
	while((fscanf(fp,"%[^,],%[^,],%[^\n]",addressBook->contacts[addressBook->contactCount].name,
								addressBook->contacts[addressBook->contactCount].phone,
								addressBook->contacts[addressBook->contactCount].email)) == 3)
	{
		
		addressBook->contactCount++;
        fgetc(fp);
	}
	fclose(fp);
}

void save_contact(struct AddressBook *addressBook)
{
    FILE *fp;
    fp = fopen("database.csv","w");

		if(fp == NULL)
		{
			perror("Error");
				return ;
		}
		for(int i = 0 ; i < addressBook->contactCount ; i++)
		{
			fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
		}

		fclose(fp);
}


