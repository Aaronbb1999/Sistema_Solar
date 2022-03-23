#include <math.h>
#include "functions.h"

const int MAXFILS=20; 
const int MAXCOLS=20;
const double G=6.67*pow(10,-11);

void SumVec(double s[],double a[],double b[], int n)
{
    int i;

    for(i=0;i<=n;i++)
    {
        s[i]=a[i]+b[i];
    }
        return;
}

double Mod1(double v[2])
{
    double M;

    M=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);

    return M;
}

void Force(double R[][2], double r[][2], int n)
{
    int i,j,k;
    double A[MAXFILS][MAXCOLS][2];
    for(i=0;i<=n;i++)
     {
         for(j=0;j<=n;j++)
         {
             for(k=0;k<=2;k++)
             {
                 A[i][j][k]=r[i][k]-r[j][k];
             }
         }
     }

     for(i=0;i<=n;i++)
    {
        for(k=0;k<=n;k++)
        {
            for(j=0;j<=n;j++)
            {
                R[i][k]+=R[i][k]+A[i][j][k];
            }
        }
    }

}

void Mod2(double mod[], double R[][2],int n)
{
    int i,k;

    for(i=0;i<=n;i++)
    {
        for(k=0;k<=n;k++)
        {
            mod[i]+=mod[i]+R[i][k]*R[i][k];
        }
        mod[i]=sqrt(mod[i]);
    }
}

void acel(double a[][2], double R[][2],double M[], int n)
{
    int i,k;
    double r[n];

    Mod2(r,R,n);

    for(i=0;i<=n;i++)
    {
        for(k=0;k<=n;k++)
        {
            a[i][k]+=G*M[i];
        }
    }

}