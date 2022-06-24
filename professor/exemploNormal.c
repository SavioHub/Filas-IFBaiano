#include <stdio.h>
#include<stdlib.h>
#define TAM 10

typedef struct fila{
    int primeiro;
    int ultimo;
    float fila[TAM];
}Fila;


void enqueue(Fila *q, float x);
void dequeue(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void imprimir(Fila q);


void enqueue(Fila *q, float x){
    if(isFull(*q)==0){
            q->ultimo++;
            q->fila[q->ultimo] = x;
            
            if(q->primeiro == -1){
                q->primeiro++;
            }//tratando a primeira inserção do primeiro elemento
    }
    else{
        printf("Fila cheia. Nao e possivel inserir elementos. OVERFLOW\n");
    }
}

void dequeue(Fila *q){
    if(isEmpty(*q)==0){
        
        if(q->primeiro == q->ultimo){
            q->primeiro = -1;
            q->ultimo = -1;
        }
        else{
            q->primeiro++;
        }
    }
    else{
        printf("Fila vazia. Nao e possivel remover. UNDERFLOW\n");
    }

}

int isEmpty(Fila q){
    if(q.primeiro == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Fila q){
    if(q.ultimo == TAM-1){
        return 1;
    }
    else{
        return 0;
    }
}

void imprimir(Fila q){
    if(isEmpty(q)==1){
        printf("Fila vazia, nao e possivel imprimir \n");
    }
    else{
        printf("\nFila = ");
        for(int i=q.primeiro; i<=q.ultimo; i++){
            printf("%.2f ", q.fila[i]);
        }
        printf("\n");
    }

}

int main(){

    // Fila q = {-1, -1}; // p.topo=-1;
    Fila q;
    q.primeiro = -1;
    q.ultimo = -1;
    
    imprimir(q);
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 5);
    enqueue(&q, 4);
    enqueue(&q, 4);
    enqueue(&q, 2);
    enqueue(&q, 5);
    enqueue(&q, 4);
    imprimir(q);
    dequeue(&q);
    imprimir(q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    imprimir(q);
    enqueue(&q, 40);
    enqueue(&q, 20);
    enqueue(&q, 50);

}