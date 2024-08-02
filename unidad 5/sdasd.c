#include <stdio.h>
int main( )
{
 int cont, suma, i, num;
 cont = 0;
 suma = 0;
for ( i = 1; i <= 50; i++)
{


printf("\n Ingrese un numero: ");
scanf("%d", &num);
if (num < 0)
cont = cont + 1;
else
suma = suma + num;

printf("La cantidad de numeros negativos es %d \n", cont);
printf("La sumatoria de los numeros positivos es %d \n",
suma);
return 0;

if (num < 0)
    cont = cont + 1;
else
suma = suma + num;
}
printf("La cantidad de numeros negativos es %d \n", cont);
printf("La sumatoria de los numeros positivos es %d \n",
suma);
return 0;
}
