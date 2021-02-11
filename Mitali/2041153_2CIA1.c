//DS LAB CIA 1
//2041153
#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<ctype.h>
#define S 30

struct Employee
{
	int id,age;
	char name[S],des[S];
};typedef struct Employee emp;

void start();
void input(emp *p,int *n);
void display(emp *p,int *n);
void sort(emp p[],int *n);
void binary(emp p[],int *n);
void del(emp p[],int *n);

int main(void)
{

int n;
char c;
start();
system("color 3");

dot :
	printf("\n\nEnter No. of Employees in the Database : ");
	scanf("%d",&n);
		if(n<=0)
		{
			system("color 4");
			printf("\n\aInvalid Input!!\nNumber of Employees should be greater than Zero.");
			goto dot;
		}
system("color a");
emp* s=(emp*)malloc(n*sizeof(emp));
emp *ptr;
ptr = s;
input(ptr,&n);

		do
		{
    		printf("\n\nMENU");
    		printf("\n1.Enter New the Data");
			printf("\n2.Display the Data");
			printf("\n3.To Search Data using Binary Search");
			printf("\n4.To Delete the Data");
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
									printf("\n\nEnter No. of Employees in the Database : ");
									scanf("%d",&n);
										if(n<=0)
								  		{
										system("color 4");
										printf("\n\aInvalid Input!!\nNumber of Employees should be greater than Zero.");
										goto dot1;
										}
								system("color a");
								s=(emp*)realloc(s,n*sizeof(emp));
								ptr = s;
								input(ptr,&n);
								break;
							case '2':
							  display(ptr,&n);
							    break;
							case '3':
								binary(s,&n);
								break;
							case '4':
								del(s,&n);
							    break;
							case '5':
								system("cls");
								start();
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
printf("\nCIA 1 TASK COMPLETED!!");
return 0;
}//main

void start()
{
	printf("\n");
	printf("\t\t\t\t\t\t EMPLOYEE DATABASE\n");
	printf("________________________________________________________________________________________________________________________\n");	
}//start

void input(emp *p,int *n)
{   
	int i;
    system("cls");
    start();
    printf("\n\t\t\t..................................INPUT.....................................\n\n");
	for(i=0;i<*n;i++,p++)
		{
		  printf("\n\nEnter Details of Employee %d :\n",(i+1));
		  printf("Enter Employee Id : ");
		  scanf(" %d",&p->id);	
		  fflush(stdin);
		  printf("Enter Employee Name : ");
		  gets(p->name);
		  fflush(stdin);	
		  printf("Enter Employee Designation : ");
		  gets(p->des);
		  printf("Enter Employee Age : ");
		  scanf("%d",&p->age);  		
		}
	system("cls");
	start();	
}//input

void display(emp *p,int *n)
{   system("cls");
    system("color 3");
    start();
    int i;
    printf("\n\t\t\t................................OUTPUT.....................................\n");
	for(i=0;i<*n;i++,p++)
	{   printf("\nEMPLOYEE NO.         : %d",(i+1));
	    printf("\nEMPLOYEE ID          : %d",p->id);
		printf("\nEMPLOYEE NAME	     : %s",p->name);
		printf("\nEMPLOYEE DESIGNATION : %s",p->des);
		printf("\nEMPLOYEE AGE         : %d\n",p->age);	
	}	
printf("________________________________________________________________________________________________________________________\n");	
}//display

void sort(emp p[],int *n)
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
            
            strcpy(temp, p[j].des);
            strcpy(p[j].des, p[j+1].des);
            strcpy(p[j+1].des, temp);
            
            t=p[j].id;
            p[j].id = p[j+1].id;
            p[j+1].id = t;
            
            t=p[j].age;
            p[j].age = p[j+1].age;
            p[j+1].age = t;
            
         }//if
        }//j loop
    }//i loop		
}//sort acc to id no.

void binary(emp p[],int *n)
{ 
system("cls");
start();
system("color 3");
  char c,temp[S];
  int x,s,e,m,flag;
	do
  	{
	printf("\n\nMENU");
	printf("\n1.Search by Employee Id\n");
	printf("2.Exit\nYour Choice : ");
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
							  sort(p,n);
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
									 //strcpy(temp, p[m].name);
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
								 printf("\n\nNo Employee of this Id Present in the Database!!\n");
							    }
						        else
						        {system("color 2");
								 printf("\n\nEmployee Id Present in the Database!!\n\nDetails : \n\n");
								 printf("\nEMPLOYEE ID          : %d",p[m].id);
							     printf("\nEMPLOYEE NAME	     : %s",p[m].name);
								 printf("\nEMPLOYEE DESIGNATION : %s",p[m].des);
								 printf("\nEMPLOYEE AGE         : %d\n",p[m].age);	
							    }
							    break;
							case '2':
								system("cls");
								system("color 3");
								start();
								break;
							default :
								system("cls");
								start();
								system("color 4");
								printf("\n\aChoose Between 1 and 2.\n");	
								
					}//switch
				}//else
				
	}while(c!='2');
}//binary search by id

void del(emp p[],int *n)
{ 
int flag,i,j;
char temp[50],lname[50],c;
system("cls");
start();
system("color 3");
 do
 {
	printf("\n\nMENU\n");
	printf("1.Delete by Employee Name\n");
	printf("2.Exit\n");
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
								printf("\nEnter Name to be Deleted : ");
								fflush(stdin);
							    gets(temp);
							    strcpy(lname,p[*n-1].name);
							    strcpy(p[*n-1].name,temp);  
							    i=0;
								    while(strcmp(p[i].name,temp)!=0)
										{ 
										  i++;	
										}
								strcpy(p[*n-1].name,lname);
									if(i<(*n-1)||strcmp(p[i].name,temp)==0)
									{ 
										system("color 3");
									 
									       	for(j=i;j<*n;j++)
										    {  
										    	strcpy(p[j].name,p[j+1].name);	
										    	strcpy(p[j].des,p[j+1].des);
										    	p[j].id = p[j+1].id	;
										    	p[j].age = p[j+1].age	;
											}   	
										*n=*n-1; 
										system("cls");
										start();
										system("color a");
										printf("\nDATABASE UPDATED!!\nDISPLAY THE DATA TO VIEW THE UPDATES!!");
								    }//if
									else
									{
									system("cls");
									start();
									system("color 4");
									printf("\n\nNo Employee of this Name Present in the Database!!\n");
								    }//else
								break;
							case '2':
								system("cls");
								system("color 3");
								start();
								break;
									
							default :
								system("cls");
								start();
								system("color 4");
			     				printf("\n\aChoose Between 1 and 2.\n");	
						}//switch
				}//else
	}while(c!='2');   
}//delete by name
