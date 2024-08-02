/*La empresa TODOLIMPIO que comercializa un máximo de 25 productos, dispone del archivo
“LIMPIEZA.dat”, donde cada registro contiene:
• Número de Artículo (entero, 5 cifras)
• Unidades en stock (entero)
• Precio unitario (real)
Cada vez que se realiza una venta se ingresa por teclado, los siguientes datos:
• Número de Cliente (1 a 20) Función LEE_CONTROL
• Número de Artículo (entero, 5 cifras). Función LEE_CONTROL
• Cantidad de Unidades Vendidas. Función MAYORCERO.
Esta información termina con número de cliente igual a 0.
Si la cantidad de unidades vendidas es superior al stock existente de cada uno de los productos, NO realizar
la venta y marcarla para un posterior reporte.
Se solicita confeccionar un programa que actualice el archivo “PRODUCTOS.dat” y e informar:
a. La facturación total por cliente.
b. La cantidad de veces que cada cliente realizó una compra.
c. Emitir un listado ordenado por monto de facturación de forma descendente de acuerdo con el
siguiente diseño:
CLIENTE MONTO FACTURADO CANTIDAD DE VECES
QUE REALIZÓ UNA
COMPRA
XXX XXX,XX XX
d. Emitir un listado con el número de artículos que no se pudo realizar las ventas por falta de stock.
e. Actualizar el archivo “LIMPIEZA.dat”, en UNIDADES en STOCK según las ventas ingresadas.*/

#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int art;
    int stock;
    float preU;
} info;

typedef struct 
{
    float fact[20];
    int cont_c[20];
    int no_stock[25];

}general;

void carga(info[],general,int);// tiene que habe un  vector acumulador para la facturacion total de cada cliente, un vector contador 
//ademas cada vez que no pueda vender tiene que haber un vector que informe
void inicializar(general);
void vclientes(int[],int);
void listado_ordenado(general,int);//mando el vector de la facturacion y el vector contador, dentro creo un vector con los numeros de los clientes
void falta (info[],general,int); // mando las dos structuras para recorrer y mando la cantidad de articulos que no tienen stock suficinete
void actualizar(info[],general,int); //al final de todo actualizo el archivo
int buscar(info[],int);
int lee_control(int,int,int);
int mayor(int,int);
int main()
{

FILE*pf;
int i;
info v[25],aux;
general total;
inicializar(total);
pf = fopen("limpieza.dat","rb");
if(pf==NULL)
{
    printf("\nEl archivo no se pudo abrir");
    getch();
    exit(1);
}
i=0;
fread(&aux,sizeof(info),1,pf);
while (!feof(pf))
{
    v[i]=aux;
    fread(&aux,sizeof(info),1,pf);
    i++;
}
fclose(pf);
carga(v,total,i);
return 0;

}


void carga(info v[], general total, int ce)
{
    FILE * pf;
    int val,num,pos,cant,i;
    float preT;
    do
    {
        printf("\ningresar numero de cliente (1-20, 0 pára finalizar): ");
        scanf("%d",&val);
        if(lee_control(0,20,val)==0)
            printf("\nCliente no valido");
        
    }while(lee_control(0,20,val)==0);
    while (val != 0)
    {
       do
        {
            printf("\ningresar numero del articulo: ");
            scanf("%d",&num);
            pos = buscar(v,num);
            if(lee_control(0,99999,num)==0 && pos == -1)
                printf("\nArticulo no valido");
            
        }while(lee_control(0,99999,num)==0 && pos == -1);
        do
        {
            printf("\ningresar cantidad de unidades vendidas: ");
            scanf("%d",&cant);
            if(mayor(0,cant) == 0)
                printf("\nCantidad no valida");
        }while(mayor(0,cant) == 0);
        if (cant <= v[pos].stock)
        {
            total.fact[val] = total.fact[val] +(v[pos].art * v[pos].preU);
            total.cont_c[val]++;
            v[pos].stock -= cant;
            printf("\npago relizado");
            getch();
            system("clr");

        }
        else
        {
            printf("\nNo hay stock suficiente");
            total.no_stock[pos] = 1;
        }
        do
        {
            printf("\ningresar numero de cliente (1-20, 0 pára finalizar): ");
            scanf("%d",&val);
            if(lee_control(0,20,val)==0)
                printf("\nCliente no valido");
            
        }while(lee_control(0,20,val)==0);
        
    }
    system("clr");
    printf("\nFACTURACION TOTAL:");
    for(i=0;i<ce;i++)
        printf("\ncliente numero %d\t%f",i,total.fact[i]);
    
    printf("\nCantidad de veces compradas por cliente: ");
    for(i=0;i<ce;i++)
        printf("\ncliente num:%d\tcantidad de compras: %d",i,total.cont_c[i]);
    system("pause");
    system("clr");
    listado_ordenado(total,ce);
    getch();
    falta(v,total,ce);
    actualizar(v,total,ce);
}




void listado_ordenado(general total,int ce)
{
    int i,j;
    float aux;
    int aux2;
    int v2[20];
    vclientes(v2,20);
    for(i=0;i<ce-1;i++)
        for(j=0;j<ce-1-i;j++)
            if(total.fact[j] < total.fact[j+1])
            {
                aux = total.fact[j];
                total.fact[j] = total.fact[j+1];
                total.fact[j+1] = aux;

                aux2 = total.cont_c[j];
                total.cont_c[j] = total.cont_c[j+1];
                total.cont_c[j+1] = aux2;

                aux2  = v2[j];
                v2[j] = v2[j+1];
                v2[j+1] = aux2;

            }


    printf("\nCLIENTE\t\t\tMONTO\t\t\tCANTIDAD DE COMPRAS");
    for(i=0;i<ce;i++)
        printf("\n%-7d\t\t\t%-5f\t\t\t%d",v2[i],total.fact[i],total.cont_c[i]);
}



void vclientes(int v[], int ce)
{
    int i;
    for(i=0;i<ce;i++)
        v[i]=i+1;
}




void falta(info v[], general total,int ce)
{
    int i;
    printf("\nArticulos con falta de stock: ");
    for(i=0;i<ce;i++)
        if(total.no_stock[i] == 1)
            printf("\n%d",v[i].art);
}




void actualizar(info v[],general total,int ce)
{
    FILE * pf;
    int i;
    info aux;
    pf = fopen("limpieza.dat","wb");
    if(pf==NULL)
    {
        printf("\nEl archivo no se pudo abrir");
        getch();
        exit(1);
    }
    for (i=0; i < ce ; i++)
    {
        fwrite(&v[i],sizeof(info),1,pf);
    }
    
    
}



int lee_control(int inf,int sup,int val)
{
    if ( inf <= val && sup >= val)
        return 1;
    else
        return 0;
}


int mayor(int inf,int val)
{
    if(inf <= val)
        return 1;
    else
        return 0;
}