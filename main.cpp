#include "functions.h"
#include <stdio.h>
#include "math.h"


int main()
{

    int planetas=9, i,j,iter,k;
    double x[planetas],y[planetas],vx[planetas],vy[planetas],ax[planetas],ay[planetas],M[planetas];
    double inicialx[planetas],inicialy[planetas],anteriorx[planetas],anteriory[planetas];
    double xtierra[planetas], ytierra[planetas];
    double L[planetas],LTotal;
    double h,t;
    int vuelta[planetas];
    

    FILE *f1,*fr,*ft,*fl;

    //Abrimos los ficheros
    f1=fopen("condiciones_iniciales.txt","r");
    fr=fopen("Resultados.dat","w");
    ft=fopen("Resultados_tierra.dat", "w");
    fl=fopen("Momento_Ang.dat", "w");

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

    /*Posibles modificaciones a las condiciones iniciales 
    
    M[3]+=M[3]*0.1;
    M[4]-=M[3]*0.2;
    x[3]+=x[3]*0.1;
    y[3]+=y[3]*0.1;
    x[2]-=x[2]*0.1;
    y[2]-=y[2]*0.1;

    */


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

    //Preparamos variables para calcular los periodos orbitales
    for(i=0;i<planetas;i++)
    {
        vuelta[i]=0;
        inicialx[i]=x[i];
        inicialy[i]=y[i];
        anteriorx[i]=x[i];
        anteriory[i]=y[i];
    }

    //Recogemos los resultados 
    for(i=0;i<k;i++)
    {   
        //Rellenamos archivo de posiciones
        for(j=0;j<planetas;j++)
        {
            fprintf(fr,"%lf, %lf\n",x[j],y[j]);
        }
        fprintf(fr,"\n");

        verlett(x,y,vx,vy,ax,ay,M,planetas,h,iter);

        t+=h*iter;

        //Calculo de los periodos orbitales.
        for(j=1;j<planetas;j++)
        {
            if(anteriory[j]<inicialy[j] && y[j]>inicialy[j] && inicialx[j]>0 && vuelta[j]<1)  
            {
                printf("El periodo del planeta %i es %lf\n",j, t*58.1);
                vuelta[j]++;
            }

            if(anteriory[j]>inicialy[j] && y[j]<inicialy[j] && inicialx[j]<0 && vuelta[j]<1)  
            {
                printf("El periodo del planeta %i es %lf\n",j, t*58.1);
                vuelta[j]++;
            }  

        }
        for(j=1;j<planetas;j++)
        {
            anteriorx[j]=x[j];
            anteriory[j]=y[j];
        }


        //Calculo de cantidades conservadas
        LTotal=0;
        for(j=0;j<planetas;j++)
        {
            L[j]=M[j]*(x[j]*vy[j]-y[j]*vx[j]);
            LTotal+=L[j];
        }
        fprintf(fl,"%lf\n",LTotal);


        //Cambio de coordenada modelo geocentrico.
        for(j=0;j<planetas;j++)
        {
            xtierra[j]=x[j]-x[3];
            ytierra[j]=y[j]-y[3];
            fprintf(ft,"%lf, %lf\n",xtierra[j],ytierra[j]);
        }
        fprintf(ft,"\n");
    }

    fclose(fr);
    fclose(ft);
    fclose(fl);
    
    return 0;

}
