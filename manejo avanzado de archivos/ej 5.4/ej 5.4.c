#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int validar(int,int,int);
empleado buscar(empleado,int ,char[]);
int main()
{
    FILE *pf;
    int opcion,legajo;
    char ape[16];
    empleado info,encontrado;
    do
    {
    printf("MENU DE BUSQUEDA\n1)-Busqueda por legajo\n2)-Busqueda por apellido\n3)-salir\nDigite su opcion:");
    scanf("%d",&opcion);
    if(validar(opcion,1,3)==0)
    {
        system("pause");
        system("cls");
        printf("opcion invalida");
    }
    }while(validar(opcion,1,3)==0);
    while (opcion != 3)
    {
        system("pause");
        system("cls");
        if (opcion == 1)
        {
            printf("\ningresar legajo: ");
            scanf("%d",&legajo);
        }
        else
        {
            printf("\ningresar apellido: ");
            fflush(stdin);
            gets(ape);
        }
        encontrado  = buscar(info, legajo ,ape);

    }
    
}


empleado buscar (empleado info, int legajo, char ape[])
{
    FILE *pf;
    empleado encontrado;
    int inicio,mitad,fin;
    int hayado=0;
    pf=fopen("empleado.dat","r+b");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir elarchivo");
        getch();
        exit(1);
    }
    inicio = 0;
    fseek(pf,0,2);
    fin = ftell(pf) / sizeof(empleado),
    mitad = (fin + inicio)/2;

    fseek(pf,mitad*sizeof(empleado),0);
    fread(&encontrado,sizeof(empleado),1,pf);

    while (inicio <= fin && (info.legajo != legajo || strcmpi(ape,info.ape) != 0))
    {
        if()
    }
    
}