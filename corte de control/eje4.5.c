/*En un estadio de fútbol se incorporó un nuevo sistema para censar la cantidad de espectadores que pasan
por cada una de las entradas de forma de analizar el comportamiento de la gente y poder diseñar una mejor
distribución de las vías de acceso.
El estadio tiene 15 puertas numeradas del 1 al 15. La recolección de datos se realizó en todos los partidos
disputados en el estadio a lo largo de varios meses para poder tener un volumen de información suficiente
que permita realizar un análisis.
La información registrada se encuentra en un archivo con la siguiente estructura:
• Código del Evento (texto de 10 caracteres máximo)
• Número de puerta (entero)
• Cantidad de Espectadores (entero)
La información se haya ordenada por Código de Evento. Se solicita calcular y mostrar:
a. Cantidad de espectadores por cada evento.
b. El evento con menor cantidad de espectadores.
c. Grabar un archivo con el promedio de espectadores que ingresaron por cada una de las 15 entradas.
en todos los eventos analizados, informando el número de puerta y promedio*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
    char evento[11];
    int puerta;
    int cant;
}info;
typedef struct 
{
    int puerta;
    float prom;
}promedios;

void cant(info);
void prom_puerta(info,promedios);
int main()
{
    FILE * pf;
    info eventos,aux;
    promedios prom;
    cant(eventos);
    prom_puerta(eventos,prom);
}
void cant(info event)
{
    FILE *pf;
    info aux;
    int cant,band=0,men_cant;
    char event_ant[11];
    char evento_menor[11];
    pf = fopen("eventos.dat","rb");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo");
        getch();
        exit(1);
    }
    printf("\ncantidad total de personas por evento:");
    fread(&event,sizeof(info),1,pf);
    while(!feof(pf))
    {
        
        strcpy(event_ant,event.evento);
        cant = 0;
        while (!feof(pf) && strcmpi(event_ant,event.evento)==0) //punto a, calculo POR EVENTO la cantidad total de espectadores
        {
            cant += event.cant;
            fread(&event,sizeof(info),1,pf);
        }
        printf("\nel evento %s tuvo una cantidad total de %d espectadores",event_ant,cant); 
        if(band == 0 || men_cant > cant)   //punto b cada vez que termine el ciclo del corte de contrtol, veo si el total de los eventos es menor al aterior o no 
        {                                     //con eso almaceno la info necesariay vital
            men_cant = cant;
            strcpy(evento_menor,event_ant);
            band = 1;
        }
        
    }
    printf("\nel evento con menos pesonas fue el %s",evento_menor);
    fclose(pf);
}

void prom_puerta(info eventos ,promedios promedio)  //punto c , calculamos el promedio porpuerta
{
    FILE *pf;
    int puertas[15] = {0}; // vector acumulador por puertas
    int cont_puert[15] = {0}; // vector contador
    int puerta,i;
    pf = fopen("eventos.dat","rb");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo");
        getch();
        exit(1);
    }
    fread(&eventos,sizeof(info),1,pf);
    while (!feof(pf))
    {
        puerta = eventos.puerta;
        puertas[puerta-1]  += eventos.cant;   //acumula la cantidad de gente total y cuantas veces aparece  x gente en x puerta para dsp poder hacer el promedio
        cont_puert[puerta-1]++;
        fread(&eventos,sizeof(info),1,pf);

    }
    for(i=0;i<15;i++)
    {
        promedio.puerta = i+1;
        promedio.prom = puertas[i] / cont_puert[i];
        fwrite(&promedio,sizeof(promedios),1,pf);
    }
    fclose(pf);
}
