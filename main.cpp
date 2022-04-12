#include "functions.h"
#include <stdio.h>
#include "math.h"


int main()
{

    int planetas=9, i,j, iter,k;
    double x[planetas],y[planetas],vx[planetas],vy[planetas],ax[planetas],ay[planetas],M[planetas];
    double aux1,aux2,aux3,aux4,aux5;
    double h;
    

    FILE *f1,*fr;

    //Abrimos los ficheros
    f1=fopen("condiciones_iniciales.txt","r");
    fr=fopen("Resultados.txt","w");

    //Recogemos los datos iniciales del fichero
    for(i=0;i<planetas;i++)
    {
        fscanf(f1,"%lf, %lf, %lf, %lf, %lf",&aux1,&aux2,&aux3,&aux4,&aux5);
        x[i]=aux1;
        y[i]=aux2;
        vx[i]=aux3;
        vy[i]=aux4;
        M[i]=aux5;
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

    //Rescalamos las velocidades
    for(i=0;i<planetas;i++)
    {
        vx[i]=vx[i]*58.1;
        vy[i]=vy[i]*58.1;
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
