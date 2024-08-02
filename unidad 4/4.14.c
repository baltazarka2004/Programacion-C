#include<stdio.h>
int main()
{
    int imp,desc,nimp;
    printf("ingrese el importe a pagar:\n");
    scanf("%d",&imp);
    if (imp>100)
    {
        desc=imp*10.5/100;
        nimp=imp-desc;
    }
    else
        if (imp>=55&&imp<=100)
    {
        desc=imp*8/100;
        nimp=imp-desc;
    }
    else
        desc=imp*4.5/100;
        nimp=imp-desc;
    printf("\nel descuento es de $%d y el importe a pagar es de $%d",desc,nimp);
}
