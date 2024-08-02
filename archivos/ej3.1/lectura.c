#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int cod;
    char des[51];
    int stock;
}product;
int main()
{
    product vP[10];
    int i,ce=10;
    FILE * pf;
    pf = fopen("stock.dat","rb"); //abro elarchivo
    if(pf == NULL) //pregunto sise abrio o no
    {
        printf("falla en la apertura del archivo");
        getch();
        exit(1);
    }
    i=0;
    
    while(!feof(pf))
    {

        fread(&vP[i],sizeof(product),1,pf); //leo el archivo y lo guardo en un vectorde producto
        printf("\n%d\t\t\t%s\t\t\t%d",vP[i].cod,vP[i].des,vP[i].stock);
        i++;
    }

    fclose(pf);
    return 0;
}