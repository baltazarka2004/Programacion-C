#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int can;
    char prog[36];
    float rait;
}info;
typedef struct
{

    int can;
    float prom;
}promedios;
int main()
{
    info datos;
    promedios prome,aux;
    float T_rait,may;
    int band = 0,canalA,msvisto, cont,vuelta,ce,i=0;
    FILE *pf,*pm;
    pf = fopen("promedio.dat","rb");
    pm = fopen("promedio.csv","wt");
    if(pf == NULL || pm == NULL)
    {

        printf("\n no se pudo abrir");
        getch();
        exit(1);
    }
    
    fread(&aux,sizeof(info),1,pm);
    while(!feof(pf))
    {
        prome = aux;
        fread(&aux,sizeof(info),1,pm);
        fprintf(pm,"\n%d;%s",prome.can,prome.prom);
        i++;
    }
    ce = i;
    
    fclose(pf);
    fclose(pm);
}
