#include <stdio.h>
#include <ctype.h>
#define max 3 //maximo numero que puede contener los vectores
void cargavectores(int[], char[], int[], int[], int[] );
int igualacero(int[],int[],int[]);
int debajodelpunto(int[],int[],int[],int[]);
int deposito(int[],int[],int[]);
int validar(int,int,int); //retorna 1 si es verdadero y retorna 0 si es falso
void mostrar(int[],int[],int[],int,int,int);
int main() 
{
    int vcodigo[max]={0};
    char vclase[max]={0};
    int vnumero[max]={0};
    int vstock[max]={0};
    int vrep[max]={0};
    int vb[max]={0};
    int vc[max]={0};
    int vd[max]={0};
    int cb,cc,cd,i,cont=0,stock_max; //creo 3 contadores para pode luego mostrar todo en una funcion llamada mostrar, cada situacion con su respectivo mensaje y contador
    cargavectores(vcodigo,vclase,vnumero,vstock,vrep);
    cb=igualacero(vcodigo,vstock,vb);
    cc=debajodelpunto(vcodigo,vstock,vnumero,vc);
    cd=deposito(vcodigo,vnumero,vd);
    mostrar(vb,vc,vd,cb,cc,cd);
    for(i=0;i<=max-1;i++)
        {
            if(i==0||stock_max<vstock[i])
                stock_max=vstock[i];
        }
    printf("\nEstos son los codigos de los articulos con mayor stock: ");
    for ( i = 0; i <max-1; i++)
        {
            if(stock_max==vstock[i])
                printf("\n %d",vcodigo[i]);
        
        }


}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cargavectores(int vcodigo[], char vclase[], int vnumero[], int vstock[], int vrep[]) 
{
    int i,cod,numero,stock,reposicion,valido;
    char clase;
    for(i=0;i<=max-1;i++)
    {
        do
        {
            printf("\ningrese el codigo del articulo (entre 1 y 500): ");
            scanf("%d",&cod);
            if(valido=validar(1,500,cod)!= 1)
                printf("\ncodigo no valido, volver a ingresar\n");
        }while(valido=validar(1,500,cod)!= 1);
        vcodigo[i]=cod;
        do
        {
            printf("\ningresar clase del articulo(de la A a la D): ");
            fflush(stdin);
            scanf("%c",&clase);
            clase=toupper(clase);
            if(clase<'A'||clase>'D')
            printf("\nclase no valida , vovler a ingresar");         
        }while(clase<'A'||clase>'D');
        vclase[i]=clase;
        do
        {
            printf("\ningresar el numero de deposito donde se encuentra el articulo");
            scanf("%d",&numero);
            if(valido=validar(1,100,numero) != 1)
            printf("\ndeposito invalido,volver a ingresar");

        } while (valido=validar(1,100,numero) != 1);
        vnumero[i]=numero;
        do
        {
            printf("\ningresar stock del articulo: ");
            scanf("%d",&stock);
            if(valido=validar(0,2000,stock) != 1)
            printf("\nstock no valido, volver a ingresar");

        } while (valido=validar(0,2000,stock) != 1);
        vstock[i]=stock;
        do
        {
            printf("\ningresar el punto de reposicion: ");
            scanf("%d",&reposicion);
            if(valido=validar(500,1000,reposicion) != 1)
            printf("\nreposicion invalida, volver a ingresar ");

        } while (valido=validar(500,1000,reposicion) != 1 );
        vrep[i]=reposicion;
        
        
        






    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int igualacero(int vcodigo[],int vstock[],int vb[])
{
    int i,cb=0;
    for(i=0;i<=max-1;i++)
    {
        if(vstock[i]==0)
        {
            cb++;
            vb[cb-1]=vcodigo[i];
        }
    }
    return (cb);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int debajodelpunto(int vcodigo[],int vstock[],int vrep[],int vc[])
{
    int i,cc=0;
    for(i=0;i<=max-1;i++)
    {
        if(vstock[i]<vrep[i]&&vstock[i]!=0)
        {
            cc++;
            vc[cc-1]=vcodigo[i];
        }
    }
    return cc;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int deposito(int vcodigo[], int vnumero[], int vd[])
{
    int i,cd=0;
    for(i=0;i<=max-1;i++)
    {
        if (vnumero[i]>=15 && vnumero[i]<=50)
        {
            cd++;
            vd[cd-1]=vcodigo[i];
        }
        
    }
    return cd;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int validar(int inf,int sup,int var)
{
    if(var>=inf && var<=sup)
    return 1;
    else
    return 0;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar(int vb[], int vc[], int vd[], int cb, int cc, int cd)
{
    int i;
    printf("\narticulos con 0 stock:");
    for(i=0;i<=cb-1;i++)
    {
        printf("\n%d",vb[i]);
    }
    printf("\narticulos con  stock por debajo del punto de reposicion:");
    for(i=0;i<=cc-1;i++)
    {
        printf("\n%d",vc[i]);
    }
    printf("\narticulos con deposito entre 15-50:");
    for(i=0;i<=cd-1;i++)
    {
        printf("\n%d",vd[i]);
    }
}




