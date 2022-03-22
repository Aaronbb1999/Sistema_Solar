#include "functions.h"
#include <stdio.h>

int main()
{
    double a[]={1,2,4,5};
    double b[]={1,5,2,0};
    double s[]={0,0,0,0};
    int n=4;
    double M;

    SumVec(s,a,b,n);
    M=Mod(a);

    
    printf("Vector suma: (%lf)\n",b[0]);
    printf("Modulo de a: %lf",M);

    
    return 0;

}