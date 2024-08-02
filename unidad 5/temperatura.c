#include<stdio.h>
int main()
{
    int cont;
    float temp,prom,suma;
    suma=0;
    cont=0;
    scanf("%f",&temp);
    while (temp!=0)
    {
        suma+=temp;
        cont++;
        scanf("%f",&temp);
    }
    if (cont>0)
    {
        prom=suma/cont;
        printf("el promedio es %.2f",prom);
    }
    else
        printf("no se ingresaron tmeperaturas");
}
