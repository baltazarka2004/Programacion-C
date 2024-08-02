/*Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados). Se pide
determinar el/los empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a
cero.
a. Los números de legajo son números correlativos de 1 a 100*/



#include<stdio.h>
#define ce 100
int carga(int[]);
int validar(int,int, int);
int mayor(int[], int[]);
void mostrar(int[],int);
int main()
{
    int Vsueldo[ce]={0};
    int Vmayor[ce]={0};
    int cont,cont_m;
    cont=carga(Vsueldo);
    cont_m=mayor(Vsueldo,Vmayor);
    mostrar(Vmayor,cont_m);
}




int carga(int V1[])
{
    int sueldo,legajo,cont,val;
    cont=0;
    do
    {
        printf("\nIngresar legajo del trabajador(de 1-100,0 para finalizar): ");
        scanf("%d",&legajo);
        if(val=validar(0,100,legajo)!=1)
        printf("\nlegajo no valido, vovler a ingresar\n");

    } while (val=validar(0,100,legajo)!=1);
    while (legajo!=0 && cont<=100)
    {
        do
        {
            printf("\ningresar sueldo del empleado: ");
            scanf("%d",&sueldo);
            if(sueldo<0)
            printf("\nsueldo menor a cero");

        }while (sueldo<0);
        V1[legajo-1]=sueldo;
        cont++;
        do
        {
        printf("\nIngresar legajo del trabajador(de 1-100,0 para finalizar): ");
        scanf("%d",&legajo);
        if(val=validar(0,100,legajo)!=1)
        printf("\nlegajo no valido, vovler a ingresar\n");

        } while (val=validar(0,100,legajo)!=1);

        
        
    }

    return cont;
    
    


    
}

int validar (int inf, int sup, int var)
{
    if(var<=sup && var>=inf)
    return 1;
    else
    return 0;
}

int mayor(int V1[], int V2[])
{
    int i, sueldo_may = V1[0], cont = 0;
    for (i = 0; i <= ce - 1; i++)
    {
        if (i == 0 || sueldo_may < V1[i])
         {  
             sueldo_may = V1[i];
         }
    }


    for (i = 0; i < ce - 1; i++)
    {
        if (sueldo_may == V1[i])
           {
            V2[cont] = i;
            cont++;
           }
    }
    return cont;
}



void mostrar(int v2[], int cont)
{
    int i;
    printf("\nempleado con mayor sueldo: \n");
    for(i=0;i<cont;i++)
    {
        printf("%d",v2[i+1]);
    }
}