#include<stdio.h>
#include<stdlib.h>
#define expensas 1000
void ponerenx(char[][5],int,int);
int carga(char[][5],int,int);
int validar(int,int,int);
void mostrar(char[][5],int,int,int);
int main()
{
    char mat[15][5];
    int total;
    ponerenx(mat,15,5);
    total=carga(mat,15,5);
    mostrar(mat,15,5,total);
}



void ponerenx(char mat[][5],int dto,int piso)
{
    int i,j;
    for(i=0;i<=dto-1;i++)
    {
        for(j=0;j<=piso-1;j++)
        {
            mat[i][j]='x';
        }
    }
}




int carga(char mat[][5],int dto,int piso)
{
    int depto,n_piso,val,cont=0,total;
    do
    {
        printf("\ningresar piso(1-5): ");
        scanf("%d",&n_piso);
        if(val=validar(1,5,99)==0)
            printf("\npiso no valido");
        
    }while(val=validar(1,5,99)==0);
    while (n_piso!=99 && cont<15*5)
    {
        do
        {
            printf("\ningresar departamento(1-15): ");
            scanf("%d",&depto);
            if(val=validar(1,15,15)==0)
                printf("\ndepartamenti no valido");
            
        }while (val=validar(1,15,15)==0);
        cont++;
        mat[depto-1][piso-1]=' ';
        do
        {
            printf("\ningresar piso(1-5): ");
            scanf("%d",&n_piso);
            if(val=validar(1,5,99)==0)
                printf("\npiso no valido");  
        } while (val=validar(1,5,99)==0);
        
        
    }
    total=cont*expensas;
    return total;
    
}




void mostrar(char mat[][5],int dto,int piso,int total)
{
    int i,j;
    printf("\n\t\t\ttotal recaudado: %d\n\t\t\tdepartamentos deudores\npiso");
    for(i=0;i<=dto-1;i++)
    {
        printf("\t\t\tdepto %d",i+1);
    }
    for (i=0;i<=piso-1;i++)
    {
        for(j=0;j<=dto-1;j++)
            printf("\t\t\t%c",mat[j][i]);
    }
    
}
