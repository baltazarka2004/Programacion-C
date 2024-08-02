/*3.8 Se dispone de un archivo denominado INSCRIPTOS.dat que contiene la información de los inscriptos a un
curso de programación. El curso tiene una capacidad máxima para 60 personas. El archivo aún no está
completo ya que la inscripción se realiza por partes. Por cada inscripto se tiene la siguiente información:
• DNI (entero)
• Apellido y Nombres (texto de 20 caracteres máximo)
• Pagado (campo entero donde 1 indica que pagó y 0 que aún adeuda la matrícula)
Se desea realizar un programa que cumpla con dos funciones:
a. Registrar los pagos de los alumnos ya inscriptos.
b. SI hay cupo, agregar nuevos inscriptos.
El programa solicitará el ingreso del DNI y lo buscará entre los inscriptos, en caso de que lo encuentre dará
la opción para registrar el pago (si es que no está pago ya). En caso de que no lo encuentre dará la opción
para inscribirlo al curso (el pago se realiza luego). En el momento que ya no quede cupo en el curso si llega
un nuevo inscripto se le preguntará si desea quedar registrado para un curso futuro, y en caso afirmativo
se le solicitará el teléfono y se guardará el nombre, DNI y teléfono en un archivo Interesados.dat.
El ingreso de datos finaliza con un DNI negativo. 2
Al finalizar se debe actualizar el archivo de inscriptos con los cambios realizados*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    int dni;
    char ayn[21];
    int pag;
}info;
typedef struct 
{
    int dni;
    int telf;
    char nom[21];
}fut;

void paga(info[],int,int);
void interesado(int);
int buscar(info[],int,int);
int validar(int,int,int);


int main()
{
    FILE *pf;
    int max=60,i=0;
    info pers[max],aux;
    pf = fopen("INSCRIPTOS.dat","rb");

    if(pf==NULL)
    {
        printf("\nel archivo no se abrio");
        getch();
        exit(1);
    }
    i=0;
    fread(&aux,sizeof(info),1,pf);
    while(!feof(pf))
    {
        pers[i]=aux;
        fread(&aux,sizeof(info),1,pf);
        i++;
    }
    fclose(pf);
    paga(pers,i,max);
}


void paga(info v[], int ce, int max)
{
    FILE *pf;
    info aux;
    int val,pos,i;
    char resp[21];
    char pago[21];
    pf = fopen("INSCRIPTOS.dat","wb");
    if(pf==NULL)
    {
        printf("\nel archivo no se abrio");
        getch();
        exit(1);
    }
    do
    {
        printf("\ningrese DNI,""negativo"" para finalizar:");   //pregunto si el dni es valdio o no 
        scanf("%d",&val);
        if(validar(-1,99999999,val)== 0)
            printf("\ndni invalido");
        
    } while (validar(-1,99999999,val)== 0);
    pos=buscar(v,val,max);
    while (val > 0)
    {
        if(pos== -1)   //busco si el dni esta o no , en caso de que no este entro en la operacion de agregarlo
        {
            if(ce != max)   //si no supero la cnatidad maxima le pregutno si queire o no agregarlo
            {
                do
                {
                    printf("\ndesea ingresar un nuevo alumno?: ");
                    fflush(stdin);
                    gets(resp);
                    if(strcmpi(resp,"si")!=0 && strcmpi(resp,"no")!=0)
                        printf("\nERROR");
                }while(strcmpi(resp,"SI")!=0 && strcmpi(resp,"NO")!=0);
                if(strcmpi(resp,"si")==0)  //si repsonde que si aumento la cantidad total que hay en el vector de struct y pregurno por el nombre 
                {
                    ce++;
                    printf("\ningrese nombre y apelldio:");
                    fflush(stdin);
                    gets(resp);
                    strcpy(v[ce].ayn,resp);
                    v[ce].dni = val;
                    v[ce].pag = 0;

                }

            }
            else
            {
                printf("\nesta interesado en que guardemos su nombre para futuro? ");   //en caso de que la cantidad maxima se supere
                fflush(stdin);                                                          //hago una duncion para los interesados
                gets(resp);
                if(strcmpi(resp,"si")==0)
                    interesado(val);
            }

        }
        else
        {
           pos = buscar(v,val,ce);      //en caso de queeste anotado debo de ver si ah pagado o no 
           if(v[pos].pag == 0)
           {
            printf("\nAh realizado el pago? :");
            fflush(stdin);
            gets(pago);
            if(strcmpi(pago,"si")==0)
                v[pos].pag = 1;
           } 
        }
        do
        {
            printf("\ningrese DNI,""negativo"" para finalizar:");   //pregunto si el dni es valdio o no 
            scanf("%d",&val);
            if(validar(-1,99999999,val)== 0)
                printf("\ndni invalido");
        }while (validar(-1,99999999,val)== 0);
        pos=buscar(v,val,max);
    }
    for(i=0;i<ce;i++)
        fwrite(&v[i],sizeof(info),1,pf);
    printf("\narchivo actualizado");
    fclose(pf);

    
}

int buscar(info v[],int val,int ce)
{
    int pos=-1,i=0;
    while(i<ce && pos == -1)
    {
        if(v[i].dni == val)
            pos = i;
        else
            i++;
    }
    return pos;
}

void interesado(int val)
{
    FILE*pf;
    int telfo;
    fut persona;
    pf = fopen("interesados.dat","ab");
    if(pf==NULL)
    {
        printf("\n33333el archivo no se abrio");
        getch();
        exit(1);
    }
    persona.dni = val;
    do
    {
        printf("\ningresar telefono del alumno:");
        scanf("%d",&telfo);
        if(validar(0,9999999999,telfo) == 0)
            printf("\n222error");
    } while (validar(0,9999999999,telfo) == 0);
    persona.telf = telfo;
    printf("\ningresar nombre del alumno:");
    fflush(stdin);
    gets(persona.nom);
    fwrite(&persona,sizeof(persona),1,pf);
    
}


int validar(int inf,int sup,int val)
{
    if(inf <= val && sup >= val)
        return 1;
    else
        return 0;
}
