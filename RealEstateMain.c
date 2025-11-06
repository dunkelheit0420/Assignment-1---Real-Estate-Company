//	SEP101 - ASSIGNMENT 1
//	RealEstateMain.c - main program for the real estate company

//	Daryl Gonzales					Shay Symonnette	                  Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	19-Oct-25	D. Gonzales		Created RealEstateMain.c file
//	21-Oct-25	D. Gonzales		Added some setup code for extracting the data from the text files
//	25-Oct-25	D. Gonzales		Cleaned up main() after the extract function worked, added validation for the 
//								extract function
//	25-Oct-25	All members		Meeting about the project at 18:00 EST
//	30-Oct-25	D. Gonzales		Added validation for opening the txt files
//	06-Nov-25	D. Gonzales		Added initialization for the real estate company's name and address

#define _CRT_SECURE_NO_WARNINGS
#include "RealEstate.h"

int main(void) {

	int retVal = 0;

	// This sets all of the value to zero at the beginning by default which helps when dealing with the fact 
	// that realEstate -> apartment -> property -> monthlyUtilities and monthlyPropertyTax do not exist and 
	// should set to zero. Same thing for realEstate -> semiDetachedHouse -> property -> monthlyCondoFees.
	struct RealEstateCompany realEstate = { 0 };

	strcpy(realEstate.name, REAL_ESTATE_COMPANY_NAME);
	strcpy(realEstate.address, REAL_ESTATE_COMPANY_ADDRESS);

	// Extract data from file
	retVal = ExtractDataFromFile(&realEstate, APARTMENT_FILE, TOWNHOUSES_FILE, SEMIDETACHED_HOUSES_FILE);

	// Validation for opening the txt files
	if (retVal > 0) {
		PrintReport(realEstate);
	}
	else printf("ERROR: Something went wrong with extracting the files, please check the filenames and try again.\n");
	return;
}

/*
TO-DO LIST:
1. Create a function for calculating return on investment (CalculateROI)				Shay
2. Create a function for calculating the current value (CalculateCurrentValue)			Shay
3. Create a function for calculating captital gains (CalculateCapitalGains)				Shay
4. Create a function for determining the performance for each property type (DeterminePerformance)		Eugene
   In DeterminePerformance, the first line would be to calculate the monthly earnings becuase it is
   different for each property type, then we call the other functions, CalculateROI,
   CalculateCurrentValue and CalculateCapitalGains.
5. Defining the name and address of the Real Estate Company							Daryl
6. Create a function for printing the report.		Daryl
7. Answer question 1.								Daryl
8. Answer question 2.								Eugene
9. Answer question 3.								Eugene
10. Answer question 4.								Shay
*/