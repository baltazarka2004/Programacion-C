#include<stdio.h>
int main ()
{
    int num1,num2,num3;
    printf("ingresar tres numero distintos: ");
    scanf("%d%d%d",&num1,&num2,&num3);
    if (num1>num2 && num1>num3)
    printf("\nel mayor es %d",num1);
    else
    if(num2>num3 && num2>num1)

    printf("\nel mayor es: %d",num2);
    else
    printf ("\nel mayor es: %d",num3);



}
