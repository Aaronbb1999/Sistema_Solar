#include "functions.h"
#include <stdio.h>
#include "math.h"


int main()
{
    int n=8,i, iter;
    double r[n+1][2],v[n+1][2],a[n+1][2],w[n+1][2];
    double M[n+1];
    double aux1,aux2,aux3;
    double h;
    

    M[0]=1;

    FILE *f1,*f2,*f3,*fr;

    //Abrimos los ficheros
    f1=fopen("distancias.txt","r");
    f2=fopen("masas.txt","r");
    f3=fopen("velocidades.txt","r");
    fr=fopen("Resultados.txt","w");

    //Recogemos los datos iniciales de los ficheros
    for(i=1;i<=n;i++)
    {
        fscanf(f1,"%lf",&aux1);
        fscanf(f2,"%lf",&aux2);
        fscanf(f3,"%lf",&aux3);
        r[i][0]=aux1;
        v[i][1]=aux3;
        M[i]=aux2;
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("Elige el paso de la iteracion\n:");
    scanf("%lf",&h);
    printf("Elige el número de iteraciones de la simulación\n:");
    scanf("%i",&iter);

    //Rescalamos las masas

    for(i=0;i<=n;i++)
    {
        M[i]=M[i]/Ms;
    }

    //Rescalamos las velocidades
    for(i=1;i<=n;i++)
    {
        v[i][1]=(v[i][1]/c)/sqrt((G*Ms)/(c*c*c));
    }   

    //Algoritmo de Verlett
    acel(a,r,M,n);
    for(i=1;i<=iter;i++)
    {
        fprintf(fr,"%lf,%lf\t%lf,%lf\t%lf,%lf\t%lf,%lf\t%lf,%lf\t%lf,%lf\t%lf,%lf\t%lf,%lf\t%lf,%lf\n",r[0][0],r[0][1],r[1][0],r[1][1],r[2][0],r[2][1],r[3][0],r[3][1],r[4][0],r[4][1],r[5][0],r[5][1],r[6][0],r[6][1],r[7][0],r[7][1],r[8][0],r[8][1]);
        posic(r,v,a,h,n);
        omega(w,v,a,h,n);
        acel(a,r,M,n);
        veloc(w,v,a,h,n);
    }
    
    fclose(fr);
    
    return 0;

}
