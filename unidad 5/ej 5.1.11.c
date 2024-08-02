#include<stdio.h>
int main()
{
    int tern=0,terp=0,post=0,neg=0,t=0,temp;
    for(t=1;t<=18;t++)
    {
        printf("ingresar temperatura: ");
        scanf("%d",&temp);
        if(temp>0)
        {
            post++;
            neg=0;
        }
        else
        {
            neg++;
            post=0;
        }
        if(post>=3)
            terp++;
        else
        {
            if(neg>=3)
                tern++;
        }

    }
    printf("\nhay %d de ternas positivas y hay %d de ternas negativas",terp,tern);
}
