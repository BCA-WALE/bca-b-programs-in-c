/*Create the student database to store the roll number, name class and marks of 3
subjects for n students. Display the student details in a formatted way. Implement
modify and search operation in a structure.
*/

//PQ2 question 1
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
struct student
{
	int roll, cls, marks[3] ;
	char name[100];	
};typedef struct student stu;

void input(stu s[],int n);
void display(stu s[],int n);
void modify(stu s[],int n);
void search(stu s[],int n);
int position(stu s[],int n,int r);

void student()
{   int n;char c;

	printf("\nEnter No. of Students In the Class : ");
	scanf("%d",&n);
	stu arr[n];
	input(arr,n);
do
{	
	printf("\n\nTo Display the Data Press 1\n");
	printf("To Modify the Data Press 2\n");
	printf("To Search a Name Press 3\nTo Exit Student Database Press 4.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nSTUDENT DATABASE : \n\n");
			display(arr,n);
			break;
		case '2' :
			modify(arr,n);
			break;
		case '3' :
			search(arr,n);
			break;
		case '4' :
			break;
		default:
			printf("\nChoose between 1,2,3,4.\n");
	}//switch
}while(c!='4');
	
}

void input(stu s[],int n)
{ int i,j;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Details of Student %d :\n",(i+1));
		printf("Roll no. : ");
		scanf("%d",&s[i].roll);
		fflush(stdin);
		printf("Name : ");
		gets(s[i].name);
		printf("Class : ");
		scanf("%d",&s[i].cls);
		for(j=0;j<3;j++)
		{
		printf("Marks of subject %d : ",(j+1));
		scanf("%d",&s[i].marks[j]);
		}
	}
}

void display(stu s[],int n)
{
int i,j;
	for(i=0;i<n;i++)
	{
		printf("\nDetails of Student %d :\n",(i+1));
		printf("Roll no. : %d\n",s[i].roll);
		printf("Name : %s\n",s[i].name);
		printf("Class : %d\n",s[i].cls);
		for(j=0;j<3;j++)
		printf("Marks of subject %d : %d\n",(j+1),s[i].marks[j]);
		
	}	
}
void modify(stu s[],int n)
{   
int r,k;
char c;
	printf("\nEnter Roll no. whose Details are to be Modified : ");
	scanf("%d",&r);
	k=position(s,n,r);
	if(k==0)
	printf("\nNo Student of this Roll No. Exists");
	else
	{
	printf("\nTo Modify Name Press 1\n");
	printf("To Modify Marks of subject 1 Press 2\n");
	printf("To Modify Marks of subject 2 Press 3\n");
	printf("To Modify Marks of subject 3 Press 4\nTo Exit Student Database Press 5.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	do
	{
	switch(c)
	{
		case '1' :
			fflush(stdin);
			printf("Enter New Name : ");
		    gets(s[k-1].name);
		    printf("\nName Updated Successfully !!");
			break;
		case '2' :
			printf("Enter New marks of Subject 1 : ");
			scanf("%d",&s[k-1].marks[0]);
			printf("\nMarks Updated Successfully !!");
			break;
		case '3' :
			printf("Enter New marks of Subject 2 : ");
			scanf("%d",&s[k-1].marks[1]);
			printf("\nMarks Updated Successfully !!");
			break;
		case '4' :
			printf("Enter New marks of Subject 3 : ");
			scanf("%d",&s[k-1].marks[2]);
			printf("\nMarks Updated Successfully !!");
			break;
		case '5' :
			break;
		default:
			printf("\nChoose between 1,2,3,4,5.\n");
	}//switch
}while(c!='5');
}
		
}
void search(stu s[],int n)
{   char x[50];
    int i,f=0,r,c;
	printf("\nEnter Name to Searched : ");
	fflush(stdin);
	gets(x);
	for(i=0;i<n;i++)
	 if(stricmp(s[i].name,x)==0)
	 {
	 	f=1;
	 	r=s[i].roll;
	 	c=s[i].cls;
	 	break;
	 }
	if(f==0)
	printf("\nNo Match Found");
	else
	printf("\n%s is Roll No. %d of Class %d\n.",x,r,c);
	
}

int position(stu s[],int n,int r)
{
int i,p=0;
for(i=0;i<n;i++)
	 if(r==s[i].roll)
	 {
	 	p=i+1;
	 	break;
	 }
	return p;
}
