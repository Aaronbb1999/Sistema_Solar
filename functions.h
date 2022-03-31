#ifndef _functions
#define _functions

const int MAXFILS=20; 
const int MAXCOLS=20;
const double G=6.67E-11;
const double c=1.496E11;
const double Ms=1.99E30;

double Mod1(double v[2]);
void acel(double a[][2], double R[][2],double M[]);
void Reinitialize(double A[][1], int fils, int cols);
void posic(double r[][1],double v[][1], double a[][1], double h,int n);
void omega(double w[][1], double v[][1],double a[][1],double h, int n);
void veloc(double w[][1],double v[][1], double a[][1], double h, int n);

#include "functions.cpp"
#endif