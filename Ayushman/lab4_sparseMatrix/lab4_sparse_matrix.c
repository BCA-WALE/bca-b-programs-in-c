/*

Write a menu driven program to read a sparse matrix of integer values, search and 
* print the appropriately triple < row, column, "value" > that represents the elements in the sparse matrix:

Expected Tasks:

=> read a matrix (let it be a sparse matrix) //for complexity, if you can, take a matrix 
find whether it is sparse are dense martrix and display the details; if it is sparse matrix, 
do the rep. of sparse matrix in 3 * N matrix

=> rep. sparse matrix in 3 x N form, and display the representation (3 x N matrix)

=>search for the elt in 3 x N matrix and print the details

*/


// header files
#include <stdio.h>
#include <stdlib.h>


// macros
/*

#define row 3
#define column 30
*/



// function declaration
void menu(void);
void pause_screen(void);
void array_insertion_int(int [][10], int *, int *);
void display_sparse_matrix(int [][10], int *, int *);
int display_special_matrix(int [][10], int *, int *, int [][40]);
void linear_sentinel_search_int(int [][40], int *, int *);
int search_element_int(int *);

// main function
int main()
{
	
	// declaration of variables
	int matrix[10][10], nonZeroMatrix[3][40], option, position, elements, row, column, number;


	// initialisation of variables
	option = position = row = column = elements = number = 0;


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
				array_insertion_int(matrix, &row, &column); 
			 	 	 
				}
				break;
			
			case 2:{
				display_sparse_matrix(matrix, &row, &column);
			       
			    }
		       	break;
		       		
		    case 3:{
				elements = display_special_matrix(matrix, &row, &column, nonZeroMatrix);	
				
				}
				break;
				
			case 4: {
				search_element_int(&number);
				linear_sentinel_search_int(nonZeroMatrix, &elements, &number);
			
				}
				break;

			case 5: 
				printf("\n\t....Exiting!\n\n");
				break;

			default: printf("\n\tKindly input the correct given options. Thank you.");

		}
		
		

        }while(option != 5);


	return 0;
}
	
	


// funtion definitons

// menu
void menu(void)
{
	printf("\n\tLAB 4 SPARSE MATRIX PROGRAM!");
	printf("\n\t____________________________\n\n");

	printf("\n\n\t\t\tMENU");

	printf("\n\n\t1. Enter integer elements in the matrix.");
	printf("\n\n\t2. Display the elements of sparse matrix.");	
	printf("\n\n\t3. Display the non-zero elements in 3*N form");
	printf("\n\n\t4. Search for a non-zero element in the 3*N form matrix.");
	printf("\n\n\t5. Exit.\n");

}


// function continues the program when the user presses enter
void pause_screen(void)
{
	char var = 't';
	
	do
	{
		var = getchar();
	}while(var != '\n' && var != EOF);
}



// insertion of elemts in the matrix
void array_insertion_int(int array[][10], int *rows, int *columns)
{
	int i, j;
	i = j = 0;
	
	printf("\n\tEnter the size of the matrix -");
	printf("\n\tnumber of rows (max 10): ");
    scanf("%d", rows);
    
    printf("\n\tnumber of columns (max 10): ");
    scanf("%d", columns);
    
    
    if(*rows > 10 || *rows < 1 || *columns > 10 || *columns < 1)  // validation
	{
		printf("\n\tEnter the rows and columns between 1 - 10 only!!");
		array_insertion_int(array, rows, columns);  // how to use recursion if a function has parameters?
	}
	

    printf("\n\tEnter the elements -\n");

    for (i = 0; i < *rows; i++)
    {
		for(j = 0; j < *columns; j++)
		{
			printf("\n\tElement [%d][%d]: ", i, j);
			scanf("%d", &array[i][j]);
		}
		
    }
    pause_screen();

}


// display sparse matrix
void display_sparse_matrix(int array[][10], int *rows, int *columns)
{
	int i, j;
	i = j = 0;

	for (i = 0; i < *rows; i++)
    {
		for(j = 0; j < *columns; j++)
        {
			printf("\n\tElement [%d][%d]: %d", i, j, array[i][j]);
        }
        printf("\n");

    }
    
    printf("\n\n");
    
    for (i = 0; i < *rows; i++)
    {
		for(j = 0; j < *columns; j++)
        {
			printf("\t%d", array[i][j]);
        }
        printf("\n\n");

    }
    
	pause_screen();
}


// display non-zero elements in 3*N form
int display_special_matrix(int array[][10], int *rows, int *columns, int specialMatrix[][40])
{
	
	int i, j, k;
    i = j = k = 0;

    for (i = 0; i < *rows; i++)
	{
	    for(j = 0; j < *columns; j++)
        {
			if(array[i][j] != 0)
			{
				specialMatrix[0][k] = i;
				specialMatrix[1][k] = j;
				specialMatrix[2][k] = array[i][j];
			    printf("\n\tElement [%d][%d]: %d", specialMatrix[0][k], specialMatrix[1][k], specialMatrix[2][k]);
			    k++;

			}
        }

    }	
    
    printf("\n\n");
    
    printf("\n\t3 * N matrix form -\n\n");
    printf("\n\tRow \tColumn \tValue");
    
    for (i = 0; i < k; i++)
	{
	    printf("\n\t%d \t %d  \t %d", specialMatrix[0][i], specialMatrix[1][i], specialMatrix[2][i]);

    }
        
    pause_screen();
    return k;
}


// linear sentinel search
void linear_sentinel_search_int(int array[][40], int *numberOfElements, int *number)
{
	int i, last;

	i = last = 0;

	last = array[2][*numberOfElements];
	array[2][*numberOfElements] = *number;
	
	printf("\n\n\tLinear Sentinel Search -\n");

	while(array[2][i] != *number)
	{
		printf("\n\tLoop runs %d times", (i + 1));  // number of times executed
		i++;
	}

	array[2][*numberOfElements] = last;

	if(i < (*numberOfElements - 1) || array[2][i] == *number)
	{
		
		printf("\n\tThe number %d is found at index: %d,%d", *number, array[0][i], array[1][i]);
		pause_screen();

	}

	else
	{
		printf("\n\tElement %d not found in the array.", *number);
		pause_screen();
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
