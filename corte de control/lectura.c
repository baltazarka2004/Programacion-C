#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int mes;
    char tarifa[11];
    float precio;
} infoT;

int main() {
    FILE *pf;
    pf = fopen("viajes.dat", "rb");
    
    if (pf == NULL) {
        printf("El archivo no existe\n");
        exit(1);
    }
    
    infoT algo;

    while (fread(&algo, sizeof(infoT), 1, pf) == 1) {
        printf("%d\t%s\t%f\n", algo.mes, algo.tarifa, algo.precio);
    }

    fclose(pf);

    return 0;
}
