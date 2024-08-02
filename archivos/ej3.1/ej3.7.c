/*Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas a lo
largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)
El mes tiene 30 días y se sabe que como máximo cada aerolínea realiza 5 vuelos diarios. Luego se dispone de un
segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes para la aerolínea
con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)
Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
con la información de los pasajeros que realizar los viajes. Al finalizar, grabar la información en un nuevo
archivo llamado Aero1.dat. Agregar la opción para exportar el archivo Aero1 a formato csv.*/
#include <stdio.h>
#include<stdlib.h>
typedef struct 
{
    char cod[11];
    int dia;
    int n_vue;
    float pre;
    int pas;
}info;
typedef struct 
{
    int dni;
    int vuelo;
}pasajeros;
void carga(int);
int main()
{
    FILE * vuel, *pasa,*aer;
    int i=0;
    vuel = fopen("vuelos.dat","rb");
    if(vuel==NULL)
    {
        printf("\nno se abrio el archivo");
        getch();
        exit(1);
    }
    while(!feof())
    {
        
        i++;
    }
    fclose(vuel);
    carga(i);
}


void carga(int cant)
{
    FILE *vuel, *pasa,*aer;
    info pasa[cant];
    char cod[11];
    int i=0;
    printf("\ningrese el codigo de la aerolinea: ");
    gets(cod);
    
    
}
