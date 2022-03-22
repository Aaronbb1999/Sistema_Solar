#include <math.h>
#include "functions.h"

void SumVec(double s[],double a[],double b[], int n)
{
    int i;

    for(i=0;i<=n;i++)
    {
        s[i]=a[i]+b[i];
    }
        return;
}

double Mod(double v[2])
{
    double M;

    M=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);

    return M;
}
