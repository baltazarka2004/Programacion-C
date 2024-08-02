/*Se dispone del archivo binario PRECIOS.DAT con datos de productos según la siguiente estructura:
• Código de Producto (entero)
• Descripción (texto de 20 caracteres máximo)
• Precio (float)
Realizar un programa que permita modificar el precio y/o la descripción de productos dado su código.
El programa debe permitir modificar varios precios finalizando con un código de producto igual a 0.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int code;
    char des[21];
    float pre;

}info;
typedef struct
{
    char des[21];
    float pre;
}modificaciones;

int datovalido();
void modific (modificaciones);

int main()
{
    FILE *pf;

    int codigo,band,val;

    modificaciones cambios;

    info producto;

    pf = fopen("precios.dat","r+b");

    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo");
        exit(1);
    }

    codigo = datovalido();



    while (codigo != 0)
    {
        printf("\ningrese nueva descripcion o vieja:");
        fflush(stdin);
        gets(cambios.des);
        do
        {
            printf("\ningresar nuevo precio o antiguo: ");
            scanf("%f",&cambios.pre);
            if(cambios.pre<0)
                printf("\nprecio invalido");

        }while(cambios.pre<0);

        band=0;
        fread(&producto,sizeof(info),1,pf);
        while (!feof(pf) && band == 0)
        {
            if(producto.code == codigo)
            {

                band=1;
                strcpy(producto.des,cambios.des);
                producto.pre=cambios.pre;
            }
            else
                fread(&producto,sizeof(info),1,pf);
                
        }
        if(band == 1)
        {
            fseek(pf,sizeof(info)*(-1),1);
            fwrite(&producto,sizeof(info),1,pf);
        }
        else
            printf("\ncodigo no encontrado");
        codigo = datovalido();
    }
    fclose(pf);

}



int datovalido()
{
    int val;
    do
    {
        printf("\ningrese codigo de producta a modificar:");
        scanf("%d",&val);
        if(val < 0)
            printf("\ndato invalido");

    }while(val < 0);
    return val;
}


void modific(modificaciones cambios)
{
    printf("\ningrese nueva descripcion o vieja:");
    fflush(stdin);
    gets(cambios.des);
    do
    {
        printf("\ningresar nuevo precio o antiguo: ");
        scanf("%f",&cambios.pre);
        if(cambios.pre<0)
            printf("\nprecio invalido");

    }while(cambios.pre<0);
}
