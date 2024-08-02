#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} ingreso;

typedef struct {
    int legajo;
    char ape[16];
    char nom[31];
    ingreso fecha;
    int cat;
} empleado;
void ordenar();
void mostrar();
int main()
{
   void ordenar();
   void mostrar();
}


void ordenar()

{
 FILE *pf;
    empleado actual, anterior;
    int primR = 1,ultiI,cont,ordenado;
    pf = fopen("empeleados.dat","r+b");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir elarchivo");
        getch();
        exit(1);
    }
    do
    {
        ordenado=1;
        fread(&anterior,sizeof(empleado),1,pf);
        cont = 1;
        while ((primR && !feof(pf)) || (!primR && cont <= ultiI))
        {
            fread(&actual,sizeof(empleado),1,pf);
            cont++;
            if(!feof(pf))
            {
                if(anterior.legajo>actual.legajo)
                {
                    fseek(pf,sizeof(empleado)*-2,1);
                    fwrite(&actual,sizeof(empleado),1,pf);
                    fwrite(&anterior,sizeof(empleado),1,pf);
                    ultiI = cont;
                    ordenado = 0;
                }
                else 
                    anterior = actual;
                
            }
        }
        primR=0;
        rewind(pf);
    }while(!ordenado);
    fclose(pf);
}

void mostrar()
{
    FILE *pf;
    empleado info;
    pf = fopen("empleados.dat","rb");
    printf("\nlistado de empleados:");
    fread(&info,sizeof(empleado),1,pf);
    while(!feof(pf))
    {
        printf("\n%d\t%16s\t%31s",info.legajo,info.ape,info.nom);
        fread(&info,sizeof(empleado),1,pf);

    }
    fclose(pf);
}