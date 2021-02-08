//DS LAB 4 SPARSE MATRIX
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#define S 20
struct sparse
{
	int row,col,val;
}rep[S];typedef struct sparse sp;

void start();
void input(int r,int c,int p[r][c]);
void display(int r,int c,int p[r][c]);
void sparsity(int r,int c,int p[r][c],int *n);
void represent(int r,int c,int p[r][c],int x);
void nonzerodisplay(int n);
void search(int n);
 
 void main()
 {  int r,c,flag,arr[S][S],n,x;
 	sp rep[S];
    char ch;
    start();
	system("color 3");
 	do
		{
    		printf("\n\nMENU");
    		printf("\n1.Enter the Data");
    		printf("\n2.Display the Data");
			printf("\n3.To check if the Matrix is Sparse or Dense");
			printf("\n4.To Search Data in the matrix");
			printf("\n5.Exit\nYour Choice : ");
			fflush(stdin);	
			ch=getchar();
				if(!isdigit(ch))
				{
				system("cls");
				start();
				system("color 4");
				printf("\n\aEnter a Digit.");
				}
				else
				{
					switch(ch)
						{
							case '1':
								    do
								    {
								 	printf("\n\nEnter No. of Rows : ");
								 	scanf("%d",&r);
								 	printf("Enter No. of Columns : ");
								 	scanf("%d",&c);
								 	int arr[r][c];
								 	if(r<=0||c<=0)
								 	{ 	system("color 4");
									 	printf("\nInvalid Input!!\nNumber of Rows and Columns should be greater than Zero.");
								 	    flag =0;
									 }
								 	else
								 	flag =1;
								 	}while (flag==0);
								 	system("color 3");	
								 	input(r,c,arr);
								 	break;
							case '2': 
								 	display(r,c,arr);
								 	break;
							case '3':
								sparsity(r,c,arr,&n);
								if(n==0)
								printf("\nTry Entering a Different Array\n");
								else
								{ 	x=(r*c)-n;
								    
								 	represent(r,c,arr,x);									
								}
								 	break;	 	
							case '4':
								 	search(x);
								 	break;	 	
							case '5':
								 	break;
							default:	 	
								 	
								system("cls");
								start();
								system("color 4");
								printf("\n\aChoose Between 1,2,3,4,5.\n");
					}//switch
			}//else
	}while(ch!='5');
printf("\nLAB TASK 4 COMPLETED!!");								 	
}//main
							
 void start()
{
	printf("\n");
	printf("\t\t\t\t\t\t SPARSE MATRIX\n");
	printf("________________________________________________________________________________________________________________________\n");	
}//start
 
 void input(int r,int c,int p[r][c])
 {
 	int i,j;
	system("cls");
    start();
    printf("\n\t\t\t..................................INPUT.....................................\n\n");
 	printf("\nEnter %d Elements in the Matrix : \n",(r*c));
 	for(i=0;i<r;i++)
 	for(j=0;j<c;j++)
 	{
 	scanf("%d",&p[i][j]);	
	}
 	system("cls");
	start();	
 }//input
 
 void display(int r,int c,int p[r][c])
 {
 	 system("cls");
    system("color 3");
   start();
    int i,j;
    printf("\n\t\t\t................................OUTPUT.....................................\n\n");
    for(i=0;i<r;i++)
    {
	 	for(j=0;j<c;j++)
	 	{  
		    printf("%d\t",p[i][j]);	
		}
	printf("\n\n");
    }
printf("________________________________________________________________________________________________________________________\n");	

 }//display
 
void sparsity(int r,int c,int p[r][c],int *n)
{	 system("cls");
     start();
	int i,j,count=0,tot=r*c;
	 for(i=0;i<r;i++)
    {
	 	for(j=0;j<c;j++)
	 	{  
	 	if(p[i][j]==0)
	 	count++;
		 }
	}
 if(((float)count/(float)tot) > 0.5)
	{ printf("\n\nIT IS SPARSE MATRIX\n"); 	
	 *n=count;
	}
	else
	{
	printf("\n\nIT IS DENSE MATRIX\n"); 
	*n=0;
	}
	
}//sparsity

void represent(int r,int c,int p[r][c],int x)
{
int i,j,n,k=0;
				
	for(i=0;i<r;i++)
	{
        for(j=0;j<c;j++)
		{
            if (p[i][j]!=0)
			{
                rep[k].col=j;
                rep[k].row=i;
                rep[k].val=p[i][j];
                k++;
            }//if
        }//j loop
    }//i loop
nonzerodisplay(x);
}//representation

void nonzerodisplay(int n)
{  // system("cls");
    system("color 3");
   // start();
    int i,j;
    printf("\n\t\t\t................................OUTPUT.....................................\n\n");
    printf("\n\tROW\t\tCOLUMN\t\tVALUE\n");
    for(i=0;i<n;i++)
    printf("\n\t %d \t\t   %d \t\t  %d", rep[i].row+1,rep[i].col+1,rep[i].val);
	printf("\n\n");
    
printf("________________________________________________________________________________________________________________________\n");	
}//print rep

void search(int n)
{ int i,x,flag;
  char c ;
system("cls");
start();
	do
	{
	printf("\nEnter Element to be Searched : ");
	scanf(" %d",&x);
	flag=0;
	for(i=0;i<n;i++)
	if(rep[i].val==x)
	{ //system("cls");
	  //start();
	  system("color a");
	  printf("\nElement Found in Row %d and Column %d",rep[i].row+1,rep[i].col+1);
	  flag=1;
	}
	if(flag==0)
	{
	system("cls");
	start();
	system("color 4");
	printf("\nElement not Found");
	 
	}
	printf("\n\nTo Search Again Press 1 Otherwise Press any key : ");
	fflush(stdin);
	c=getchar();
	
	}while(c=='1');
	system("color 3");
}//search
