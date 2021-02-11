//This file is a sub section of practice Question set 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void display3();
void sort();

char a[10000][10000];
int n;

void _2DCharArray()
{
char c,ch;
int i;
  
do
{   printf("\n\nHow Many Names do you want to Enter : ");
    scanf("%d",&n);
	printf("Enter List of Names : \n");
    for(i=0;i<n;i++)
    { fflush(stdin);
       gets(a[i]);
    }

	printf("\n\nTo Display List of Names  press 1\n");
	printf("To Alphabetically Arrange the Names   press 2\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nList of Names : \n");
			display3();
			break;
		case '2' :
			sort();
			printf("\nList of Names in Alphabetical Order: \n");
			display3();
			break;
		default:
			printf("Choose between 1,2.\n");
	}
	fflush(stdin);
	printf("\n\nDo you want to Run any 2D Char Array Program Again?\nIf YES press 'Y' or 'y'\nOtherwise press any key.\nYour Choice : ");
	ch=getchar();
}while(ch=='Y'||ch=='y');

}

void display3()
{
 int i;
    for(i=0;i<n;i++)
    puts(a[i]);
 	
}//display3

void sort()
{int i,j;
char temp[10000];

for (i=0; i<(n); i++)
    {
    for (j=0; j<(n-1); j++)
        {
        if (strcmp(a[j], a[j+1]) > 0) 
         {
            strcpy(temp, a[j]);
            strcpy(a[j], a[j+1]);
            strcpy(a[j+1], temp);
         }
        }
    }	
}//sort alphabetically
