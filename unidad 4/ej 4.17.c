#include<stdio.h>
#include<ctype.h>
int main ()
{
    int hist,imp;
    char cod;

    printf("ingresar numero de historial del pasiente: ");
    scanf("%d",&hist);
    getchar();
    printf("ingresar codigo de la presentacion medica: ");
    scanf("%c",&cod);
    toupper(cod);
    printf("%c",cod);
    switch (cod)
    {
        case 'A': imp=20;
    break;
        case 'D': imp=40;
    break;
        case 'F': imp=60;
    break;
        case 'm':
        case 't': imp=150;
    break;
        default: printf("\nel codigo seleccionado no tiene un importe asignado");



    }
    printf("\nel numero de historial es: %d\nel codigo seleccionado es: %c\nel importe a pagar es de $%d",hist,cod,imp);
}

