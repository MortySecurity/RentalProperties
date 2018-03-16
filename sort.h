#ifndef SORT_H_
#define SORT_H_

void swap( Node *pNode_A, Node *pNode_B);

int (*pComparator) ( RentalProperty *a, RentalProperty *b);


struct _Node{
	RentalProperty *pRental;
	struct _Node *pNext;
} Node;




#endif
