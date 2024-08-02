#include<stdio.h>
int main()
{
    int cod,cant;
    float precio,desc;
    printf("ingrese el codigo del articulo: ");
    scanf("%d",&cod);
    printf("\ningrese la cantidad de unidades a comprar: ");
    scanf("%d",&cant);
    switch (cod)
    {
        case 1:
        case 10:
        case 100:
            precio=cant*10;
            break;
        case 2:
        case 22:
        case 222:
            precio=((cant/10)*65)+((cant%10)*65);
            break;
        case 3:
        case 33:
        case 333:
            if (cant>=10)
            {


                desc=(cant*3)*0.1;
                precio=(cant*3)-desc;
            }
            else
                precio=cant*3;
                break;
                default: printf("\nel codigo utulizado no tiene un articulo vinculado");

    }
    printf("\nel importe a pagar es de: $%.2f\n",precio);

}
