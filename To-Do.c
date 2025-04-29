#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULLCHAR '\0'

struct Tarea
{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
}Nodo;

Nodo * CrearListaVacia();
Nodo * CrearNodo(Tarea T);
void IngresarTarea(char Buff, int IntBuff);
void InsertarNodo(Nodo **Start, Nodo *Nodo);
//void InsertNodoAlFinal(Nodo **Start, Nodo *nodo);

//! Implemente una interfaz para elegir qué tareas de la lista de pendientes
//! deben ser transferidas a la lista de tareas realizadas.  

int main()
{
    Nodo * Start;
    Start = CrearListaVacia();
    Tarea Datos;
    char Buff[100];
    int IntBuff;
    int flag = 1;
    int ID = 1000;

    do
    {
        printf("Ingresar la tarea pendiente, decripcion y duracion (10 a 100?): \n");
        gets(Buff);
        //fgets(Buff,100,stdin);
        Datos.Descripcion = (char *)malloc((strlen(Buff) + 1)*sizeof(char));
        strcpy(Datos.Descripcion,Buff);
        
        printf("Ingrese la duracion: (10 a 100)\n");
        scanf("%d",&IntBuff);
        printf("\n");
        
        Datos.TareaID = ID;
        
        Nodo * nodo = CrearNodo(Datos);
        InsertarNodo(&Start,nodo);
        
        printf("Desea ingresar otra tarea?\n\t Y = si\t N = no\n");
        memset(Buff,0,100);
        fflush(stdin);
        gets(Buff);
        
        if (Buff[0] == 'N' || Buff[0] == 'n')
        {
            flag = 1;
        }

        ID ++;
        
    } while (flag != 0); 
    
    //liberar memoria
    
    
    return 0;
}


Nodo * CrearListaVacia()
{
    return NULL;
}

Nodo * CrearNodo(Tarea T)
{
    Nodo *NNodo = (Nodo *)malloc(sizeof(Nodo));
    NNodo->T = T;
    NNodo->Siguiente = NULL;
    return NNodo;
}

void InsertarNodo(Nodo **Start, Nodo *Nodo)
{
    Nodo->Siguiente = *Start;
    *Start = Nodo;
}

// void InsertNodoAlFinal(Nodo **Start, Nodo *nodo)
// {
//     Nodo * Aux = *Start;

//     while (Aux->Siguiente)
//     {
//         Aux = Aux->Siguiente;
//     }
//     Aux->Siguiente = nodo;
// }