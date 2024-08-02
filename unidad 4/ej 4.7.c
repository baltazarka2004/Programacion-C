#include<stdio.h>
int main()
{
    int l1,l2,l3;
    printf("ingrese 3 valores enteros,positivos y mayores a 0:\n");
    scanf("%d%d%d",&l1,&l2,&l3);
    if (l1+l2>l3&&l1+l3>l2&&l2+l3>l1)
    {
        printf("con los valores %d, %d, %d se puede formar un triangulo",l1,l2,l3);
    }
    else
        printf("no se puede formar un triangulo");
}
