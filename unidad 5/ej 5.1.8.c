#include<stdio.h>
int main ()
{
    int cont=0,may=0,men=0,edad,i=0;
    float alt,sume,suma;
    for(1;i<=45;i++)
    {
        printf("ingresar edad y altura del estudiante: ");
        scanf("%d%f",&edad,&alt);
        if(edad>10)
            may++;
        if(alt<1.40)
            men++;
        sume+=edad;
        suma+=alt;
        cont++;

    }
    printf("\nde los 45 alumnos ingresado se pudo extraer los siguientes datos:\npromedio de edad:%.2f \naltura promedio:%.2f \ncantidad de alumnos mayores a 10:%d \ncantidad de alumnos ue miden menos de 1.40 cm: %d",sume/cont,suma/cont,may,men);

return 0;
}
