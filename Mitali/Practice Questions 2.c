//this file contains only main method and calls its functions from header files "pq2 *"
//Practice Question Set 2
#include<stdio.h>
#include<stdlib.h>
#include"pq2 student(1).h"
#include"pq2 book(4).h"
#include"pq2 cricket(2).h"
#include"pq2 candidate(3).h"
#include"pq2 Railway(5).h"


int main()
{  char c;
printf("PRACTICE QUESTIONS SET 2 ");
do
{
	printf("\n\nFor Questions related to Students Press 1\n");
	printf("For Questions related to Cricketer Press 2\n");
	printf("For Questions related to Candidate Press 3\n");
	printf("For Questions related to Books Press 4\n");
	printf("For Questions related to Railway Resevation Press 5\nTo Exit Press 6.\nYour Choice : ");
	fflush(stdin);
	c = getchar();
	if(!isdigit(c))
	printf("Enter a Digit.\n");
	else
	switch(c)
	{
		case '1' :
			student();
			break;
		case '2' :
			cricket();
			break;
		case '3' :
			candidate();
			break;
		case '4' :
			book();
			break;
		case '5' :
			railway();
			break;
		case '6' :
			break;
		default:
			printf("Choose between 1,2,3,4,5,6.\n");
	}//switch
	
}while(c!='6');
printf("\n\nWeek 2 Task Completed.");
	return 0;
}

