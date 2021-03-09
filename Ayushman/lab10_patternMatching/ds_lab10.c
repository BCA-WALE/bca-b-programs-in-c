// program for pattern matching


// header files
#include<stdio.h>
#include<string.h>
#include <stdlib.h>


//typedef
typedef struct string string_struct;


// structure body
struct string
{
	char var[20];
	
};


// function declarations
void pattern(struct string[]);
void substr(struct string[]);
void menu(void);
void pause(char *);


int main()
{
	string_struct str[2];
	int option;
	char var;

	do
	{
		system("clear");

		menu();

		scanf("%d", &option);
		switch(option)
		{
			case 1:
				printf("\n\n\tEnter a string: ");
				scanf("%s", str[1].var);
				break;

			case 2:
				printf("\n\tEnter second string that you want to match: ");
				scanf("%s", str[2].var);
				break;

			case 3:
				{
					printf("\n\tEntered strings are: \n");
					printf("\n\t1. %s\n",str[1].var);
					printf("\n\t2. %s\n",str[2].var);
					pause(&var);
				}
				break;

			case 4:
				{	
					pattern(str);
					pause(&var);
				}
				break;

			case 5:
				substr(str);
				break;

			case 6: 
				exit(0);

			default:
				printf("\n\tEnter correct option!\n");
		}

	pause(&var);

	}while(option != 6);

	return 0;
}


// function definitions
void menu(void)
{
	printf("\n\n\t\tLAB 10 PATTERN MATCHING PROGRAM\n\n");
    printf("\n\t\tMENU\n");

	printf("\n\t1. Enter the main string.\n");
	printf("\n\t2. Enter the substring.\n");
	printf("\n\t3. To see the strings entered.\n");
	printf("\n\t4. To see the pattern matching.\n");
	printf("\n\t5. To extract a substring.\n");
	printf("\n\t6. Exit.\n");

	printf("\n\tOption: ");
}


void pattern(string_struct str[]) 
{ 
	int i,j, flag;
	char var = 't';

    i = j = flag = 0;

	int len1 = strlen(str[1].var); 
	int len2 = strlen(str[2].var); 


	for (i = 0; i <= (len1 - len2); i++) 
	{      
	    for (j = 0; j < len2; j++) 
		{
			if (str[1].var[i + j] != str[2].var[j])         
            {
				break;
			}
		}
	  
	    if(j == len2) 
	    {
	    	printf("\n\tPattern found at index %d. \n", i);
            flag++;
        }
    }
    
    if(flag==0)
    {
        printf("\n\tNo matches found");
    }
    
    else
    {
        printf("\n\n\tTotal %d matches found",flag);
    }         
    
	pause(&var);     
}


void substr(struct string str[])
{
	int pos, index, length;
	char substr[20], var = 't';

	index = length = pos = 0;

	printf("\n\tEnter the position of the substring: ");
	scanf("%d", &pos);

	printf("\n\tEnter the length of substring: ");
    scanf("%d", &length);

    while(index < length) 
    {
      	substr[index] = str[1].var[pos + index - 1];
      	index++;
	}

    substr[index] = '\0';
    printf("\n\tThe substring is \"%s\".\n", substr);

    pause(&var);
}


void pause(char *var)
{
	do
	{
		*var = getchar();
	}while(*var != '\n');
}
 

