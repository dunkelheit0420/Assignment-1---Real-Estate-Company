//	SEP101 - ASSIGNMENT 1
//	Property.h - header file for the attributes that all of the property types share

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	06-Nov-25		D. Gonzales		Created and finishedProperty.h structure after realizing error

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
};

#endif