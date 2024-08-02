/*
Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la información ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA.
(para el cálculo de la raíz cuadrada utilizar la función sqrt disponible en la biblioteca math.h). Si el
número es negativo poner un 0 ya que no se puede calcular la raíz
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
f. Hallar el valor mínimo del vector VB y en qué posiciones se hallaron (el mínimo se pude repetir).
g. Dado un valor ingresado por teclado, indicar en qué posición se encontró del vector VC.
h. Mostrar el contenido de todos los vectores.
FUNCIONES:
I. Para el ingreso del vector AA, del punto a).
II. Para generar el vector CC, del punto c).
III. Para realizar la búsqueda del punto g).
IV. Para generar el vector VE del punto i).
V. Para mostrar los valores de todos los vectores del punto j).
*/


#include <stdio.h>
#include <math.h>
#define ce 10
void carga (float[]);
void suma (float[],float[],float[]);
int busqueda (float[]);
void mostrar (float[],float[],float[],float[],int,int,int);
int main()
{
    float va[ce];
    float vb[ce];
    float vc[ce];
    float vd[ce];
    int i,may,pos_may,men,pos_men,pos;
    carga(va);
    for(i=0;i<=ce-1;i++)
    {
        if(va[i]>0)
        {
        vb[i]=sqrt(va[i]);
        }
        else
        vb[i]=0;

    }

    suma(va,vb,vc);

    for(i=0;i<=ce-1;i++)
    {
        vd[i]=vc[ce-1-i];
    }


    for(i=0;i<=ce;i++)
    {
        if(va[i]>may || i==0)
         {   may=va[i];
        
         }
        if(vb[i]<men || i==0)
          
          {
            men=vb[i];
          }
        
    }
    for(i=0;i<=ce;i++)
    {
        if(va[i]==may)
          {
            pos_may=i;

          }
        



        if(vb[i]==men)
        {
            pos_men=i;
        }
        
    }
    
   pos=busqueda(vc);
    mostrar(va,vb,vc,vd,pos_may,pos_men,pos);
}



void carga (float va[])
{
    int i;
    float num;
    printf("\ningresar 10 numeros reales: ");
    for(i=0;i<=ce-1;i++)
    {
        scanf("%f",&num);
        va[i]=num;
        printf("\ningresar siguiente numero: ");
    }
}




void suma(float va[],float vb[],float vc[])
{
    int i;
    for(i=0;i<=ce-1;i++)
    {
        vc[i]=va[i]+vb[i];
    }
}


int busqueda(float vc[])
{
    int i,num,pos=-1;
    printf("ingrese un numero para buscar: ");
    scanf("%d",&num);
    for(i=0;i<=ce-1;i++)
    {
        if(vc[i]==num)
        pos=i;
    }
    return pos;
}


void mostrar (float va[],float vb[],float vc[],float vd[],int pos_may,int pos_men,int pos)
{
    int i;
    printf("\ncontenido del vector A: ");
    for(i=0;i<=ce-1;i++)
    {
        printf("%.2f  ",va[i]);
    }
    printf("\ncontenido del vector B: ");
    for(i=0;i<=ce-1;i++)
    {
        printf("%.2f  ",vb[i]);
    }
    printf("\ncontenido del vector C: ");
    for(i=0;i<=ce-1;i++)
    {
        printf("%.2f  ",vc[i]);
    }

    printf("\ncontenido del vector D: ");
    for(i=0;i<=ce-1;i++)
    {
        printf("%.2f  ",vd[i]);
    }

    printf("\nposision del numero mas grande del vector A: %d",pos_may+1);
    printf("\nposision del numero mas chico del vector B: %d",pos_men+1);
    if(pos>=0)
    
        printf("\nla posision del numero buscado en el vector C es la numero : %d",pos);

    else
        printf("\nel numero buscado del vector C no existe dentro de dicho vector");

    

    
}