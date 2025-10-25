//	SEP101 - ASSIGNMENT 1
//	Townhouses.h - header file for the townhouses of the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	22-Oct-25		D. Gonzales		Created Townhouses.h file, finished the structure

#pragma once
#define MAX_STR 255

struct Townhouse {
	char address[MAX_STR];
	int numRooms;
	int numBathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyCondoFees;
	double monthlyPropertyTax;
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};