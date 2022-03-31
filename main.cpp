#include "functions.h"
#include <stdio.h>
#include "math.h"


int main()
{
    int n=8,i;
    double r[n+1][2],v[n+1][2],a[n+1][2],w[n+1][2];
    double M[n+1];
    double aux1,aux2,aux3;
    

    M[0]=Ms;

    FILE *f1,*f2,*f3,*fr;

    f1=fopen("distancias.txt","r");
    f2=fopen("masas.txt","r");
    f3=fopen("velocidades.txt","r");


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

    
    for(i=1;i<=n;i++)
    {
        printf("Radio %i es: %lf\n",i,r[i][0]);
        printf("Velocidad %i es: %lf\n",i,v[i][1]);
        printf("Masa %i es: %lf\n",i,M[i]);
    }
    
    
    return 0;

}