#include <stdio.h>
#include <stdlib.h>
#include "typedef.h"
#include "struct.h"
#define datatype u16
u8 CheckID(List* L, datatype ID)
{
	/*Check for empty list*/
	if(L->Head==NULL)		
	{
		return 0;
	}else{ /*if not empty check if ID exists*/
		Node* Current=L->Head;
		while(Current!=NULL){
			if(Current->ID!=ID)
			{
				Current=Current->Next;
			}else{
				return 1;
			}
		}
		return 0;
	}
}


void ViewReservations(List* L,u8* Slots)
{	
	/*Check for empty list*/
	if(L->Head==NULL)		
	{
		printf("\nList is empty");
	}else{
		u8 i;
		/*printing slot times*/
		printf("\n      Slot Times           ");
		printf("\n---------------------------");
		printf("\nSlot 1: 2PM-2:30PM");
		printf("\nSlot 2: 2:30PM-3PM");
		printf("\nSlot 3: 3PM-3:30PM");
		printf("\nSlot 4: 3:30PM-4PM");
		printf("\nSlot 5: 4:30PM-5PM");
		printf("\n---------------------------");
		/*Printing reservations*/
		printf("\n       Reservations        ");
		for(i=0;i<5;i++){/*loop over 5 slots and check everyslot and which ID its assigned to*/
			if(!*(Slots+i)){
				Node* Current=L->Head;
				while(Current!=NULL){
					if(Current->Slot!=i)
					{
						Current=Current->Next;
					}else{
						printf("\nSlot %d |-| ID: %d ",i+1,Current->ID);
						break;
					}
				}
			}else{/*if no ID is assigned to it then print not reserved*/
				printf("\nSlot %d |-| ID: %s ",i+1,"Not reserved..!");
			}
		}
		printf("\n---------------------------");
	}
}



void CancelSlot(List* L,u8* Slots){
	printf("\nRemoving slot...");
	u16 ID=0;
	u8 Decision=0;
	do{
		/*get patient id and check if it exists*/
		printf("\nPatient ID: ");
		scanf(" %d",&ID);
		if(CheckID(L,ID)){
			Node* Current=L->Head;
			while(Current!=NULL)
			{
				if(Current->ID!=ID)
				{
					Current=Current->Next;
				}else{
					system("cls");
					if(Current->Slot!=6){
						*(Slots+(Current->Slot))=Current->Slot;
						Current->Slot=6;
						printf("\nPatient slot removed...!\n.\n.");
					}else{
						printf("\nPatient has no slots reserved...!\n.\n.");
					}
					Decision = 'n';
					break;
				}
			}
		}else{
			system("cls");
			printf("\nID not found...!");
			printf("\nWould you like to try again?(Y/N): ");
			scanf(" %c",&Decision);
		}
	}while(Decision =='Y' || Decision == 'y');
}

void ReserveSlot(List* L,u8* Slots)
{
	printf("\nReserving doctor slot...");
	u16 ID=0;
	u8 Decision=0;
	do{
		/*get patient id and check if it exists*/
		printf("\nPatient ID: ");
		scanf(" %d",&ID);
		if(CheckID(L,ID)){
			Node* Current=L->Head;
			while(Current!=NULL)
			{
				if(Current->ID!=ID)
				{
					Current=Current->Next;
				}else{
					system("cls");
					printf("\nPlease select slot to reserve:-");
					printf("\nSlot 1: 2PM-2:30PM");
					printf("\nSlot 2: 2:30PM-3PM");
					printf("\nSlot 3: 3PM-3:30PM");
					printf("\nSlot 4: 3:30PM-4PM");
					printf("\nSlot 5: 4:30PM-5PM");
					u8 i;		
					printf("\n---------------------------");
					printf("\nSlots :");
					for(i=0;i<5;i++){
						if(*(Slots+i)){
							printf(" %d |",*(Slots+i));
						}else{
							printf("%s|","N/A");
						}
					}
					printf("\n---------------------------");
					printf("\nSelection: ");
					scanf(" %d",&Decision);
					if(Decision<1||Decision>5||*(Slots+(Decision-1))==0||Current->Slot!=6){
						printf("\nInvalid input...!\n.");
						printf("\nNo slot reserved...!\n.\n.");
						break;
					}else{
						Current->Slot=Decision-1;
						*(Slots+(Decision-1))=0;
						printf("\nSlot %d reserved...!",Decision);
						break;
					}
				}
			}
		}else{
			//system("cls");
			printf("\nID not found...!");
			printf("\nWould you like to try again?(Y/N): ");
			scanf(" %c",&Decision);
		}
	}while(Decision =='Y' || Decision == 'y');
}


void PrintNode(List* L)
{
	u16 ID =0;
	printf("\nPlease enter patient ID: ");
	scanf(" %d",&ID);
	if(L->Head==NULL)		
	{
		printf("\nList is empty");
	}else{
		Node* Current=L->Head;
		while(Current!=NULL)
		{
			if(Current->ID!=ID)
			{
				Current=Current->Next;
			}else{
				printf("\nPatient");
				printf("\nName  : %s %s",Current->FirstName,Current->LastName);
				printf("\nID    : %d",Current->ID);
				printf("\nAge   : %d",Current->Age);
				printf("\nGender: %c",Current->Gender);
				if(Current->Slot==0){
					printf("\nSlot 1: 2PM-2:30PM");
				}else if(Current->Slot==1){
					printf("\nSlot 2: 2:30PM-3PM");
				}else if(Current->Slot==2){
					printf("\nSlot 3: 3PM-3:30PM");
				}else if(Current->Slot==3){
					printf("\nSlot 4: 3:30PM-4PM");
				}else if(Current->Slot==4){
					printf("\nSlot 5: 4:30PM-5PM");
				}else{
					printf("\nSlot  : Not yet reserved...!");
				}
				break;
			}
		}
	}
}

void CreateList(List* L)
{
	L->Head=NULL;
	L->Size=0;
}

void AddNode(List* L)
{
	printf("\nAdding new patient...");
	u16 ID=0;
	u8 Decision=0;
	do{
		printf("\nDesired patient ID: ");
		scanf(" %d",&ID);
		if(!CheckID(L,ID)||L->Head==NULL){
			Node* Patient=(Node*)malloc(sizeof(Node));
			Patient->ID=ID;
			printf("\nEnter patient age: ");
			scanf(" %d",&Patient->Age);

			printf("\nEnter patient first name: ");
			scanf(" %s",&Patient->FirstName);

			printf("\nEnter patient last name: ");
			scanf(" %s",&Patient->LastName);

			printf("\nEnter patient gender(M/F): ");
			scanf(" %c",&Patient->Gender);
			Patient->Slot=6;
			Patient->Next=L->Head;
			L->Head=Patient;
			printf("\nNew patient added sucessfully...!");
			L->Size++;
			break;
		}else{
			system("cls");
			printf("\nID already in use...!");
			printf("\nWould you like to try again?(Y/N)");
			scanf(" %c",&Decision);
		}
	}while(Decision =='Y' || Decision == 'y');
}

void EditNode(List* L)
{
	printf("\nEditing patient data...");
	u16 ID=0;
	u8 Decision=0;
	do{
		printf("\nPatient ID: ");
		scanf(" %d",&ID);
		if(CheckID(L,ID)){
			Node* Current=L->Head;
			while(Current!=NULL){
				if(Current->ID!=ID){
					Current=Current->Next;
				}else{
					printf("\nPlease select item to edit:-");
					printf("\nAge: 1");
					printf("\nFirst Name: 2");
					printf("\nLast Name: 3");
					printf("\nGender: 4");
					printf("\nSelection: ");
					scanf(" %d",&Decision);
					if(Decision==1){
						system("cls");
						printf("\nCurrent age: %d",Current->Age);
						printf("\nNew age: ");
						scanf(" %d",&Current->Age);
						printf("\nPatient age changed to %d...!",Current->Age);
					}else if(Decision==2){						
						system("cls");
						printf("\nCurrent first name: %s",Current->FirstName);
						printf("\nNew first name: ");
						scanf(" %s",&Current->FirstName);
						printf("\nPatient first name changed to %s...!",Current->FirstName);
					}else if(Decision==3){						
						system("cls");
						printf("\nCurrent last name: %s",Current->LastName);
						printf("\nNew last name: ");
						scanf(" %s",&Current->LastName);
						printf("\nPatient last name changed to %s...!",Current->LastName);
					}else if(Decision==4){						
						system("cls");
						printf("\nCurrent gender: %c",Current->Gender);
						printf("\nNew gender (M/F): ");
						scanf(" %c",&Current->Gender);
						printf("\nPatient gender changed to %c...!",Current->Gender);
					}else{						
						system("cls");
						printf("\nIncorrect input...!");
						printf("\nGoing back to main screen...\n.\n.\n.");
					}
					Decision = 'n';
					break;
				}
			}
		}else{
			system("cls");
			printf("\nID not found...!");
			printf("\nWould you like to try again?(Y/N): ");
			scanf(" %c",&Decision);
		}
	}while(Decision =='Y' || Decision == 'y');
}

void Authentication(u8 *Status)
{	
	u16 Mode=0;
	u16 Pw=0;
	while(*Status==0)
	{	
		printf("\nPlease choose acess mode...!");
		printf("\nPatient Mode: 0 | Admin Mode: 1");
		printf("\nDesired Mode: ");
		scanf(" %d",&Mode);
		if(Mode==0){
			*Status=0;
			system("cls");
			printf("\nPatient mode...!");
			break;
		}else if(Mode==1){
			system("cls");
			printf("\nAdmin mode...!");
			u8 Flag=0;
			printf("\nPlease enter admin password: ");
			for(Flag=0;Flag<3;Flag++)
			{
				scanf(" %d",&Pw);
				if(Pw==1234){
					*Status=1;
					system("cls");
					printf("\nAdmin acess authorized..!");
					Flag=0;
					break;
				}else if(Flag !=2){
					printf("\nInvalid password..! %d more attempt/s  left..!",2-Flag);	
					printf("\nTry again: ");
					*Status=0;
				}else if(Flag == 2){
					system("cls");
					printf("\nFailed to authenticate...!");
					printf("\nGoing back to main screen...\n.\n.\n.");
					*Status=0;
				}
			}
		}else{
			*Status=0;
			system("cls");
			printf("\nInvalid input! \nPlease enter 0 for Patient or 1 for Admin...!");
			printf("\nGoing back to main screen...\n.\n.\n.");
		}
	}
}

