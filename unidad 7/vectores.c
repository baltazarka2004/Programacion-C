#include<stdio.h>
int cargadni();
int carganota();
int dnivalido(int);
int notavalida(int);
void mostrar(int[],int[],int);
int main()
{
    int vnota[60];
    int vdni[60];
    int max,alum,dni,nota,band=0,i,nota_m,cont=0;
    max=60;
    alum=0;
    int valum_may[60];
    dni=cargadni();
    while (dni>0&&alum<=max)
    {
        alum++;
        vdni[alum-1]=dni;
        nota=carganota();
        vnota[alum-1]=nota;
        dni=cargadni();
    }
    if(alum!=0)
    {
        mostrar(vdni,vnota,alum);
        for(i=0;i<=(alum-1);i++)
        {
            if (vnota[i]>nota_m||band==0)
            {
                nota_m=vnota[i];
                band=1;
            }
        
        }
        for (i=0;i<=(alum-1);i++)
        {
            if (vnota[i]==nota_m)
            {
                valum_may[cont]=vdni[i];
                cont++;
            }    
        
    }
    printf("\nnota mas alta: %d \ndni de los alumnos que obtuvieronesta nota:\n",nota_m);
    for(i=0;i<=cont-1;i++)
    {
        printf("%d\n",valum_may[i]);
    }
    }
    else
        printf("\nno hubo alumnos ingresados.");
    return 0;

}










int cargadni()
{
    int dni;
    do
    {
        printf("\ningresar dni (menor a cero para finalizar): ");
        scanf("%d",&dni);
        if(dnivalido(dni)!=1)
        printf("\ndni invalido, volver a ingresar dni valido");

    }while(dnivalido(dni)!=1);
    return (dni);

}



int dnivalido(int dni)
{
    if (dni <= 99999999)
    {
        return 1;  // DNI válido
    }
    else
    {
        return 0;  // DNI inválido
    }
}






int carganota()
{
    int nota;
    do
    {
        printf("\ningresar nota correspondiente al alumno: ");
        scanf("%d",&nota);
        if(notavalida(nota)!=1)
        printf("\nnota  invalida, volver a ingresar nota valida");

    }while(notavalida(nota)!=1);
    return (nota);

}




int notavalida(int nota)
{
if(nota>=1&&nota<=10)
return 1;
else
return 0;
}





void mostrar(int vdni[],int vnota[],int alum)
{
    int i;
printf("\ndni del alumno \tnota del alumno\n");
for(i=0;i<=alum-1;i++)
    printf("%d\t%d\n",vdni[i],vnota[i]);
}















