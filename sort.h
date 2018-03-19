#ifndef SORT_H_
#define SORT_H_

void swap( Node *pNode_A, Node *pNode_B);

int (*pComparator) ( RentalProperty *a, RentalProperty *b);


struct _Node{
	RentalProperty *pRental;
	struct _Node *pNext;
} Node;

int compareByRent(propertyValues firstRoomVal, propertyValues secondRoomVal);
int compareByAddress(propertyValues firstRoomVal, propertyValues secondRoomVal);
int sortByRent(propertyValues publicRooms[], int n);
void sortyByRent(propertyValues publicRooms[],int n);
void sortByRooms(propertyValues publicRooms[], int n);
void sortByAddress(propertyValues publicRooms[], int n);



#endif
