/*Se dispone de un archivo con nombre Llamadas.dat que contiene llamadas telefónicas realizadas en una
empresa. Por cada llamada se dispone de la siguiente información:
• Sector (15 caracteres máximo)
• Duración en segundos (entero)
• Tipo de llamada (entero: 1 local, 2 larga distancia, 3 celular)
El archivo se encuentra organizado por Sector. Se solicita:
a. Calcular y mostrar por cada sector, la cantidad de llamadas realizadas de cada tipo.
b. Determinar cuál es el sector que habló la mayor cantidad de tiempo.
c. En un archivo llamado costos.dat hay un único registro que contiene los costos por segundo de los
tres tipos de llamadas (3 float). Se debe generar el archivo gastos.dat que totalice los gastos de
llamadas de cada sector.
d. Realizar una función que muestre los datos almacenados en gastos.dat en forma de listado.
e. Generar un archivo para cada sector con el detalle de llamadas valorizado. El archivo se debe
generar con nombresector.dat y debe contener:
• Duración en segundos (entero)
• Tipo de llamada (entero)
• Costo de la llamada (float)*/

#include <stdio.h>

#include<stdlib.h>

#include<string.h>

typedef struct
{

    char sec[16];

    int duracion;

    int tipo;

}llamada;

typedef struct 
{
    float tipo1;

    float tipo2;

    float tipo3;

}costos;

typedef struct

{
    char sec[16];

    float gast;

}gastos;

typedef struct 
{
    int dura;

    int tipo;

    float costo;
}sectores;


void iniciar(int[],int);

void cargar(costos);

void cargargast(char[],float);

void mostrar();

void generalsector(llamada,costos);


int main()
{
    llamada info;

    costos cost;

    float gasto;

    int tipos[3]= {0};

    char sector[16];

    char secM[16];
    
    int band = 0,duracion,i,maydur;

    FILE *pf;

    pf = fopen("LLAMADAS.dat","rb");

    if ( pf == NULL )

    {   
        printf("\n1) el archivo no se abrio");

        getch();

        exit(1);

    }
    cargar(cost);

    fread(&info,sizeof(llamada),1,pf);

    while (!feof(pf))
    {

        strcpy(sector,info.sec);

        printf("\ntipo de llamadas de sector:%s ",sector);

        iniciar(tipos,3);
        
        gasto = 0;

        duracion=0;

        while (!feof(pf) && strcmpi(sector,info.sec) == 0)
        {
            for(i=0;i<3;i++)
                if(info.tipo == i+1)
                {  
                    tipos[i]++;
                }

            if(info.tipo == 1)

                gasto += cost.tipo1*info.duracion;

            else if(info.tipo == 2 )

                gasto += cost.tipo2*info.duracion;

            else

                gasto += cost.tipo3*info.duracion;

            duracion = info.duracion;

            generalsector(info,cost);

            if(band == 0 || duracion > maydur)
            {
                maydur = duracion;

                strcpy(secM,sector);

                band = 1;
            }

            fread(&info,sizeof(llamada),1,pf);
            
        }
        for(i=0;i<3;i++)
            printf("\ntipo %d: %d",i,tipos[i]);
        cargargast(sector,gasto);
        
    }

    getch();

    system ("clear");

    printf("\nel sector : %s, fue el que tuvo la llamada mas larga\nduracion: %d",secM,maydur);

    getch();

    system ("clear");

    mostrar();

    fclose(pf);
    
    


    
}

void iniciar(int v[],int ce)
{
    int i;

    for(i=0;i<ce;i++)
    
        v[i]=0;
    

}

void cargar(costos cost)
{
    FILE *pf;
    pf = fopen("costos.dat","rb");
    fread(&cost,sizeof(costos),1,pf);
    fclose(pf);
}

void cargargast(char sector[],float gasto)
{
    gastos aux;
    FILE * pf;
    pf = fopen("gastos.dat","ab");
    if ( pf == NULL )
    {   
        printf("\n2) el archivo no se abrio");
        getch();
        exit(1);
    }
    aux.gast = gasto;
    strcpy(aux.sec,sector);
    fwrite(&aux,sizeof(gastos),1,pf);
    fclose(pf);

}

void mostrar()
{
    gastos v,aux;

    FILE * pf;

    pf = fopen("gastos.dat","rb");

    if ( pf == NULL )

    {   
        printf("\n3) el archivo no se abrio");

        getch();

        exit(1);

    }
    fread(&aux,sizeof(gastos),1,pf);

    printf("\nSector\t\t\tGastos");

    while(!feof(pf))
    {
        v=aux;

        printf("\n%-6s\t\t\t%-6.2f",v.sec,v.gast);

        fread(&aux,sizeof(gastos),1,pf);
    }
    getch();

    system("clear");

    fclose(pf);

}

void generalsector(llamada info, costos cost)
{

    FILE * pf;
    pf = fopen(info.sec,"wb");
    sectores v;
    if ( pf == NULL )

    {   
        printf("\n4) el archivo no se abrio");

        getch();

        exit(1);

    }
    if(info.tipo == 1)

        v.costo = cost.tipo1*info.duracion;

    else if(info.tipo == 2 )

        v.costo = cost.tipo2*info.duracion;

    else

        v.costo = cost.tipo3*info.duracion;

    v.dura=info.duracion;
    
    v.tipo=info.tipo;

    fwrite(&v,sizeof(sectores),1,pf);

    fclose(pf);

}
