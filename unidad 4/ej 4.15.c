#include<stdio.h>
int main ()
{
    int dvd,precio,desc,n1;
    printf("ingrese la cantidad de dvds a comprar(maximo 500 dvds): ");
    scanf("%d",&dvd);
    if (dvd>=50)
    {
        precio=((dvd/50)*500)+((dvd%50)*15);
        if (dvd>100)
        {



            desc=precio*10/100;
            precio=precio-desc;
        }
    }



        else
            if(dvd>10 && dvd<50)

{
            precio=((dvd/10)*120)+((dvd%10)*15);
}
        else
                precio=dvd*15;




    printf("\nel precio a pagar es $%d",precio);
}
