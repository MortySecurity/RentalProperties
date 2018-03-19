#include <stdlib.h>
#include "Node.h"

int getCount( Node *pHead )//counts list, returns num of items in list
{
	int count = 0;
	Node *pCounter = pHead;
	
	while( pCounter != NULL)
	{
		count++;
		*pCounter = *pCounter->pNextNode;
	}
	
	return count;
}

Node *getNodeAtIndex( Node *pHead, int i )//finds item in list by number, returns said item
{
	Node *pCounter = pHead;
	for(int a = 0; a < i; a++)
	{
		*pCounter = *pCounter->pNextNode;
	}
	
	return pCounter;
}

void appendNode( Node **ppHead, Node *pNewNode )//adds to end of list
{
	Node *pCounter = *ppHead;
	while( pCounter->pNextNode != NULL)
	{
		*pCounter = *pCounter->pNextNode;
	}
	*pCounter->pNextNode = *pNewNode;
}

void insertNode( Node **ppHead, Node *pNewNode, int i )//add node to location
{
	Node *pCounter = *ppHead;
	
	for(int a; a < i; a++)
	{
		*pCounter = *pCounter->pNextNode;
	}
	
	*pNewNode->pNextNode = *pCounter->pNextNode;
	*pCounter->pNextNode = *pNewNode;
	
}

Node *removeNodeAtIndex( Node **ppHead, int i )//remove node at i position, returns said node
{
	Node *pCounter = *ppHead;
	
	for(int a; a < i-1; a++)
	{
		*pCounter = *pCounter->pNextNode;
	}
	Node* pRemoveNode = pCounter->pNextNode;
	*pCounter->pNextNode = *pRemoveNode->pNextNode;
	
	return pRemoveNode;
}
