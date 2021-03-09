// program to implement quick sort

// to run this program on Windows OS, then change system("clear") to system("cls").
// it should then hopefully work.


// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// function declaration
void menu(void);
void pause_screen(char *);
void array_insertion_char(char [], int *);
void quick_sort_char_ascending(char [], int *);
void char_sort_program(char [], int *);
void display_char_array(char [], int *);
void swap(char *, char *);
int partition_char(char [], int *, int *);
void quicksort_char(char [], int , int );


// main function
int main()
{
	
	// declaration of variables
	int option, elements, number, size;
	char var, array[20];
	

	// initialisation of variables
	option = elements = number = size = 0;


	do
	{
		pause_screen(&var);
		system("clear");

		menu();

		printf("\n\n\tEnter your option: ");
		scanf("%d", &option);

		switch(option)
		{
			case 1: {
				char_sort_program(array, &size);
			       
			    }
		       	break;
		       		
		    case 2:
				printf("\n\t....Exiting!\n\n");
				break;

			default: printf("\n\tKindly input the correct given options. Thank you.");

		}
		
		

        }while(option != 2);


	return 0;
}
	
	

// funtion definitons

// menu
void menu(void)
{
	printf("\n\tLAB 6 QUICK SORT PROGRAM!");
	printf("\n\t_________________________\n\n");

	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Work with characters.\n");
	printf("\n\n\t2. Exit.\n");
	

}


// main menu for char test program
void char_sort_program(char array[], int *size)
{
	int choice, i;
	char option, var, arr[20];
	
	choice = i = 0;
	
	//system("clear");
	
	printf("\n\n\t\t\tMENU");
	
	printf("\n\n\t1. Insert elements in the array.");
	printf("\n\n\t2. Sort the elements in ascending order.");
	printf("\n\n\t3. Display the elements.");
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
		pause_screen(&var);
		
        scanf(" %c", &var);
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
				
			quicksort_char(arr, 0, (*size - 1));  // check it here
			pause_screen(&var);
			
			printf("\n\tin ASCII in ascending order: ");
	
			// shows ASCII numbers
			for(i = 0; i < *size; i++)
			{
				printf(" %d", array[i]);
			}
			char_sort_program(array, size);
			
			}
			
		else
		{
			quicksort_char(array, 0, (*size - 1));  // check it here
			printf("\n\tin ASCII in ascending order: ");
	
			// shows ASCII numbers
			for(i = 0; i < *size; i++)
			{
				printf(" %d", array[i]);
			}
			
			char_sort_program(array, size);
		}	
			
	}		
	
	else
	{
		printf("\n\tEnter a correct value!");
		pause_screen(&var);
		
		char_sort_program(array, size);
		
	}
	
}




// function to sort the elements - ascending
void quick_sort_char_ascending(char array[], int *size) 
{ 
	int i, j, current;
    char var; 
    
   	printf("\tUnsorted elements: ");
	for(i = 0; i < *size; i++)
    { 
		printf(" %c", array[i]);
	}
	printf("\n\n");
    

    for (i = 0; i < (*size - 1); i++) 
    {
       	current = i; 
        
       	for(j = (i + 1); j < *size; j++)  // changed here 
       	{
            if(array[j] < array[current]) 
            {
                current = j;
            }    
       
            display_char_array(array, size);

       	} 
     	swap(&array[i], &array[current]); 

    }
    display_char_array(array, size);
    
    pause_screen(&var);
    
    printf("\n\n\tSorted elements in ascending order: ");
	
	for(i = 0; i < *size; i++)
    {
		printf(" %c", array[i]);
	}
	
	printf("\n\tin ASCII in ascending order: ");
	
	// shows ASCII numbers
	for(i = 0; i < *size; i++)
    {
		printf(" %d", array[i]);
	}
	
	
	pause_screen(&var);
} 




// partitioning the array
int partition_char(char array[], int *low, int *high)
{
	int pivot, start, end;
	
	pivot = array[*low];  // pivot = first element
	start = *low;
	end = *high;
	
	display_char_array(array, high);
	//printf("\n\n");
	
	while(start < end)
	{
		display_char_array(array, high);
		
		while(array[start] <= pivot)
		{
			start++;
		}
		
		while(array[end] > pivot)
		{
			end--;
		}
		
		if(start < end)
		{
			swap(&array[start], &array[end]);
		}
		
		
	}
	
	swap(&array[*low], &array[end]);
	
	//printf("\n\n");
	
	//display_char_array(array, (high + 1));  // give DISPLAY FROM LOW & HIGH display(array, LOW, HIGH) - CHANGE
	
	return end;
	
}


void quicksort_char(char array[], int low, int high)
{
	int location;
	 
	if(low < high)
	{
		location = partition_char(array, &low, &high);
		
		quicksort_char(array, low, (location - 1));
		
		quicksort_char(array, (location + 1), high);
		
	}
	
}



// function for swapping
void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}


// CAN REMOVE THIS MAYBE?
// insertion of array elements - char
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



// display int array elements
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
void pause_screen(char *var)
{	
	do
	{
		*var = getchar();
	}while(*var != '\n');
}
