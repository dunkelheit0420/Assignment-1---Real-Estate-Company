//	SEP101 - ASSIGNMENT 1
//	RealEstate.c - program containing function definitions for the real estate company

//	Daryl Gonzales					Shay Symonnette
//	dgonzales12@myseneca.ca			
//	111341251						

//	Task Log
//	19-Oct-25	D. Gonzales		Created RealEstate.c file
//	21-Oct-25	D. Gonzales		Started ExtractDataFromFile function, not going well
//	22-Oct-25	D. Gonzales		Tried to fix ExtractDataFromFile function, not fully fixed
//	25-Oct-25	D. Gonzales		Fixed the ExtractDataFromFile function
//	30-Oct-25	D. Gonzales		Started PrintReport function

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "RealEstate.h"

int ExtractDataFromFile(struct RealEstateCompany* realEstate, char apartmentFilename[],
	 char townhouseFilename[], char semiDetachedHouseFilename[]) {

	int retVal = 1;
	//Retrieve data for apartments
	FILE* fpApartment = fopen(apartmentFilename, "r");
	if (fpApartment != NULL) {
		for (int i = 0; i < NUM_APARTMENTS && retVal > 0; ++i) {
			retVal = fscanf(fpApartment, " %[^\n]s ", realEstate->apartment[i].address);
			retVal = fscanf(fpApartment, "%d", &realEstate->apartment[i].numRooms);
			retVal = fscanf(fpApartment, "%d", &realEstate->apartment[i].numBathrooms);
			retVal = fscanf(fpApartment, "%lf", &realEstate->apartment[i].purchasePrice);
			retVal = fscanf(fpApartment, "%lf", &realEstate->apartment[i].monthlyRent);
			retVal = fscanf(fpApartment, "%lf", &realEstate->apartment[i].monthlyCondoFees);
			//while (fgetc(fpApartment) != '\n');//clear the file buffer before the next fscanf()
		}
		fclose(fpApartment);
	}
	else retVal = 0;
	
	//Retrieve data for townhouses
	FILE* fpTownhouse = fopen(townhouseFilename, "r");
	if (fpApartment != NULL) {
		for (int i = 0; i < NUM_TOWNHOUSES && retVal > 0; ++i) {
			retVal = fscanf(fpTownhouse, " %[^\n]s ", realEstate->townhouse[i].address);
			retVal = fscanf(fpTownhouse, "%d", &realEstate->townhouse[i].numRooms);
			retVal = fscanf(fpTownhouse, "%d", &realEstate->townhouse[i].numBathrooms);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse[i].purchasePrice);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse[i].monthlyRent);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse[i].monthlyUtilities);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse[i].monthlyCondoFees);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse[i].monthlyPropertyTax);
			//while (fgetc(fpTownhouse) != '\n'); //clear the file buffer before the next fscanf()
		}
		fclose(fpTownhouse);
	}
	else retVal = 0;

	
	//Retrieve data for semi-detached houses
	FILE* fpSemiDetachedHouse = fopen(semiDetachedHouseFilename, "r");
	if (fpApartment != NULL) {
		for (int i = 0; i < NUM_SEMIDETACHED_HOUSES && retVal > 0; ++i) {
			retVal = fscanf(fpSemiDetachedHouse, " %[^\n]s ", realEstate->semiDetachedHouse[i].address);
			retVal = fscanf(fpSemiDetachedHouse, "%d", &realEstate->semiDetachedHouse[i].numRooms);
			retVal = fscanf(fpSemiDetachedHouse, "%d", &realEstate->semiDetachedHouse[i].numBathrooms);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse[i].purchasePrice);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse[i].monthlyRent);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse[i].monthlyUtilities);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse[i].monthlyPropertyTax);
			//while (fgetc(fpSemiDetachedHouse) != '\n');//clear the file buffer before the next fscanf()
		}
		fclose(fpSemiDetachedHouse);
	}
	else retVal = 0;
	
	return retVal;
}

void utilClearInputBuffer() {
	while (getchar() != '\n');
}

void PrintReport(struct RealEstateCompany realEstate) {

}