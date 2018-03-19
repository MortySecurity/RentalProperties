#include "node.h"
#ifndef RENT_H_
#define RENT_H_

//void set_StreetName(Street *pntstreet, char *name);
//void set_fltDistance(Street *pntstreet);

char *get_StreetName(Street *pntstreet);
int get_fltDistance(Street *pntstreet);

//void set_pntStreet(PropertRental *property, Street *streets, int N);
//void set_nBedRoom(PropertRental *property);
//void set_nRent(PropertRental *property);
//void set_nStreetNumber(PropertRental *property);

//struct *get_pntStreet(PropertRental *property);
int get_nBedRoom(PropertRental *property);
int get_nRent(PropertRental *property);
int get_nStreetNumber(PropertRental *property);

int distance(PropertRental *property, PropertRental *college);
void display1(PropertRental *property);
void display2(PropertRental *property);

struct Street{

	char *StreetName;

	int  fltDistance;

};



struct PropertRental{

	struct Street *pntStreet;

	int nBedRoom;

	int nRent;

	int nStreetNumber;

};



#endif
