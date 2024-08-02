#include <stdio.h>
#include <ctype.h>
int main()
{
    int cont=0,sueldo,anio,hijos,empl,sueldof=0;
    float prom;
    char resp,estudio;
    do{
    printf("ingrese el numero de empleado- 'S' si - 'N' no\n");
    fflush(stdin);
    scanf("%c",&resp);
    resp=toupper(resp);
    if (resp!= 'S' || resp!= 'N')
        printf ("\nrespuesta no valida %c \n",resp);
    }while (resp=='S' || resp=='N');

}
