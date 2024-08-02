#include<stdio.h>
int main()
{
    int num,i=0,fac=1;
    printf("ingresar un numero: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
       {

        fac*=i;
       }

    printf("el factorial de %d es: %d",num,fac);
}
