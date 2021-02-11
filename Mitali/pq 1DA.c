//This file is a sub section of practice Question set 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void display(int *p,int n);
void odd(int *p,int n);
void even(int *p,int n);
void max(int *p,int n);
void avg(int *p,int n);

void _1DArray()
{
  char c,ch;
  int n,i;
do
{   printf("\n\nEnter Length of Array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter Numbers in Array : \n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    
	printf("\n\nTo Display Element Set  press 1\n");
	printf("To Display Odd Positioned Elements  press 2\n");
	printf("To Display Even Numbers from Element Set  press 3\n");
	printf("To Display Maximum Number from Element Set  press 4\n");
	printf("To Display Sum and Average of Numbers of Element Set  press 5\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			display(a,n);
			break;
		case '2' :
			odd(a,n);
			break;
		case '3' :
			even(a,n);
			break;
		case '4' :
			max(a,n);
			break;
		case '5' :
			avg(a,n);
			break;
		default:
			printf("Choose between 1,2,3,4,5.\n");
	}
	fflush(stdin);
	printf("\n\nDo you want to Run any 1D Array Program Again?\nIf YES press 'Y' or 'y'\nOtherwise press any key.\nYour Choice : ");
	ch=getchar();
}while(ch=='Y'||ch=='y');	
}//1D

void display(int *p,int n)
{
	int i;
	printf("\nEntered Elements are : ");
	for(i=0;i<n;i++)
	printf("%d  ",*(p+i));
}//display

void odd(int *p,int n)
{
	int i;
	printf("\nOdd Positioned Elements are : ");
	for(i=0;i<n;i++)
	if(i%2!=0)
	printf("%d  ",*(p+i));
}//Odd Positioned

void even(int *p,int n)
{
	int i;
	printf("\nEven Elements are : ");
	for(i=0;i<n;i++)
	if(*(p+i)%2==0)
	printf("%d  ",*(p+i));
}//Even Elements

void max(int *p,int n)
{
	int i,m=*(p+0);
	for(i=1;i<n;i++)
	if(*(p+i)>m)
	m=*(p+i);
	printf("\nGreatest Element from the Set : %d",m);
}//Max

void avg(int *p,int n)
{
	int i,s=0;
	float avg;
	for(i=0;i<n;i++)
	s+=*(p+i);
	avg=s/(float)n;
	printf("\nSum of Elements is : %d\nAverage of Elements is : %.2f",s,avg);
}//Sum and Average
