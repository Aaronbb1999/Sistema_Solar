#include "functions.h"
#include <math.h>
#include <stdio.h>
const int MAXFILS=20; 
const int MAXCOLS=20;
const double G=6.67E-11;
const double c=1.496E11;
const double Ms=1.99E30;

int main()
{
    double r[MAXFILS][1],v[MAXFILS][1],a[MAXFILS][1],w[MAXFILS][1];
    double M[MAXFILS];
    int n=9;

    FILE *f1,*f2,*f3,*fr;

    f1=open("distancias.txt","r");
    f2=open("masas.txt","r");
    f3=open("excentricidad.txt","r");


    for(i=1;i<=n;i++)
    {
        r[i][1]
    }

    
    return 0;

}