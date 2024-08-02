#include<stdio.h>
int main ()
{
    #define cantidad 2
    int nota1,nota2,promedio;
    printf("ingresar nota de evaluacion: ");
    scanf("%d",&nota1);
    printf("ingresar segunda nota: ");
    scanf("%d",&nota2);
    promedio=(nota1+nota2)/cantidad;
    printf("\n su promedio es de: %d",promedio);
}
