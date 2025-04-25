#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

typedef struct Nodo
{
    Tarea T;
    Nodo *Siguiente;
}Nodo;

Nodo * CrearListaVacia();
Nodo * CrearNodo(Tarea T);
void InsertNodoAlFinal(Nodo **Start, Nodo *nodo);

// interfaz de carga de tareas pendientes con descripcion y durecion de la misma, 
// id generado automaticamente autoincremental comenzando del numero 1000
// al cabo de cada tarea preguntar al usuario si desea agregar una nueva o finalizar la carga

int main()
{
    Nodo * Start;
    Start = CrearListaVacia();
    Tarea Datos;
    char Buff[100];
    printf("Ingresar la tarea pendiente, decripcion y duracion (10 a 100?): \n");
    gets(Buff);
    //fgets(Buff,100,stdin);
    Datos.Descripcion = (char *)malloc((strlen(Buff) + 1)*sizeof(char));
    strcpy(Datos.Descripcion,Buff);

    Nodo * nodo = CrearNodo(Datos);

    
    
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

void InsertNodoAlFinal(Nodo **Start, Nodo *nodo)
{
    Nodo * Aux = *Start;

    while (Aux->Siguiente)
    {
        Aux = Aux->Siguiente;
    }
    Aux->Siguiente = nodo;
    
}