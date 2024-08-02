#include <stdio.h>
#include <ctype.h>
int main ()
{
  float efect=0,tarj=0,cheq=0,iva=0 ,total= 0,monto= 0;
  char met;

  printf("ingresar motodo de pago- utilizar F para finalizar\n");
  scanf("%c",&met);
  getchar();
  met=toupper(met);
  while(met!='F')
  {
      printf("\ningresar monto a pagar\n");
      scanf("%f",&monto);
      if(met=='E')

          efect+=monto*0.9;
      else
      {
          if (met=='C')
            cheq+=monto*1.2;
            else
        {

             if(met=='T')
                tarj+=monto*1.12;
             else
                printf("\nel metodo de pago ingresado no es valido");

            }
        }
        printf("ingresar motodo de pago- utilizar F para finalizar\n");
        fflush(stdin);
        scanf("%c",&met);
        getchar();
        met=toupper(met);
    }
    total=efect+tarj+cheq;
    iva=total*0.21;
    printf("efectivo en caja: %.2f \nventas de tarjeta: %.2f \ventas con cheque: %.2f \ntotal de ventas: %.2f \nimporte de iva: %.2f",efect,tarj,cheq,total,iva);
}
