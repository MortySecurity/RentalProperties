#ifndef Node_H_   /* Include guard */
#define Node_H_

typedef struct Node
{
	struct PropertRental thisRental;
	struct Node *pNextNode;
}Node;

int getCount( Node *pHead );

Node *getNodeAtIndex( Node *pHead, int i );

void appendNode( Node **ppHead, Node *pNewNode );

void insertNode( Node **ppHead, Node *pNewNode, int i );

Node *removeNodeAtIndex( Node **ppHead, int i );





#endif
