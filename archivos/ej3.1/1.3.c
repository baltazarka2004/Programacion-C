 /*3.1 Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA.
*/
#include <stdio.h>
#include<stdlib.h>
typedef struct
{
    int dni;
    char NyA[81];
    int n1;
    int n2;
    float prom;
}compuT;
void lecturna(compuT); //funcion para leer
void grabado();//funcion de guardado
int carga_dniV(int,int);//cargo y valido el dni
int notas(int,int);
int main()
{

    grabado();
    
    return 0;

}

 


void grabado()
{
    compuT alum;
    FILE * pf;
    pf = fopen("alumno.dat","wb"); //creo el archivo de guardado
    if(pf == NULL)
    {

        printf("\nno se pudo abrir el archivo"); //por si no se abre correctamente
        system("pause");
        exit(1);
    }
    alum.dni = carga_dniV(0,99999999); //pido el dni
    while(alum.dni != 0) // finaliza con un 0
    {
        printf("\ningrese nombre y apelldio(no mas de 80 caracteres):"); //pido el nombre 
        fflush(stdin);
        fgets(alum.NyA);
        alum.n1 = notas(0,10);
        alum.n2 = notas(0,10); //cargamos las dos notas
        alum.prom = (alum.n1 + alum.n2) / 2;
        fwrite(&alum,sizeof(compuT),1,pf); //guardamos el archivo
        lecturna(alum); // leemos
        alum.dni = carga_dniV(0,99999999); //pido el dni

    }

    printf("\n\t\t\tarchivo de alumnos creado correctemente");
    fclose(pf); //cerramos el archivo

}



void lecturna(compuT alum)
{
    FILE * pf;
    pf = fopen("alumno.dat","rb");
    if(pf == NULL)
    {

        printf("\nno se pudo abrir el archivo"); //por si no se abre correctamente
        exit(1);
    }
    fread(&alum,sizeof(compuT),1,pf);
    fclose(pf);
}