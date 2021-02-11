/*Define a structure called cricketer which contains the player name, team name and
batting average. Define a function to read and display the details for n cricketers.
 Define a function to search for the given cricketer. If the name is matching, then
display the details of the cricketer. If the given name is not matching, then display an
appropriate message.*/


//PQ2 question2
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct cricketer
{

float bavg;
char pname[100];
char tname[100];	
};typedef struct cricketer cri;

void input3(cri s[],int n);
void display3(cri s[],int n);
void search2(cri s[],int n);

void cricket()
{   int n;char c;

	printf("\nEnter No. of Cricketers : ");
	scanf("%d",&n);
	cri arr[n];
	input3(arr,n);
do
{	
	printf("\n\nTo Display the Data Press 1\n");
	printf("To Search a Name Press 2\nTo Exit Player Database Press 3.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nPLAYER DATABASE : \n\n");
			display3(arr,n);
			break;
		case '2' :
			search2(arr,n);
			break;
		case '3' :
			break;
		default:
			printf("\nChoose between 1,2,3.\n");
	}//switch
}while(c!='3');
	
}

void input3(cri s[],int n)
{ int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Details of Player %d :\n",(i+1));
		
		fflush(stdin);
		printf("Name : ");
		gets(s[i].pname);
		
		fflush(stdin);
		printf("Team : ");
		gets(s[i].tname);
		
		printf("Batting Average : ");
		scanf("%f",&s[i].bavg);
		
	}
}

void display3(cri s[],int n)
{
int i;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Player %d :\n",(i+1));
		
		printf("Player Name : %s\n",s[i].pname);
		printf("Team Name : %s\n",s[i].tname);
		printf("Price : %.2f\n",s[i].bavg);
		
	}	
}

void search2(cri s[],int n)
{   char pn[100],tn[100];
    int i,f=0;
	float ba;
	printf("\nEnter Name to Searched : ");
	fflush(stdin);
	gets(pn);
	for(i=0;i<n;i++)
	 if(stricmp(s[i].pname,pn)==0)
	 {
	 	f=1;
	 	ba =s[i].bavg;
	 	strcpy(tn,s[i].tname);
	 	break;
	 }
	if(f==0)
	printf("\nNo Match Found");
	else
	printf("\n%s is from Team %s with a Batting Average of %.2f\n.",pn,tn,ba);
	
}

