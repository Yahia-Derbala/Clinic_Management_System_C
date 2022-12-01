/*includes for printf & scanf and user defined functions*/
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "typedef.h"

void main()
{		
	printf("\nClinic Management System by Yahia Emad");
	/*Status flag 0 for patient, 1 for admin*/
	u8 Status=0;
	u8 Selection=0;
	u8 Decision=0;
	u8 Slots[5]={1,2,3,4,5};
	/*Creating a list of patients struct*/
	List List;
	/*Initializing the list*/
	CreateList(&List);
	do{
		/*Mode selection and authentication*/
		Authentication(&Status);
		/*if admin acess authorized*/
		if(Status){
			/*prompt for admin features*/
			printf("\nPlease select one of the following options:-");
			printf("\nAdd new patient record: 1");
			printf("\nEdit patient record: 2");
			printf("\nReserve a slot with the doctor: 3");
			printf("\nCancel reservation: 4");
			printf("\nSelection: ");
			scanf(" %d",&Selection);
			/*check desired admin feature and exectue coressponding function*/
			switch(Selection)
			{
				case 1:
				system("cls");
				printf("\nAdd new patient selected...!");
				AddNode(&List);
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
				case 2:
				system("cls");
				printf("\nEdit patient selected...!");
				EditNode(&List);
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
				case 3:
				system("cls");
				printf("\nReserve slot with doctor selected...!");
				ReserveSlot(&List,Slots);
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
				case 4:
				system("cls");
				printf("\nCancel reservation selected...!");
				CancelSlot(&List,Slots);
				printf("\n.\n.\nGoing back to main screen...\n.\n.\n.");
				break;
				default:
				system("cls");
				printf("\nIncorrect input...!");
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
			}
		}else{ /*else prompt for patient features*/
			printf("\nPlease select one of the following options:-");
			printf("\nView  patient record: 1");
			printf("\nView today's reservations: 2");
			printf("\nSelection: ");
			scanf(" %d",&Selection);
			/*check patient features and coresspoding functions*/
			switch(Selection)
			{
				case 1:
				system("cls");
				printf("\nView patient record selected...!");
				PrintNode(&List);
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
				case 2:
				system("cls");
				printf("\nView today's reservations selected...!");
				ViewReservations(&List,Slots);
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
				default:
				system("cls");
				printf("\nIncorrect input...!\n.\n.");
				printf("\nGoing back to main screen...\n.\n.\n.");
				break;
			}
		}
		Selection=0;
		printf("\nWould you like to do something else?(Y/N): ");
		scanf("  %c",&Decision);
		system("cls");
	}while (Decision == 'y' || Decision == 'Y'); // Checks if user wants to continue
	printf("\nThank you for using Clinic Management System...!\n.\n.\n.\nExiting...");
}
