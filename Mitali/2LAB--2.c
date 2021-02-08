//DS Program 2 Deletion
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<ctype.h>
struct library
{
  char bn[50],an[50];
  int id;
 	
};typedef struct library lib;

void start();
void input(lib *p,int *n);
void display(lib *p,int *n);
void del(lib p[], int *n);
void insert(lib p[],int *n,int *a);
void sentinel(lib p[],int *n);

void main()
{

int n,a;
char c;
start();
system("color 3");

dot1 :
	printf("\n\nEnter No. of Books in the Database : ");
	scanf("%d",&n);
		if(n<=0)
  		{
		system("color 4");
		printf("\n\aInvalid Input!!\nNumber of Books should be greater than Zero.");
		goto dot1;
		}
system("color a");
a=n+50;
lib* l=(lib*)malloc(a*sizeof(lib));
lib *ptr;
ptr = l;
	input(ptr,&n);
		do
		{
    		printf("\n\nMENU");
			printf("\n1.Display the Data");
			printf("\n2.Insert New Values in Database");
			printf("\n3.Delete values from Database");
			printf("\n4.Exit\nYour Choice : ");
			fflush(stdin);	
			c=getchar();
				if(!isdigit(c))
				{
				system("cls");
				start();
				system("color 4");
				printf("\n\aEnter a Digit.");
				}
				else
				{
					switch(c)
						{
							case '1':
								display(ptr,&n);
							    break;
							case '2':
								insert(l,&n,&a);
								break;
							case '3':
								del(l,&n);
								break;
							case '4':
							    break;
							default :
								system("cls");
								start();
								system("color 4");
								printf("\n\aChoose Between 1,2,3,4.\n");
						}//switch
				}//else
		}while(c!='4');
printf("\nLAB TASK 2 COMPLETED!!");
}//main

void start()
{
	printf("\n");
	printf("\t\t\t\t\t\t LIBRARY DATABASE\n");
	printf("________________________________________________________________________________________________________________________\n");	
}//start

void input(lib *p,int *n)
{   
	int i;
    system("cls");
    start();
    printf("\n\t\t\t..................................INPUT.....................................\n\n");
	for(i=0;i<*n;i++,p++)
		{
		  printf("\n\nEnter Details of Book %d :\n",(i+1));	
		  fflush(stdin);
		  printf("Enter Book Name : ");
		  gets(p->bn);
		  fflush(stdin);	
		  printf("Enter Author Name : ");
		  gets(p->an);
		  printf("Enter Book Id : ");
		  scanf("%d",&p->id);  		
		}
	system("cls");
	start();	
}//input

void display(lib *p,int *n)
{   system("cls");
    system("color 3");
    start();
    int i;
    printf("\n\t\t\t................................OUTPUT.....................................\n");
	for(i=0;i<*n;i++,p++)
	{   
	    printf("\nBOOK NO.    : %d",(i+1));
		printf("\nBOOK NAME   : %s",p->bn);
		printf("\nAUTHOR NAME : %s",p->an);
		printf("\nBOOK ID     : %d\n",p->id);	
	}	
printf("________________________________________________________________________________________________________________________\n");	
}//display

void del(lib p[], int *n)
{   int x,i;
char c;
    system("cls");
    system("color a");
    start();
    	do
  	{
	printf("\n\nMENU");
	printf("\n1.Delete by Position\n");
	printf("2.Delete by Name or Id\n");
	printf("3.Exit\nYour Choice : ");
	fflush(stdin);	
			c=getchar();
				if(!isdigit(c))
				{
				system("cls");
		 		start();
				system("color 4");
				printf("\n\aEnter a Digit.");
				}
				else
				{
					switch(c)
						{ 
							case '1':
									dot2: 
									printf("\nEnter the Position from which the Data is to be Deleted : ");
									scanf("%d",&x);
									if(x<1||x>*n)
									{
										system("color 4");
								        printf("\n\aInvalid Input!!\nEnter a valid Book No.\n");
									    goto dot2;
									}//if
									else
									{
										system("color 3");
										x=x-1; 
									       	for(i=x;i<*n;i++)
										    {  
										    	strcpy(p[i].bn,p[i+1].bn);	
										    	strcpy(p[i].an,p[i+1].an);
										    	p[i].id = p[i+1].id	;
											}   	
										*n=*n-1; 
										system("cls");
										start();
										printf("\nDATABASE UPDATED!!\n");
									}//else	
									break;
							case '2':
								    sentinel(p,n);
									break;
							case '3':
									system("cls");
									system("color 3");
									break;
							default :
								system("cls");
								start();
								system("color 4");
								printf("\n\aChoose Between 1 and 2.\n");
						}//switch
				}//else
	}while(c!='3');
								
}//delete


void insert(lib p[],int *n,int *a)
{
	int x,i,o,y; lib *j;
    char bm[50],am[50];
    system("cls");
    system("color 2");
    start();
    y=*n;
    
   	 dot3: 
		printf("\nEnter the Position where you want to Insert the Data Into the Database : ");
		scanf("%d",&x);
		if(x<1 || x>(*n+1) || (*n+1)>=*a)
		{
			system("color 4");
	       	printf("\n\aEither the Array is full or Position Entered was Beyond Array Size.\nTherefore, No New Element can be entered in this Array.\n");
	        goto dot3;
		}//if
		else
		{  
			system("color 3");
			*n=*n+1;
			x=x-1;
				printf("\nEnter Data of the New Book\n");
			    fflush(stdin);
			    printf("Enter Book Name : ");
			    gets(bm);
			    fflush(stdin);	
			    printf("Enter Author Name : ");
			    gets(am);
			    printf("Enter Book Id : ");
			    scanf("%d",&o); 
				    while(y>=x)	
			   		{
				    	strcpy(p[y+1].bn,p[y].bn);
				    	strcpy(p[y+1].an,p[y].an);
				    	p[y+1].id=p[y].id;
				    	y=y-1;
					}//while
		   
			   strcpy(p[x].bn,bm);
			   strcpy(p[x].an,am);
			   p[x].id = o;
	
			system("cls");
			start();
			printf("\nDATABASE UPDATED!!\n");
		
	    }//else
}//insert 

void sentinel(lib p[],int *n)
{ 
int flag,x,lid,i,j,k;
char temp[50],lname[50],c;
system("cls");
start();
system("color 3");

	printf("\n\nMENU");
	printf("\n1.Delete by Id\n");
	printf("2.Delete by Book Name\n");
	printf("Your Choice : ");
	fflush(stdin);	
			c=getchar();
				if(!isdigit(c))
				{
				system("cls");
				start();
				system("color 4");
				printf("\n\aEnter a Digit.");
				}
				else
				{
					switch(c)
						{
							case '1':
								system("cls");
								start();
								system("color 3");
								printf("\nEnter Id No. to be Deleted : ");
							 	scanf("%d",&x);
							 	//sentinel search
								lid = p[*n-1].id;
								p[*n-1].id=x;
								i=0;
								for(k=0;k<*n;k++)
								{
									while(p[i].id!=x)
									{ 
									  i++;	
									}
								p[*n-1].id=lid;
									if(i<(*n-1)||x==p[*n-1].id)
									{
										system("color 3");
									 
									       	for(j=i;j<*n;j++)
										    {  
										    	strcpy(p[j].bn,p[j+1].bn);	
										    	strcpy(p[j].an,p[j+1].an);
										    	p[j].id = p[j+1].id	;
											}   	
										*n=*n-1; 
										system("cls");
										start();
										printf("\nDATABASE UPDATED!!\n");
										i++;
									}
									else
									{system("cls");
									system("color 4");
									 printf("\n\nNo Student of this Id Present in the Database!!\n");
								    }
								}//for loop 
								break;
								
							case '2':
								system("cls");
								start();
								system("color 3");
								printf("\nEnter Name to be Deleted : ");
								fflush(stdin);
							    gets(temp);
							    strcpy(lname,p[*n-1].bn);
							    strcpy(p[*n-1].bn,temp);  
							    i=0;
							    for(k=0;k<*n;k++)
								{
								    while(strcmp(p[i].bn,temp)!=0)
										{ 
										  i++;	
										}
								strcpy(p[*n-1].bn,lname);
									if(i<(*n-1)||strcmp(p[i].bn,temp)==0)
									{ 
										system("color 3");
									 
									       	for(j=i;j<*n;j++)
										    {  
										    	strcpy(p[j].bn,p[j+1].bn);	
										    	strcpy(p[j].an,p[j+1].an);
										    	p[j].id = p[j+1].id	;
											}   	
										*n=*n-1; 
										system("cls");
										start();
										printf("\nDATABASE UPDATED!!\n");
									    i++;
								    }
									else
									{
									system("cls");
									system("color 4");
									printf("\n\nNo Student of this Name Present in the Database!!\n");
								    }
								}//for
								    
									break;
									
							default :
								system("cls");
								start();
								system("color 4");
			     				printf("\n\aChoose Between 1 and 2.\n");	
						}//switch
				}//else   
}//sentinel search and delete
