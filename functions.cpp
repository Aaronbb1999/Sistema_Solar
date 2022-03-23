#include <math.h>
#include "functions.h"

const int MAXFILS=20; 
const int MAXCOLS=20;
const double G=6.67*Pow(10,-11);

void Reinitialize(double A[][MAXCOLS], int fils, int cols)
{
    int i,j;

    for(i=0;i<=fils;i++)
    {
        for(j=0;j<=cols;j++)
        {
            A[i][j]=0;
        }
    }
}

double Mod1(double v[2])
{
    double M;

    M=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);

    return M;
}

void acel(double a[][2], double r[][2], double M[] ,int n)
{
    int i,j,k,i1;
    double R[MAXFILS][MAXCOLS][2];
    double A[MAXFILS][MAXCOLS][2];
    double aux[2];
    double mod;

    Reinitialize(a,n,2);

    for(i=0;i<=n;i++)
     {
         for(j=0;j<=n;j++)
         {
             for(k=0;k<=2;k++)
             {
                 R[i][j][k]=r[i][k]-r[j][k];
             }
         }
     }

    for(i=0;i<=n;i++)
     {
         for(j=0;j<=n;j++)
         {

             for(i1=0;i1<=2;i1++)
             {
                aux[i1]=R[i][j][i1];
             }
             mod=Mod1(aux);
             for(k=0;k<=2;k++)
             {
                if(mod<=0.000001)
                {
                    A[i][j][k]=-G*M[j]*R[i][j][k]/(mod*mod*mod);
                }
             }
         }
     }

     for(i=0;i<=n;i++)
    {
        for(k=0;k<=2;k++)
        {
            for(j=0;j<=n;j++)
            {
                a[i][k]+=a[i][k]+A[i][j][k];
            }
        }
    }

}
