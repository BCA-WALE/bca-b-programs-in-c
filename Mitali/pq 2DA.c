//This file is a sub section of practice Question set 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void display2();
void row();
void identity();

int n,a[1000][1000];
void _2DArray()
{
char c,ch;
int i,j;
do
{   printf("\n\nEnter No. of Rows and Columns of Matrix : ");
    scanf("%d",&n);
    a[n][n];
    
    printf("Enter Numbers in Array : \n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    
	printf("\n\nTo Display the Matrix  press 1\n");
	printf("To Calculate Row Total of a given Matrix  press 2\n");
	printf("To Check whether given Matrix is Identity Matrix or not  press 3\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
		    display2();
			break;
		case '2' :
			row();
			break;
		case '3' :
			identity();
			break;
		default:
			printf("Choose between 1,2,3.\n.");
	}
	fflush(stdin);
	printf("\nDo you want to Run any 2D Array Program Again?\nIf YES press 'Y' or 'y'\nOtherwise press any key.\nYour Choice : ");
	ch=getchar();
}while(ch=='Y'||ch=='y');	
}

void display2()
{
	int i,j;
	printf("\nEntered Elements are : \n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	printf("%d ",a[i][j]);
	printf("\n");
    }
}//display

void row()
{
	int i,j,c;
	printf("\nEntered Elements are : \n");
	for(i=0;i<n;i++)
	{c=0;
	for(j=0;j<n;j++)
	c+=a[i][j];
	printf("Sum of %d Row is %d\n",(i+1),c);
    }
}//row sum

void identity()
{
	int i,j,c=1;
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
		if(i==j && a[i][j]!=1)
		{c=0;
		 break;
		}
		else if (i!=j && a[i][j]!=0)
		{
			c=0;
			break;
		}
	}
    }
    if(c==0)
    printf("\nEntered Matrix is not an Identity Matrix\n");
    else 
    printf("\nEntered Matrix is an Identity Matrix\n");
}//identity matrix
