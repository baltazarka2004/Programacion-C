#include<stdio.h>
#include <ctype.h>
int main ()
{
int voc=0,i;
char letra,l2;
    for (i=1;i<=100;i++)
        {
        printf("ingresar una letra:");
        scanf("%c",&l2);
        getchar();
            if (l2=='a'||l2=='e'||l2=='o'||l2=='i'||l2=='u')

                voc++;


        }
        printf("\nla cantidad de vocales son : %d",voc);
        return 0;

}
