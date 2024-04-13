///	Package:	meqcalc
///	File:		meqcalc.c 
///	Purpose:	Modeling mEq calculations
///	Author:		jrom876

/**
	Copyright (C) 2023 
	Jacob Romero, Creative Engineering Solutions, LLC
	cesllc876@gmail.com
**/

/** References:	
 * https://sciencing.com/calculate-milliequivalent-5009675.html
 * https://ptable.com/?lang=en#Properties
 * https://www.environmentalexpress.com/ee/s/product/detail/01t4W00000EmE1OQAV
 * 
 * mEq = (mass*valence)/Molecular Weight
 * 
**/

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <math.h>
#include "meqcalc.h"
#include "ptableDefines.h"
//~ #include <check.h>

/// STANDARD DEFINITIONS FOR PROJECT SCICALC 
#define PI	(double)3.14159265358979323846 	// ad infinitum
#define LIGHT_SPEED	299792458.0 		// meters per second
#define STACK_OVERFLOW	2147483648		// Hex 0x80000000
#define DATA_SIZE 1000
#define MILLI 1.0e-3
#define MICRO 1.0e-6
#define NANO 1.0e-9
#define PICO 1.0e-12
#define KILO 1.0e3
#define MEGA 1.0e6
#define GIGA 1.0e9
#define TERA 1.0e12 
#define true 1
#define false 0

double totalMassInSolOneElement (double conc, double solVolume, double mMass, int valence) {
	double totalMass = conc*solVolume;
	printf("Total Mass:\t%0.6lf\n",totalMass);
	double mEq = (totalMass*valence)/(mMass*MILLI);
	printf("mEq:\t%0.6lf\n",mEq);
	return mEq;	
}


double getConcentrationInMeq2Elements (double msolute, double solVolume, double mMass1, double mMass2, int valence) {
	double molWeight = mMass1 + mMass2;
	printf("Molecular Weight:\t\t\t%0.6lf grams/mole\n",molWeight);
	double mEq = (msolute*valence)/(molWeight);
	printf("mEq:(mass solute*valence)/molWeight = \t%0.6lf\n",mEq*KILO);
	double concentrationInMeq = mEq/solVolume;
	printf("concentration mEq: mEq/vol solvent\t%0.6lf mEq/L\n",concentrationInMeq*KILO);
	return mEq;	
}

/// mEq/L = [(mass*valence)/Molecular Weight]/volume of solvent
double getMassOfNaCl (double goal, double solVolume) {
	int valence = 2;
	double molWeight = SODIUM + CHLORINE;
	//~ printf("\nMolecular Weight:\t\t\t%0.6lf grams/mole\n",molWeight);
	double mNaCl = (goal*solVolume*molWeight)/valence;
	printf("NaCl\t%.4lf mEq\t%0.4lf L H2O = \t%0.6lf mg\n",goal, solVolume, mNaCl);
	return mNaCl;	
}

/// mEq/L = [(mass*valence)/Molecular Weight]/volume of solvent
double getPercent (double meql, int valence, double el1, double el2) {
	//~ int valence = 2;
	double molWeight = el1 + el2;
	//~ printf("\nMolecular Weight:\t\t\t%0.6lf grams/mole\n",molWeight);
	double percent = ((meql*molWeight)/valence)*MILLI;
	printf("percent = %.4lf\n",percent);
	return percent;	
}

/// mEq/L = [(mass*valence)/Molecular Weight]/volume of solvent
double getmass_given_percent (double percent, int valence, double el1, double el2) {
	double molWeight = el1 + el2;
	//~ printf("\nMolecular Weight:\t\t\t%0.6lf grams/mole\n",molWeight);
	//~ double percent = ((meql*molWeight)/valence)*MILLI;
	double mass = (percent*valence)/(molWeight*MILLI);
	printf("mass = %.4lf\n",mass);
	return mass;	
}

/** MAIN **/

int main(int argc, char const *argv[]) {
	////~ totalMassInSolOneElement(78.2*MILLI, 0.75, POTASSIUM, 1);
	////~ getConcentrationInMeq2Elements(30*MILLI, 0.4, SODIUM, CHLORINE, 2);
	////~ getMassOfNaCl(2.567, 0.4);
	getPercent (30.8, 2, SODIUM, CHLORINE);
	getmass_given_percent (0.9, 2, SODIUM, CHLORINE);
	
	for (double g = 100; g<155; g=g+5) {
		double mNaCl = getMassOfNaCl(g, 0.025);
	}
	printf("\n");
	
	for (double g = 100; g<155; g=g+5) {
		getMassOfNaCl(g, 0.25);
	}
	printf("\n");
	
	for (double g = 100; g<155; g=g+5) {
		double mNaCl = getMassOfNaCl(g, 0.5);
	}
	return 0;
 }
