#include<stdio.h>
int main()
{
    int valor,hora,sueldo;
    printf("ingrese el valor de sus horas: ");
    scanf("%d",&valor);
    printf("ingrese el total de horas trabajadas: ");
    scanf("%d",&hora);
    if(hora>150)
    {
        sueldo=(hora*valor)+1000;

    }
    else
        sueldo=(hora*valor)+500;
    printf("su sueldo es de: $%d",sueldo);
}
