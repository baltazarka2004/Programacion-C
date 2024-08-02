/*
El INTA desea conocer las plantaciones existentes en una zona determinada
y para ello recorre cada chacra/estancia y consulta qu� tienen sembrado.
No se conoce ni la cantidad de establecimientos a censar ni la cantidad
posible de especies de cultivo para la zona.
Para ello ingresar� por teclado los datos necesarios para completar el
archivo SIEMBRA.DAT que posee la siguiente estructura:
    Especie          --> (string 20 caracteres m�ximo)
    Establecimientos --> (contador entero)
    Hectareas 		  -->(Acumulador flotante)
En el archivo se cuentan y acumulan tipos de sembrad�o y hect�reas
sembradas del mismo en el total de establecimientos censados.
Si la especie sembrada no existe previamente se agregar� al archivo y si
ya existe, se cuenta como un nuevo establecimiento sembrado y se acumulan
las hect�reas sembradas.
La carga culmina con una especie llamada �FIN�
Al finalizar:
    1) Mostrar un listado con los datos cargados Indicando Especie sembrada,
       cantidad de establecimientos que la sembraron y cantidad de hect�reas
       sembradas.
    2) Indicar cu�ntos cultivos distintos existen en la zona.
    3) Antes de cerrar el programa cambiar el nombre del archivo por otro
       que se ingresa por teclado

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char especie[21];
    int est;
    float hec;
}plantas;

int validarH(float,int);
void nombre(char[]);
void mostrar();
int main()
{
    FILE * pf;
    plantas siembra;
    int band;
    char esp[21];
    float cant;
    pf = fopen("siembra.dat","w+b");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo");
        getch();
        exit(1);

    }
    printf("\ningresar nombre la especie: ");
    fflush(stdin);
    gets(esp);
    while (strcmpi(esp,"fin")!=0)
    {
       do
       {
        printf("\ningresar cantidad de hectareas: ");
        scanf("%f",&cant);
        if(validarH(cant,0)==0)
            printf("\ncantidad negativa");
       } while (validarH(cant,0)==0);
        rewind(pf);
        band=0;
        fread(&siembra,sizeof(plantas),1,pf);
        while (band == 0 && !feof(pf))
        {
            if(strcmpi(esp,siembra.especie)==0)
            {
                band = 1;
            }
            else
                fread(&siembra,sizeof(plantas),1,pf);

            if(band == 0)
            {
                strcpy(siembra.especie,esp);
                siembra.est=1;
                siembra.hec = cant;

                fflush(pf);

                fwrite(&siembra,sizeof(plantas),1,pf);
            }
            else
            {
                siembra.est++;
                siembra.hec+=cant;
                fseek(pf,sizeof(plantas)*(-1),1);
                fwrite(&siembra,sizeof(plantas),1,pf);

            }


        }
        printf("\ningresar nombre la especie: ");
        fflush(stdin);
        gets(esp);


    }
    fclose(pf);
    mostrar();
    printf("\n ingrese nombre para el archivo: ");
    fflush(stdin);
    gets(esp);
    nombre(esp);
    return 0;
}


int validarH(float val,int inf)
{
    if (val > inf)
        return 1;
    else
        return 0;
}

void mostrar()
{
    FILE *pf;
    plantas sembrado;
    int especies;
    pf=fopen("siembra.dat","r+b");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo");
        getch();
        exit(1);
    }
    especies = 0;
    printf("\n aca estoy");
    rewind(pf);
    fread(&sembrado,sizeof(plantas),1,pf);
    while (!feof(pf))
    {
        especies++;
        printf("\nel cultivo %20s tiene un total de %d establecimientos y un total de %.2f de hectareas",sembrado.especie,sembrado.est,sembrado.hec);
        fread(&sembrado,sizeof(plantas),1,pf);
    }
    printf("\n hay un total de %d especies en la zona",especies);
    fclose(pf);





}

void nombre(char nombrenuevo[])
{
    if( rename("simbra.dat",nombrenuevo)==0)
        printf("\nombre cambiado");
    else
        printf("\nno se pdo cambiar el nombre");

}
