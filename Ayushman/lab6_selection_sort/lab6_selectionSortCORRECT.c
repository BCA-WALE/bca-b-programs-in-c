// program to implement selection sort

// to run this program on Windows OS, then change system("clear") to system("cls").
// it should then hopefully work.


// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structure student
struct student
{
	char name[20];
	int roll, marks;
};



// function declaration
void menu(void);
void pause_screen(char *);
void array_insertion_char(char [], int *);
void selection_sort_char_ascending(char [], int *);
void char_sort_program(char [], int *);
void display_char_array(char [], int *);
void swap(char *, char *);
void display(struct student *stud, int *);
void insert(struct student *stud, int *);
void selection_sort_char_descending(char [], int *);
void struct_sort(struct student *stud, int *);
void selection_sort_struct_descending(struct student *stud, int *);
void selection_sort_struct_ascending(struct student *stud, int *);


// main function
int main()
{
	
	// declaration of variables
	int option, elements, number, size;
	char var, array[20];
	
	struct student stud[10];
	
	
	// ptr = (struct person*) malloc(n * sizeof(struct person));  // from the web - dont use

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
			 	insert(stud, &size);

				}
				break;
			
			case 2: {
				struct_sort(stud, &size);
			       
			    }
		       	break;

            case 3: {
                display(stud, &size);

                }
                break;
		       		
		    case 4:
				printf("\n\t....Exiting!\n\n");
				break;
				
			case 5:{
                char_sort_program(array, &size);

                }
		        break;	

			default: printf("\n\tKindly input the correct given options. Thank you.");

		}
		
		

        }while(option != 4);


	return 0;
}
	
	

// funtion definitons

// menu
void menu(void)
{
	printf("\n\tLAB 6 SELECTION SORT PROGRAM!");
	printf("\n\t____________________________\n\n");

	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Insert student records.");
	printf("\n\n\t2. Sort the records according to the roll number.");
	printf("\n\n\t3. Display the records.");
	printf("\n\n\t4. Exit.\n");
	printf("\n\n\t5. test case with characters\n");

}


// main menu for char test program
void char_sort_program(char array[], int *size)
{
	int choice, i;
	char option, var, arr[20];
	
	choice = i = 0;
	
	system("clear");
	
	printf("\n\n\t\t\tMENU");
	
	printf("\n\n\t1. Insert elements in the array.");
	printf("\n\n\t2. Sort the elements in ascending order.");
	printf("\n\n\t3. Sort the elements in descending order.");
	printf("\n\n\t4. Display the elements.");
	printf("\n\n\t5. Exit to main menu.\n");
		
	
	printf("\n\tEnter your choice: ");
	scanf("%d", &choice);
	
	if(choice == 5)
	{
		main();
	}
	
	
	else if(choice == 1)
	{
		array_insertion_char(array, size);
		char_sort_program(array, size);
	}
	
	else if(choice == 4)
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
				
			selection_sort_char_ascending(arr, size);
			pause_screen(&var);
			char_sort_program(array, size);
			
			}
			
		else
		{
			selection_sort_char_ascending(array, size);
			char_sort_program(array, size);
		}	
			
	}
	
	else if(choice == 3)
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
				
			selection_sort_char_descending(arr, size);
			pause_screen(&var);
			char_sort_program(array, size);
			
			}
			
		else
		{
			selection_sort_char_descending(array, size);
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



// sorting struct elements
void struct_sort(struct student *stud, int *size)
{
	int i, choice;
	char option, var;
	
	struct student stu[10];
	
	printf("\n\tAscending or descending order (1 or 2): ");
	scanf("%d", &choice);
	
	printf("\n\tDo you want to retain the array elements in the array? (y/n): ");
	scanf(" %c", &option);
	
	
	// ascending order
	if(choice == 1)
	{

		// when elements are retained
		if(option == 'y')
		{
			printf("\n\tElements retained.\n");
				
			for(i = 0; i < *size; i++)
			{
				stu[i].roll = stud[i].roll;
				strcpy(stu[i].name, stud[i].name);
				stu[i].marks = stud[i].marks;
			}
				
			selection_sort_struct_ascending(stu, size);
			pause_screen(&var);
			main();
				
			}
				
		else
		{
			selection_sort_struct_ascending(stud, size);
			main();
		}	
	}
	
	
	// descending order
	else if(choice == 2)
	{

		// when elements are retained
		if(option == 'y')
		{
			printf("\n\tElements retained.\n");
				
			for(i = 0; i < *size; i++)
			{
				stu[i].roll = stud[i].roll;
				strcpy(stu[i].name, stud[i].name);
				stu[i].marks = stud[i].marks;
			}
				
			selection_sort_struct_descending(stu, size);
			pause_screen(&var);
			main();
				
			}
				
		else
		{
			selection_sort_struct_descending(stud, size);
			main();
		}
	
	}
	
	
	else
	{
		printf("\n\tEnter a correct value!");
		pause_screen(&var);
		
		struct_sort(stud, size);
		
	}
			
	
}



// sort struct elements according to roll num ascending order
void selection_sort_struct_ascending(struct student *stud, int *size)
{
	int i, j, current;
	struct student temp;
	
	char var;
	
	i = j = current = 0;
	
	printf("\n\tUnsorted records: \n");
	display(stud, size);
	
	for(i = 0; i < (*size - 1); i++)
	{
		current = i;
		
		for(j = (i + 1); j < *size; j++)
		{
			if(stud[current].roll > stud[j].roll)
			{
				current = j;
			}
			// display(*stud, size);
		}
		
		temp = stud[i];
		stud[i] = stud[current];
		stud[current] = temp;
		
	}
	    
    pause_screen(&var);
    
    printf("\n\n\tSorted elements in ascending order: ");
	
	display(stud, size);	
	
}




// sort struct elements according to roll num descending order
void selection_sort_struct_descending(struct student *stud, int *size)
{
	int i, j, current;
	struct student temp;
	
	char var;
	
	i = j = current = 0;
	
	printf("\n\tUnsorted records: \n");
	display(stud, size);
	
	for(i = 0; i < (*size - 1); i++)
	{
		current = i;
		
		for(j = (i + 1); j < *size; j++)
		{
			if(stud[current].roll < stud[j].roll)
			{
				current = j;
			}
			// display(*stud, size);
		}
		
		temp = stud[i];
		stud[i] = stud[current];
		stud[current] = temp;
		
	}
	    
    pause_screen(&var);
    
    printf("\n\n\tSorted elements in descending order: ");
	
	display(stud, size);	
	
}




// display the records of the students
void display(struct student *stud, int *size)
{
	int i;
    char var;
	
	i = 0;
	system("clear");

    printf("\n\tRoll. no \tName \t\tMarks");
    for(i = 0; i < *size; i++)
    {
        printf("\n\t%d \t\t%s \t\t%d", stud[i].roll, stud[i].name, stud[i].marks);

    }

    pause_screen(&var);
	
}



// insert struct elements
void insert(struct student *stud, int *size)
{
    int i;
    char var;

    i = 0;

    printf("\n\tEnter the number of records to be inserted (max 10): ");
    scanf("%d", size);

    if(*size > 10 || *size < 0)
    {
        printf("\n\tKindly enter number between 1-10 only!!");
        pause_screen(&var);
        insert(stud, size);
    }

    else
    {

        for(i = 0; i < *size; i++)
        {
            printf("\n\tStudent %d", (i + 1));
            printf("\n\tEnter the student roll no. : ");
            scanf("%d", &stud[i].roll);

            printf("\n\tEnter the student name: ");
            scanf("%s", stud[i].name);

            printf("\n\tEnter the student marks: ");
            scanf("%d", &stud[i].marks);

            printf("\n\n");
        }
    }

}



// function to sort the elements - ascending
void selection_sort_char_ascending(char array[], int *size) 
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



// function to sort the elements - descending
void selection_sort_char_descending(char array[], int *size) 
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
            if(array[j] > array[current]) 
            {
                current = j;
            }    
       
            display_char_array(array, size);

       	} 
     	swap(&array[i], &array[current]); 

    }
    display_char_array(array, size);
    
    pause_screen(&var);
    
    printf("\n\n\tSorted elements in descending order: ");
	
	for(i = 0; i < *size; i++)
    {
		printf(" %c", array[i]);
	}
	
	printf("\n\tin ASCII in descending order: ");
	
	// shows ASCII numbers
	for(i = 0; i < *size; i++)
    {
		printf(" %d", array[i]);
	}
	
	
	pause_screen(&var);
}



// function for swapping
void swap(char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}



// insertion of array elements - int
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
