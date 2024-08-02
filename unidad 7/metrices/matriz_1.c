/*Se desea desarrollar un sistema de reservas de entradas para un cine. La sala consta de 12 filas numeradas
de la 1 a la 12 y cada fila tiene 9 butacas numeradas a partir de la columna central, con las butacas impares a
la derecha y las pares a la izquierda, como en el siguiente esquema:
8 6 4 2 1 3 5 7 9
Para la carga, se debe mostrar al usuario un esquema con las butacas disponibles y reservadas, marcando
con la letra D las disponibles y con la letra R las reservadas.
Por cada reserva se debe solicitar la fila y número de butaca a reservar. Cada vez que se realice una
reserva se deberá actualizar el esquema que muestra las butacas. Si la butaca seleccionada ya estaba
ocupada se debe informar al usuario para que seleccione otra. El proceso de reserva finaliza con una fila
con un número negativo.
Al finalizar mostrar:
a. la cantidad de asientos disponibles y la cantidad de asientos reservados.
b. los números de filas que quedaron vacías.
c. la o las filas con mayor cantidad de espectadores.

matris de 12x9
12: filas
9:butacas

*/
#include<stdio.h>
#include<stdlib.h>
void ponerend(char [][9],int,int);
void carga(char [][9],int,int);
int cantidad(char [][9],int,int);
void esquema(char [][9],int,int);
void vacias(char [][9],int[],int,int);
void mayor(char [][9],int [],int,int);
int main()
{
    char mat [12][9];
    int butacas [12]={0};
    int may_fila[12]={0};
    int d,total,r;
    total=12*9;
    ponerend(mat,12,9);
    carga(mat,12,9);
    d=cantidad(mat,12,9);
    r=total-d;
    printf("\nasientos disponible: %d\nasientos reservados: %d",d,r);
    vacias(mat,butacas,12,9);
    mayor(mat,may_fila,12,9);




}

                                                    


void ponerend(char mat[][9],int fila, int columna)
{
    int i,j;
    for(i=0;i<=fila-1;i++)
    {
        for(j=0;j<=columna-1;j++)
        {
            fflush(stdin);
            mat[i][j]='d';
        }
    }
}

void carga(char mat[][9],int fila, int columna)
{
    int f,c,cont=0;
    esquema(mat,fila,columna);
    do
    {
        printf("\nseleccionar fila (1-12): ");
        scanf("%d",&f);


    } while (f>12||f==0);
    while (f>0||cont==12*9)
    {
        cont++;
        do
        {
            printf("\nseleccionar butaca(1-9): ");
            scanf("%d",&c);
        }while(c<1||c>9);
        if(mat[f-1][c-1]=='d')
        {
            switch (c)
            {
                case 8:
                mat[f-1][0]='r';
                break;
                case 6:
                mat[f-1][1]='r';
                break;
                case 4:
                mat[f-1][2]='r';
                break;
                case 2:
                mat[f-1][3]='r';
                break;
                case 1:
                mat[f-1][4]='r';
                break;
                case 3:
                mat[f-1][5]='r';
                break;
                case 5:
                mat[f-1][6]='r';
                break;
                case 7:
                mat[f-1][7]='r';
                break;
                case 9:
                mat[f-1][8]='r';
                break;

            }
        }
        else
            printf("\nbutaca ya reservada\n");
        system("pause");
        system("cls");
        esquema(mat,fila,columna);
        do
        {
            printf("\nseleccionar fila (1-12): ");
            scanf("%d",&f);
        } while (f>12||f==0);


    }


}


void esquema(char mat[][9],int fila,int columna)
{
    int i,j;
    printf("\t2 8\t2 6\t2 4\t2 2\t2 1\t2 3\t2 5\t2 7\t2 9");
    for(i=0;i<fila;i++)
    {
        printf("\n%d",i+1);
        for(j=0;j<columna;j++)
        {
            printf("\t%2c",mat[i][j]);
        }
    }
}

int cantidad(char mat[][9],int fila,int columna)
{
    int i,j,cont=0;
    for(i=0;i<=fila-1;i++)
    {
        for(j=0;j<=columna-1;j++)
        {
            if(mat[i][j]=='d')
                cont++;
        }
    }
    return cont;
}

void vacias(char mat[][9],int vacia[],int fila,int columna)
{
    int i,j,cont=0,lugar=0;
    for(i=0;i<=fila-1;i++)
    {
        for(j=0;j<=columna-1;j++)
        {
            if(mat[i][j]==0)
                cont++;
        }
        if(cont==9)
        {
            vacia[lugar]=i+1;
            lugar++;
        }
    }
    printf("\nfilas vacias: ");
    for(i=0;i<=lugar;i++)
    {
        printf("%d ",vacia[i]);
    }
}

void mayor(char mat[][9],int may[],int fila,int columna)
{
    int i,j,mayor;
    int vmayor[12]={0};
    printf("\nlas filas con mayor espectadores son: ");
    for(i=0;i<=fila-1;i++)
    {
        for(j=0;j<=columna-1;j++)
        {
            vmayor[i]+=mat[i][j];
        }
        if(mayor>mayor||i==0)
        {
            mayor=vmayor[i];
        }
    }

    for(i=0;i<=fila-1;i++)
    {
        if(vmayor[i]==mayor)
        printf("%d  ",i+1);
    }

}

