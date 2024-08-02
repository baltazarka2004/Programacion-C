#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int dia;
    int mes;
    int anio;
}ingreso;

typedef struct 
{
    int legajo;
    char ape[16];
    char nom[31];
    ingreso fecha;
    int cat;

}empleados;
int main()
{
    FILE *pf;
    empleados info;
    pf = fopen("empleados.dat","rb");
    fread(&info,sizeof(empleados),1,pf);
    while(!feof(pf))
    {
        printf("\n%d        %16s    %31s     %d     %d",info.legajo,info.ape,info.nom,info.fecha.anio,info.cat);
        fread(&info,sizeof(empleados),1,pf);

    }
    fclose(pf);
}