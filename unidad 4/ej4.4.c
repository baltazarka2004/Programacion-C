#include<stdio.h>
int main ()
{
    int num1,num2,num3;
    printf("ingrese 3 valores: ");
    scanf("%d%d%d",&num1,&num2,&num3);
    if (num1>num3 && num2>num3)

        printf("mayores al tercero");
        else
            if(num1==num2 && num2==num3)

            printf("tres iguales");
            else
                printf("alguno es menor");

}
