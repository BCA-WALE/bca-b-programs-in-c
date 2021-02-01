//1D Integer Array insertion program //

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,menuchoice,intelementcount,intdeletechoice,intarray[50],charelementcount,chardeletechoice,floatelementcount,floatdeletechoice;
	char exitchoice,chararray[50];
	float floatarray[50];
	do{
		system("cls");
		printf("\n\t\tProgram 1\n\n1.Integer Array Menu\n2.Character Array Menu\n3.Float Array Menu\n4.Exit the Program\n\nEnter your choice: ");
		scanf("%d",&menuchoice);
		switch(menuchoice)
		{
			case 1:
				system("cls");
				printf("\n1.Add Elements\n2.Display the Array\n3.Delete Elements\n\nEnter your choice: ");
				scanf("%d",&menuchoice);
				switch(menuchoice)
				{
					case 1:
						system("cls");
						printf("\nHow many elements do you wish to insert?\n:");
						scanf("%d",&intelementcount);
						if(intelementcount>50 || intelementcount<=0)
						{
							printf("***Please enter the total element number within the range of 50!!***");
						}
						
						for(i=0;i<intelementcount;i++)
						{
							printf("\nEnter element number %d: ",i);
							scanf("%d",&intarray[i]);
						}
						break;
					case 2:
						for(i=0;i<intelementcount;i++)
						{
							printf("\nIndex No. %d : %d",i,intarray[i]);	
						}
						break;
					case 3:
						system("cls");
						printf("Enter the index number for the element you want to remove:\n");
						for(i=0;i<intelementcount;i++)
						{
							printf("\nIndex No. %d : %d",i,intarray[i]);	
						}
						printf("\n\nEnter your choice:");
						scanf("%d",&intdeletechoice);
						for(i=intdeletechoice;i<intelementcount;i++)
						{
							intarray[i]=intarray[i+1];
						}
						intelementcount--;
						printf("\n\n***Element Deleted Successfully***\n\nUpdated Array:\n");
						for(i=0;i<intelementcount;i++)
						{
							printf("Element No. %d : %d\n",i,intarray[i]);	
						}
						break;
					}
					printf("\n\nDo you want to go back to the main menu?[Y/N]\n:");
					fflush(stdin);
					scanf("%c",&exitchoice);
					break;
	
			case 2:
				system("cls");
				printf("\n1.Add Elements\n2.Display the Array\n3.Delete Elements\n\nEnter your choice: ");
				scanf("%d",&menuchoice);
				switch(menuchoice)
				{
					case 1:
						system("cls");
						printf("\nHow many elements do you wish to insert?\n:");
						scanf("%d",&charelementcount);
						if(charelementcount>50 || charelementcount<=0)
						{
							printf("***Please enter the total element number within the range of 50!!***");
						}
						
						for(i=0;i<charelementcount;i++)
						{
							printf("\nEnter element number %d: ",i);
							fflush(stdin);
							scanf("%c",&chararray[i]);
						}
						break;
					case 2:
						for(i=0;i<charelementcount;i++)
						{
							printf("\nIndex No. %d : %c",i,chararray[i]);	
						}
						break;
					case 3:
						system("cls");
						printf("Enter the index number for the element you want to remove:\n");
						for(i=0;i<charelementcount;i++)
						{
							printf("\nIndex No. %d : %c",i,chararray[i]);	
						}
						printf("\n\nEnter your choice:");
						scanf("%d",&chardeletechoice);
						for(i=chardeletechoice;i<charelementcount;i++)
						{
							chararray[i]=chararray[i+1];
						}
						charelementcount--;
						printf("\n\n***Element Deleted Successfully***\n\nUpdated Array:\n");
						for(i=0;i<charelementcount;i++)
						{
							printf("Index No. %d : %c\n",i,chararray[i]);	
						}
						break;
					}
					printf("\n\nDo you want to go back to the main menu?[Y/N]\n:");
					fflush(stdin);
					scanf("%c",&exitchoice);
					break;
			
			case 3:
				system("cls");
				printf("\n1.Add Elements\n2.Display the Array\n3.Delete Elements\n\nEnter your choice: ");
				scanf("%d",&menuchoice);
				switch(menuchoice)
				{
					case 1:
						system("cls");
						printf("\nHow many elements do you wish to insert?\n:");
						scanf("%d",&floatelementcount);
						if(floatelementcount>50 || floatelementcount<=0)
						{
							printf("***Please enter the total element number within the range of 50!!***");
						}
						
						for(i=0;i<floatelementcount;i++)
						{
							printf("\nEnter element number %d: ",i);
							fflush(stdin);
							scanf("%f",&floatarray[i]);
						}
						break;
					case 2:
						for(i=0;i<floatelementcount;i++)
						{
							printf("\nIndex No. %d : %f",i,floatarray[i]);	
						}
						break;
					case 3:
						system("cls");
						printf("Enter the index number for the element you want to remove:\n");
						for(i=0;i<floatelementcount;i++)
						{
							printf("\nIndex No. %d : %f",i,floatarray[i]);	
						}
						printf("\n\nEnter your choice:");
						scanf("%d",&floatdeletechoice);
						for(i=floatdeletechoice;i<floatelementcount;i++)
						{
							floatarray[i]=floatarray[i+1];
						}
						floatelementcount--;
						printf("\n\n***Element Deleted Successfully***\n\nUpdated Array:\n");
						for(i=0;i<floatelementcount;i++)
						{
							printf("Index No. %d : %f\n",i,floatarray[i]);	
						}
						break;
					}
					printf("\n\nDo you want to go back to the main menu?[Y/N]\n:");
					fflush(stdin);
					scanf("%c",&exitchoice);
					break;
			
			case 4:
				exit(0);
				}
			}while(exitchoice=='y' || exitchoice=='Y');
				
		}

