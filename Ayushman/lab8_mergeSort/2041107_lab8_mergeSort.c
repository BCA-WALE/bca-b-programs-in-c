// program to implement merge sort

// to run this program on Windows OS, then change system("clear") to system("cls").
// it should then hopefully work.


// header files
#include <stdio.h>
#include <stdlib.h>



// function declaration
void menu(void);
void pause_screen(char *);
void array_insertion_int(int [], int *);
void int_sort_program(int [], int *);
void display_int_array(int [], int *, int *);
void merge_function(int [], int, int);
void mergeSort(int [], int, int, int);


// main function
int main()
{
	
	// declaration of variables
	int option, elements, number, size, array[20];
	char var;
	

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
				int_sort_program(array, &size);
			       
			    }
		       	break;
		       		
		    case 2:
				printf("\n\t....Exiting!\n\n");
				exit(0);
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

	printf("\n\n\t1. Work with integers.\n");
	printf("\n\n\t2. Exit.\n");
	

}


// main menu for int test program
void int_sort_program(int array[], int *size)
{
	int choice, i, arr[20];
	char option, var;
	
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
		array_insertion_int(array, size);
		int_sort_program(array, size);
	}
	
	else if(choice == 3)
	{
		display_int_array(array, &i, size);
		
        // scanf(" %c", &var);
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
				
			merge_function(arr, 0, (*size - 1));  // check it here
			pause_screen(&var);
			
			printf("\n\tArray:");
			
			for(i = 0; i < *size; i++)
			{
				printf(" %d", arr[i]);
			}
			
			int_sort_program(array, size);
			
			}
			
		else
		{
			merge_function(array, 0, (*size - 1));  // check it here
			
			printf("\n\tArray:");
	
			for(i = 0; i < *size; i++)
			{
				printf(" %d", array[i]);
			}
			
			int_sort_program(array, size);
		}	
			
	}		
	
	else
	{
		printf("\n\tEnter a correct value!");
		pause_screen(&var);
		
		int_sort_program(array, size);
		
	}
	
}


void mergeSort(int array[], int left, int mid, int right)
{
    int i, j, k;
    int former = mid - left + 1;
    int latter = right - mid;
 
 
    int leftarr[former], rightarr[latter];
 

    for(i = 0; i < former; i++)
    {
        leftarr[i] = array[left + i];
	}
	
    for(j = 0; j < latter; j++)
    {    
		rightarr[j] = array[mid + 1 + j];
	}
	
	 
    i = 0; 
    j = 0; 
    k = left;
    
    while (i < former && j < latter) 
    {
        if (leftarr[i] <= rightarr[j]) 
        {
            array[k] = leftarr[i];
            i++;
        }
        
        else 
        {
            array[k] = rightarr[j];
            j++;
        }
        k++;
        
        display_int_array(array, &i, &k);
    }
 

    while (i < former) 
    {
        array[k] = leftarr[i];
        i++;
        k++;
    }
 

    while (j < latter) 
    {
        array[k] = rightarr[j];
        j++;
        k++;
    }
    
}
 


void merge_function(int array[], int left, int right)
{
	int mid;
	
    if (left < right) 
    {
        mid = (left + right)/ 2;
 
        merge_function(array, left, mid);
        merge_function(array, (mid + 1), right);
 
        mergeSort(array, left, mid, right);
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
void display_int_array(int array[], int *left, int *right)
{
	int k = 0;
	
	printf("\n\t");
	
	for(k = *left; k < *right; k++)
	{ 
		printf(" %d", array[k]);
	}
	
	printf("\n");

}



// function continues the program when the user presses enter
void pause_screen(char *var)
{	
	do
	{
		*var = getchar();
	}while(*var != '\n');
}
