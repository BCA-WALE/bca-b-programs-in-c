
// header files
#include <stdio.h>
#include <stdlib.h>


// function declaration
void menu(void);
void pause_screen(void);
void array_insertion_int(int [], int *);
void insertion_sort_int(int [], int *);
void int_sort_program(int [], int *);
void display_int_array(int [], int *);
void char_sort_program(char [], int *);
void display_char_array(char [], int *);
void array_insertion_char(char [], int *);
void insertion_sort_char(char [], int *); 



// main function
int main()
{
	
	// declaration of variables
	int array[20], option, elements, number, size;
	char char_array[20];

	// initialisation of variables
	option = elements = number = size = 0;


	do
	{
		pause_screen();
		system("clear");

		menu();

		printf("\n\n\tEnter your option: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1: {
				int_sort_program(array, &size);
			 	 	 
				}
				break;
			
			case 2:{
				char_sort_program(char_array , &size);
			       
			    }
		       	break;
		       		
		    case 3: 
				printf("\n\t....Exiting!\n\n");
				break;

			default: printf("\n\tKindly input the correct given options. Thank you.");

		}
		
		

        }while(option != 3);


	return 0;
}
	
	


// funtion definitons

// menu
void menu(void)
{
	printf("\n\tLAB 5 INSERTION SORT PROGRAM!");
	printf("\n\t____________________________\n\n");

	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Integer data type");
	printf("\n\n\t2. Char data type");
	printf("\n\n\t3. Exit.\n");

}



void int_sort_program(int array[], int *size)
{
	int choice, i, arr[20];
	char option;
	
	choice = i = 0;
	
	system("clear");
	
	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Insert elements in the 1-D array.");
	printf("\n\n\t2. Sort the elements.");
	printf("\n\n\t3. Display the array elements.");
	printf("\n\n\t4. Exit to main menu.\n");
	
	
	printf("\n\tEnter your choice: ");
	scanf("%d", &choice);
	
	if(choice == 4)
	{
		main();
	}
	
	
	else if(choice == 1)
	{
		array_insertion_int(array, size);
		int_sort_program(array, size);
	}
	
	else if(choice == 3)
	{
		display_int_array(array, size);
		pause_screen();
		int_sort_program(array, size);
	}
	
	
	else if(choice == 2)
	{
		printf("\n\tDo you want to retain the array elements in the array? (y/n): ");
		scanf(" %c", &option);
		

		// when elements are retained
		if(option == 'y')
		{
			printf("\n\tElements retained.\n");
			
			for(i = 0; i < *size; i++)
			{
				arr[i] = array[i];
			}
				
			insertion_sort_int(arr, size);
			pause_screen();
			int_sort_program(array, size);
			
			}
			
		else
		{
			insertion_sort_int(array, size);
			int_sort_program(array, size);
		}	
			
	}
		
	
	
	else
	{
		printf("\n\tEnter a correct value!");
		pause_screen();
		
		int_sort_program(array, size);
		
	}
	
}



void char_sort_program(char array[], int *size)
{
	int choice, i;
	
	char option, arr[20];
	
	choice = i = 0;
	
	system("clear");
	
	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Insert character elements in the 1-D array.");
	printf("\n\n\t2. Sort the elements.");
	printf("\n\n\t3. Display the array elements.");
	printf("\n\n\t4. Exit to main menu.\n");
	
	
	printf("\n\tEnter your choice: ");
	scanf("%d", &choice);
	
	if(choice == 4)
	{
		main();
	}
	
	
	else if(choice == 1)
	{
		array_insertion_char(array, size);
		char_sort_program(array, size);
	}
	
	else if(choice == 3)
	{
		display_char_array(array, size);
		pause_screen();
		char_sort_program(array, size);
	}
	
	
	else if(choice == 2)
	{
		printf("\n\tDo you want to retain the array elements in the array? (y/n): ");
		scanf(" %c", &option);
		

		// when elements are retained
		if(option == 'y')
		{
			printf("\n\tElements retained.\n");
			
			for(i = 0; i < *size; i++)
			{
				arr[i] = array[i];
			}
				
			insertion_sort_char(arr, size);
			pause_screen();
			char_sort_program(array, size);
			
			}
			
		else
		{
			insertion_sort_char(array, size);
			char_sort_program(array, size);
		}	
			
	}
		
	
	else
	{
		printf("\n\tEnter a correct value!");
		pause_screen();
		
		char_sort_program(array, size);
		
	}
	
}




// function to sort the elements 
void insertion_sort_int(int array[], int *size) 
{ 
    int i, j, current; 
    
    printf("\tUnsorted elements: ");
	for(i = 0; i < *size; i++)
    { 
		printf(" %d", array[i]);
	}
	printf("\n\n");
        
    for (i = 1; i < *size; i++) 
    {
        current = array[i]; 
        j = i - 1; 
  
        while (array[j] > current && j >= 0) 
        {
			display_int_array(array, size); 
            array[j + 1] = array[j]; 
            j--;
        
        } 
        array[j + 1] = current; 
        
    }
    
    pause_screen();
    
    printf("\n\n\tSorted elements: ");
	
	for(i = 0; i < *size; i++)
    {
		printf(" %d", array[i]);
	}
	
	pause_screen();
} 




// function to sort the elements - char array
void insertion_sort_char(char array[], int *size) 
{ 
    int i, j, current; 
    
    printf("\tUnsorted elements: ");
	for(i = 0; i < *size; i++)
    { 
		printf(" %c", array[i]);
	}
	printf("\n\n");
        
    for (i = 1; i < *size; i++) 
    {
        current = array[i]; 
        j = i - 1; 
  
        while (array[j] > current && j >= 0) 
        { 
			display_char_array(array, size);
            array[j + 1] = array[j]; 
            j--;
        
        } 
        array[j + 1] = current; 
        
    }
    
    pause_screen();
    
    printf("\n\n\tSorted elements: ");
	
	for(i = 0; i < *size; i++)
    {
		printf(" %c", array[i]);
	}
	
	pause_screen();
}



// insertion of elements - char
void array_insertion_char(char array[], int *size)
{
	int i;
	i = 0;
	
	printf("\n\tEnter number of elements in array (max 20): ");
    scanf("%d", size);
    
    
    if(*size > 20 || *size < 1)  // validation
	{
		printf("\n\tEnter the size between 1 - 20 only!!");
		array_insertion_char(array, size);  
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
    scanf("%d", size);  
    
    
    if(*size > 20 || *size < 1)  // validation
	{
		printf("\n\tEnter the size between 1 - 20 only!!");
		array_insertion_int(array, size);  
	}
	

    printf("\n\tEnter %d elements\n", *size);

    for (i = 0; i < *size; i++)
    {
		printf("\n\tElement %d: ", (i + 1));
        scanf("%d", &array[i]);
    }

}



// display int array elements
void display_int_array(int array[], int *size)
{
	int k = 0;
	
	printf("\n\t");
	
	for(k = 0; k < *size; k++)
	{ 
		printf(" %d", array[k]);
	}
}

// display char array elements
void display_char_array(char array[], int *size)
{
	int k = 0;
	
	printf("\n\t");
	
	for(k = 0; k < *size; k++)
	{ 
		printf(" %c", array[k]);
	}
	
}



// function continues the program when the user presses enter
void pause_screen(void)
{
	char var = 't';
	
	do
	{
		var = getchar();
	}while(var != '\n');
}
