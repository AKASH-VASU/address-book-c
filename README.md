# address-book-c
Address Book application using C with file handling

# 📒 Address Book in C

## 📌 Description

This is a **Command-Line Interface (CLI) based Address Book application** written in C.

It uses a menu-driven system to manage contacts like adding, searching, editing, and deleting.


All contact data is stored in a CSV file, so it is saved even after closing the program.

🖥️ Interface

    * Command-Line Interface (CLI)
    
    * Menu-driven program

🚀 Features

    * Add new contacts
    
    * Search contacts by name, phone, or email
    
    * Edit contact details
    
    * Delete contacts
    
    * Display all contacts (sorted by name)
    
    * Save and load contacts from file
    
    * Easy navigation using menu and back option

✅ Validation

    * Phone number must be 10 digits and only digits
    
    * Email must end with '@gmail.com' and contains only lowercase
    
    * Duplicate phone numbers and emails are not allowed


🛠️ Technologies Used

    * C Programming
    
    * File Handling
    
    * Structures, Pointers and Arrays

📂 Project Structure

    AddressBook/
    │── main.c
    │── addressbook.c
    │── addressbook.h
    │── unique.c
    │── unique.h
    │── database.csv

▶️ How to Run

### Compile

    gcc main.c addressbook.c unique.c or gcc*.c

### Run

    ./a.out

## Sample Output

    Address Book Menu:
    
    1. Add/Create contact
    
    2. Search contact
    
    3. Edit contact
    
    4. Delete contact
    
    5. List all contacts
    
    6. Exit

## Future Improvements

    * Add GUI version
    
    * Use linked list instead of array
    
    * Improve search (partial matching)

## 👨‍💻 Author

**Akash Vasu**
