//	SEP101 - ASSIGNMENT 1
//	RealEstate.c - program containing function definitions for the real estate company

//	Daryl Gonzales					Shay Symonette					Yevhenii Karaman (Eugene)
//	dgonzales12@myseneca.ca			ssymonette@myseneca.ca			ykaraman1@myseneca.ca
//	111341251						148719248						110047255								

//	Task Log
//	19-Oct-25	D. Gonzales		Created RealEstate.c file
//	21-Oct-25	D. Gonzales		Started ExtractDataFromFile function, not going well
//	22-Oct-25	D. Gonzales		Tried to fix ExtractDataFromFile function, not fully fixed
//	25-Oct-25	D. Gonzales		Fixed the ExtractDataFromFile function
//	30-Oct-25	D. Gonzales		Started PrintReport function
//	06-Nov-25	D. Gonzales		Finished the PrintReport function
//  11-Nov-25   E. Karaman      Added function DeterminePerformance
//  15-Nov-25   S. Symonette    Added CalculateROI, CalculateCurrentValue, CalculateCapitalGains functions
//  15-Nov-25   S. Symonette    Fixed DeterminePerformance function to fit new function definitions
//	16-Nov-25	D. Gonzales		Fixed minor issues regarding syntax, making it more consistent
//								Addressed the ROI issue (total vs annual)
//	16-Nov-25	S. Symonette	Fixed some bugs in my functions, updated Eugene's DeterminePerformance to match

#define _CRT_SECURE_NO_WARNINGS

#include "RealEstate.h"

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

void ApartmentMonthlyEarnings(struct Property* p) {
	p->monthlyEarnings = p->monthlyRent - p->monthlyCondoFees;
}

void TownhouseMonthlyEarnings(struct Property* p) {
	p->monthlyEarnings = p->monthlyRent - p->monthlyUtilities - p->monthlyCondoFees - p->monthlyPropertyTax;
}

void SemiDetachedMonthlyEarnings(struct Property* p) {
	p->monthlyEarnings = p->monthlyRent - p->monthlyUtilities - p->monthlyPropertyTax;
}

void CalculateROI(struct Property* property) {
	if (property == NULL) return;

	if (property->purchasePrice > 0.0) {
		property->annualROI = 100.0 * 12.0 * property->monthlyEarnings / property->purchasePrice;
	}
	else property->annualROI = 0.0;
}

void CalculateCurrentValue(struct Property* property) {
	if (property == NULL) return;

	if (INTEREST_RATE > 0.0) {
		property->currentValue = (12.0 * property->monthlyEarnings) / INTEREST_RATE;

	}
	else property->currentValue = 0.0;
}

void CalculateCapitalGains(struct Property* property) {
	if (property == NULL) return;

	property->capitalGains = property->currentValue - property->purchasePrice;
}

void DeterminePerformance(struct RealEstateCompany* realEstate) {
	
	// All of the values are set to zero at initialization of the struct RealEstate in main so there
	// shouldn't be a need to do it again here.

	// In the assignment document, it asks us to calculate the return on investment by 
	// summming the return on investment for each property type. However, the printed example
	// report in the assignment document seems to be an average. Hence, we included both totalAnnualROI
	// and averageAnnualROI.
	
	// Apartments
	for (int i = 0; i < NUM_APARTMENTS; ++i) {
		ApartmentMonthlyEarnings(&realEstate->apartment.property[i]);
		realEstate->apartment.totalMonthlyEarnings += realEstate->apartment.property[i].monthlyEarnings;
		
		CalculateROI(&realEstate->apartment.property[i]);
		realEstate->apartment.totalAnnualROI += realEstate->apartment.property[i].annualROI;
		realEstate->apartment.averageAnnualROI = realEstate->apartment.totalAnnualROI / NUM_APARTMENTS;
		
		CalculateCurrentValue(&realEstate->apartment.property[i]);
		realEstate->apartment.totalCurrentValue += realEstate->apartment.property[i].currentValue;
		
		CalculateCapitalGains(&realEstate->apartment.property[i]);
		realEstate->apartment.totalCapitalGains += realEstate->apartment.property[i].capitalGains;
	}
	
	// Townhouses
	for (int i = 0; i < NUM_TOWNHOUSES; ++i) {
		TownhouseMonthlyEarnings(&realEstate->townhouse.property[i]);
		realEstate->townhouse.totalMonthlyEarnings += realEstate->townhouse.property[i].monthlyEarnings;
		
		CalculateROI(&realEstate->townhouse.property[i]);
		realEstate->townhouse.totalAnnualROI += realEstate->townhouse.property[i].annualROI;
		realEstate->townhouse.averageAnnualROI = realEstate->townhouse.totalAnnualROI / NUM_TOWNHOUSES;
		
		CalculateCurrentValue(&realEstate->townhouse.property[i]);
		realEstate->townhouse.totalCurrentValue += realEstate->townhouse.property[i].currentValue;
		
		CalculateCapitalGains(&realEstate->townhouse.property[i]);
		realEstate->townhouse.totalCapitalGains += realEstate->townhouse.property[i].capitalGains;
	}

	// Semi-Detached Houses
	for (int i = 0; i < NUM_SEMIDETACHED_HOUSES; ++i) {
		SemiDetachedMonthlyEarnings(&realEstate->semiDetachedHouse.property[i]);
		realEstate->semiDetachedHouse.totalMonthlyEarnings += realEstate->semiDetachedHouse.property[i].monthlyEarnings;
		
		CalculateROI(&realEstate->semiDetachedHouse.property[i]);
		realEstate->semiDetachedHouse.totalAnnualROI += realEstate->semiDetachedHouse.property[i].annualROI;
		realEstate->semiDetachedHouse.averageAnnualROI = realEstate->semiDetachedHouse.totalAnnualROI / NUM_SEMIDETACHED_HOUSES;
		
		CalculateCurrentValue(&realEstate->semiDetachedHouse.property[i]);
		realEstate->semiDetachedHouse.totalCurrentValue += realEstate->semiDetachedHouse.property[i].currentValue;
		
		CalculateCapitalGains(&realEstate->semiDetachedHouse.property[i]);
		realEstate->semiDetachedHouse.totalCapitalGains += realEstate->semiDetachedHouse.property[i].capitalGains;
	}
}

void PrintReport(struct RealEstateCompany realEstate) {
	printf("The following are financial stats for %s, %s.\n\n", realEstate.name, realEstate.address);
	printf("For the apartments, the monthly earnings are $%0.2f, the total roi is %0.2f%%, the average roi is %0.2f%%, the total value is $%0.2f and the capital gains are $%0.2f\n\n",
		realEstate.apartment.totalMonthlyEarnings, realEstate.apartment.totalAnnualROI, realEstate.apartment.averageAnnualROI, realEstate.apartment.totalCurrentValue, realEstate.apartment.totalCapitalGains);
	printf("For the townhouses, the monthly earnings are $%0.2f, the total roi is %0.2f%%, the average roi is %0.2f%%, the total value is $%0.2f and the capital gains are $%0.2f\n\n",
		realEstate.townhouse.totalMonthlyEarnings, realEstate.townhouse.totalAnnualROI, realEstate.townhouse.averageAnnualROI, realEstate.townhouse.totalCurrentValue, realEstate.townhouse.totalCapitalGains);
	printf("For the semidetached houses, the monthly earnings are $%0.2f, the total roi is %0.2f%%, the average roi is %0.2f%%, the total value is $%0.2f and the capital gains are $%0.2f\n\n",
		realEstate.semiDetachedHouse.totalMonthlyEarnings, realEstate.semiDetachedHouse.totalAnnualROI, realEstate.semiDetachedHouse.averageAnnualROI, realEstate.semiDetachedHouse.totalCurrentValue, realEstate.semiDetachedHouse.totalCapitalGains);
}