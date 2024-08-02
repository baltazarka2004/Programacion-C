#include <stdio.h>

void condicion(float, float, float);
float mayor_valor(float, float, float);
float promedio(float, float, float);
float suma(float, float, float);
int verificar_orden(float, float, float);
int main()
{
    float num1,num2,num3;
    printf("ingresar una terna de numeros (ponerlos de forma ordenada creciente para finalizar el ingreso): ");
    scanf("%f %f %f",&num1,&num2,&num3);
    condicion(num1,num2,num3);
    return 0;
}

void condicion(float n1,float n2,float n3)
{
    int opcion,orden;
    float result;
    orden=verificar_orden(n1,n2,n3);
    while (orden!=1 && opcion!=4)
    {

        do{
            printf("\n** opciones posibles *\n1- Mayor valor\n2- Promedio\n3- Suma\n4- Finalizar\n* digite su opcion: ");
            scanf("%d",&opcion);
            if(opcion<1||opcion>4)
            printf("\nopcion invalida\n");

        }while(opcion<1||opcion>4);

        switch (opcion)
        {
            case 1:
            result=mayor_valor(n1,n2,n3);
            printf("\nel mayor numero dentro de la terna es: %.2f",result);
            break;
            case 2:
                result=promedio(n1,n2,n3);
                printf("\nel promedio  de la terna es: %.2f",result);
                break;
            case 3:
            result=suma(n1,n2,n3);
            printf("\nla suma de la terna es: %.2f",result);

            break;

        case 4:
            break;
        }
        printf("\ningresar una terna de numeros (ponerlos de forma ordenada creciente para finalizar el ingreso): ");
        scanf("%f %f %f",&n1,&n2,&n3);
        orden=verificar_orden(n1,n2,n3);

    }

}

float mayor_valor(float n1,float n2, float n3)
{
    float mayor;
    mayor=n1;
    if(n2>mayor)
    mayor=n2;
    if(n3>mayor)
    mayor=n3;
    return mayor;
}
float suma(float n1,float n2,float n3)
{
    float suma;
    suma=n1+n2+n3;
    return suma;
}
float promedio(float n1,float n2,float n3)
{
    float prom;
    prom=suma(n1,n2,n3);
    prom/=3;
    return prom;
}
int verificar_orden(float n1, float n2, float n3) {
    if (n1 <= n2 && n2 <= n3) {
        return 1;  // Terna ordenada en forma creciente
    } else {
        return 0;  // Terna no ordenada
    }
}
