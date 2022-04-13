#ifndef _functions
#define _functions

const double Ms=1988500;
const double c=1.496E8;

void acel(double x[], double y[], double ax[], double ay[], double m[], int planetas);
void verlett(double x[], double y[], double vx[], double vy[], double ax[], double ay[], double m[], int planetas, double h, int iteraciones);

#include "functions.cpp"
#endif