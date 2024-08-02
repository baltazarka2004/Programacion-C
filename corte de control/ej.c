/*
Un banco tiene el archivo secuencial SALDOS, con los saldos de sus casi 20000 clientes de Caja de Ahorro,
 al inicio del mes.  
Cada registro tiene los siguientes datos:

Número de Caja de Ahorro (entero, de 6 cifras)
Apellido Y Nombre (alfanumérico de 30 caracteres)
Saldo (real, mayor o igual a cero)
Existe además un segundo archivo secuencial con los movimientos del mes, 
llamado MOVI, ordenado por sucursal del banco. Cada registro contiene:

Sucursal del Banco (entero de 4 cifras no correlativo)
Número de Cuenta de Ahorro
Mes (entero)
Día (entero)
Código de Operación (entero: 1à depósito (suma al saldo); 2à extracción (resta al saldo))
Importe (real, mayor que cero)
En el caso de las extracciones, antes de proceder a realizar la resta del importe al saldo, 
evaluar si éste es mayor al importe (no puede quedar saldo negativo en la Caja de Ahorro). 
 En este caso, guardar en el archivo SIN_SALDO los datos que vienen en el archivo MOVI.

Confeccionar un programa para que:

a) Se actualice el archivo SALDOS con los movimientos registrados.*/



#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int numC;
    char ayn[31];
    float saldo;

}data;
typedef struct 
{
    int suc;
    int numC;
    int mes;
    int dia;
    int ope;
    float imp;

}movimientos;


int main()
{
    FILE *pf, *arch,*no_saldo;
    movimientos move;
    data cliente[20000],aux;
    int i,ce;
    pf = fopen("saldos.dat","rb");
    arch = fopen("movi.dat","rb");
    no_saldo = fopen("sin_saldo","wb");
    if ( arch == NULL || pf == NULL || no_saldo == NULL)
    {   
        printf("\nel archivo no se abrio");
        getch();
        exit(1);
    }
    i=0;
    fread(&aux,sizeof(data),1,pf);
    while (!feof(pf))
    {
       cliente[i] = aux;
       while (!feof(arch))
       {
        fread(&move,sizeof(movimientos),1,arch);
        if(cliente[i].numC == move.numC)
        {
            if (move.ope == 1)
            {
                cliente[i].saldo += move.imp;
            }
            else 
            {
               if(cliente[i].saldo > move.imp)
                    cliente[i].saldo -= move.imp;
                else
                    fwrite(&move,sizeof(movimientos),1,arch);
               
            }
            
            
        }
        i++;
       }
       fclose(pf);
       fclose(no_saldo);
       fclose(arch);


       ce = i; 
       pf = fopen("saldos.dat","wb");
       if (pf == NULL)
        {   
            printf("\nel archivo no se abrio");
            getch();
            exit(1);
        }
       for(i=0;ce<i;i++)
        fwrite(&cliente[i],sizeof(data),1,pf);
        
    }
    

}

