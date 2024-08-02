#include<stdio.h>
void carga(int[],int);
void invertir(int[],int[],int);
void mostrar(int[],int);
int main()
{
    int veca[10];
    int vecb[10];
    carga(veca,10);
    invertir(veca,vecb,10);
    mostrar(vecb,10);
    return 0;
}
void carga(int v1[],int x)
{
    int i,num;
    
    printf("ingresar numeros: \n");
    for(i=0;i<=x-1;i++)
    {
        scanf("%d",&num);
        v1[i]=num;
    }
}
void invertir(int v1[],int v2[], int x)
{
    int i;
    for(i=0;i<=x-1;i++)
    {
        v2[i]=v1[x-1-i];

    }
}
void mostrar(int v1[],int x)
{
    int i;
    for ( i = 0; i<=x-1; i++)
    {
        printf("%d ",v1[i]);
    }
    
}   