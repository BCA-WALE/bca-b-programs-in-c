//Practice Questions set 1
//this file contains main and call its functions from pq1DA,pq1DCA,pq2DA,pq2DCA
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void _1DArray();
void _2DArray();
void _1DCharArray();
void _2DCharArray();

int main()
{   char c,ch;
printf("PRACTICE QUESTIONS");
do
{
	printf("\n\nFor Questions related to 1D array press 1\n");
	printf("For Questions related to 2D array press 2\n");
	printf("For Questions related to 1D Character array press 3\n");
	printf("For Questions related to 2D Character array press 4\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			_1DArray();
			break;
		case '2' :
			_2DArray();
			break;
		case '3' :
			_1DCharArray();
			break;
		case '4' :
			_2DCharArray();
			break;
		default:
			printf("Choose between 1,2,3,4.\n");
	}
	fflush(stdin);
	printf("\nDo you want to Run any Practice Question Again?\nIf YES press 'Y' or 'y'\nOtherwise press any key.\nYour Choice : ");
	ch=getchar();
}while(ch=='Y'||ch=='y');
printf("\n\n Task Completed.");
	
	return 0;
}



