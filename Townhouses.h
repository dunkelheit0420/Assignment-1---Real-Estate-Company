//	SEP101 - ASSIGNMENT 1
//	Townhouses.h - header file for the townhouses of the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	22-Oct-25		D. Gonzales		Created Townhouses.h file, finished the structure
//	30-Oct-25		D. Gonzales		Added header guards shown in class
//	06-Nov-25		D. Gonzales		Added Property structure

#ifndef _TOWNHOUSES_H_
#define _TOWNHOUSES_H_

#include "Property.h"

struct Townhouse {
	struct Property property[NUM_TOWNHOUSES];
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};

#endif