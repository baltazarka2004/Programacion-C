#include<stdio.h>
int main()
{
    char car;
    printf("ingrese un caracter: ");
    scanf("%c",&car);
    switch (car)

       {
           case 'a':
           case 'e':
               case 'i':
               case 'o':
               case 'u': printf("\nsu caracter es una vocal y tiene como valor el numero: %d\n",car);
           break;
           default: printf("\nsu caracter no es una vocal y tiene como valor numerico el numero: %d\nx",car);


       }

}
