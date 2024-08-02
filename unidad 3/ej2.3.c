#include<stdio.h>
int main()
{
    int num1,num2,suma,prod,cos,rest;

    printf("ingrese un numero entero: ");

    scanf("%d",&num1);

    printf("\n ingrese otro numero entero: ");

    scanf("%d",&num2);

    suma=num1+num2;

    prod=num1*num2;

    cos=num1/num2;

    rest=num1%num2;

    printf("\n el resultado de operar %d y %d es: ",num1,num2);

    printf("\n suma: %d",suma);

    printf("\n producto: %d",prod);

    printf("\n cosiente: %d ",cos);

    printf("\n resto: %d",rest);
    return 0;
}
