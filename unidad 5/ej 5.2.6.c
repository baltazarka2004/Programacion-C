#include <stdio.h>
int main()
{
    int cont,imp;
    float prom,desc,impf;
    cont=0;
    prom=0;
    desc=0;
    printf("ingresar importe a pagar-ingresar un numero igual o menor a cero para finalizar operacion\n");
    fflush(stdin);
    scanf("%d",&imp);
    while (imp>0)
    {
        if (imp<50)
        {
            cont++;
            desc=(0.035*imp);
            impf=imp-desc;
            prom+=imp;
        }
        else
        {
            if(imp>=50 && imp<=150)
            {
                cont++;
                desc=(float)(0.1*imp);
                impf=imp-desc;
                prom+=imp;
            }
            else
            {
                if(imp>=151 && imp<=300)
                {
                    cont++;
                    desc=(float)(0.2*imp);
                    impf=imp-desc;
                    prom+=imp;

                }
                else
                {
                    cont++;
                    desc=(float)(0.25*imp);
                    impf=imp-desc;
                    prom+=imp;

                }
            }

        }
        printf("\nel descuento a efectuar es de $%.2f y el importe a pagar es de $%.2f\n",desc,impf);
        printf("ingresar importe a pagar-ingresar un numero igual o menor a cero para finalizar operacion\n");
        fflush(stdin);
        scanf("%d",&imp);

    }
    prom=(float)prom/cont;
    printf("\nel importe promedio de vemtas es de $%.2f",prom);
}
