//	SEP101 - ASSIGNMENT 1
//	RealEstate.h - header file for the real estate company

//	Daryl Gonzales					Shay Symonnette						
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	18-Oct-25		D. Gonzales		Created RealEstate.h file
//	19-Oct-25		D. Gonzales		Defined some constants, wrote struct RealEstate, and struct Apartments
//	21-Oct-25		D. Gonzales		Wrote struct Feature, struct Townhouse and struct SemiDetachedHouses
//									Added comments to explain what each structure does.
//	22-Oct-25		D. Gonzales		Decided to create separate header files for each property type for clarity
//	25-Oct-25		D. Gonzales		Added some comments for clarity, now that the extract from file function is fixed.

#pragma once

// Defining some constants needed for the structures and functions
#define MAX_STR 255
#define NUM_APARTMENTS 5
#define NUM_TOWNHOUSES 5
#define NUM_SEMIDETACHED_HOUSES 5

// Defining the txt files where we are getting our information from
#define APARTMENT_FILE "Apartments.txt"
#define TOWNHOUSES_FILE "Townhouses.txt"
#define SEMIDETACHED_HOUSES_FILE "SemiDetachedHouses.txt"

// Including some useful libraries and the header files necessary for our code
#include <stdbool.h>
#include <stdio.h>
#include "Apartments.h"
#include "SemiDetachedHouses.h"
#include "Townhouses.h"

// Structure of all the property types that the Real Estate Company owns
struct RealEstateCompany {
	char name[MAX_STR];
	char address[MAX_STR];
	struct Apartment apartment[NUM_APARTMENTS];
	struct Townhouse townhouse[NUM_TOWNHOUSES];
	struct SemiDetachedHouse semiDetachedHouse[NUM_SEMIDETACHED_HOUSES];
};

// Some functions needed for our code

// Extracts data from the file names provided for each property type and assigns those 
// values to the features of each property in the structure of Real Estate Company.
int ExtractDataFromFile(struct RealEstateCompany* realEstate, const char* apartmentFile, 
						const char* townhouseFile, const char* semiDetachedHouseFile);
