// a menu driven program to compare, concatenate, copy strings and find the length of a string

// for Windows OS, change system("clear") to system("cls"), it will hopefully work.

// header files
#include <stdio.h>
#include <stdlib.h>


// function declarations
void menu(void);
void copy(char *, char *);
void concat(char *, char *, char *);
void screen_pause(char *);
int strlength(char *);
int compare(char *, char *);


// main function
int main()
{
    int option, length, flag;
    char string1[20], string2[20], catstr[40], *s1, *s2, var;

    s1 = string1;
    s2 = string2;
    
    option = flag = 0;

    do
    {
		system("clear");
        menu();
        
        printf("\n\tEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: 
            {
				printf("\n\tEnter string 1: ");
				//fflush(stdin);
				
				scanf(" %[^\n]s", s1);   // EPIC PROBLEMS FACED.
				//fgets(s1, sizeof(string1), stdin);
				
				printf("\n\tEnter string 2: ");
				scanf(" %[^\n]s", s2);   // THE SOLUTION IS ADD A WHITESPACE.
				
				//fgets(s2, sizeof(string2), stdin);  // anomaly behavior by fgets?  
				
				copy(s1, s2);

                printf("\n\tString copied successfully, string2 is: %s\n\n", s2);
                screen_pause(&var);
			}
                break;
                
            case 2:
				{
					printf("\n\tEnter string 1: ");
					scanf(" %[^\n]s", s1); 
					 
					printf("\n\tEnter string 2: ");
					scanf(" %[^\n]s", s2);
					
					concat(s1, s2, catstr);
					
					printf("\n\tStrings concatenated successfully, concat is: %s\n\n", catstr);
					screen_pause(&var);
				}
				break;
				
			case 3:
				{
					printf("\n\tString1: %s", s1);
					printf("\n\tString1: %s", s2);
					printf("\n\tconcatenated string: %s", catstr);
					screen_pause(&var);
				}
				break;
				
			case 4:
				{	
					printf("\n\tEnter string 1: ");
					scanf(" %[^\n]s", s1); 
					
					length = strlength(s1);
					printf("\n\tLength of the string1 is: %d bytes", length);
					
					screen_pause(&var);
				}
				break;
            
            case 5:
				{
					printf("\n\tEnter string 1: ");
					scanf(" %[^\n]s", s1); 
					 
					printf("\n\tEnter string 2: ");
					scanf(" %[^\n]s", s2);
					
					flag = compare(s1, s2);
					
					if(flag == 0)
					{
						printf("\n\tStrings are same with value: %s", s1);
					}
					
					else
					{
						printf("\n\tStrings are not the same as string1 is: %s, and string2 is: %s", s1, s2);
					}
					screen_pause(&var);
				}
				break;
            
            case 6:
                printf("\n\tExiting...\n\n");
                exit(0);
                break;

            default: printf("\n\tKindly input the correct given options. Thank you.");        
            
        }
        screen_pause(&var);

    }while(option != 6);
     
    return 0;
}


// menu function
void menu(void)
{
    printf("\n\n\t\tLAB 9 STRINGS PROGRAM\n\n");
    printf("\n\t\tMENU");

    printf("\n\t1. Copy strings.");
	printf("\n\t2. Concatenate strings.");
	printf("\n\t3. Display the strings.");
	printf("\n\t4. Find length of the string.");
	printf("\n\t5. Compare the strings.");
    printf("\n\t6. Exit");
}


// DOESNT WORK when char pointers used - gives wrong output - garbage value
void copy(char str1[], char str2[]) 
{
	int i;
	
    for(i = 0; str1[i] != '\0'; i++)
    {
		str2[i] = str1[i];
	}
	str2[i] = '\0';
	
}


void concat(char str1[], char str2[], char concat[])
{
	int i, j;
	
	for(i = 0; str1[i] != '\0'; i++)
	{
		concat[i] = str1[i];
	}
	
	for(j = 0; str2[j] != '\0'; j++, i++)
	{
		concat[i] = str2[j];
	}
	concat[i] = '\0';
}


// strlen
int strlength(char *str)
{
	int length;
	
	for(length = 0; *str != '\0'; str++, length++);
	
	return length++;
	
}


// compare strings
int compare(char *str1, char *str2)
{
	int flag;
	flag = 0;
	
	while(*str1 != '\0')
	{
		if(*str1 != *str2)
		{
			flag = 1;
			break;
		}
		str1++;
		str2++;
		
	}
	
	return flag;
	
}


// pauses the screen 
void screen_pause(char *var)
{	
	do
	{
		*var = getchar();
	}while(*var != '\n');
}




