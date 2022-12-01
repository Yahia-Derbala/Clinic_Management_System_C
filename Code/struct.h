#include "typedef.h"
/*Nodes and Lists*/
typedef struct Node
{
	u16 ID;
	u8 FirstName[50];
    u8 LastName[50];
	u8 Age;
	u8 Gender;
	u8 Slot;
	struct Node* Next;
}Node;

typedef struct List 
{
	Node* Head;
	u8 Size;
}List;