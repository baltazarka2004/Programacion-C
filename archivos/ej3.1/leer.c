#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    char des[51];
    int stock;
} product;

int main()
{
    product vP[10];
    int i = 0;
    FILE *pf;
    
    pf = fopen("stock.dat", "rb"); // Abre el archivo en modo lectura binaria
    
    if (pf == NULL)
    {
        printf("Falla en la apertura del archivo");
        exit(1);
    }

    // Leer el archivo de manera segura
    while (fread(&vP[i], sizeof(product), 1, pf) == 1)
    {
        printf("%d\t\t%s\t\t%d\n", vP[i].cod, vP[i].des, vP[i].stock);
        i++;

        // Asegúrate de que no se exceda el límite del arreglo vP
        if (i >= 10)
        {
            printf("Límite de productos alcanzado (10)\n");
            break;
        }
    }

    fclose(pf);
    return 0;
}
