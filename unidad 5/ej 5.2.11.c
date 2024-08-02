#include <stdio.h>
int main ()
{
    int max = 0, num,may,may2 = 0;
    printf ("ingrese un numero entero - utilice el 0 para finalizar la operacion \n");
    scanf("%d",&num);
    while (num != 0)
    {
        if(max == 0||num>may)
        {
            max = 1;
            may2 = may;
            may = num;

        }
        else
        {
            if (num > may2)
                may2=num;
        }
        printf("ingesar otro numero - utuilizar 0 para finalizar:\n");
        scanf("%d",&num);
    }
    printf("el numero mayor es %d y el que le sigue es %d",may,may2);
    return 0;
}
