#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int code;
    char des[21];
    float pre;

}info;

int main()
{
    FILE *pf;
    info algo;
    pf = fopen("precios.dat","rb");
    fread(&algo,sizeof(info),1,pf);
    while(!feof(pf))
    {
        printf("\n%d        %s      %.2f",algo.code,algo.des,algo.pre);
        fread(&algo,sizeof(info),1,pf);

    }
    fclose(pf);

}
