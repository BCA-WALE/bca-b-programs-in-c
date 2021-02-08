//DS LAB 3 SENTINAL AND BINARY SEARCH
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<ctype.h>
#define S 30

struct student
{
	int id;
	char name[S];
	
};typedef struct student st;

void start();
void input(st *p,int *n);
void sortn(st p[],int *n);
void sortr(st p[],int *n);
void display(st *p,int *n);
void binary(st p[],int *n);
void sentinel(st p[],int *n);

void main()
{

int n;
char c;
start();
system("color 3");
		do
		{
    		printf("\n\nMENU");
    		printf("\n1.Enter the Data");
			printf("\n2.Display the Data");
			printf("\n3.To Search Data using Sentinel Search");
			printf("\n4.To Search Data using Binary Search");
			printf("\n5.Exit\nYour Choice : ");
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
								dot1 :
									printf("\n\nEnter No. of Students in the Database : ");
									scanf("%d",&n);
										if(n<=0)
								  		{
										system("color 4");
										printf("\n\aInvalid Input!!\nNumber of Students should be greater than Zero.");
										goto dot1;
										}
								system("color a");
								st* s=malloc(n*sizeof(st));
								st *ptr;
								ptr = s;
									input(ptr,&n);
								break;
							case '2':
							  display(ptr,&n);
							    break;
							case '3':
								sentinel(ptr,&n);
								break;
							case '4':
								binary(s,&n);
							    break;
							case '5':
								system("color 3");
							    break;
							default :
								system("cls");
								start();
								system("color 4");
								printf("\n\aChoose Between 1,2,3,4,5.\n");
						}//switch
				}//else
		}while(c!='5');
printf("\nLAB TASK 3 COMPLETED!!");
}//main

void start()
{
	printf("\n");
	printf("\t\t\t\t\t\t STUDENT DATABASE\n");
	printf("________________________________________________________________________________________________________________________\n");	
}//start

void input(st *p,int *n)
{   
	int i;char c;
    system("cls");
    start();
    printf("\n\t\t\t..................................INPUT.....................................\n\n");
	for(i=0;i<*n;i++,p++)
		{
		  printf("\n\nEnter Details of Student %d :\n",(i+1));
		  printf("Enter id No. : ");
		  scanf("%d",&p->id);  	
		  fflush(stdin);
		  printf("Enter Student Name : ");
		  gets(p->name);   		
		}
	system("cls");
	start();	
}//input

void sortn(st p[],int *n)
{ int i,j,t;
  char temp[30];

for (i=0; i<(*n); i++)
    {
    for (j=0; j<(*n-1); j++)
        {
        if (strcmp(p[j].name, p[j+1].name) > 0) 
         {
            strcpy(temp, p[j].name);
            strcpy(p[j].name, p[j+1].name);
            strcpy(p[j+1].name, temp);
            t=p[j].id;
            p[j].id = p[j+1].id;
            p[j+1].id = t;
            
         }//if
        }//j loop
    }//i loop	
}//sort acc to name

void sortr(st p[],int *n)
{
int i,j,t;
char temp[S];
for (i=0; i<(*n); i++)
    {
    for (j=0; j<(*n-1); j++)
        {
        if (p[j].id > p[j+1].id) 
         {
            strcpy(temp, p[j].name);
            strcpy(p[j].name, p[j+1].name);
            strcpy(p[j+1].name, temp);
            t=p[j].id;
            p[j].id = p[j+1].id;
            p[j+1].id = t;
            
         }//if
        }//j loop
    }//i loop		
} //sort acc to id no.

void display(st *p,int *n)
{   system("cls");
    system("color 3");
    start();
    int i;
    printf("\n\t\t\t................................OUTPUT.....................................\n");
	for(i=0;i<*n;i++,p++)
	{   
	    printf("\nROLL NO.     : %d",p->id);
		printf("\nSTUDENT NAME : %s\n",p->name);
		
	}	
printf("________________________________________________________________________________________________________________________\n");	
}//display 

void binary(st p[],int *n)
{ 
system("cls");
start();
system("color 3");
  char c,temp[S];
  int x,s,e,m,flag;
	do
  	{
	printf("\n\nMENU");
	printf("\n1.Search by Id\n");
	printf("2.Search by Name\n");
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
							  system("cls");
							  start();
							  system("color 3");
							  sortr(p,n);
							  printf("\nEnter Id to be Searched : ");
							  scanf("%d",&x);
							  s=0;
							  e=*n-1;
							  m=(s+e)/2;
							  flag=0;
								  while(s<=e)
								  {
								  	if(p[m].id==x)
								  	{
									 flag = 1;
									 strcpy(temp, p[m].name);
								  	 break;
								    }
								    else if(x>p[m].id)
								    {
								    	s=m+1;
								    	m=(s+e)/2;
									}
									else
									{
										e=m-1;
										m=(s+e)/2;
									} 
								  }//binary while
						        if(flag==0)
						        {
								 system("color 4");
								 printf("\n\nNo Student of this Id Present in the Database!!\n");
							    }
						        else
						        {system("color 2");
								 printf("\n\nStudent Id Present in the Database!!\n\nDetails : \n\nID   : %d\nNAME : %s\n\n",x,temp);	
							    }
							    break;
							case '2':
								system("cls");
								start();
								system("color 3");
								sortn(p,n);
								printf("\nEnter Name to be Searched : ");
								fflush(stdin);
							    gets(temp);
								  s=0;
								  e=*n-1;
								  m=(s+e)/2;
								  flag=0;
								  while(s<=e)
								  {
								  	if(strcmp(p[m].name,temp)==0)
								  	{
									 flag = 1;
									 x=p[m].id;
								  	 break;
								    }
								    else if(strcmp(p[m].name,temp)<0)
								    {
								    	s=m+1;
								    	m=(s+e)/2;
									}
									else
									{
										e=m-1;
										m=(s+e)/2; 
									} 
								  }//binary while
						        if(flag==0)
						        {system("color 4");
						         printf("\n\nNo Student of this Name Present in the Database!!\n");
						        }
						        else
						        {system("color 2");
						         printf("\n\nStudent Name Present in the Database!!\n\nDetails : \n\nID   : %d\nNAME : %s\n\n",x,temp);
							    }
								break;
							case '3':
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
}//binary search

void sentinel(st p[],int *n)
{ 
int flag,x,lid,i,count,j;
char temp[S],lname[S],c;
system("cls");
start();
system("color 3");
	do
  	{
	printf("\n\nMENU");
	printf("\n1.Search by Id\n");
	printf("2.Search by Name\n");
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
								system("cls");
								start();
								system("color 3");
								printf("\nEnter Id No. to be Searched : ");
							 	scanf("%d",&x);
							 	//sentinel search
								lid = p[*n-1].id;
								p[*n-1].id=x;
								i=0;count=0;
									while(p[i].id!=x)
									{ count++;
									  i++;	
									}
								p[*n-1].id=lid;
									if(i<(*n-1)||x==p[*n-1].id)
									{ system("color 2");
									  printf("\n\nStudent of this Id Present in the Database!!\n\nDetails : \n\nID   : %d\nNAME : %s\n\n",x,p[i].name);	
									}
									else
									{system("color 4");
									 printf("\n\nNo Student of this Id Present in the Database!!\n");
								    }
								    printf("\nNo. of Comparisons in Sentinel Search : %d\n",count);
									//linear search
									for(i=0,count=0;i<*n;i++)
									{   count++;
										if(p[i].id==x)
										break;
									}
									printf("No. of Comparisons in Linear Search : %d\n",count);
								break;
								
							case '2':
								system("cls");
								start();
								system("color 3");
								printf("\nEnter Name to be Searched : ");
								fflush(stdin);
							    gets(temp);
							    strcpy(lname,p[*n-1].name);
							    strcpy(p[*n-1].name,temp);  
							    i=0;count=0;
								    while(strcmp(p[i].name,temp)!=0)
										{ count++;
										  i++;	
										}
								strcpy(p[*n-1].name,lname);
									if(i<(*n-1)||strcmp(p[i].name,temp)==0)
									{ system("color 2");
									  printf("\n\nStudent Name Present in the Database!!\n\nDetails : \n\nID   : %d\nNAME : %s\n\n",p[i].id,temp);	
									}
									else
									{system("color 4");
									printf("\n\nNo Student of this Name Present in the Database!!\n");
								    }
								    printf("\nNo. of Comparisons in Sentinel Search : %d\n",count);
									//linear search
									for(i=0,count=0;i<*n;i++)
									{   count++;
										if(strcmp(p[i].name,temp) == 0)
										break;
									}
									printf("No. of Comparisons in Linear Search : %d\n",count);
								break;
							case '3':
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
    
}//sentinel search


