#include<stdio.h>
int main ()
{
    int anio,mes;
    printf("ingrese el anio y mes de nacimiento: ");
    scanf("%d%d",&anio,&mes);
    if (anio%4>0)
        switch (mes)
    {
        case 1: printf("\nel mes tiene 31 dias"); break;
        case 2: printf("\nel mes tiene 29 dias"); break;
        case 3: printf("\nel mes tiene 31 dias"); break;
        case 5: printf("\nel mes tiene 31 dias"); break;
        case 7: printf("\nel mes tiene 31 dias"); break;
        case 8: printf("\nel mes tiene 31 dias"); break;
        case 10: printf("\nel mes tiene 31 dias"); break;
        case 12: printf("\nel mes tiene 31 dias"); break;
        default: printf("\nel mes tiene 30 dias");


    }
    else
        switch(mes)
    {
        case 1: printf("\nel mes tiene 31 dias"); break;
        case 2: printf("\nel mes tiene 28 dias"); break;
        case 3: printf("\nel mes tiene 31 dias"); break;
        case 5: printf("\nel mes tiene 31 dias"); break;
        case 7: printf("\nel mes tiene 31 dias"); break;
        case 8: printf("\nel mes tiene 31 dias"); break;
        case 10: printf("\nel mes tiene 31 dias"); break;
        case 12: printf("\nel mes tiene 31 dias"); break;
        default: printf("\nel mes tiene 30 dias");
    }
}
