#include <stdio.h>
typedef struct 
{
    float a;
    int b;
}algo;

int main()
{
    FILE *pf,*arch;
    algo v,aux;
    int i=0,ce;
    arch = fopen("promedio.dat","rb");
    pf = fopen("promedio.csv","wt");
    fread(&aux,sizeof(algo),1,arch);
    while(!feof(arch))
    {
        v = aux;
        fprintf(pf,"\n%d;;%.2f",v.b,v.a);
        fread(&aux,sizeof(algo),1,arch);
        i++;
    }
    printf("listo");
    
    fclose(pf);
    fclose(arch);
}