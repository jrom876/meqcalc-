// meqcalc.h //
#ifndef MEQCALC_H
#define MEQCALC_H

/**
	Copyright (C) 2023 
	Jacob Romero, Creative Engineering Solutions, LLC
	cesllc876@gmail.com
**/

double SODIUM_MASS	= 22.99;
double CHLORINE_MASS	= 35.45;

double SODIUM[] = {22.99,1};
double CHLORINE[] = {35.45,1};

double H[]  = {1.008, 1};
double He[] = {4.026, 2};
double Li[]	= {6.94, 1};
double Be[] = {9.012, 2};
double B[]	= {10.81, 3};
double C[]	= {12.011, 4};
double N[]	= {14.077, 3};
double O[]	= {15.999, 2};
double F[]	= {18.998, 1};
double Ne[]	= {20.180, 8};
double Na[]	= {22.99, 1};
double Mg[] = {24.305, 2};
double Al[]	= {26.982, 3};
double Si[]	= {28.085, 4};
double P[] 	= {30.974, 3};
double S[]	= {32.06, 2};
double Cl[]	= {35.45, 1};
double Ar[]	= {39.948, 8};
double K[]	= {39.098, 1};
double Ca[]	= {0.078, 2};

double totalMassInSolOneElement (double conc, double solVolume, double mMass, int valence);
double getConcentrationInMeq2Elements (double msolute, double solVolume, double mMass1, double mMass2, int valence);
double getMassOfNaCl (double goal, double solVolume);

#endif
