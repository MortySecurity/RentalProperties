#ifndef Node_H_   /* Include guard */
#define Node_H_


int getCount( Node *pHead );

Node *getNodeAtIndex( Node *pHead, int i );

void appendNode( Node **ppHead, Node *pNewNode );

void insertNode( Node **ppHead, Node *pNewNode, int i );

Node *removeNodeAtIndex( Node **ppHead, int i );


typedef struct Node
{
	Rental thisRental;
	Node *pNextNode;
}


#endif
