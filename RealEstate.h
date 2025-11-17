//	SEP101 - ASSIGNMENT 1
//	RealEstate.h - header file for the real estate company

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255			
	
//	Task Log
//	18-Oct-25		D. Gonzales		Created RealEstate.h file
//	19-Oct-25		D. Gonzales		Defined some constants, wrote struct RealEstate, and struct Apartments
//	21-Oct-25		D. Gonzales		Wrote struct Feature, struct Townhouse and struct SemiDetachedHouses
//									Added comments to explain what each structure does.
//	22-Oct-25		D. Gonzales		Decided to create separate header files for each property type for clarity
//	25-Oct-25		D. Gonzales		Added some comments for clarity, now that the extract from file function is fixed.
//	30-Oct-25		D. Gonzales		Added header guards shown in class
//	06-Nov-25		D. Gonzales		Added the real estate company's name and address
//  11-Nov-25       E. Karaman      Added function DeterminePerformance

#ifndef _REALESTATE_H_
#define _REALESTATE_H_

// Defining some constants needed for the structures and functions
#define NUM_APARTMENTS 5
#define NUM_TOWNHOUSES 5
#define NUM_SEMIDETACHED_HOUSES 5
#define INTEREST_RATE 0.05

// Defining the txt files where we are getting our information from
#define APARTMENT_FILE "Apartments.txt"
#define TOWNHOUSES_FILE "Townhouses.txt"
#define SEMIDETACHED_HOUSES_FILE "SemiDetachedHouses.txt"

// Defining the name and address of the Real Estate Company as constants
// because these will never change
#define REAL_ESTATE_COMPANY_NAME "Brookfield Asset Management"
#define REAL_ESTATE_COMPANY_ADDRESS "11 Yonge Street"

// Including some useful libraries and the header files necessary for our code
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "Apartments.h"
#include "SemiDetachedHouses.h"
#include "Townhouses.h"
#include "Property.h"

// Structure of all the property types that the Real Estate Company owns
struct RealEstateCompany {
	char name[MAX_STR];
	char address[MAX_STR];
	struct Apartment apartment;
	struct Townhouse townhouse;
	struct SemiDetachedHouse semiDetachedHouse;
};

// Some functions needed for our code

// Extracts data from the file names provided for each property type and assigns those 
// values to the features of each property in the structure of Real Estate Company.
int ExtractDataFromFile(struct RealEstateCompany* realEstate, char apartmentFilename[],
	char townhouseFilename[], char semiDetachedHouseFilename[]);
void DeterminePerformance(struct RealEstateCompany* realEstate);
void PrintReport(struct RealEstateCompany realEstate);

#endif