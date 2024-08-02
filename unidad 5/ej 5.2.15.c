#include <stdio.h>
#include<ctype.h>
int main()
{
    int fecha,cole,num,cant_t,dni,nacimiento,mujer_t,t_mala,t_bueno,cont,band,colegio_b,m_bueno,total_n,total_t,alum,i;
    float encuesta;
    char  esp,sexo,resp;
    total_t=0;
    total_n=0;
    cont=0;
    mujer_t=0;
    t_bueno=0;
    t_mala=0;
    alum=0;
    printf("ingeresar fecha (dd/mm/aa)\n");
    scanf("%d",fecha);
    printf("\ncantidad de colegio encuestados\n");
    scanf("%d",cole);
    for(i=1;i<=cole;i++)
    {
        do
        {
            printf("\ningrese numero de escuela\n");
            scanf("%d",num);
            if (num<0)
            printf("\nnumero invalido");
        }while(num<0);
        do
        {
            printf("\ncantidad de alumnos\n");
            scanf("%d",cant_t);
            if (cant_t<0)
            
                printf("\nnumero invalido\n");
            
            
        } while (cant_t<0);
        do
        {
            printf("\ningresar especialidad\n");
            fflush(stdin);
            scanf("%c",esp);
            esp=toupper(esp);
            if(esp!='T' && esp!='N')
            printf("\nEspecialidad no valida\n");
        } while (esp!='T' && esp!='N');
        
        
    }


}