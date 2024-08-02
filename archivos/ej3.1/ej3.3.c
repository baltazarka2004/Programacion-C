#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int cod;
    float pre;
    char des[51];
}product;
void modificar(product[],int);
void actualizar(product[],int);
int buscar(product[],int,int);
void exportar(product[],int);
int main()
{
    product vP[100],aux;
    int i,ce=100;
    FILE * pf;
     //abro elarchivo
    if( (pf = fopen("productos.dat","rb")) == NULL)  //pregunto sise abrio o no
    {
        printf("falla en la apertura del archivo");
        getch();
        exit(1);
    }
    i=0;
    fread(&aux,sizeof(product),1,pf); //leo el archivo y lo guardo en un vectorde producto
    while(!feof(pf))
    {
        vP[i]=aux;
        fread(&aux,sizeof(product),1,pf); //leo el archivo y lo guardo en un vectorde producto
        i++;
    }
    fclose(pf);
    modificar(vP,i);
    actualizar(vP,i);
    exportar(vP,i);
    return 0;

}

 

void modificar(product vP[], int ce)
{
    int val,pos;
    float precio;
    do
    {
        printf("\ningrear codigode producto");
        scanf("%d",&val);
        if(val < 0)
            printf("\nvalor negativo, volver a ingresar");

    }while(val < 0);
    while(val != 0)
    {
        pos = buscar(vP,val,ce);
        if(pos != -1)
        {


            do
            {
                printf("\ningresar precio del producto: ");
                scanf("%f",&precio);
                if(precio < 0)
                        printf("\nprecio negativo");

            }while(precio < 0);
            vP[pos].pre = precio;
        }
        else
            printf("\n no se encontro el producto");
        do
        {
            printf("\ningrear codigode producto");
            scanf("%d",&val);
            if(val < 0)
                printf("\nvalor negativo, volver a ingresar");

        }while(val < 0);
    }
}

 

int buscar(product vP[],int code,int ce)
{
    int i = 0,pos=-1;
    while(i < ce && pos == -1)
    {
        if(vP[i].cod == code)
            pos = i;
        else
            i++;
    }
    return pos;
}


void actualizar(product vP[],int ce)
{
    FILE * pf;
    int i;
    pf = fopen("productos.dat","wb");
    if(pf == NULL)
    {
        printf("\n1111No se abrio el archivo");
        getch();
        exit(1);
    }
    for(i=0;i<ce;i++)
    {
        fwrite(&vP[i],sizeof(product),1,pf);
    }
    fclose(pf);
}

void exportar(product vP[],int ce)
{
    FILE * pf;
    int i;
    pf = fopen("productos.csv","wt"); // si no existe LO CREA
    if(pf == NULL)
    {
        printf("\n222222No se abrio el archivo");
        getch();
        exit(1);
    }
    fprintf(pf,"Codigo;Precio;Descripcion");
    for(i=0;i<ce;i++)
    {
        fprintf(pf,"\n%d;%.2f;%s",vP[i].cod,vP[i].pre,vP[i].des);
    }
    fclose(pf);

}