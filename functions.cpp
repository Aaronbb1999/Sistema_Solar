#include "functions.h"
#include "math.h"


void acel(double x[], double y[], double ax[], double ay[], double m[], int planetas)
{
    int i, j;
    double mod,rx,ry,fx,fy;

    //Reiniciamos las aceleraciones
    for(i=0;i<planetas;i++)
    {
        ax[i]=0;
        ay[i]=0;
    }

    for(i=0;i<planetas;i++)
    {
        for(j=i+1;j<planetas;j++)
        {
            rx=x[i]-x[j];
            ry=y[i]-y[j];
            mod=sqrt(rx*rx+ry*ry);

            fx=(-1)*m[i]*m[j]*rx/(mod*mod*mod);
            fy=(-1)*m[i]*m[j]*ry/(mod*mod*mod);

            ax[i]+=fx/m[i];
            ay[i]+=fy/m[i];
            ax[j]-=fx/m[j];
            ax[j]-=fy/m[j];
        }
    }
    
    return;
}

void verlett(double x[], double y[], double vx[], double vy[], double ax[], double ay[], double m[], int planetas, double h, int iteraciones)
{
    int i, j;
    double hmid=h/2;
    double wx[planetas],wy[planetas];
    acel(x,y,ax,ay,m,planetas);

    for(i=0; i<iteraciones; i++)
    {
        //Nuevas posiciones
        for(j=0;j<planetas;j++)
        {
            wx[j]=vx[j]+hmid*ax[j];
            wy[j]=vy[j]+hmid*ay[j];

            x[j]+=h*wx[j];
            y[j]+=h*wy[j];
        }

        //Nuevas aceleraciones
        acel(x,y,ax,ay,m,planetas);

        //Nuevas velocidades
        for(j=0;j<planetas;j++)
        {
            vx[j]=wx[j]+hmid*ax[j];
            vy[j]=wy[j]+hmid*ay[j];
        }
    }

    return;
}