//	SEP101 - ASSIGNMENT 1
//	SemiDetached.h - header file for the semi-detached houses of the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	22-Oct-25		D. Gonzales		Created SemiDetached.h file, finished the structure
//	30-Oct-25		D. Gonzales		Added header guards shown in class
//	06-Nov-25		D. Gonzales		Added Property structure

#ifndef _SEMIDETACHEDHOUSES_H_
#define _SEMIDETACHEDHOUSES_H_

#include "Property.h"

struct SemiDetachedHouse {
	struct Property property[NUM_SEMIDETACHED_HOUSES];
	double monthlyEarnings;
	double annualROI;
	double currentValue;
	double capitalGains;
};

#endif