#ifndef RENT_H_
#define RENT_H_

struct Street{
	char *StreetName;
	int  fltDistance;
};

struct PropertRental{
	struct Street *pntStreet;
	int nBedRoom;
	int nRent;
	int nStreetNumber;
}

#endif
