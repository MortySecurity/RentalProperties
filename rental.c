/*
Bayan Mansour
*/
int ranNum(int min, int max){ //simply returns a random number based on time and the min/max
    int ranNum = rand()%(max + 1 - min) + min;
    return ranNum;	

}

PropertRental *makeRental()
{
	PropertRental newRental = (ranNum(0, 9), ranNum(1, 4), ranNum(4, 12)*50, ranNum(1, 200));
	PropertRental *pRental = &newRental;
	return *pRental;
}

/*void set_StreetName(Street *pntstreet, char *name){
    pntstreet->StreetName = name;
}

void set_fltDistance(Street *pntstreet){
    pntstreet->fltDistance = 100*ranNum(4,50);
}*/

char *get_StreetName(Street *pntstreet){
    return pntstreet->StreetName;
}

int get_fltDistance(Street *pntstreet) {
    return pntstreet->fltDistance;
}

/*void set_pntStreet(PropertRental *property, Street *streets, int N){
    property->pntStreet = streets[ranNum(0,N-1)];
}


void set_nBedRoom(PropertRental *property){
    property->nBedRoom = ranNum(1,4);
}

void set_nRent(PropertRental *property){
    property->nRent = 50 * ranNum(4,12);
}

void set_nStreetNumber(PropertRental *property){
    property->nStreetNumber = ranNum(1,200);
}*/


/*struct *get_pntStreet(PropertRental *property){
    return property->pntStreet;
}*/

int get_nBedRoom(PropertRental *property){
    return property->nBedRoom;
}

int get_nRent(PropertRental *property){ 
    return property->nRent;
}
s
int get_nStreenNumber(PropertRental *property){
    return property->nStreenNumber;
}

int distance(PropertRental *property){
    Street *pntstreet = get_pntStreet(property);
    return get_fltDistance(pntstreet) + 20 * get_nStreenNumber(property);
}

void display1(PropertRental *property){
    // Addr: 168 Squirrel Cres., # Rooms: 2, Rent/Room: $600, Distance: 4.56 km
    Street *pntstreet = get_pntStreet(property);
    int nStreenNumber = get_nStreenNumber(property);
    char *streetName = get_StreetName(pntstreet);
    int rooms = get_nBedRoom(property);
    int rent = get_nRent(property);
    float total_dist = distance(property)*1.0/1000.0;
    printf("Addr: %d %s , # Rooms: %d, Rent/Room: $%d, Distance: %.2f km",nStreenNumber,streetName,rooms,rent,total_dist);
}

void_display2(Node *head){
    /*
    Address                              # Rooms  Rent/Room   Distance
    ------------------------------------------------------------------
    102 Mouse Ave.                             4        350    4.94 km
     22 Fox St.                                2        400    3.04 km
     57 Coyote Crt.                            4        400    4.54 km
      5 Cat St.                                4        400    3.00 km
     91 Cat St.                                1        500    4.72 km
    168 Squirrel Cres.                         2        600    4.56 km
    */
    
    printf("Address                              # Rooms  Rent/Room   Distance\n");
    printf("------------------------------------------------------------------\n");
    while( head != NULL){
        PropertRental *property = head->thisRental;
        Street *pntstreet = get_pntStreet(property);
        int nStreenNumber = get_nStreenNumber(property);
        char *streetName = get_StreetName(pntstreet);
        int rooms = get_nBedRoom(property);
        int rent = get_nRent(property);
        float total_dist = distance(property)*1.0/1000.0;
        printf("%3d ",nStreenNumber);
        printf(%-33s ",streetName);
        printf("%7d  ",rooms);
        printf("%9d   ",rent);
        printf("%5.2f km\n",total_dist);

        head = head->pNextNode;
        
    }
        
    
    

}