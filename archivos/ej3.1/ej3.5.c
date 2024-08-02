/*Se dispone de un archivo llamado Stock.dat que contiene la información de los 10 productos que vende una
fábrica. En el archivo se guarda:
• Código de artículo (entero)
• Descripción (50 caracteres máximo)
• Stock (entero)
Guía Práctica – V1.0 3 / 8
Luego se ingresan por teclado las ventas a realizar indicando:
• Código de artículo
• Cantidad
 La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stock de dicho producto, sino
hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la
cantidad que no pudo venderse, dicho registro debe contener:
• Código de artículo
• Cantidad
Se genera un registro por cada venta que no pudo concretarse, pudiendo quedar en el archivo varios
registros faltantes del mismo producto.
Al finalizar actualizar el archivo Stock.dat con el stock actualizado luego de procesar las ventas.

*/

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int cod;
    char des[51];
    int stock;
}info;
void carga(info[],int);
int buscar(info[],int,int);
int validar(int,int);
void noStock(info[],int,int);
int main()
{
    FILE *pf;
    pf = fopen("Stock.dat","rb");
    if(pf == NULL)
    {
        printf("\nno se pudo abrir el archivo");
        getch();
        exit(1);
    }
    info produ[10],aux;
    int i;
    i=0;
    fread(&aux,sizeof(info),1,pf);
    while (fread(&aux, sizeof(info), 1, pf) == 1)
    {
        produ[i]=aux;
        fread(&aux,sizeof(info),1,pf);
        i++;
    }
    fclose(pf);
    carga(produ,i);
    


}


void carga(info v[],int ce)

{
    FILE * pf;
    int val,cant,code,cant_nodisp,i;
    do
    {
        printf("\ningresar codigo del producto: ");
        scanf("%d",&val);
        if(validar(0,val)== 0 && buscar(v,val,ce) == -1)
            printf("\ncodigo invalido o no existente");
        
    }while (validar(0,val)== 0 && buscar(v,val,ce) == -1);
    
    while (val != 0)
    {
        code = buscar(v,val,ce);
        do
        {
            printf("\ningrese cantidad a vender: ");
            scanf("%d",&cant);
            if(validar(0,cant)== 0)
                printf("\ncantidad negativa");
            
        } while (validar(0,cant)== 0);
        if(v[code].stock >= cant)
            v[code].stock = v[code].stock - cant;
        else
            {
                cant_nodisp = cant - v[code].stock;
                noStock(v,code,cant_nodisp);
                v[code].stock = 0;
            }
        do
        {
            printf("\ningresar codigo del producto: ");
            scanf("%d",&val);
            if(validar(0,val)== 0 && buscar(v,val,ce) == -1)
                printf("\ncodigo invalido o no existente");
            
        }while (validar(0,val)== 0 && buscar(v,val,ce) == -1);
            
    }
    pf = fopen("Stock.dat","wb");
    if(pf==NULL)
    {
        printf("\n2222 no se pudo abrir el archivo");
        getch();
        exit(1);
    }
    for(i=0;i<ce;i++)
    {
        fwrite(&v[i],sizeof(info),1,pf);
    }
    fclose(pf);
    printf("\narchivo actuializado");
}


int buscar(info v[],int code, int ce)
{
    int i,pos = -1;
    while (pos == -1 && i < ce)
    {
        if(code == v[i].cod)
            pos = i;
        else
            i++;
    }
    return pos;
    
}

int validar(int inf,int val)
{
    if (inf <= val)
        return 1;
    else 
        return 0;
}


void noStock(info v[],int code,int cant)
{
    FILE * pf;
    
    pf = fopen("Faltantes.dat","ab");
    if(pf==NULL)
    {
        printf("\n3333 no se pudo abrir el archivo");
        getch();
        exit(1);
    }
    fwrite(&cant,sizeof(int),1,pf);
    fwrite(&v[code].cod,sizeof(info),1,pf);
    fclose(pf);



}

