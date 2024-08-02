#include<stdio.h>
#define PI 3.14
int main()
{
    int valor;
    float grados,rad;
    printf("ingrese: 1 para grados o 2 para radiantes ");
    scanf("%d",&valor);
    switch (valor)
    {
        case 1: printf ("\ningrese los grados: ");
        scanf("%f",&grados);
        rad=180/PI;
        rad=rad*grados;
        printf("\nsu valor de grados a radianes es: %.2f",rad);
        break;
        case 2: printf("\ningrese los radianes: ");
        scanf("%f",&rad);
        grados= (PI/180)*rad;
        printf(" su valor de radianes convertidoa grados es de: %.2f°",grados);
        break;

    }
}
