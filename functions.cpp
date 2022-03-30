#include <math.h>
#include "functions.h"
#include <stdio.h>
const int MAXFILS=20; 
const int MAXCOLS=20;
const double G=6.67E-11;
const double c=1.496E11;
const double Ms=1.99E30;


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

double Mod1(double v[1])
{
    double M;

    M=sqrt(v[0]*v[0]+v[1]*v[1]);

    return M;
}

void acel(double a[][1], double r[][1], double M[] ,int n)
{
    int i,j,k,i1;
    double R[MAXFILS][MAXCOLS][2];
    double A[MAXFILS][MAXCOLS][2];
    double aux[1];
    double mod;

    //Reiniciamos la matriz de aceleraciones
    Reinitialize(a,n,1);

    for(i=0;i<=n;i++)
     {
         for(j=0;j<=n;j++)
         {
             for(k=0;k<=1;k++)
             {
                 //Hallamos las diferencias entre cada planeta y lo almacenamos en un tensor
                 R[i][j][k]=r[i][k]-r[j][k];
             }
         }
     }

    for(i=0;i<=n;i++)
     {
         for(j=0;j<=n;j++)
         {
             //Se halla el módulo del vector que une le planta i con el j
             for(i1=0;i1<=1;i1++)
             {
                aux[i1]=R[i][j][i1];
             }
             mod=Mod1(aux);
             for(k=0;k<=1;k++)
             {
                //si no es el mismo planeta, hallamos las aceleraciones que produce cada planeta sobre otro
                if(mod<=0.000001)
                {
                    A[i][j][k]=-G*M[j]*R[i][j][k]/(mod*mod*mod);
                }
             }
         }
     }


    //Se halla la aceleración total del planeta.
    for(i=0;i<=n;i++)
    {
        for(k=0;k<=1;k++)
        {
            for(j=0;j<=n;j++)
            {
                a[i][k]+=a[i][k]+A[i][j][k];
            }
        }
    }

}

void posic(double r[][1],double v[][1], double a[][1], double h,int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=1;j++)
        {
            r[i][j]=r[i][j]+h*v[i][j]+(h*h)/2*a[i][j];
        }
    }
}

void omega(double w[][1], double v[][1],double a[][1],double h, int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=1;j++)
        {
            w[i][j]=v[i][j]+h/2*a[i][j];
        }
    }
}

void veloc(double w[][1],double v[][1], double a[][1], double h, int n)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=1;j++)
        {
            v[i][j]=w[i][j]+h/2*a[i][j];
        }
    }
}