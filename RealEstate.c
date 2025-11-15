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
//	06-Nov-25	D. Gonzales		Finished the PrintReport function
//  11-Nov-25   E. Karaman      Added function DeterminePerformance
//  15-Nov-25   S. Symonette    Added CalculateROI, CalculateCurrentValue, CalculateCapitalGains functions
//  15-Nov-25   S. Symonette    Fixed determinePerformance function to fit new function definitions

#define _CRT_SECURE_NO_WARNINGS

#include "Property.h"
#include <stdio.h>
#include <string.h>
#include "RealEstate.h"

#define INTEREST_RATE 0.05

int ExtractDataFromFile(struct RealEstateCompany* realEstate, char apartmentFilename[],
	char townhouseFilename[], char semiDetachedHouseFilename[]) {

	int retVal = 1;
	//Retrieve data for apartments
	FILE* fpApartment = fopen(apartmentFilename, "r");
	if (fpApartment != NULL) {
		for (int i = 0; i < NUM_APARTMENTS && retVal > 0; ++i) {
			retVal = fscanf(fpApartment, " %[^\n] ", realEstate->apartment.property[i].address);
			retVal = fscanf(fpApartment, "%d", &realEstate->apartment.property[i].numRooms);
			retVal = fscanf(fpApartment, "%d", &realEstate->apartment.property[i].numBathrooms);
			retVal = fscanf(fpApartment, "%lf", &realEstate->apartment.property[i].purchasePrice);
			retVal = fscanf(fpApartment, "%lf", &realEstate->apartment.property[i].monthlyRent);
			retVal = fscanf(fpApartment, "%lf", &realEstate->apartment.property[i].monthlyCondoFees);
			//while (fgetc(fpApartment) != '\n');//clear the file buffer before the next fscanf()
		}
		fclose(fpApartment);
	}
	else retVal = 0;

	//Retrieve data for townhouses
	FILE* fpTownhouse = fopen(townhouseFilename, "r");
	if (fpApartment != NULL) {
		for (int i = 0; i < NUM_TOWNHOUSES && retVal > 0; ++i) {
			retVal = fscanf(fpTownhouse, " %[^\n] ", realEstate->townhouse.property[i].address);
			retVal = fscanf(fpTownhouse, "%d", &realEstate->townhouse.property[i].numRooms);
			retVal = fscanf(fpTownhouse, "%d", &realEstate->townhouse.property[i].numBathrooms);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse.property[i].purchasePrice);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse.property[i].monthlyRent);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse.property[i].monthlyUtilities);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse.property[i].monthlyCondoFees);
			retVal = fscanf(fpTownhouse, "%lf", &realEstate->townhouse.property[i].monthlyPropertyTax);
			//while (fgetc(fpTownhouse) != '\n'); //clear the file buffer before the next fscanf()
		}
		fclose(fpTownhouse);
	}
	else retVal = 0;


	//Retrieve data for semi-detached houses
	FILE* fpSemiDetachedHouse = fopen(semiDetachedHouseFilename, "r");
	if (fpApartment != NULL) {
		for (int i = 0; i < NUM_SEMIDETACHED_HOUSES && retVal > 0; ++i) {
			retVal = fscanf(fpSemiDetachedHouse, " %[^\n] ", realEstate->semiDetachedHouse.property[i].address);
			retVal = fscanf(fpSemiDetachedHouse, "%d", &realEstate->semiDetachedHouse.property[i].numRooms);
			retVal = fscanf(fpSemiDetachedHouse, "%d", &realEstate->semiDetachedHouse.property[i].numBathrooms);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse.property[i].purchasePrice);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse.property[i].monthlyRent);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse.property[i].monthlyUtilities);
			retVal = fscanf(fpSemiDetachedHouse, "%lf", &realEstate->semiDetachedHouse.property[i].monthlyPropertyTax);
			//while (fgetc(fpSemiDetachedHouse) != '\n');//clear the file buffer before the next fscanf()
		}
		fclose(fpSemiDetachedHouse);
	}
	else retVal = 0;

	return retVal;
}

void PrintReport(struct RealEstateCompany realEstate) {
	printf("The following are financial stats for %s, %s.\n\n", realEstate.name, realEstate.address);
	printf("For the apartments, the monthly earnings are $%0.2f, the roi is %0.2f%%, the total value is $%0.2f and the capital gains are $%0.2f\n\n",
		realEstate.apartment.monthlyEarnings, realEstate.apartment.annualROI, realEstate.apartment.currentValue, realEstate.apartment.capitalGains);
	printf("For the townhouses, the monthly earnings are $%0.2f, the roi is %0.2f%%, the total value is $%0.2f and the capital gains are $%0.2f\n\n",
		realEstate.townhouse.monthlyEarnings, realEstate.townhouse.annualROI, realEstate.townhouse.currentValue, realEstate.townhouse.capitalGains);
	printf("For the semidetached houses, the monthly earnings are $%0.2f, the roi is %0.2f%%, the total value is $%0.2f and the capital gains are $%0.2f",
		realEstate.semiDetachedHouse.monthlyEarnings, realEstate.semiDetachedHouse.annualROI, realEstate.semiDetachedHouse.currentValue, realEstate.semiDetachedHouse.capitalGains);
}

double CalculateROI(struct Property* properties, int numProperties, double (*monthlyEarningsFunc)(struct Property*)) {
	if (properties == NULL || numProperties <= 0 || monthlyEarningsFunc == NULL)
		return 0.0;

	double totalROI = 0.0;

	for (int i = 0; i < numProperties; i++) {
		double monthlyEarnings = monthlyEarningsFunc(&properties[i]);
		double purchasePrice = properties[i].purchasePrice;

		if (purchasePrice > 0.0)
			totalROI += 100.0 * 12.0 * monthlyEarnings / purchasePrice;
	}

	return totalROI;
}

double CalculateCurrentValue(struct Property* properties, int numProperties, double (*monthlyEarningsFunc)(struct Property*)) {
	if (properties == NULL || numProperties <= 0 || monthlyEarningsFunc == NULL)
		return 0.0;

	double totalValue = 0.0;

	for (int i = 0; i < numProperties; i++) {
		double monthlyEarnings = monthlyEarningsFunc(&properties[i]);
		totalValue += (12.0 * monthlyEarnings) / INTEREST_RATE;
	}

	return totalValue;
}

double CalculateCapitalGains(struct Property* properties, int numProperties, double (*monthlyEarningsFunc)(struct Property*)) {
	if (properties == NULL || numProperties <= 0 || monthlyEarningsFunc == NULL)
		return 0.0;

	double totalGain = 0.0;

	for (int i = 0; i < numProperties; i++) {
		double purchasePrice = properties[i].purchasePrice;
		double currentValue = (12.0 * monthlyEarningsFunc(&properties[i])) / INTEREST_RATE;
		totalGain += (currentValue - purchasePrice);
	}

	return totalGain;
}

double ApartmentMonthlyEarnings(struct Property* p) {
	return p->monthlyRent - p->monthlyCondoFees;
}

double TownhouseMonthlyEarnings(struct Property* p) {
	return p->monthlyRent - p->monthlyUtilities - p->monthlyCondoFees - p->monthlyPropertyTax;
}

double SemiDetachedMonthlyEarnings(struct Property* p) {
	return p->monthlyRent - p->monthlyUtilities - p->monthlyPropertyTax;
}

void DeterminePerformance(struct RealEstateCompany* realEstate) {
	// Apartments
	realEstate->apartment.monthlyEarnings = 0;
	for (int i = 0; i < NUM_APARTMENTS; ++i) {
		realEstate->apartment.monthlyEarnings +=
			realEstate->apartment.property[i].monthlyRent -
			realEstate->apartment.property[i].monthlyCondoFees;
	}
	realEstate->apartment.annualROI = CalculateROI(realEstate->apartment.property, NUM_APARTMENTS, ApartmentMonthlyEarnings);
	realEstate->apartment.currentValue = CalculateCurrentValue(realEstate->apartment.property, NUM_APARTMENTS, ApartmentMonthlyEarnings);
	realEstate->apartment.capitalGains = CalculateCapitalGains(&realEstate->apartment.property, NUM_APARTMENTS, ApartmentMonthlyEarnings);

	// Townhouses
	realEstate->townhouse.monthlyEarnings = 0;
	for (int i = 0; i < NUM_TOWNHOUSES; ++i) {
		realEstate->townhouse.monthlyEarnings +=
			realEstate->townhouse.property[i].monthlyRent -
			realEstate->townhouse.property[i].monthlyCondoFees -
			realEstate->townhouse.property[i].monthlyUtilities -
			realEstate->townhouse.property[i].monthlyPropertyTax;
	}
	realEstate->townhouse.annualROI = CalculateROI(realEstate->townhouse.property, NUM_TOWNHOUSES,TownhouseMonthlyEarnings);
	realEstate->townhouse.currentValue = CalculateCurrentValue(realEstate->townhouse.property, NUM_TOWNHOUSES, TownhouseMonthlyEarnings);
	realEstate->townhouse.capitalGains = CalculateCapitalGains(realEstate->townhouse.property, NUM_TOWNHOUSES, TownhouseMonthlyEarnings);

	// Semi-Detached Houses
	realEstate->semiDetachedHouse.monthlyEarnings = 0;
	for (int i = 0; i < NUM_SEMIDETACHED_HOUSES; ++i) {
		realEstate->semiDetachedHouse.monthlyEarnings +=
			realEstate->semiDetachedHouse.property[i].monthlyRent -
			realEstate->semiDetachedHouse.property[i].monthlyUtilities -
			realEstate->semiDetachedHouse.property[i].monthlyPropertyTax;
	}
	realEstate->semiDetachedHouse.annualROI = CalculateROI(realEstate->semiDetachedHouse.property, NUM_SEMIDETACHED_HOUSES, SemiDetachedMonthlyEarnings );
	realEstate->semiDetachedHouse.currentValue = CalculateCurrentValue(realEstate->semiDetachedHouse.property, NUM_SEMIDETACHED_HOUSES, SemiDetachedMonthlyEarnings);
	realEstate->semiDetachedHouse.capitalGains = CalculateCapitalGains(realEstate->semiDetachedHouse.property, NUM_SEMIDETACHED_HOUSES, SemiDetachedMonthlyEarnings);
}