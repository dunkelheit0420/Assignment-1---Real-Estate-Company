//	SEP101 - ASSIGNMENT 1
//	SemiDetached.h - header file for the semi-detached houses of the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	22-Oct-25		D. Gonzales		Created SemiDetached.h file, finished the structure

#pragma once
#define MAX_STR 255

struct SemiDetachedHouse {
	char address[MAX_STR];
	int numRooms;
	int numBathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyPropertyTax;
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};