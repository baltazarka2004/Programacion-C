/*
Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo se
encuentra ordenado por sucursal y contiene la siguiente estructura:
• Sucursal (15 caracteres máximo)
• Código de producto (entero)
• Cantidad (entero)
Por otro lado, se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
• Código de producto (entero)
• Descripción (20 caracteres máximo)
• Precio (float)
• Stock (entero)
• Punto de pedido (entero)
• Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos, pero sí se sabe que no hay más de 200. Se desea:
a. Mostrar el importe total vendido en cada sucursal.
b. Mostrar la recaudación total de la empresa en el mes.
c. Determinar la sucursal que vendió mayor cantidad de productos.
d. Actualizar el archivo de productos con el nuevo stock.
e. Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mes queden
con stock menor al punto de pedido. 
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
    char suc[16];
    int code;
    int cant;
}info; 
typedef struct
{
    int code;
    char des[21];
    float pre;
    int stock;
    int ped;
    int cantP;
}venta;//no hay más de 200

int cargararch(venta[],int);
void import(venta[],info,int);
int main()
{
    info suc;
    venta v[200];
    int max = 200, ce;
    ce = cargararch(v,max);
    import(v,suc,ce);
    

}

int cargararch(venta v[], int ce)
{
    FILE * pf;
    int i;
    venta aux;
    pf = fopen("ventas.dat","rb");
    if(pf == NULL)
    {
        printf("\nnose pudo abrir el archivo");
        getch();
        exit(1);

    }
    fread(&aux,sizeof(venta),1,pf);
    i=0;
    while (!feof(pf))
    {
        v[i]= aux;
        fread(&aux,sizeof(venta),1,pf);
        i++;


    }
    fclose(pf);
    return i;

}

void import(venta v[], info suc, int ce)
{
    FILE * pf;
    info aux;
    int sucant;
    pf = fopen("productos.dat","rb");
    if(pf == NULL)
    {
        printf("\nnose pudo abrir el archivo");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(info),1,pf);
    while(!feof(pf))
    {
        suc=aux;
        sucant = suc.suc;
        
    }

}
