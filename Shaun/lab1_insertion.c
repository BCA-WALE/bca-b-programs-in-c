//1D Integer Array insertion program //

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i,menuchoice,dtypechoice,elementcount,intarray[50],displaychoice,insertionchoice,intinsertionindex,intinsertionelement;
	int charelementcount,charinsertionelement,charinsertionindex;
	int floatinsertionindex,floatinsertionelement,floatelementcount;
	char exitchoice,chararray[50];
	float floatarray[50];
	do{
		system("cls");
		printf("\n\t\tProgram 1\n\n1.Add elements into a 1D Array\n2.Display the 1D array\n3.Insert elements in between the array\n4.Exit the Program\n\nEnter your choice: ");
		scanf("%d",&menuchoice);
		switch(menuchoice)
		{
			case 1:
				system("cls");
				printf("\n1.1D Integer Array\n2.1D Character Array\n3.1D Float Array\n\nEnter your choice: ");
				scanf("%d",&dtypechoice);
				switch(dtypechoice)
				{
					case 1:
						system("cls");
						printf("\nHow many elements do you wish to insert?\n:");
						scanf("%d",&elementcount);
						if(elementcount>50 || elementcount<=0)
						{
							printf("***Please enter the total element number within the range of 50!!***");
						}
						
						for(i=0;i<elementcount;i++)
						{
							printf("\nEnter element number %d: ",i);
							scanf("%d",&intarray[i]);
						}
						break;
					
					case 2:
						system("cls");
						printf("\nHow many elements do you wish to insert?\n:");
						fflush(stdin);
						scanf("%d",&charelementcount);
						if(charelementcount>50 || charelementcount<=0)
						{
							printf("***Please enter the total element number within the range of 50!!***");
						}
						
						for(i=0;i<charelementcount;i++)
						{
							fflush(stdin);
							printf("\nEnter element number %d: ",i);
							scanf("%c",&chararray[i]);
						}
						break;
					
					case 3:
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
							scanf("%f",&floatarray[i]);
						}
						break;
				}
				printf("\n\nDo you want to go back to the main menu?[Y/N]\n:");
				fflush(stdin);
				scanf("%c",&exitchoice);
				break;
				
			case 2:
					system("cls");
					printf("\n1.1D Integer Array\n2.1D Character Array\n3.1D Float Array\n\nEnter your choice: ");
					scanf("%d",&displaychoice);
					switch(displaychoice)
					{
						case 1:
							for(i=0;i<elementcount;i++)
							{
								printf("\nElement No. %d : %d",i,intarray[i]);	
							}
							break;
							
						case 2:
							for(i=0;i<charelementcount;i++)
							{
								printf("\nElement No. %d : %c",i,chararray[i]);	
							}
							break;
						
						case 3:
							for(i=0;i<floatelementcount;i++)
							{
								printf("\nElement No. %d : %f",i,floatarray[i]);	
							}
							break;
					}
					printf("\n\nDo you want to go back to the main menu?[Y/N]\n:");
					fflush(stdin);
					scanf("%c",&exitchoice);
					break;
			
			case 3:
				system("cls");
				printf("\n1.1D Integer Array\n2.1D Character Array\n3.1D Float Array\n\nEnter your choice: ");
				scanf("%d",&insertionchoice);
				switch(insertionchoice)
				{
					case 1:
						system("cls");
						printf("Enter the index number in which you want to insert your new element\n:");
						scanf("%d",&intinsertionindex);
						printf("\nEnter the element you want to add\n:");
						scanf("%d",&intinsertionelement);
							for(i=elementcount-1;i>=intinsertionindex-1;i--)
							{
								intarray[i+1]=intarray[i];
							}
							intarray[intinsertionindex] = intinsertionelement;
							elementcount++;
						break;
					
					case 2:
						system("cls");
						printf("Enter the index number in which you want to insert your new element\n:");
						scanf("%d",&charinsertionindex);
						printf("\nEnter the element you want to add\n:");
						fflush(stdin);
						scanf("%c",&charinsertionelement);
							for(i=charelementcount-1;i>=charinsertionindex-1;i--)
							{
								chararray[i+1]=chararray[i];
							}
							chararray[charinsertionindex] = charinsertionelement;
							charelementcount++;
						break;
					case 3:
						system("cls");
						printf("Enter the index number in which you want to insert your new element\n:");
						scanf("%d",&floatinsertionindex);
						printf("\nEnter the element you want to add\n:");
						scanf("%f",&floatinsertionelement);
							for(i=floatelementcount-1;i>=floatinsertionindex-1;i--)
							{
								floatarray[i+1]=floatarray[i];
							}
							intarray[floatinsertionindex] = floatinsertionelement;
							floatelementcount++;
						break;

						
						printf("\n\nDo you want to go back to the main menu?[Y/N]\n:");
						fflush(stdin);
						scanf("%c",&exitchoice);
						break;
				 
						
				}
		}
	
	}while(exitchoice=='y' || exitchoice=='Y');
}

