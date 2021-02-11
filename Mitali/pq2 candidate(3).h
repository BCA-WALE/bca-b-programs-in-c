/*Define a structure called candidate which contains candidate name, candidate political
party, constituency number and number of votes received by the candidate. Write a
program to read and display the details for n candidates. Define a function to display
the details of the candidate for the given constituency number.*/


//PQ2 question3
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct canditates
{

int cnum,vnum;
char pparty[100];
char cname[100];	
};typedef struct canditates can;

void input4(can s[],int n);
void display4(can s[],int n);
void search3(can s[],int n);

void candidate()
{   int n;char c;

	printf("\nEnter No. of Candidates : ");
	scanf("%d",&n);
	can arr[n];
	input4(arr,n);
do
{	
	printf("\n\nTo Display the Data Press 1\n");
	printf("To Display According to Constituency Number Press 2\nTo Exit Election Database Press 3.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nPLAYER DATABASE : \n\n");
			display4(arr,n);
			break;
		case '2' :
			search3(arr,n);
			break;
		case '3' :
			break;
		default:
			printf("\nChoose between 1,2,3.\n");
	}//switch
}while(c!='3');
	
}

void input4(can s[],int n)
{ int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Details of Player %d :\n",(i+1));
		
		fflush(stdin);
		printf("Candidate Name : ");
		gets(s[i].cname);
		
		fflush(stdin);
		printf("Political Party  : ");
		gets(s[i].pparty);
		
		printf("Constituency Number : ");
		scanf("%d",&s[i].cnum);
		
		printf("Number of Votes : ");
		scanf("%d",&s[i].vnum);
		
	}
}

void display4(can s[],int n)
{
int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Player %d :\n",(i+1));
		
		printf("Candidate Name : %s\n",s[i].cname);
		printf("Political Party : %s\n",s[i].pparty);
		printf("Constituency Number : %d\n",s[i].cnum);
		printf("Number of Votes : %d\n",s[i].vnum);
		
	}	
}

void search3(can s[],int n)
{   char pa[100],ca[100];
    int i,f=0,v,c;
	printf("\nEnter Constituency Number to Searched : ");
scanf("%d",&c);
	for(i=0;i<n;i++)
	 if(s[i].cnum==c)
	 {
	 	f=1;
	    v =s[i].vnum;
	 	strcpy(pa,s[i].pparty);
	 	strcpy(ca,s[i].cname);
	 	break;
	 }
	if(f==0)
	printf("\nNo Match Found");
	else
	{	printf("\nCandidate Name : %s\n",ca);
		printf("Political Party : %s\n",pa);
		printf("Number of Votes : %d\n",v);
	}

	
}
