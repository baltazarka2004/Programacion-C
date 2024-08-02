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
    info datos,aux;
    promedios prome;
    float T_rait,may;
    int band = 0,canalA,msvisto, cont,vuelta;
    FILE *pf,*pm;
    pf = fopen("rating.dat","rb");
    pm = fopen("promedio.dat","wb");
    if(pf == NULL || pm == NULL)
    {

        printf("\n no se pudo abrir");
        getch();
        exit(1);
    }
    printf("\ncanales que superan el raiting de 15 puntos:");
    fread(&aux,sizeof(info),1,pf);
    while(!feof(pf))
    {
        datos = aux;
        canalA = datos.can;
        T_rait = 0;
        cont = 0;
        vuelta = 0;
        while(canalA == datos.can && !feof(pf))
        {

            T_rait += datos.rait;
            cont ++;
            if(T_rait < 15 && vuelta == 0)
            {
                printf("\nA-%s",datos.prog);
                vuelta = 1;

            }
            fread(&datos,sizeof(info),1,pf);
        }


        if(band == 0 && may < T_rait)
        {
            band =1;
            may = T_rait;
            msvisto = canalA;
        }
        prome.prom = T_rait / cont;
        prome.can  = canalA;
        printf("\n%.2f\n%d",prome.prom,prome.can);

        getch();
        fwrite(&prome,sizeof(promedios),1,pm);
        fread(&aux,sizeof(info),1,pf);


    }
    fclose(pf);
    fclose(pm);
}
