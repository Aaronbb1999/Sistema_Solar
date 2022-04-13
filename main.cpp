#include "functions.h"
#include <stdio.h>
#include "math.h"


int main()
{

    int planetas=9, i,j, iter,k;
    double x[planetas],y[planetas],vx[planetas],vy[planetas],ax[planetas],ay[planetas],M[planetas];
    double h;
    

    FILE *f1,*fr;

    //Abrimos los ficheros
    f1=fopen("condiciones_iniciales.txt","r");
    fr=fopen("Resultados.dat","w");

    //Recogemos los datos iniciales del fichero
    for(i=0;i<planetas;i++)
    {
        fscanf(f1,"%lf, %lf, %lf, %lf, %lf",&x[i],&y[i],&vx[i],&vy[i],&M[i]);
    }

    fclose(f1);

    printf("Elige el paso de la iteracion\n:");
    scanf("%lf",&h);
    printf("Elige el numero de iteraciones por evolucion\n:");
    scanf("%i",&iter);
    printf("Elige el numero de datos a tomar\n:");
    scanf("%i",&k);

    //Rescalamos las masas
    for(i=0;i<planetas;i++)
    {
        M[i]=M[i]/Ms;
    }

    //Rescalamos posiciones
    for(i=0;i<planetas;i++)
    {
        x[i]=x[i]/c;
        y[i]=y[i]/c;
    }   

    //Rescalamos las velocidades
    for(i=0;i<planetas;i++)
    {
        vx[i]=vx[i]*58.1*24*60*60/c;
        vy[i]=vy[i]*58.1*24*60*60/c;
    }   

    //Recogemos los resultados 
    for(i=0;i<=k;i++)
    {
        for(j=0;j<planetas;j++)
        {
            fprintf(fr,"%lf, %lf\n",x[j],y[j]);
        }
        fprintf(fr,"\n");

        verlett(x,y,vx,vy,ax,ay,M,planetas,h,iter);
    }

    
    fclose(fr);
    
    return 0;

}
