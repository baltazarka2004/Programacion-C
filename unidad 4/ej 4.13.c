#include<stdio.h>
int main()
{
    int art;
    printf("introducir codigo del articulo: ");
    scanf("%d",&art);
    if (art>=1200 && art<=90000)
    {
        if((art>=12121 && art<=18081)||(art>=30012 && art<=45565)||(art>=67000 && art<=68000))
            printf("el articulo numero %d es defectuoso",art);
        else
            printf("el articulo numero %d no es defectuoso",art);

    }
    else
        printf("fuera del catalogo");
}
