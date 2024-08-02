#include<stdio.h>

int main ()
{
    int num1,num2,resto,coc;
 printf(" ingresar dos numeros: ");
 scanf("%d""%d",&num1,&num2);
 coc=num1/num2;
 resto=num1%num2;
 if (resto==0)
 {
     printf("%d es divisible por %d",num1,num2);
 }
 else
    printf("%d no es divisible por %2d",num1,num2);
}
