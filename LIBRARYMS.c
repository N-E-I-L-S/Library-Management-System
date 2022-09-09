#include <stdio.h>
#include <time.h>
#include <string.h>

//Structure to Store Information of books
struct Lib
{
    char book_name[20];
    char author_name[20];
    float price;
    char time_[20];         //Time of addition of a book
}l[200];
//Extern Initialisation
int total=0;            //Stores total number of books

void Add()          // Add Books
{
    int count=0;
    printf("How many Books do you want to add?\n");
    scanf("%d", &count);
    for(int i=0;i<count;i++)
    {
    printf("Book-%d\n", i+1);
    Add_one();
    }
}
void Add_one()          //Add 1 Book
{
    int flag=0;
    time_t t = time(NULL);
    printf("Please Enter Book Name below: ");
    scanf("%s", l[total].book_name);
    printf("Please Enter Author Name below: ");
    scanf("%s", l[total].author_name);
    printf("Please Enter Price of the book: ");
    scanf("%f", &l[total].price);
    strcpy(l[total].time_, ctime(&t));
    printf("Book Added on : %s\n",l[total].time_);
    total++;
}

void Pallbooks()            //Print All Books
{
    if(total==0)
    printf("No Books Added Yet! \n");
    else
    {
    printf("ALL BOOKS ARE\n");
    for(int i=0; i<total;i++)
    {
        printf("-----------------------------------\n");
        printf("%d:\n", i+1);
        printf("Book Name : %s\n", l[i].book_name);
        printf("Author Name : %s\n", l[i].author_name);
        printf("Book Price : %f\n", l[i].price);
        printf("It was Added on : %s\n", l[i].time_);
        printf("------------------------------------\n");
    }
    }
}

void Avail(){               //Check Availibility of Books
    char search[20];
    int resultno=-1,choice, flag=0;
    if(total!=0){
    printf("Do you want to search by\n 1. Book Name or\n 2. Author name?\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
    printf("Please Enter Book Name to Search :\n");
    scanf("%s", search);
    for(int i=0; i<=total;i++)
    {
        if(!(strcmp(l[i].book_name, search)))
        {resultno=i;
        break;}
    }
    flag=1;
    break;
    case 2:
    printf("Please Enter Author Name to Search :\n");
    scanf("%s", search);
    for(int i=0; i<=total;i++)
    {
        if(!(strcmp(l[i].author_name, search)))
        {resultno=i;
        break;}
    }
    flag=1;
    break;
    default:
    printf("\nPlease Enter valid choice next time! ");
    }
    if(resultno==-1 && flag==1)
    printf("Sorry Book Not Found! \n");
    else if(resultno!=-1 && flag==1)
    {
    printf("Book is Available! \nInformation of book :\n\n");
    printf("Book Name :%s\n", l[resultno].book_name);
    printf("Author Name :%s\n", l[resultno].author_name);
    printf("Book Price : %f\n", l[resultno].price);
    printf("It was Added on : %s\n\n", l[resultno].time_);
    }
    }
    else
    printf("No Books are Available!\n");
}

void Issue()            //Issue a Book
{
    float value=0.0;
    int index;
    char check[20];
    if(total!=0){
    printf("Please Check Availibilty of book before  proceeding \n");
    printf("Do You want to go back? (yes/no)\n");
    scanf("%s", check);
    if(!(strcmp(check, "no")))
    {
        Pallbooks();
        printf("Kindly enter the index number mentioned with the book you wish to issue\n");
        scanf("%d", &index);
        index-=1;
        if(index<=total && total>=0){
        value=(float)(l[index].price);
        value=value/10;
        printf("The Amount payable for renting the book for 7 days is : Rs. %f\n", value);
        for(int i=index; i<total;i++)
        l[i]=l[i+1];
        total-=1;
        if(total!=0)
        {printf("The Updated List is: \n");
        Pallbooks();}
        else
        printf("All Books have been issued! ");
        }
        else
        printf("Kindly enter from the indices mentioned\n");
    }
    }
    else
    printf("No Books are Available! \n");
}

int Password_auth(){      //Password Authentication for Admin
    int enpass=0;
    int entry=1, pass;
    char pinretry[5];
    while(entry!=4){
    printf("Kindly enter a valid PIN to continue!\n");
    scanf("%d", &pass);
    if(pass==enpass)
    {
    printf("PIN Matched ...\nYou are logged in as Admin\n");
    return 2;
    }
    else
    {
        printf("Entered PIN is wrong\nDo you want to keep trying? (yes/no)\n");
        scanf("%s", pinretry);
        if(!(strcmp("no", pinretry)))
        {
        printf("Directing You back with no effect on Account Status \n");
        break;
        }
        else
        entry++;
    }
    }
    if(entry==4)
    printf("You have exhausted 3 attempts! ...Logged in as a User!\n ");
    return 1;
    }


void Update()           //Update Information of a book
{
    int index;
    Pallbooks();
    if(total!=0){
    printf("Enter index number to edit informaton of that book\n");
    scanf("%d", &index);
    index-=1;
    printf("Change information below:\n");
    printf("Enter Book Name: ");
    scanf("%s", l[index].book_name);
    printf("Please Enter Author Name : ");
    scanf("%s", l[index].author_name);
    printf("Please Enter Price of the book: ");
    scanf("%d", &l[index].price);
    printf("Edited List is:\n");
    Pallbooks();
    }
}

int main() 
{
    //Initialisation
    int i, control=0, lgn=1;
    char an[20], bn[20];
    l[0].price=100;
    
    //Initial Login
    printf("Login as: \n1.User \n2.Admin\n");
    scanf("%d", &lgn);
    if(lgn==2)
    lgn=Password_auth();
    
    //Loop
    while(control!=7)
    {
        printf("\n\n********######WELCOME TO E-LIBRARY#####********\n\n");
        printf("Account Status : ");
        if(lgn==2)
        printf("Admin\n\n");
        else
        printf("User\n\n");
        printf("1. Add book(s) (admin only)\n");
        printf("2. Check availibilty of a book\n");
        printf("3. Issue a book\n");
        printf("4. See all books\n");
        printf("5. Edit information of a book(admin only)\n");
        printf("6. Switch between Admin and User\n");
        printf("7. EXIT\n");
        printf("Please Enter your choice from above\n");
        scanf("%d", &control);
        //Control
        switch(control)
        {
            case 1:
            if(lgn==2)
            Add();
            else
            printf("Please Login as Admin to proceed! \n");
            break;
            case 2:
            Avail();
            break;
            case 3:
            Issue();
            break;
            case 4:
            Pallbooks();
            break;
            case 5:
            if(lgn==2)
            Update();
            else
            printf("Please Login as Admin! to proceed \n");
            break;
            case 6:
            if(lgn==1)
            lgn=Password_auth();
            else
            {
            printf("You are Logged in as User");   
            lgn=1;}
            break;
            case 7:
            break;
            default:
            printf("Please Enter a valid choice\n");
        }
    }
    //Outro
    printf("THANK YOU FOR VISITING!");
    return 0;
}