#include <stdio.h>
int main()
{
    int cont=0, cant=0,dni,n1,n2;
    float prom=0;
    printf("ingresar el dni del alumno-numero negativo si desea finalizar la operacion\n");
    scanf("%d",&dni);
    while (dni>0)
    {
        printf("\ningresar las notas del alumno (2):\n");
        scanf("%d",&n1);
        scanf("%d",&n2);
        if (n1>=7 && n2>=7)
        {
            printf("\nel alumno con dni: %d, obtuvo las notas %d y %d [Aprobado]",dni,n1,n2);
            cont++;
            cant++;
            prom+=n1+n2;
        }
        else
        {


            if(n1>=4 && n2>=4)
            {


               printf("\nel alumno con dni: %d, obtuvo las notas %d y %d [Final]",dni,n1,n2);
                cont++;
            }
            else
            {
                printf("\nel alumno con dni: %d, obtuvo las notas %d y %d [Desaprobado]",dni,n1,n2);
                cont++;
                }
            }

        printf("\ningresar el dni del alumno-numero negativo si desea finalizar la operacion\n");
        fflush(stdin);
        scanf("%d",&dni);
    }
    if (cont>0)
    {
        prom=prom/(cant*2);
        printf("\nel promedio de notas de los promocionados es de %.2f",prom);
    }
    else
        printf("no se ingresaron alumnos");
}

