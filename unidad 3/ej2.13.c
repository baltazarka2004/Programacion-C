#include<stdio.h>
int main()
{
    int numero,cifra,cifra2,cifra3,aux,resul,resulf;
    printf("ingrese un numero positivo de 4 cifras: ");
    scanf ("%d",&numero);
    cifra=numero/1000;
    aux=numero%1000;
    cifra2=aux/100;
    aux=aux%100;
    cifra3=aux/10;
    aux=aux%10;
    resul=cifra+cifra2+cifra3+aux;
    resulf=resul/10;
    aux=resul%10;
    resulf=resulf+aux;
    resulf=(resulf/10)+(resulf%10);
    printf("\n tu resultado es: %d",resulf);
}


