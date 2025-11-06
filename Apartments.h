//	SEP101 - ASSIGNMENT 1
//	Apartments.h - header file for the apartments of the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	22-Oct-25		D. Gonzales		Created Apartments.h file, finished the structure
//	30-Oct-25		D. Gonzales		Added header guards shown in class
//	06-Nov-25		D. Gonzales		Added Property structure

#ifndef _APARTMENTS_H_
#define _APARTMENTS_H_

#include "Property.h"

struct Apartment {
	struct Property property[NUM_APARTMENTS];
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};

#endif