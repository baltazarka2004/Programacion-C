#include <stdio.h>
#include <ctype.h>
int main()
{
    int band,cont_10,homb,muj,legajo,ant,cat,legajo_mayor;
    float s_basico,s_mayor;
    char sexo;
    band = 0;
    cont_10=0;
    homb=0;
    muj=0;
    do{
        printf("ingresar legajo del empleado - igual a cero para finalizar- entre 1000 y 5000\n");
        scanf("%d",&legajo);
        if(legajo<1000 || legajo>5000 )
            printf("\nlegajo invalido\n");

    }while (legajo<1000 || legajo > 5000 );
    while(legajo!=0)
        {
            do
            {
             printf("\ningresar sueldo- mayor a 1000: $");
             scanf("%f",&s_basico);
             if (s_basico<1000)

                printf("\nsueldo invalido");



            }while(s_basico<1000);
            do
            {
                printf("\ningresar antiguedad: ");
                scanf("%d",&ant);
                if(ant<=0)
                    printf("\nvalor no valido\n");
            }while(ant<=0);
            if ( ant>10)
                {
                    cont_10++;
                    s_basico*=1.1;
                }
                do
                {
                    printf("\ningresar genero: ");
                    fflush(stdin);
                    scanf("%c",&sexo);
                    sexo=toupper(sexo);
                    if(sexo!='M' && sexo!='F')

                            printf("\ngenero no valido\n");

                }while(sexo!='M' && sexo!='F');
                if(sexo='M')
                    homb++;
                else
                    muj++;
                do
                {
                    printf("\ningresar categoria: ");
                    scanf("%d",&cat);
                    if(cat<1||cat>5)
                        printf("\ncategoria no valida\n");
                } while (cat<1||cat>5);
                if(cat==2 || cat==3)
                {
                    s_basico+=500;
                }
                else if (cat==4)
                {
                    s_basico*=1.1;                  /* code */
                }
                else if (cat==5)
                {
                    s_basico*=1.3;
                }
                if(band==0 || s_basico>s_mayor)
                {
                    band=1;
                    s_mayor=s_basico;
                    legajo_mayor=legajo;
                }
                printf("\nel sueldo del empleado con legajo %d es de $%.2f\n",legajo,s_basico);
                printf("ingresar legajo del empleado - igual a cero para finalizar- entre 1000 y 5000\n");
                scanf("%d",&legajo);
                if(legajo<1000 || legajo>5000 && legajo!=0)
                    printf("\nlegajo invalido\n");

        }
        printf("\nla cantidad de empleados de mas de 10 años de antiguedad es de : %d\nel empleado con legado %d tiene el mayor sueldo, con un sueldo de $%.2f\ny hay un total de %d empleados hombres \ny un total de %d empleadas mujeres",cont_10,legajo_mayor,s_mayor,homb,muj);



}
