#include<stdio.h>
int main()
{
    int i=0,j=0,perf,cont=0;
    for(i=1;i<=9000;i++)
    {
        for(j=1;j<i;j++)
        {
            if(i%j==0)
                perf+=j;
        }
        if(perf==i)
        {
            cont++;
            printf("%d\n",i);
        }
        perf=0;
    }
    printf("la cantidad de numeros perfectos comprendidos entre el 1 y el 9000 son: %d",cont);
}
