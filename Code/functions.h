#include "typedef.h"
#define datatype u16
#include "struct.h"
/*Linked list functions*/
void CreateList(List* L);
void PrintNode(List* L);
void AddNode(List* L);
void EditNode(List* L);
void DeleteNodeID(List* L,datatype ID);
u8 CheckID(List* L,datatype ID);


/*General functions*/
void Authentication(u8 *Status);

/*Admin functions*/
void AddNewPatient(List* L);
void EditPatient(List* L);
void ReserveSlot(List* L,u8* Slots);
void CancelSlot(List* L,u8* Slots);

/*Patient functions*/
void ViewPatient(List* L);
void ViewReservations(List* L,u8* Slots);




