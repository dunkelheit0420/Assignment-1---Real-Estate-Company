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

#define _CRT_SECURE_NO_WARNINGS
#include "RealEstate.h"

int main(void) {
	struct RealEstateCompany realEstate;
	ExtractDataFromFile(&realEstate, APARTMENT_FILE, TOWNHOUSES_FILE, SEMIDETACHED_HOUSES_FILE);
	printf("%s", realEstate.semiDetachedHouse[0].address);
	printf("\n");
	printf(realEstate.apartment[2].address);
	printf("\n");
	printf(realEstate.apartment[3].address);
	printf("\n");
	printf(realEstate.apartment[4].address);
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
5. Defining the name and address of the Real Estate Company							Eugene
6. Create a function for printing the report.		Daryl
7. Answer question 1.								Daryl
8. Answer question 2.								Daryl
9. Answer question 3.								Eugene
10. Answer question 4.								Shay
*/