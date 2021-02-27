// reversing sparse matrix

#include <stdio.h>

int main()
{
	int i, j, matrix[3][10], row, col, total, temp, array[10][10];
	
	i = j = temp = total = row = col = 0;
	
	printf("**Works only with ascending order of rows and column input**\n\n");
	
	printf("row: ");
	scanf("%d", &row);
	
	printf("Column: ");
	scanf("%d", &col);
	
	printf("\nTotal non-zero elements: ");
	scanf("%d", &total);
	
	while(temp < total)
	{
		printf("Element no. %d\n", temp+1);
		printf("row: ");
		scanf("%d", &matrix[0][temp]);
				
		printf("Column: ");
		scanf("%d", &matrix[1][temp]);
				
		printf("Element: ");
		scanf("%d", &matrix[2][temp]);
		temp++;
		
		printf("\n");
	}
	
	//for(temp = 0; temp < row; i++)
	
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			array[i][j] = 0;
		}
		
	}
	
	printf("\n\nArray with zeroes - \n");

	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("\t%d", array[i][j]);
		}
		printf("\n");
		
	}
	
	
	temp = 0;
	
	for(i = 0; i < row; i++)  // change
	{
		for(j = 0; j < col; j++)  // change
		{
			if(((i+1) == matrix[0][temp]) && ((j+1) == matrix[1][temp])) // && (temp < total))
			{
				array[i-1][j-1] = matrix[2][temp];
				temp++;
					
			}
		}
	}
		
	
	printf("\n\tTrying out\n");
	
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("\t%d", array[i][j]);
		}
		printf("\n");
		
	}
	
	return 0;
}



