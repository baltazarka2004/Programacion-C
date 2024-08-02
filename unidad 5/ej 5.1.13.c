#include<stdio.h>
int main()
{
    int prim=0,cont=0,i=0,j=0;
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=i;j++)
        {
            if (i%j==0)
                cont++;
        }
        if (cont==2||cont==1)
            prim++;
        printf("%d\n",i);
        cont=0;
    }
    printf("la cantidad de numeros primos es de: %d",prim);
}
