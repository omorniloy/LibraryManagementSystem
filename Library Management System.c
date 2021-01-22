#include<stdio.h>
#include<string.h>
#define n 50
int number = 1000;
FILE *fp, *fp2;

void menu();
void admin();
void admin_reg();
void admin_login();
void user_create();
void user_delete();
void add_book();
void search_book();
void issue_book();


struct Employee
{
    char emp_id[n], pass[n];
};
struct Employee e;

struct Book
{
    int book_id, quantity;
    char book_name[n],edition[n],author[n];
};
struct Book b;

struct User
{
    char student_id[n], student_name[n], address[n];
};
struct User s;

int main()
{
    admin();
    return 0;
}

void menu()
{
    int choice;

    system("cls");
    printf("-----------Welcome to Library Management System-----------\n");
    printf("----------------------------------------------------------\n");
    printf("1. User Create Account\n");
    printf("2. User Delete Account\n");
    printf("3. Add Book\n");
    printf("4. Search Book\n");
    printf("5. Issue Book\n");
    printf("6. Logout\n");
    printf("\nEnter your choise: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            user_create();
            break;
        case 2:
            user_delete();
            break;
        case 3:
            add_book();
            break;
        case 4:
            search_book();
            break;
        case 5:
            issue_book();
            break;
        case 6:
            admin();
            break;
        default:
            printf("Please enter a valid choice.\n");
            break;

    }
    getch();
}

void admin()
{
    int option;
    system("cls");
    printf("-----------Welcome to Library Management System-----------\n");
    printf("----------------------------------------------------------\n");
    printf("1. Admin Register\n");
    printf("2. Admin Login\n");
    printf("\nEnter your choise: ");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            admin_reg();
            break;
        case 2:
            admin_login();
            break;
        default:
            printf("Please enter a valid choice.\n");
            break;
    }
    getch();
}

void admin_reg()
{
    if ((fp2 = fopen("emp.txt","a+")) == NULL){
       printf("Error! opening file");
    }
    else
    {
        printf("\n\n------------Registration------------\n\n");
        printf("\nEnter User ID: ");
        fflush(stdin);
        gets(e.emp_id);
        fprintf(fp2, "%s ", e.emp_id);

        fflush(stdin);
        printf("\nEnter Password: ");
        fflush(stdin);
        gets(e.pass);
        fprintf(fp2, "%s ", e.pass);
    }
    fclose(fp2);

    printf("\n\n-----------Employee added successfully----------\n");
    printf("\n\n\nPress any key...\n\n");
    getch();
    admin();
}

void admin_login()
{
    char u[n], p[n];
    printf("\n\n-----------------Login-----------------\n\n");
    printf("User ID: ");
    fflush(stdin);
    gets(u);
    printf("Password: ");
    fflush(stdin);
    gets(p);

//    if ((fp2 = fopen("emp.txt","r")) == NULL)
//    {
//       printf("Error! opening file");
//    }
//    else
//    {
//        while(fscanf(fp,"%s %s\n\n",e.user_id, e.pass) != EOF)
//        {
        if(strcmp(u, e.emp_id)==0 && strcmp(p, e.pass) == 0)
        {
            printf("\nSuccessfully login\n");
            getch();
            printf("Press any key to enter the main menu");
            menu();
        }
        else
        {
            printf("\nWrong user id and password.\n");
            admin_login();
        }

}

void user_create()
{
    if ((fp = fopen("my.txt","a+")) == NULL){
       printf("Error! opening file");
    }
    else
    {
        fflush(stdin);
        printf("\nEnter user name: ");
        gets(s.student_name);
        fprintf(fp, "%s ", s.student_name);

        fflush(stdin);
        printf("\nEnter ID number: ");
        gets(s.student_id);
        fprintf(fp, "%s ", s.student_id);

        fflush(stdin);
        printf("\nEnter address: ");
        gets(s.address);
        fprintf(fp, "%s ", s.address);
    }
    fclose(fp);

    printf("\n\n-----------User added successfully----------\n");
    printf("\nUser Name: ");
    puts(s.student_name);
    printf("\nID number: ");
    puts(s.student_id);
    printf("\nAddress: ");
    puts(s.address);
    getch();

    menu();
}
void user_delete()
{
    printf("user_delete");
}
void add_book()
{
    int temp = 0;
    FILE *fp;
    //struct Book b;
    //b.book_id = number+1;

    if ((fp = fopen("my.txt","a+")) == NULL){
       printf("Error! opening file");
    }
    else
    {
        fflush(stdin);
        printf("\nEnter book ID: ");
        scanf("%d", &b.book_id);
        fprintf(fp, "%d ", b.book_id);

        fflush(stdin);
        printf("\nEnter book name: ");
        gets(b.book_name);
        fprintf(fp, "%s ", b.book_name);

        fflush(stdin);
        printf("\nEnter edition: ");
        gets(b.edition);
        fprintf(fp, "%s ", b.edition);

        fflush(stdin);
        printf("\nEnter author name: ");
        gets(b.author);
        fprintf(fp, "%s ", b.author);

        printf("\nEnter no of books: ");
        scanf("%d", &b.quantity);
        fprintf(fp, "%d \n", b.quantity);

    }
    fclose(fp);

    printf("\n\n-----------Book added successfully----------\n");
    printf("\nBook ID: %d \n",b.book_id);
    printf("\nBook Name: ");
    puts(b.book_name);
    printf("\nEdition: ");
    puts(b.edition);
    printf("\nAuthor: ");
    puts(b.author);
    printf("\nNo of available copy: %d\n\n", b.quantity);
    getch();
    //number++;

    menu();
}
void search_book()
{
    FILE *fp;
    int found = 0;
    char srch[50];
    printf("\nSearch Books\nEnter a book name for search: ");
    fflush(stdin);
    gets(srch);
    if ((fp = fopen("my.txt","r")) == NULL){
       printf("Error! opening file");
    }
    else
    {
        while(fscanf(fp,"%d %s %s %s %d\n\n",&b.book_id, b.book_name, b.edition, b.author, &b.quantity)!=EOF)
        {
            if(strcmp(srch, b.book_name) == 0)
            {
                found = 1;
                printf("\nBook ID: %d \n",b.book_id);
                printf("\nBook Name: ");
                puts(b.book_name);
                printf("\nEdition: ");
                puts(b.edition);
                printf("\nAuthor: ");
                puts(b.author);
                printf("\nNo of available copy: %d\n\n", b.quantity);
                break;
            }
        }

       /* while(fread(&b, sizeof(struct Book), 1, fp))
        {
            if(strcmp(srch, b.book_name) == 0)
            {
                found = 1;
                printf("\nBook ID: %d \n",b.book_id);
                printf("\nBook Name: ");
                puts(b.book_name);
                printf("\nEdition: ");
                puts(b.edition);
                printf("\nAuthor: ");
                puts(b.author);
                printf("\nNo of available copy: %d\n\n", b.quantity);
                break;
            }
        }*/

        if(!found)
        {
            printf("\n\nNo Record");
        }

		fclose(fp);
		printf("\n\n\nPress any key...\n\n");
		getch();
		menu();
    }
}
void issue_book()
{
    printf("issue_book");
}

