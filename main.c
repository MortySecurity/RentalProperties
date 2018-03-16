/*
* Todd Hakvoort
* Lab4
* CST8234
*/

#include <stdio.h>
#include <stdlib.h>

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

void all(void ppCurrentList, void pDefault, void pFavs)//sorts current list and displays as in lab4, then ask what user thinks
{
	printf( "all");
	if( ppCurrentList != NULL)
	{
		if( ppCurrentList == &pDefault) printf( "Undecided Rental Properties \n");
		if( ppCurrentList == &pFavs) printf( "Favourite Rental Properties \n");
	
		printf( "Address				# Rooms	   Rent/Rooms	Distance\n");
		printf( "__________________________	_______	_______	_________\n");
		while( /* list does not equal null */)
		{
			printf( "%d %-26s	%7d	%7d	/*float or double whatever we set distance to*/ km \n", /*number, name, room, rent, distance*/);
			/*code to go to next in list*/
		}
	
		printf("What do you think about this rental property?");
		printf("	Addr: %d %s, # Rooms: %d, Rent/Room: $%d, Distance: /*float or double whatever we set distance to*/ km \n", /*number, name, room, rent, distance for first in list */);
	}
	else printf("There are no more rental properties");

}

void defaultList(void ppCurrentList,void pDefault)//Generate a new rental property (50% of the time) and add it to the “default” list.  Set the current list to “default”, and do an ALL. 
{
	printf("defaultList");
	/* call chance generate new property */
	ppCurrentList = &pDefault;	
}

void favs(void ppCurrentList, void pFavs)//Set the current list to “favourites” list, and do an ALL.
{
	printf("favs");
	ppCurrentList = &pFavs;
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

void next()//display the next rental property on the current list, or print “There are no more rental properties” if you were already at the last one on the list.
{
	printf("next");
}

void left()//Remove the just-viewed property from the current list, delete it, and either display the next rental property on the current list, or print “There are no more properties” if you were already at the last one on the list. 
{
	printf("left");
}

void right()//If you are currently viewing the favourites list, print out “This property is already on the favourites list”.  Otherwise, remove the just-viewed property from the default list, and append it to the favourites list, and either display the next rental property on the default list, or print “There are no more rental properties” if you were already at the last one on the list.
{
	printf("right");
}

void main()
{
	char input;
	void *pDefault = NULL;
	void *pFavs = NULL;
	void **ppCurrentList = &pDefault;
	
	all( ppCurrentList, pDefault, pFavs);
	while( input != 'q')
	{
		printf( "Command ('h' for help): ");
		scanf( "%s" , input);
	
		if( input == 'h') help();
		else if( input == 'a') all( ppCurrentList, pDefault, pFavs);
		else if( input == 'l') left();
		else if( input == 'r') right();
		else if( input == 'n') next();
		else if( input == 'f')
		{		
			favs( **ppCurrentList, *pFavs);
			all ( ppCurrentList, pDefault, pFavs);
		}
		else if( input == 'd')
		{
			defaultList( **ppCurrentList, *pDefault);
			all ( ppCurrentList, pDefault, pFavs);
		}
		else if( input == 's')
		{
			sort();
			all( ppCurrentList, pDefault, pFavs);
		}
		else 
		{
			printf("That is not a supported command")
			help();
		}
	}	
	
}
