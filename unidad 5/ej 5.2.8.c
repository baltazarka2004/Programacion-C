#include <stdio.h>
int main()
{
    int cont,vuelta,prim,num,d;
    cont=0;
    vuelta=0;
    prim=2;
 do
    {
        printf("ingresar cantidad de numeros primos que quiere\n");
        scanf("%d",&num);
        if(num<0)
            printf("numero invalido (debe de ser mayor a 0)");

    }while (num<0);
    while(num>0)
        for (d=2;d<=prim;d++)
    {
        if(prim%d==0)
            cont++;

    }
    if(cont<=2)
        printf("%d \n",prim);
    prim++;
    vuelta++;
}
