//	SEP101 - ASSIGNMENT 1
//	Apartments.h - header file for the apartments of the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	22-Oct-25		D. Gonzales		Created Apartments.h file, finished the structure
//	30-Oct-25		D. Gonzales		Added header guards shown in class

#ifndef _APARTMENTS_H_
#define _APARTMENTS_H_

#define MAX_STR 255

struct Apartment {
	char address[MAX_STR];
	int numRooms;
	int numBathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyCondoFees;
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};

#endif