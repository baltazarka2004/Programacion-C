/*3.9 Una fábrica produce como máximo 20 productos diferentes y necesita un reporte de la producción realizada
durante el año. Para ello se dispone del archivo “ARTICULOS.dat”, el cual contiene:
• Código de artículo (entero de 4 cifras no correlativo)
• Descripción del artículo (30 caracteres máximo)
• Cantidad de stock remanente del año anterior (entero)
A continuación, se procesa por teclado, la información correspondiente a todo el año:
• Número del mes de producción. Ingresar y controlar mediante la Función LEE_CONTROL.
• Código de artículo (entero de 4 cifras no correlativo) Ingresar y controlar un número de 4 cifras.
Función LEE_CONTROL.
• Cantidad de unidades que se produjeron en ese mes. Controlar si el número es mayor que 0.
Función MAYOR_CERO.
Esta información no se encuentra ordenada, y termina con número de mes igual a 0.
Se solicita construir un programa que determine e informe:
a. Para cada artículo, la cantidad de unidades producidas en cada uno de los 12 meses del año, de
acuerdo con el siguiente modelo:
Código Artículo Descripción Ene. Feb. … Oct. Nov. Dic.
XXX XXXXXXXXX XX XX … XX XX XX
XXX XXXXXXXXX XX XX … XX XX XX
b. Confeccionar un listado con el/los códigos y descripción de aquellos artículos que NO se produjeron
en todo el año.
c. Generar el archivo actualizado llamado “ARTI_ACTUALIZADO.dat” con la suma del stock remanente
del año anterior más la cantidad producida en el primer trimestre del presente año*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int code;
    char des[31];
    int stock;
}info;
void carga(info[],int);                                                         //LISTO
int lee_control(int,int,int);  //una funcion para controlar                    // LISTO
int mayor_cero(int,int);   //para ver si es mayoa a ceor                        //LISTO
int no_correlativo(int); //para ver que los numero no sean correlativos         //listo
int buscar(int,info[],int); //busca la pos del codigo                           //listo
void todo_cero(int[][12],int,int); //inicializa la matriz en 0                  //listo
void mostrar(info[],int[][12],int,int);  //FALTA
void art_nopro(int[][12],int,int,info[]);   //crea un listado de articulos que no se producieron //FALTA
int main()
{
    FILE *pf;
    info v_prod[20],aux;
    int i=0;
    
    pf = fopen("articulos.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo se pudo abrir el archivo");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(info),1,pf);
    while (!feof(pf))
    {
        v_prod[i]=aux;
        fread(&aux,sizeof(info),1,pf);
        i++;
    }
    fclose(pf);
    carga(v_prod,i);
}



//FUNCIONES
    void carga(info v[],int ce)  //funcion principal
    {
        FILE *pf;
        int mes,i,cod,cant,pos;
        int product[ce][12];
        todo_cero(product,ce,12);  //inicializo la matriz
        do //pregunto sobre el mes de produccion
        {
            printf("\nIngresar mes de produccion: ");
            scanf("%d",&mes);
            if(lee_control(0,12,mes)==0)
                printf("\nNumero de mes erroneo");
                
        }while(lee_control(0,12,mes)==0);
        while(mes!=0)
        {
            do   //pregunto sobre el codgio
            {
                printf("\nIngrese el codigo del producto(no correlativo):");
                scanf("%d",&cod);
                if(lee_control(0,9999,cod) == 0 && no_correlativo(cod) == 0)
                    printf("\nCodigo invalido");
                
            }while (lee_control(0,9999,cod) == 0 && no_correlativo(cod) == 0);
            do //pregunto sobre la cantidad producida
            {
                printf("\nIngrese la cantidad de articulos que se produjeron:");
                scanf("%d",&cant);
                if(mayor_cero(0,cant)==0)
                    printf("\nCantidad invalido");
                
            }while (mayor_cero(0,cant) == 0);
            pos = buscar(cod,v,ce); //busco la posision del codigo
            product[pos][mes] += cant; //y almaceno
            v[pos].stock += cant;
            do //pregunto sobre el mes de produccion
            {
                printf("\nIngresar mes de produccion: ");
                scanf("%d",&mes);
                if(lee_control(0,12,mes)==0)
                    printf("\nNumero de mes erroneo");
                    
            }while(lee_control(0,12,mes)==0);  
            
        }
        mostrar(v,product,ce,12);
        art_nopro(product,ce,12,v);
        pf = fopen("“ARTI_ACTUALIZADO.dat","wb");
        if(pf==NULL)
        {
            printf("\n222Archivo no abierto");
            getch();
            exit(1);
        }
        for(i=0;i<ce;i++)
            fwrite(&v[i],sizeof(info),1,pf);
        fclose(pf);
    }


int lee_control(int inf,int sup,int val)  //una funcion para controlar 
{
    if(inf <= val && sup>=val)
        return 1;
    else
        return 0;
}


int mayor_cero(int inf,int val)  //para ver si es mayoa a ceor 
{
    if (inf <= val)
        return 1;
    else 
        return 0;
}



int no_correlativo(int numero)
{
// Verificar que el número tenga 4 cifras
    if (numero < 1000 || numero > 9999) {
        return 0;
    }

    // Verificar que las cifras no sean correlativas
    int cifra1,cifra2,cifra3,cifra4;
     cifra1 = numero / 1000;
     cifra2 = (numero / 100) % 10;
     cifra3 = (numero / 10) % 10;
     cifra4 = numero % 10;

    if (cifra1 == cifra2 + 1 || cifra1 == cifra2 - 1 ||
        cifra2 == cifra3 + 1 || cifra2 == cifra3 - 1 ||
        cifra3 == cifra4 + 1 || cifra3 == cifra4 - 1) {
        return 0;
    }

    // Si todas las condiciones se cumplen, el número es válido
    return 1;
}



int buscar(int cod,info v[],int ce) //busca la pos del codigo
{
    int i,pos;
    i=0;
    pos =-1;
    while(i<ce && pos == -1) 
    {
        if(v[i].code == cod)
            pos=i;
        else
            i++;
    }   
    return pos;
    
}

void todo_cero(int m[][12],int ce, int mes) //inicializa la matriz en 0   
{
    int i,j;
    for(i=0;i<ce;i++)
        for(j=0;j<mes;j++)
            m[i][j]=0;
}



void mostrar(info v[],int m[][12],int ce, int meses)  //FALTA
{
    int i,j;
    printf("\nCódigo\t\tArticulos\t\tDescripción\t\tEne.\t\tFeb\t\tMar\t\tAbr\t\tMay\t\tJun\t\tJul\t\tAgo\t\tSep\t\tOct\t\tNov\t\tDis");
    for(i=0;i<ce;i++)
    {
        printf("\n%-6d\t\t%-9d\t\t%-11s",v[i].code,v[i].stock,v[i].des);
        for(j=0;j<=meses;j++)
            printf("\t\t%-3d",m[i][j]);
    }
}


void art_nopro(int m[][12],int ce,int meses,info v[])   //crea un listado de articulos que no se producieron //FALTA
{
    int i,j,cont=0,total=0;
    int nostock[ce];
    char paralelo[ce][21];

    for(i=0;i<ce;i++)
    {
        for(j=0;j<=meses;j++)
            if(m[i][j] == 0)
                cont++;
        if(cont == meses)
        {
            nostock[total]=v[i].code;
            strcpy(paralelo[i],v[i].des);
            total++;
        }
    }
}
