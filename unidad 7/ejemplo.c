
#include <stdio.h>
int main()
{
 float vector_reales[10];
 int i;
 // Lee los 10 números reales y los ubica secuencialmente en el arreglo
 for(i=0; i<=9; i++)
 {
 printf("\nIngrese un numero real: ");
 scanf("%f", &vector_reales[i]);
 }
 // Muestra el contenido del arreglo
 printf("\n Contenido del arreglo\n");
 for(i=0; i<=9; i++)
 {
 printf("%6.2f\t", vector_reales[i]);
 }
}