#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} ingreso;

typedef struct {
    int legajo;
    char ape[16];
    char nom[31];
    ingreso fecha;
    int cat;
} empleado;

void fechahoy(ingreso *hoy);
int diavalido(int val, int inf, int sup);

int main() {
    FILE *pf;
    int aniosT;
    empleado info;
    ingreso hoy;

    fechahoy(&hoy);

    pf = fopen("empleados.dat", "r+b");
    if (pf == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    fread(&info, sizeof(empleado), 1, pf);

    while (!feof(pf)) {
        aniosT = hoy.anio - info.fecha.anio;

        if (aniosT >= 0 && aniosT <= 2)
            info.cat = 1;
        else if (aniosT >= 3 && aniosT <= 5)
            info.cat = 2;
        else if (aniosT >= 6 && aniosT <= 10)
            info.cat = 3;
        else
            info.cat = 4;

        fseek(pf, -sizeof(empleado), SEEK_CUR);
        fwrite(&info, sizeof(empleado), 1, pf);
        fflush(pf);
        fread(&info, sizeof(empleado), 1, pf);
    }

    fclose(pf);

    return 0;
}

void fechahoy(ingreso *hoy) {
    int dia, mes, anio;

    do {
        printf("\ningresar dia actual: ");
        scanf("%d", &dia);
        if (diavalido(dia, 1, 31) == 0)
            printf("\ndia invalido");
    } while (diavalido(dia, 1, 31) == 0);
    hoy->dia = dia;

    do {
        printf("\ningresar mes actual: ");
        scanf("%d", &mes);
        if (diavalido(mes, 1, 12) == 0)
            printf("\nmes invalido");
    } while (diavalido(mes, 1, 12) == 0);
    hoy->mes = mes;

    do {
        printf("\ningresar año actual: ");
        scanf("%d", &anio);
        if (anio < 2022)
            printf("\nanio invalido");
    } while (anio < 2022);
    hoy->anio = anio;
}

int diavalido(int val,int inf,int sup)
{

    if(val < inf && val > sup)
        return 0;
    else
        return 1;
}
