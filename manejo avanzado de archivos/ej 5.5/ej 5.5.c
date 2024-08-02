/*
Realizar un sistema completo de agenda telefónica básico donde por cada contacto se guarda el nombre y el
número de teléfono. Las funcionalidades a desarrollar son:
• Mostrar la cantidad de contactos guardados
• Alta de nuevos contactos
• Búsqueda secuencial de contactos por nombre
• Modificación de contactos
• Borrado de contactos (a elección si desea realizar borrado físico o lógico)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char borrado;
    char nom[31];
    int num;
}agenda;
int menu();
int validar(int,int,int);
void mostrar();
void nuevocontacto();
agenda busqueda(char[]);
void modificacion();
void borrado(int);
int main()
{
    FILE *pf;
    int opcion,delete;
    agenda contacto;
    char nombre[31];
    opcion = menu();
    while (opcion != 6)
    {
        system("cls");
        if(opcion == 1)
            mostrar();
        else if (opcion == 2)
            nuevocontacto();
        else if(opcion == 3)
        {
            printf("\ningresar nombre a buscar:");
            fflush(stdin);
            gets(nombre);
            contacto  = busqueda(nombre);
            printf("\ninformacion del contacto\nnombre %31s\nnumero: %d",contacto.nom,contacto.num);
        }
        else if (opcion == 4)
            modificacion();
        else
        {
            do
            {
                printf("\ningrese que tipo de borrado desea realizar:\n1-logico\n2-fisico");
                scanf("%d",&delete);
                if(validar(delete,1,2)==0);
                    printf("\nopcion no valida");
            }while (validar(delete,1,2)==0);
            borrado(delete);
        }


        system("pause");
        system("clear");
        opcion = menu();


    }

}

int menu()
{
    int opcion;
    printf("\nMENU TELEFONICO\n1)Mostrar la cantidad de contactos\n2)ingresar nuevo contacto\n3)Búsqueda secuencial de contactos por nombre\n4)Modificación de contactos\n5)Borrado de contactos\n6)Salir");
    do
    {
        printf("\nDigite su opcion:");
        scanf("%d",&opcion);
        if(validar(opcion,1,6)==0)
            printf("\nopcion no valida, volver a ingresa....");
    } while (validar(opcion,1,6)==0);
    return opcion;


}


void mostrar()
{
    FILE*pf;
    agenda contacto,aux;
    pf=fopen("contactos.dat","rb");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo o no existe");
        getch();
        exit(1);
    }
    fread(&aux,sizeof(agenda),1,pf);
    printf("\nContacto\t\tNumero");
    while (!feof(pf))
    {
        contacto  = aux;
        printf("\n%s\t\t%d",contacto.nom,contacto.num);
        fread(&aux,sizeof(agenda),1,pf);

    }
    fclose(pf);
}


void nuevocontacto()
{
    FILE * pf;
    agenda contacto;
    int num;
    pf=fopen("contactos.dat","ab");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo");
        getch();
        exit(1);
    }
    do
    {
        printf("\ningresar numero del nuevo contacto:");
        scanf("%d",&num);
        if(validar(num,0,9999999999)==0)
        {
            printf("\nnumero no valido....volver a ingresar");
            system("pause");
            system("cls");
        }
    } while (validar(num,0,9999999999)==0);
    contacto.num=num;
    printf("\ningresar nombre del contacto:");
    fflush(stdin);
    gets(contacto.nom);
    fwrite(&contacto,sizeof(agenda),1,pf);
    fclose(pf);
}


agenda busqueda(char nombre[])
{
    FILE * pf;
    agenda contactos;
    int encontrado = 0;
    pf=fopen("contactos.dat","rb");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo o no existe");
        getch();
        exit(1);
    }
    fread(&contactos,sizeof(pf),1,pf);
    while(!feof(pf) && encontrado == 0)
    {
        if(strcmpi(nombre,contactos.nom) == 0)
            encontrado = 1;
        else
            fread(&contactos,sizeof(pf),1,pf);
    }
    fclose(pf);
    if(encontrado == 0)
        {
            strcpy(contactos.nom,"NO EXISTENTE");
            contactos.num = 0;
            return contactos;
        }
    else
        return contactos;

}


void modificacion()
{
    FILE *pf;
    agenda contactos;
    int opcion,band = 1;
    char modificar[31];
    pf = fopen("contactos.dat","r+b");
    if(pf==NULL)
    {
        printf("\nno se pudo abrir el archivo o no existe");
        getch();
        exit(1);
    }
    printf("\ningresar nombre del contacto:");

    fflush(stdin);

    gets(modificar);

    fread(&contactos,sizeof(agenda),1,pf);

    while (!feof(pf) && band != 0)

    {

        if(strcmpi(modificar,contactos.nom)==0)

        {

            do

            {
                printf("\n1-modificar numero\n2-modificar nombre");
                scanf("%d",&opcion);
                if(validar(opcion,1,2)==0)
                    printf("\nvolver a ingresar");

            }while(validar(opcion,1,2)==0);

            if(opcion==1)

            {

                printf("\ningresar nuevo numero");
                scanf("%d",&contactos.num);

            }

            else

            {

                printf("\ningresar nuevo nombre:");
                fflush(stdin);
                gets(contactos.nom);

            }

            fseek(pf,sizeof(agenda)*(-1),1);

            fwrite(&contactos,sizeof(agenda),1,pf);
            band = 0;
            fflush(pf);
        }


        fread(&contactos,sizeof(agenda),1,pf);

    }
    if(band == 1)
        printf("\n contacto no existente ");
    fclose(pf);
}


void borrado (int opcion)
{
    FILE *pf,*temp,*historico;
    char nombre[31];
    agenda info;
    printf("\ningresar nombre de contacto que desea borrar: ");
    fflush(stdin);
    gets(nombre);
    if(opcion == 1)
    {
        pf=fopen("contactos.dat","r+b");
        if(pf==NULL)
        {
            printf("\nno se pudo abrir");
            getch();
            exit(1);
        }
        fread(&info,sizeof(agenda),1,pf);
        while (!feof(pf))
        {
            if(strcmpi(info.nom,nombre)==0)
            {
                info.borrado = 'S';
                fseek(pf,sizeof(agenda)*(-1),1);
                fwrite(&info,sizeof(agenda),1,pf);
            }
        }
    }
    else
    {
        pf=fopen("contactos.dat","rb");
        temp=fopen("contactos.temp","wb");
        historico  = fopen("historicos.dat","ab");
        if(pf==NULL || temp == NULL)
        {
            printf("\nno se pudo abrir");
            getch();
            exit(1);
        }
        fread(&info,sizeof(agenda),1,pf);
        while (!feof(pf))
        {
            if(strcmpi(info.nom,nombre)!=0)
                fwrite(&info,sizeof(agenda),1,temp);
            else
                fwrite(&info,sizeof(agenda),1,historico);
            fread(&info,sizeof(agenda),1,pf);
        }
        fclose(pf);
        fclose(temp);
        fclose(historico);
    }

}


int validar(int val,int inf,int supp)
{
    if(val >= inf && val <= supp)
        return 1;
    else
        return 0;

}
