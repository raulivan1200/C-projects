#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <conio.h>
#include <string.h>
using namespace std;

// Declaramos algunas variables globales
int count = 0, opc, x, y, d;

// Definimos la estructura de nodo para la cola
struct node {
    char data[50];
    node* next;
}*front, * rear;

// Función para crear la cola
void crearCola() {
    front = NULL;
    rear = NULL;
}

void encolar(char x[50]) {
    node* q;
    q = new node; //Se crea un nuevo nodo
    strcpy(q->data, x); //Se copia el valor en el nodo
    q->next = NULL; //El siguiente nodo es nulo

    if (front == NULL) {
        front = q;
        rear = q;
    } else {
        rear->next = q; //El nodo anterior apunta al nuevo nodo
        rear = q; //La parte posterior de la cola ahora apunta al nuevo nodo
    }
}


void desencolar() {
    char elem[50];
    node* q;
    q = front;

    if (q == NULL) {
        printf("\nLa Cola ya esta vacia\n");
        return;
    }
    front = q->next; //Se actualiza el puntero al siguiente nodo
    strcpy(elem, q->data); //Pasamos el primer valor de la cola
    delete q; //Eliminamos el nodo

    printf("\n\nEl elemento %s ha sido eliminado de la cola", elem); //Se imprime el valor eliminado
}

 void mostrar_cola() {
    node* q, *prev;
    q = front;
    prev = NULL;
    if (q == NULL) {
        printf("La cola a mostrar está vacía ");
        return;
    }
    printf("Cola:\n");
    while (q != NULL) {
        printf("\t%s | Prev: %s | Next: %s\n", q->data, prev == NULL ? "NULL" : prev->data, q->next == NULL ? "NULL" : q->next->data);
        prev = q;
        q = q->next;
    }
}


void vaciar_cola() {
    node* q;
    q = front;
    if (q == NULL) {
        printf("La Cola ya esta vacia\n");
        return;
    }
    while (q != NULL) {
        front = q->next; //Se actualiza el puntero al siguiente nodo
        delete (q); //Se elimina el nodo
        q = front; //Se actualiza el nodo actual
    }
}
    
int main(){
    char valor[50];
    setlocale(LC_CTYPE,"Spanish");
    fflush (stdin);
    crearCola();
    system ("CLS");
    do{
        printf("|Seleccione una opcion de 1 a 4|\n");
        printf("(1)  Encolar\n");
        printf("(2)  Desencolar\n");
        printf("(3)  Elementos de la cola\n");
        printf("(4)  Vaciar cola\n");
        printf("Inserte la opción: ");		
        scanf("%d",&opc);
        system ("cls");
        switch (opc){
            case 1: 			
                printf ("Encolar\n");
                printf ("Deme el elemento que desea encolar: ");
                fflush(stdin); 
                gets(valor); 
                encolar(valor);
                printf ("Elemento encolado");
                getch();
                break; 
            case 2: 
                printf ("Desencolar\n");				
                desencolar(); 
                getch();
                break; 
            case 3:
                printf("Elementos de la cola\n\n\n");				
                mostrar_cola();
                getch();
                break;
            case 4:
                printf ("Vaciando cola...");				
                vaciar_cola();
                getch();
                break;
            default: 
                printf ("Opción no válida");
                getch();
                break;
        }
        system("cls"); 
    } while (opc!=5);
}

