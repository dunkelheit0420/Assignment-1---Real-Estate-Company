//	SEP101 - ASSIGNMENT 1
//	Property.h - header file for all of the units within each Property type

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255							

//	Task Log
//	06-Nov-25		D. Gonzales		Created and finished Property.h structure after realizing error
//	16-Nov-25		D. Gonzales		Realized another error, but decided to just stick with the modularity
//									of Property for the individual units, and Apartments, Townhouses, 
//									SemiDetachedHouses for the overall collection of units.
//	16-Nov-25		E. Karaman		Added functions to calculate the monthlyEarnings for each type of property
//	16-Nov-25		S. Symonette	Added functions to calculate annualROI, currentValue and
//									capitalGains

#ifndef _PROPERTY_H_
#define _PROPERTY_H_

#define MAX_STR 255

struct Property {
	char address[MAX_STR];
	int numRooms;
	int numBathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyCondoFees;
	double monthlyPropertyTax;
	double monthlyUtilities;
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};

// Changes the monthlyEarnings, annualROI,currentValue and capitalGains inside Property for each unit
void ApartmentMonthlyEarnings(struct Property* p);
void TownhouseMonthlyEarnings(struct Property* p);
void SemiDetachedMonthlyEarnings(struct Property* p);
void CalculateROI(struct Property* property);
void CalculateCurrentValue(struct Property* property);
void CalculateCapitalGains(struct Property* property);

#endif