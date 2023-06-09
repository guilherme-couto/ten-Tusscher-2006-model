#ifndef PARAMETERS_H
#define PARAMETERS_H

/*------------------------------------------------------
Parameters for ten Tusscher model 2006 (https://journals.physiology.org/doi/full/10.1152/ajpheart.00109.2006)
from https://tbb.bio.uu.nl/khwjtuss/SourceCodes/HVM2/Source/Main.cc - ten Tusscher code
https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3263775/ - Benchmark
and https://github.com/rsachetto/MonoAlg3D_C/blob/master/src/models_library/ten_tusscher/ten_tusscher_2006_RS_CPU.c - Sachetto MonoAlg3D
--------------------------------------------------------*/

/*-----------------------------------------------------
Options for define cell type:
-----------------------------------------------------*/
#include "cell_type.h"


/*-----------------------------------------------------
Model parameters
-----------------------------------------------------*/
double chi = 1400.0;                // Surface area-to-volume ratio -> cm^-1
double Cm = 0.185;                  // Cell capacitance per unit surface area -> uF/ (???)^2 (ten Tusscher)


/*-----------------------------------------------------
Parameters
-----------------------------------------------------*/
// Constants
double R = 8314.472;        // Gas constant -> (???) [8.314472 J/(K*mol)]
double T = 310.0;           // Temperature -> K
double F = 96485.3415;      // Faraday constant -> (???) [96.4867 C/mmol]
double RTONF = 26.713761;   // R*T/F -> (???)
double FONRT = 0.037434;    // F/(R*T) -> (???)

// Intracellular volumes
double V_C = 0.016404;      // Cellular volume -> (???) [16404 um^3]
double V_SR = 0.001094;     // Sarcoplasmic reticulum volume -> (???) [1094 um^3]
double V_SS = 0.00005468;   // Subsarcolemmal space volume -> (???) [54.68 um^3]

// External concentrations
double K_o = 5.4;           // Extracellular potassium (K+) concentration -> mM
double Na_o = 140;          // Extracellular sodium (Na+) concentration -> mM
double Ca_o = 2.0;          // Extracellular calcium (Ca++) concentration -> mM

// Parameters for currents
double G_Na = 14.838;       // Maximal I_Na (sodium current) conductance -> nS/pF
double G_K1 = 5.405;        // Maximal I_K1 (late rectifier potassium current) conductance -> nS/pF
#if defined(EPI) || defined(M)
double G_to = 0.294;        // Maximal I_to (transient outward potassium current) conductance -> nS/pF (epi and M cells)
#endif
#ifdef ENDO
double G_to = 0.073;        // Maximal I_to (transient outward potassium current) conductance -> nS/pF (endo cells)
#endif
double G_Kr = 0.153;        // Maximal I_Kr (rapidly activating delayed rectifier potassium current) conductance -> nS/pF
#if defined(EPI) || defined(ENDO)
double G_Ks = 0.392;        // Maximal I_Ks (slowly activating delayed rectifier potassium current) conductance -> nS/pF (epi and endo cells)
#endif
#ifdef M
double G_Ks = 0.098;        // Maximal I_Ks (slowly activating delayed rectifier potassium current) conductance -> nS/pF (M cells)
#endif
double p_KNa = 0.03;        // Relative I_Ks permeability to Na+ over K+ -> dimensionless
double G_CaL = 3.98e-5;     // Maximal I_CaL (L-type calcium current) conductance -> cm/ms/uF
double k_NaCa = 1000.0;     // Maximal I_NaCa (Na+/Ca++ exchanger current) -> pA/pF
double gamma_I_NaCa = 0.35; // Voltage dependence parameter of I_NaCa -> dimensionless
double K_mCa = 1.38;        // Half-saturation constant of I_NaCa for intracellular Ca++ -> mM
double K_mNa_i = 87.5;      // Half-saturation constant of I_NaCa for intracellular Na+ -> mM
double k_sat = 0.1;         // Saturation factor for I_NaCa -> dimensionless
double alpha = 2.5;         // Factor enhancing outward nature of I_NaCa -> dimensionless
double P_NaK = 2.724;       // Maximal I_NaK (Na+/K+ pump current) -> pA/pF
double K_mK = 1.0;          // Half-saturation constant of I_NaK for Ko -> mM
double K_mNa = 40.0;        // Half-saturation constant of I_NaK for intracellular Na+ -> mM
double G_pK = 0.0146;       // Maximal I_pK (plateau potassium current) conductance -> nS/pF
double G_pCa = 0.1238;      // Maximal I_pCa (plateau calcium current) conductance -> nS/pF
double K_pCa = 0.0005;      // Half-saturation constant of I_pCa for intracellular Ca++ -> mM
double G_bNa = 0.00029;     // Maximal I_bNa (sodium background current) conductance -> nS/pF
double G_bCa = 0.000592;    // Maximal I_bCa (calcium background current) conductance -> nS/pF

// Intracellular calcium flux dynamics
double V_maxup = 0.006375;  // Maximal I_up -> mM/ms
double K_up = 0.00025;      // Half-saturation constant of I_up -> mM
double V_rel = 0.102;       // Maximal I_rel conductance -> mM/ms
double k1_prime = 0.15;     // R to O and RI to I I_rel transition rate -> mM^-2*ms^-1
double k2_prime = 0.045;    // O to I  and R to RI I_rel transition rate -> mM^-1*ms^-1
double k3 = 0.06;           // O to R and I to RI I_rel transition rate -> ms^-1
double k4 = 0.005;          // I to O and RI to I I_rel transition rate -> ms^-1
double EC = 1.5;            // Half-saturation constant of k_Ca_SR -> mM
double max_SR = 2.5;        // Maximum value of k_Ca_SR -> dimensionless
double min_SR = 1.0;        // Minimum value of k_Ca_SR -> dimensionless
double V_leak = 0.00036;    // Maximal I_leak conductance -> mM/ms
double V_xfer = 0.0038;     // Maximal I_xfer conductance -> mM/ms

// Calcium buffering dynamics
double Buf_C = 0.2;         // Total cytoplasmic buffer concentration -> mM
double K_bufc = 0.001;      // Half-saturation constant of cytoplasmic buffers -> mM
double Buf_SR = 10.0;       // Total sarcoplasmic reticulum buffer concentration -> mM
double K_bufsr = 0.3;       // Half-saturation constant of sarcoplasmic reticulum buffers -> mM
double Buf_SS = 0.4;        // Total subspace buffer concentration -> mM
double K_bufss = 0.00025;   // Half-saturation constant of subspace buffer -> mM


/*----------------------------------------
Initial Conditions for epicardium cells
from https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3263775/
-----------------------------------------*/
#ifdef EPI
double V_init = -85.23;       // Initial membrane potential -> mV
double X_r1_init = 0.00621;   // Initial rapid time-dependent potassium current Xr1 gate -> dimensionless
double X_r2_init = 0.4712;    // Initial rapid time-dependent potassium current Xr2 gate -> dimensionless
double X_s_init = 0.0095;     // Initial slow time-dependent potassium current Xs gate -> dimensionless
double m_init = 0.00172;      // Initial fast sodium current m gate -> dimensionless
double h_init = 0.7444;       // Initial fast sodium current h gate -> dimensionless
double j_init = 0.7045;       // Initial fast sodium current j gate -> dimensionless
double d_init = 3.373e-5;     // Initial L-type calcium current d gate -> dimensionless
double f_init = 0.7888;       // Initial L-type calcium current f gate -> dimensionless
double f2_init = 0.9755;      // Initial L-type calcium current f2 gate -> dimensionless
double fCass_init = 0.9953;   // Initial L-type calcium current fCass gate -> dimensionless
double s_init = 0.999998;     // Initial transient outward current s gate -> dimensionless
double r_init = 2.42e-8;      // Initial transient outward current r gate -> dimensionless
double Ca_i_init = 0.000126;  // Initial intracellular Ca++ concentration -> mM
double Ca_SR_init = 3.64;     // Initial sarcoplasmic reticulum Ca++ concentration -> mM
double Ca_SS_init = 0.00036;  // Initial subspace Ca++ concentration -> mM
double R_prime_init = 0.9073; // Initial ryanodine receptor -> dimensionless
double Na_i_init = 8.604;     // Initial intracellular Na+ concentration -> mM
double K_i_init = 136.89;     // Initial intracellular K+ concentration -> mM
#endif

/*----------------------------------------
Initial Conditions for endocardium or M cells
from https://tbb.bio.uu.nl/khwjtuss/SourceCodes/HVM2/
-----------------------------------------*/
#if defined(ENDO) || defined(M)
double V_init = -86.2;        // Initial membrane potential -> mV
double X_r1_init = 0.0;       // Initial rapid time-dependent potassium current Xr1 gate -> dimensionless
double X_r2_init = 1.0;       // Initial rapid time-dependent potassium current Xr2 gate -> dimensionless
double X_s_init = 0.0;        // Initial slow time-dependent potassium current Xs gate -> dimensionless
double m_init = 0.0;          // Initial fast sodium current m gate -> dimensionless
double h_init = 0.75;         // Initial fast sodium current h gate -> dimensionless
double j_init = 0.75;         // Initial fast sodium current j gate -> dimensionless
double d_init = 0.0;          // Initial L-type calcium current d gate -> dimensionless
double f_init = 1.0;          // Initial L-type calcium current f gate -> dimensionless
double f2_init = 1.0;         // Initial L-type calcium current f2 gate -> dimensionless
double fCass_init = 1.0;      // Initial L-type calcium current fCass gate -> dimensionless
double s_init = 1.0;          // Initial transient outward current s gate -> dimensionless
double r_init = 0.0;          // Initial transient outward current r gate -> dimensionless
double Ca_i_init = 0.00007;   // Initial intracellular Ca++ concentration -> mM
double Ca_SR_init = 1.3;      // Initial sarcoplasmic reticulum Ca++ concentration -> mM
double Ca_SS_init = 0.00007;  // Initial subspace Ca++ concentration -> mM
double R_prime_init = 1.0;    // Initial ryanodine receptor -> dimensionless
double Na_i_init = 7.67;      // Initial intracellular Na+ concentration -> mM
double K_i_init = 138.3;      // Initial intracellular K+ concentration -> mM
#endif

#endif // PARAMETERS_H