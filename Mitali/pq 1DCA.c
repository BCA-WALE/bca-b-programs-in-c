//This file is a sub section of practice Question set 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int len(char *p);
void rev(char *p);
void copy(char *p);
void freq(char *p);

void _1DCharArray()
{char c,ch;
  int l;
  char a[10000];
do
{   //printf("\n\nEnter Length of Array : ");
    //scanf("%d",&n);
    fflush(stdin);
    printf("\nEnter the String : ");
    gets(a);
    
    
	printf("\n\nTo Display a String  press 1\n");
	printf("To Calculate Length of the String   press 2\n");
	printf("To Display Reverse of the String  press 3\n");
	printf("To Copy One String to Another  press 4\n");
	printf("To Calculate Frequency of a Character in the String press 5\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			printf("\nEntered String is : ");
			puts(a);
			break;
		case '2' :
		  	l = len(a);
		  	printf("\nLength of Entered String is :%d\n",l);
			break;
		case '3' :
			rev(a);
			break;
		case '4' :
			copy(a);
			break;
		case '5' :
			freq(a);
			break;
		default:
			printf("Choose between 1,2,3,4,5.\n");
	}
	fflush(stdin);
	printf("\n\nDo you want to Run any 1D Char Array Program Again?\nIf YES press 'Y' or 'y'\nOtherwise press any key.\nYour Choice : ");
	ch=getchar();
}while(ch=='Y'||ch=='y');
}

int len(char *p)
{
int i=1,l=0;
char c = *(p+0);
	while(c!='\0')
	{l++;
	 c = *(p+i);
	 i++;
	}
	return l;

			
}//length of string

void rev(char *p)
{
	int i,l;
	l= len(p);
	printf("\nReverse of Entered String is : ");
	for(i=l-1;i>=0;i--)
	printf("%c",*(p+i));
}//reverse of string

void copy(char *p)
{
	int i,l;
	l= len(p);
	char b[l];
	for(i=0;i<l;i++)
	b[i]=*(p+i);
	printf("\nEntered String is Copied to Another String.\n");
	//puts(b);
		
}//copy

void freq(char *p)
{ char ch;
  int i,l,c=0;
  	l= len(p);
	printf("\nEnter the Character whose Frequency is to be Displayed : ");
	fflush(stdin);
	ch = getchar();
		for(i=0;i<l;i++)
		if(*(p+i)==ch)
		c++;
		if(c==0)
		printf("\nThe Character is not Present in the String.");
		else
		printf("\nThe Character Occured %d times in the String.",c);
}//frequency of a character

