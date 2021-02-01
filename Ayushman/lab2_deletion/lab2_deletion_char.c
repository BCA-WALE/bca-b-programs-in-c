/*

a program to delete char element(s) from one dimensional array
 
note - display option doesn't work
*/


// header files
#include <stdio.h>
#include <stdlib.h>


// function declaration
void menu(void);


// main function
int main()
{
	// declaration of variables
	char array[25], element;
	int i, limit, option, _exit, position;
	char var;


	// initialisation of variables
	i = limit = option = _exit = position = 0;
	element = 0.0;
	var = 'd';


	do
	{
		system("clear");

		menu();

		printf("\n\n\tEnter your option: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1: {
				 printf("\n\tEnter number of elements in array: ");
				 scanf("%d", &limit);

				 printf("\n\tEnter %d elements\n", limit);

				 for (i = 0; i < limit; i++)
				 {
					 printf("\n\tElement %d: ", (i + 1));
					 fflush(stdin);
					 scanf(" %c", &array[i]);
					 
				 }

				}
				break;

			case 2: {

				if(limit == 0)
				{
					printf("\n\n\n\tFirst enter elements of array!");
					printf("\n\tPress option 1 in the menu.\n\n");
					
					do
					{
						var = getchar();
					}while(var != '\n' && var != EOF);
					

					option = 0;
				}
				else {

					printf("\n\tThe %d elements are -\n\n", limit);

					   for (i = 0; i < limit; i++)
					   {
						   printf("\n\tAt position %d: %c\n", (i + 1), array[i]);
					   }
					   
					   do
					{
						var = getchar();
					}while(var != '\n' && var != EOF);

					}
				}
				break;

			case 3: {
				if(limit == 0)
				{
					printf("\n\n\n\tFirst enter elements of array!");
					printf("\n\tPress option 1 in the menu.\n\n");
					
					do
					{
						var = getchar();
					}while(var != '\n' && var != EOF);
					
					option = 0;

				}

				else
				{
					printf("\n\tEnter position where you want to insert an element: ");
					scanf("%d", &position);

					printf("\n\tEnter element to insert: ");
					scanf(" %c", &element);
					
					for (i = (limit - 1); i >= (position - 1); i--)
					{
						array[i+1] = array[i];
					}

					array[position-1] = element;
					limit++;
				
					printf("\n\tResultant array is -\n");

					for (i = 0; i < limit; i++)
					{
						printf("\n\tAt position %d: %c\n", (i + 1), array[i]);
					}
					
					do
					{
						var = getchar();
					}while(var != '\n' && var != EOF);

				}
				}
				break;

			case 4: {
				
				if(limit == 0)
				{
					printf("\n\n\n\tFirst enter elements of array!");
					printf("\n\tPress option 1 in the menu.\n\n");
					
					do
					{
						var = getchar();
					}while(var != '\n' && var != EOF); // reference - https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
					
					option = 0;

				}
				else
				{
				
					printf("\n\tEnter position where you want to delete element: ");
					scanf("%d", &position);
					
					if(position >= (limit + 1))
					{
						printf("\n\tNo element is present!! Deletion aborted.\n");
					}
					
					else
					{
						for (i = (position - 1); i < (limit - 1); i++)
						{
							array[i] = array[i + 1];
						}
						limit--;

						printf("\n\tResultant array:\n");

						for (i = 0; i < limit; i++)
						{
							printf("\n\tAt position %d: %c\n", (i + 1), array[i]);
						}
						
						do
						{
							var = getchar();
						}while(var != '\n' && var != EOF);
					}
				}

				}
				break;

			case 5: exit(0);
				break;

			default: printf("\n\tKindly input the correct given options. Thank you.");

		}
		
		do
		{
			var = getchar();
		}while(var != '\n' && var != EOF);

        }while(option != 5);


	return 0;
}


// funtion definitons

// menu
void menu(void)
{
	printf("\n\tLAB 2 DELETION PROGRAM! - char");
	printf("\n\t__________________________________\n\n");

	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Enter character elements in the array.");
	printf("\n\n\t2. Display the array elements");
	printf("\n\n\t3. Insert an element.");
	printf("\n\n\t4. Delete an element.");
	printf("\n\n\t5. Exit.\n");

}

