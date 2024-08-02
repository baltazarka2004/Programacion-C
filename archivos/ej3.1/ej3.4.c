/*Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo original se llama precios.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
No se sabe la cantidad de registros del archivo.
Se solicita generar un nuevo archivo llamado Precios_actualizados.dat.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int cod;
    float pre;
    char des[51];
}produ;
int validarAUM(int,int);
int main()
{
    produ articulo;
    int i=0;
    float aum;
    FILE * pf,*arch;
    pf = fopen("precios.dat","rb");
    arch = fopen("Precios_actualizados.dat","wb");
    if (pf == NULL || arch == NULL)
    {
        printf("\nno se puedo abrir el archivo");
        getch();
        exit(1);
    }
    do
    {
        printf("\n ingrese el porsentaje de aumento de precios de los articulos:");
        scanf("%f",&aum);
        if(validarAUM(0,aum) == 0)
            printf("\nvalor negativo, colcer a ingresar");
    }while(validarAUM(0,aum) == 0);
    aum = aum/100;
    
    fread(&articulo,sizeof(produ),1,pf);
    articulo.pre= articulo.pre + (articulo.pre*aum);
    while(!feof(pf))
    {
        fwrite(&articulo,sizeof(produ),1,arch);
        fread(&articulo,sizeof(produ),1,pf);
        articulo.pre= articulo.pre + (articulo.pre*aum);
    }

    fclose(pf);
    fclose(arch);

}


int validarAUM(int inf, int val)
{
    if (inf < val)
        return 1;
    else
        return 0;
}