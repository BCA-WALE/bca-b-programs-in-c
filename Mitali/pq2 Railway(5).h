/*Using Structures in C , Create a Railway Reservation database storing the passenger
no as integer, passenger name which holds maximum of 25 characters, ticket price as
float for 5 passengers. Write a menu driven program to do the following: a)Read and
display the structure details. b)Search the given  passenger number using functions to
display as &quot;Passenger found&quot; or &quot;Passenger Not found&quot;. c)Modify the ticket price as
Rs.300 if the ticket price falls between the range of Rs.250 to Rs 299 using functions.*/


//PQ2 question5
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
struct railwayresevation
{
	int pn ;
	char pass[25];
	float pr;	
};typedef struct railwayresevation rr;

void input5(rr s[],int n);
void display5(rr s[],int n);
void modify2(rr s[],int n);
void search4(rr s[],int n);


void railway()
{   int n;char c;

	printf("\nEnter No. of Passengers in the Train : ");
	scanf("%d",&n);
	rr arr[n];
	input5(arr,n);
do
{	
	printf("\n\nTo Display the Data Press 1\n");
	printf("To Modify the Ticket Price Press 2\n");
	printf("To Search a Passenger with Passenger no. Press 3\nTo Exit Passenger Database Press 4.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nPASSENGER DATABASE : \n\n");
			display5(arr,n);
			break;
		case '2' :
			modify2(arr,n);
			break;
		case '3' :
			search4(arr,n);
			break;
		case '4' :
			break;
		default:
			printf("\nChoose between 1,2,3,4.\n");
	}//switch
}while(c!='4');
	
}

void input5(rr s[],int n)
{ int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Details of Passenger %d :\n",(i+1));
		printf("Passenger No. : ");
		scanf("%d",&s[i].pn);
		fflush(stdin);
		printf("Passenger Name : ");
		gets(s[i].pass);
		printf("Ticket Price : ");
		scanf("%f",&s[i].pr);
	
	}
}

void display5(rr s[],int n)
{
int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Passenger %d :\n",(i+1));
		printf("Passenger No. : %d\n",s[i].pn);
		printf("Passenger Name : %s\n",s[i].pass);
		printf("Ticket Price : %.2f\n",s[i].pr);
	
	}	
}
void modify2(rr s[],int n)
{  
int i,f=0; 
float m,na,a;

	printf("\nEnter Lower Limit of Price Range to be Targeted : ");
	scanf("%f",&m);
	printf("Enter Upper Limit of Price Range to be Targeted : ");
	scanf("%f",&na);
	
	printf("Enter New Ticket Price : ");
	scanf("%f",&a);

	if(m>=na)
	printf("\nInvalid Price Range.\n");
	else
	{	for(i=0;i<n;i++)
	     
	       if(s[i].pr>=m && s[i].pr<=na)
		   { 
			  s[i].pr =a;
			  f=1;
		   }	
		 	if(f==0)
	printf("\nNo Ticket Price in the Database lies in Entered Range.");
	else
    printf("\nPrice Updated Successfully !!");

		

    }
		
}
void search4(rr s[],int n)
{  
    int i,f=0,c;
	printf("\nEnter Passenger Number to Searched : ");
    scanf("%d",&c);
	for(i=0;i<n;i++)
	 if(s[i].pn==c)
	 {
	 	f=1;
	 	break;
	 }
	if(f==0)
	printf("\nPassenger Not Found");
	else
    printf("\nPassenger Found");
	
}
