#ifndef Node_H_   /* Include guard */
#define Node_H_

void createRental();
void moveRental(); 


typedef struct Rental
{
	int streetNum;
	Street *pStreet;
	int room;
	int rent;
};

typedef struct Node
{
	Rental *pnextNode;
}

#endif