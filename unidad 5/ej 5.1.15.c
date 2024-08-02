#include <stdio.h>
int main()
{
    int centro,i,j,c1=0,c2=0,c3=0,c4=0;
    float x,y;
    centro=0;
    for(i=1;i<5;i++)
    {
        printf("\nparticipante numero: %d",i);
        for(j=1;j<=3;j++)
        {
            printf("\ningresar cordenadas de disparo (x,y): ");
            scanf("%f%f",&x,&y);
            if(x>0&&y>0)
                c1++;
            else
            {
                if(x<0&&y>0)
                    c2++;
                else
                {
                    if(x<0&&y<0)
                        c3++;
                    else
                    {
                        if(x>0&&y<0)
                            c4++;
                            else
                            centro++;
                    }
                }
            }
        }
        printf("el participante %d efectuo\n%d en el cuadrante 1\n%d en el cuadrante 2\n%d en el cuadrante 3\n%d en el cuadrante 4",i,c1,c2,c3,c4);
        c1=0;
        c2=0;
        c3=0;
        c4=0;
    }
    printf("\nhubo un total de %d tiros al centro",centro);
    return 0;
}
