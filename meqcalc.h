// meqcalc.h //
#ifndef MEQCALC_H
#define MEQCALC_H

/**
	Copyright (C) 2023 
	Jacob Romero, Creative Engineering Solutions, LLC
	cesllc876@gmail.com
**/

double totalMassInSolOneElement (double conc, double solVolume, double mMass, int valence);
double getConcentrationInMeq2Elements (double msolute, double solVolume, double mMass1, double mMass2, int valence);
double getMassOfNaCl (double goal, double solVolume);

#endif
