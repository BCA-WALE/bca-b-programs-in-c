/*

a menu driven program to implement linear search (sentinel) and binary search.

Special Guidelines:
Linear Sentinel Search:
- Min. of 2 different data types// array of objects with 2 different data type is also fine (can search in all 2 data types with menu driven program)
- do sentinel search and show the no. of searches for best/average and worst cases.

Binary Search:
- have 2 data types  namely 1. int or float 2. Char array or String and do the search in both the data types
- Can  either take the input in the sorted order itself.  (for complexity - if the sorted order is missed during input, it can prompt the user (eg. input of 5 elts.. let the elts be 10, 20, 12 (here it has to stop the user saying you can enter 20 or >20 only as the prev elt is 20)  or take the input in any order and later can check whether it is in sorted order or not; if not in sorted order, should redirect the array for sorting and later do the binary search
- Print the messages according to the result (if found, Print the message accordingly. Eg.  elt X is present in position Y; if not , say elt is not found in the array

*/

// header files
#include <stdio.h>
#include <stdlib.h>


// function declaration

// for int
void linear_sentinel_search_int(int [], int *, int *);
void array_insertion_int(int [], int *);
int search_element_int(int *);
void linear_search_int(int [], int *, int *);
void binary_search_int(int [], int, int, int);


// for char
char search_element_char(char *);
void linear_sentinel_search_char(char [], int *, char *);
void linear_search_char(char [], int *, char *);
void binary_search_char(char [], int, int, char); 
void array_insertion_char(char [], int *);


// MENU
void menu(void);
void menu_binary_search(int [], char [], int *);
void menu_linear_search(int [], char [], int *);



// main function
int main()
{
	// declaration of variables
	int array_int[20], limit, option, position, element;
	char var, array_char[20];


	// initialisation of variables
	limit = option = position = element = 0;
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
				menu_linear_search(array_int, array_char, &limit);
				
				do
				{
					var = getchar();
				}while(var != '\n' && var != EOF);
				
				}
				break;
				
			case 2: {
				menu_binary_search(array_int, array_char, &limit);

				}
				
				do
				{
					var = getchar();
				}while(var != '\n' && var != EOF);
				
				break;

			case 3: exit(0);
				break;

			default: printf("\n\tKindly input the correct given options. Thank you.");

		}

		do
		{
			var = getchar();
		}while(var != '\n' && var != EOF);

     }while(option != 3);


	return 0;
}



// funtion definitons

// menu
void menu(void)
{
	printf("\n\tLAB 3 SEARCHING PROGRAM! - int");
	printf("\n\t_____________________________\n\n");

	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Linear and Linear Sentinel Search");
	printf("\n\n\t2. Binary Search");
	printf("\n\n\t3. Exit.\n");

}



// insertion of  - int
void array_insertion_char(char array[], int *size)
{
	int i;
	i = 0;
	
	printf("\n\tEnter number of elements in array (max 20): ");
    scanf("%d", size);  // why no * or & with size?
    
    
    if(*size > 20 || *size < 1)  // validation
	{
		printf("\n\tEnter the size between 1 - 20 only!!");
		array_insertion_char(array, size);  // how to use recursion if a function has parameters?
	}
	

    printf("\n\tEnter %d elements\n", *size);

    for (i = 0; i < *size; i++)
    {
		printf("\n\tElement %d: ", (i + 1));
        scanf(" %c", &array[i]);
    }

}



// insertion of array elements - int
void array_insertion_int(int array[], int *size)
{
	int i;
	i = 0;
	
	printf("\n\tEnter number of elements in array (max 20): ");
    scanf("%d", size);  // why no * or & with size?
    
    
    if(*size > 20 || *size < 1)  // validation
	{
		printf("\n\tEnter the size between 1 - 20 only!!");
		array_insertion_int(array, size);  // how to use recursion if a function has parameters?
	}
	

    printf("\n\tEnter %d elements\n", *size);

    for (i = 0; i < *size; i++)
    {
		printf("\n\tElement %d: ", (i + 1));
        scanf("%d", &array[i]);
    }

}



// menu for linear search
void menu_linear_search(int array_int[], char array_char[], int *size)
{
	char option = 'y', var = 't', element_char = 'c';
	int choice, element_int;
	
	choice = element_int = 0;
	
	system("clear");
	
	printf("\n\n\tLinear and Linear Sentinel Search");
	printf("\n\t1. use int datatype");
	printf("\n\t2. use char datatype");
	
	printf("\n\tEnter your choice: ");
	scanf("%d", &choice);
	
	printf("\n\tDo you want to retain the array elements? (y/n): ");
	scanf(" %c", &option);
	
	
	// when elements are retained
	if(option == 'y')
	{
		printf("\n\tElements retained.\n");
		
		if(choice == 1)  // int
		{
			element_int = search_element_int(&element_int);  // feed element to search
			
			linear_search_int(array_int, size, &element_int);
			
			linear_sentinel_search_int(array_int, size, &element_int);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
		
		else  // char
		{
			element_char = search_element_char(&element_char);
			
			linear_search_char(array_char, size, &element_char);
			
			linear_sentinel_search_char(array_char, size, &element_char);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
	}
	
	
	// when elements are not retained
	else if(option == 'n')
	{
		if(choice == 1)  // int
		{
			array_insertion_int(array_int, size);
			
			element_int = search_element_int(&element_int);  // feed element to search
			
			linear_search_int(array_int, size, &element_int);
			
			linear_sentinel_search_int(array_int, size, &element_int);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
		
		else  // char
		{
			array_insertion_char(array_char, size);
			
			element_char = search_element_char(&element_char);
			
			linear_search_char(array_char, size, &element_char);
			
			linear_sentinel_search_char(array_char, size, &element_char);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
	}
	
	else
	{
		printf("\n\tEnter a correct value!");
		do
		{
			var = getchar();
		}while(var != '\n' && var != EOF);
		
		menu_linear_search(array_int, array_char, size);
	}
}
	
	

// element to search for - int
int search_element_int(int *element)
{
	printf("\n\tWhich element do you want to search for?");
	printf("\n\tElement: ");
	
	scanf("%d", element);
	return *element;
}


// element to search for - char
char search_element_char(char *element)
{
	printf("\n\tWhich element do you want to search for?");
	printf("\n\tElement: ");
	
	scanf(" %c", element);
	return *element;
}



// linear sentinel search - char
void linear_sentinel_search_char(char array[], int *size, char *character)
{
	int i;
	char last;

	i = 0;
	last = 'z';

	last = array[*size - 1];
	array[*size - 1] = *character;
	
	printf("\n\n\tLinear Sentinel Search -\n");

	while(array[i] != *character)
	{
		printf("\n\tLoop runs %d times", (i + 1));  // number of times executed
		i++;
	}

	array[*size - 1] = last;

	if(i < (*size - 1) || array[i] == *character)
	{
		
		printf("\n\tThe number %c is found at index: %d and position: %d\n\n", *character, i, (i + 1));

	}

	else
	{
		printf("\n\tElement %c not found in the array.", *character);
	}


}



// linear sentinel search - int
void linear_sentinel_search_int(int array[], int *size, int *number)
{
	int i, last;

	i = last = 0;

	last = array[*size - 1];
	array[*size - 1] = *number;
	
	printf("\n\n\tLinear Sentinel Search -\n");

	while(array[i] != *number)
	{
		printf("\n\tLoop runs %d times", (i + 1));  // number of times executed
		i++;
	}

	array[*size - 1] = last;

	if(i < (*size - 1) || array[i] == *number)
	{
		
		printf("\n\tThe number %d is found at index: %d and position: %d\n\n", *number, i, (i + 1));

	}

	else
	{
		printf("\n\tElement %d not found in the array.", *number);
	}


}



// linear search function - int
void linear_search_int(int array[], int *size, int *number)
{
	int i, flag;
	
	i = flag = 0;
	
	printf("\n\n\tLinear search -\n");
	
	for(i = 0; i < *size; i++)
	{
		printf("\n\tLoop runs %d times", (i + 1));  // number of times executed
		
		if(array[i] == *number)  // checking the number in array
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 1)
	{
		
		printf("\n\tElement %d found at position: %d", *number, (i + 1));
		
	}
	
	else
	{
		printf("\n\tElement %d not found in the array.", *number);
	}
	
}



// linear search function - char
void linear_search_char(char array[], int *size, char *character)
{
	int i, flag;
	
	i = flag = 0;
	
	printf("\n\n\tLinear search -\n");
	
	for(i = 0; i < *size; i++)
	{
		printf("\n\tLoop runs %d times", (i + 1));  // number of times executed
		
		if(array[i] == *character)  // checking the number in array
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 1)
	{
		
		printf("\n\tElement %c found at position: %d", *character, (i + 1));
		
	}
	
	else
	{
		printf("\n\tElement %c not found in the array.", *character);
	}
	
}



// binary search menu
void menu_binary_search(int array_int[], char array_char[], int *size)
{
	char option = 'y', var = 't', element_char = 'c';
	int choice, element_int;
	
	choice = element_int = 0;
	
	system("clear");
	
	printf("\n\n\tBinary Search");
	printf("\n\t1. use int datatype");
	printf("\n\t2. use char datatype");
	
	printf("\n\tEnter your choice: ");
	scanf("%d", &choice);
	
	printf("\n\tDo you want to retain the array elements? (y/n): ");
	scanf(" %c", &option);
	
	
	// when elements are retained	
	if(option == 'y')
	{
		printf("\n\tElements retained.\n");
		
		if(choice == 1)  // int
		{
			element_int = search_element_int(&element_int);  // feed element to search
			
			binary_search_int(array_int, 0, (*size - 1), element_int);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
		
		else  // char
		{	
			element_char = search_element_char(&element_char);
			
			binary_search_char(array_char, 0, (*size - 1), element_char);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
	}
	
	
	
	// when elements are not retained
	else if(option == 'n')
	{
		if(choice == 1) 
		{
			array_insertion_int(array_int, size);  // insertion of array elements
			
			element_int = search_element_int(&element_int);  // feed element to search
			
			binary_search_int(array_int, 0, (*size - 1), element_int);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
		
		else
		{
			array_insertion_char(array_char, size);
			
			element_char = search_element_char(&element_char);
			
			binary_search_char(array_char, 0, (*size - 1), element_char);
			
			do
			{
				var = getchar();
			}while(var != '\n' && var != EOF);
		}
	}
	
	else
	{
		printf("\n\tEnter a correct value!");
		do
		{
			var = getchar();
		}while(var != '\n' && var != EOF);
		
		menu_linear_search(array_int, array_char, size);
	}
}



// binary search function - char
void binary_search_char(char array[], int min, int max, char element) 
{
	int mid, i, flag;
	
	mid = i = flag = 0;
	
	printf("\n\tBinary Search");
	
	while (min <= max) 
	{
		printf("\n\tLoop runs %d times", (++i));  // number of times executed
		
		mid = (max + min) / 2;

		if (array[mid] == element)
		{
			flag = 1;
			break;
		}

		else if(array[mid] < element)
		{
			min = mid + 1;
		}
		
		else
		{
			max = mid - 1;
		}
	}
	
	if(flag == 0)
	{
		printf("\n\tElement %c not found in the array.", element);
		
	}
			
	else
	{
		printf("\n\tElement %c found at position: %d", element, (mid + 1));
	}

}



// binary search function - int
void binary_search_int(int array[], int min, int max, int element) 
{
	int mid, i, flag;
	
	mid = i = flag = 0;
	
	printf("\n\tBinary Search");
	
	while (min <= max) 
	{
		printf("\n\tLoop runs %d times", (++i));  // number of times executed
		
		mid = (max + min) / 2;

		if (array[mid] == element)
		{
			flag = 1;
			break;
		}

		else if(array[mid] < element)
		{
			min = mid + 1;
		}
		
		else
		{
			max = mid - 1;
		}
	}
	
	if(flag == 0)
	{
		printf("\n\tElement %d not found in the array.", element);
		
	}
			
	else
	{
		printf("\n\tElement %d found at position: %d", element, (mid + 1));
	}

}
