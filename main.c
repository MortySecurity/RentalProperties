/*
* Todd Hakvoort
* Lab4
* CST8234
*/

#include <stdio.h>
#include <stdlib.h>

#include <Node.h>
#include <Node.c>
#include <rent.h>
#include <rent.c>
#include <sort.h>
#include <sort.c>


int ranNum(int min, int max){ //simply returns a random number based on time and the min/max
int ranNum = rand()%(max + 1 - min) + min;
return ranNum;	
}

void help()//Print out a brief list all the available commands 
{
	printf("Valid commands are: \n");
	printf("	 h  - display this help \n");
	printf("	 a  - display all the rental properties on the current list  \n");
	printf("	 f  - switch to the favourites list \n");
	printf("	 d  - switch to the default list \n");
	printf("	 l  - 'swipe left' on the current rental property \n");
	printf("	 r  - 'swipe right' on the current rental property \n");
	printf("	 n  - skip to the next rental property \n");
	printf("	 sa - set the sorting to 'by address' \n");
	printf("	 sn - set the sorting to 'by number of rooms' \n");
	printf("	 sr - set the sorting to 'by rent' \n");
	printf("	 sd - set the sorting to 'by distance' \n");
	printf("	 q  - quit the program \n");
}

void all(Node **ppCurrentList, Node *pDefault, Node *pFavs)//sorts current list and displays as in lab4, then ask what user thinks
{
	if( getCount( **ppCurrentList) != 0)
	{
		if( ppCurrentList == &pDefault) printf( "Undecided Rental Properties \n");
		if( ppCurrentList == &pFavs) printf( "Favourite Rental Properties \n");
	
		printf( "Address				# Rooms	   Rent/Rooms	Distance\n");
		printf( "__________________________	_______	_______	_________\n");
		
		Node *pCounter = **ppCurrentList;
		while(*pCounter != NULL)
		{
			printf( "%d %-26s	%7d	%7d	/*float or double whatever we set distance to*/ km \n", /*number, name, room, rent, distance*/);
			*pCounter->*pNextNode;
		}
	
		printf("What do you think about this rental property?");
		printf("	Addr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: /*float or double whatever we set distance to*/ km \n", /*number, name, room, rent, distance for first in list */);
	}
	else printf("There are no more rental properties");

}

void defaultList(Node **ppCurrentList,Node *pDefault)//Generate a new rental property (50% of the time) and add it to the “default” list.  Set the current list to “default”, and do an ALL. 
{
	/* call chance generate new property */
	**ppCurrentList = *pDefault;	
}

void favs(Node **ppCurrentList, Node *pFavs)//Set the current list to “favourites” list, and do an ALL.
{
	**ppCurrentList = *pFavs;
}

void sort()//Organize the properties according to the desired sort method <n> 
{
	char input = scanf("%s", input);
	if (input == 'r')printf("sr")/*replace print with sort by rent function*/;
	else if (input == 'd')printf("sd")/*replace print with sort by distance function*/;
	else if (input == 'n')printf("sn")/*replace print with sort by rooms function*/;
	else if (input == 'a')printf("sa")/*replace print with sort by add function*/;
	else printf("s error");
}

int next(Node **ppCurrentList, int count)//display the next rental property on the current list, or print “There are no more rental properties” if you were already at the last one on the list.
{
	count++;
	Node *pNode = *getNodeAtIndex( Node *ppCurrentList, count );
	if( *pNode != NULL)
	{
			printf("What do you think about this rental property?");
		printf("	Addr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: /*float or double whatever we set distance to*/ km \n", /*number, name, room, rent, distance for Next in list */);
	}
	else printf("There are no more rental properties");
	return count;
}

void left( Node **ppCurrentList, int count)//Remove the just-viewed property from the current list, delete it, and either display the next rental property on the current list, or print “There are no more properties” if you were already at the last one on the list. 
{
	*removeNodeAtIndex( **ppCurrentList, count);
	Node *pNode = *getNodeAtIndex( Node *ppCurrentList, count );
	
	if( *pNode != NULL)
	{
			printf("What do you think about this rental property?");
		printf("	Addr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: /*float or double whatever we set distance to*/ km \n", /*number, name, room, rent, distance for Next in list */);
	}
	else printf("There are no more rental properties");
}

int right( Node **ppCurrentList, Node *pFavs, int count)//If you are currently viewing the favourites list, print out “This property is already on the favourites list”.  Otherwise, remove the just-viewed property from the default list, and append it to the favourites list, and either display the next rental property on the default list, or print “There are no more rental properties” if you were already at the last one on the list.
{
	if( ppCurrentList == &pFavs)
	{
		printf("This property is already on the favourites list");
		count++;
	}
	else 
	{
		Node **ppFavs = &pFavs;
		appendNode( Node **ppFavs, *removeNodeAtIndex( **ppCurrentList, count );
	}		
	return count;
}

void main()
{
	
	srand(time(NULL));
	
	Street streets[] = {
		{"First Street", ranNum(40, 5)*100},
		{"Second Street", ranNum(40, 5)*100},
		{"Third Street", ranNum(40, 5)*100},
		{"Bad Street", ranNum(40, 5)*100},
		{"Fourth Street", ranNum(40, 5)*100},
		{"Boxing Street", ranNum(40, 5)*100},
		{"A Street", ranNum(40, 5)*100},
		{"NotA Street", ranNum(40, 5)*100},
		{"Random Street", ranNum(40, 5)*100},
		{"Taco Road", ranNum(40, 5)*100},
	};
	
	char input;
	Node *pDefault = malloc( sizeof( Node));
	Node *pFavs = malloc( sizeof( Node));
	Node **ppCurrentList = &pDefault;
	Node *pNode = **ppCurrentList;
	int count = 0;
	
	all( ppCurrentList, pDefault, pFavs);
	while( input != 'q')
	{
		printf( "Command ('h' for help): ");
		scanf( "%s" , input);
	
		if( input == 'h') help();
		else if( input == 'a')
		{
			all( ppCurrentList, pDefault, pFavs);
			count = 0;
		}
		else if( input == 'l') 
		{
			left(ppCurrentList);
		}
		else if( input == 'r') 
		{
			count = right(ppCurrentList, pFavs);
		}
		else if( input == 'n') 
		{
			count = next(ppCurrentList);
		}
		else if( input == 'f')
		{		
			favs( **ppCurrentList, *pFavs);
			all ( ppCurrentList, pDefault, pFavs);
			count = 0;
		}
		else if( input == 'd')
		{
			defaultList( **ppCurrentList, *pDefault);
			all ( ppCurrentList, pDefault, pFavs);
			count = 0;
		}
		else if( input == 's')
		{
			sort();
			all( ppCurrentList, pDefault, pFavs);
			count = 0;
		}
		else 
		{
			printf("That is not a supported command");
			help();
		}
	}	
	
}
