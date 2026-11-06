1. Develop a Program in C for the following:
a. Define a record (structure) titled Book with the following fields: Book_ID, Title, Author, Price, Availability Status      (Available/Issued).
b. Dynamically allocate memory to store the details of N books, where N is entered by the user.
c. Implement the following functions:
     i. create() – To allocate memory and read the details of N books and store them in the allocated memory.
    ii. display() – To display the details of all books available in the library.
    iii. search() – To search for a book using Book ID and display the book details if found.
    iv. issueBook() – To issue a book by updating its availability status and display an appropriate message.
    v. returnBook() – To return an issued book by updating its availability status and display an appropriate message.
d. Build a menu-driven interface with the following options:
i. Add Book Records.
ii. Display all Book Records.
iii. Search Book by Book ID.
iv. Issue a Book.
v. Return a Book.
vi. Exit.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char title[30], author[30], status[10];
    float price;
};

struct Book *b;
int n = 0;

void create()
{
    int i;
    printf("Enter number of books: ");
    scanf("%d", &n);

    b = (struct Book *)malloc(n * sizeof(struct Book));

    for(i = 0; i < n; i++)
    {
        printf("\nBook %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &b[i].id);
        printf("Title: ");
        scanf(" %[^\n]", b[i].title);
        printf("Author: ");
        scanf(" %[^\n]", b[i].author);
        printf("Price: ");
        scanf("%f", &b[i].price);

        strcpy(b[i].status, "Available");
    }
}

void display()
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(strcmp(b[i].status, "Available") == 0)
        {
            printf("\nID: %d", b[i].id);
            printf("\nTitle: %s", b[i].title);
            printf("\nAuthor: %s", b[i].author);
            printf("\nPrice: %.2f", b[i].price);
            printf("\nStatus: %s\n", b[i].status);
        }
    }
}

void search()
{
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(b[i].id == id)
        {
            printf("\nID: %d\nTitle: %s\nAuthor: %s\nPrice: %.2f\nStatus: %s\n",
                   b[i].id, b[i].title, b[i].author,
                   b[i].price, b[i].status);
            return;
        }
    }

    printf("Book not found!\n");
}

void issueBook()
{
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(b[i].id == id)
        {
            if(strcmp(b[i].status, "Available") == 0)
            {
                strcpy(b[i].status, "Issued");
                printf("Book issued successfully!\n");
            }
            else
                printf("Book is already issued!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

void returnBook()
{
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
    {
        if(b[i].id == id)
        {
            if(strcmp(b[i].status, "Issued") == 0)
            {
                strcpy(b[i].status, "Available");
                printf("Book returned successfully!\n");
            }
            else
                printf("Book is already available!\n");
            return;
        }
    }

    printf("Book not found!\n");
}

int main()
{
    int ch;

    do
    {
        printf("\n\n--- LIBRARY MENU ---");
        printf("\n1. Add Book Records");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: free(b); printf("Exit\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(ch != 6);

    return 0;
}


