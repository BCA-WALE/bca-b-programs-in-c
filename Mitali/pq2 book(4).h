/* Create a menu driven program using functions for a book management store having
book id, book name ,author, price of the book to perform the following operations.
Read and display the details for 5 books using functions read() and display(). Using
maximum() function ,display the details of the book having maximum price. Using
count() function , count the books having the same author name and display. */

//PQ2 question 4
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct book
{
int id;
float price;
char bname[100];
char author[100];	
};typedef struct book b;

void input2(b s[],int n);
void display2(b s[],int n);
void maximum(b s[],int n);
void count(b s[],int n);

void book()
{
int n;char c;

	printf("\nEnter No. of Books in Store : ");
	scanf("%d",&n);
	b arr[n];
	input2(arr,n);
do
{	
	printf("\n\nTo Display the Data Press 1\n");
	printf("To Display the Book with Maximum Price Press 2\n");
	printf("To Count and Display the Books having the Same Author Name Press 3\nTo Exit Book Database Press 4.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nBOOK DATABASE : \n\n");
			display2(arr,n);
			break;
		case '2' :
			maximum(arr,n);
			break;
		case '3' :
			count(arr,n);
			break;
		case '4' :
			break;
		default:
			printf("\nChoose between 1,2,3,4.\n");
	}//switch
}while(c!='4');
		
}

void input2(b s[],int n)
{ int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Details of Book %d :\n",(i+1));
		
		printf("Book Id : ");
		scanf("%d",&s[i].id);
		
		fflush(stdin);
		printf("Name : ");
		gets(s[i].bname);
		
		fflush(stdin);
		printf("Author : ");
		gets(s[i].author);
		
		printf("Price : ");
		scanf("%f",&s[i].price);
		
	}
}

void display2(b s[],int n)
{
int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Book %d :\n",(i+1));
		printf("Book Id : %d\n",s[i].id);
		printf("Name : %s\n",s[i].bname);
		printf("Author : %s\n",s[i].author);
		printf("Price : %.2f\n",s[i].price);
	}	
}

void maximum(b s[],int n)
{
int i,p;
float max=0;
for(i=0;i<n;i++)
  if(s[i].price > max)
	{
		max = s[i].price;
		p=i;
	}
	printf("\nDetails of Book with Highest price :\n");
		printf("Book Id : %d\n",s[p].id);
		printf("Name : %s\n",s[p].bname);
		printf("Author : %s\n",s[p].author);
		printf("Price : %.2f\n",s[p].price);

}

void count(b s[],int n)
{
int i, j, c;
    int flag[n] ;
    for(i=0;i<n;i++)
    flag[i]=0;
    
    for(i=0; i<n ; i++)
    {
        c = 1;
        for(j=i+1; j<n; j++)
        {
            if(flag[i]==0 && strcmp(s[i].author, s[j].author) == 0)
            {
                c++; 
				flag[j]=1;
            }
        }
       if(flag[i]==0)
        printf("\nAuthor %s wrote %d books in the Database\n", s[i].author, c);
         flag[i]=1;
    }
}

