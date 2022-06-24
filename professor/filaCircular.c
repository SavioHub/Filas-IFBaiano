#include <stdio.h>
#include<stdlib.h>
#define TAM 6

struct fila{
    int primeiro;
    int ultimo;
    float elementos[TAM];
};

typedef struct fila Fila;

void enqueue(Fila *q, float x);
void dequeue(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void imprimir(Fila q);



void enqueue(Fila *q, float x){
    if(isFull(*q)==0){
            q->ultimo = (q->ultimo+1) % TAM;
            q->elementos[q->ultimo] = x;
            if(q->primeiro==-1){
                q->primeiro++;
            }
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
            q->primeiro = (q->primeiro+1) % TAM;
        }
    }
    else{
        printf("Pilha vazia. Nao e possivel remover. UNDERFLOW\n");
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
    if(q.primeiro<q.ultimo && q.primeiro == 0 && q.ultimo == TAM-1){
        return 1;
    }
    else if(q.primeiro>q.ultimo && q.primeiro-q.ultimo == 1){
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
        if(q.primeiro<=q.ultimo){
            for(int i=q.primeiro; i<=q.ultimo; i++){
                printf("%f ", q.elementos[i]);
            }
            printf("\n");
        }
        else{
            for(int i=q.primeiro; i<TAM; i++){
                printf("%f ", q.elementos[i]);
            }
            for(int i=0; i<=q.ultimo; i++){
                printf("%f ", q.elementos[i]);
            }
        }

    }

}

int main(){

    Fila q = {-1, -1};

    printf("%i %i", q.primeiro, q.ultimo) ;// p.topo=-1;
    imprimir(q);
    inseir(&q, 4);
    inseir(&q, 2);
    inseir(&q, 5);
    inseir(&q, 6);
    inseir(&q, 7);
    inseir(&q, 8);
    inseir(&q, 9);
    inseir(&q, 47);
    imprimir(q);
    remover(&q);
    imprimir(q);
    remover(&q);
    remover(&q);
    remover(&q);
    imprimir(q);
    inseir(&q, 40);
    inseir(&q, 20);
    inseir(&q, 50);
    imprimir(q);
    inseir(&q, 60);
    imprimir(q);
    inseir(&q, 70);
    imprimir(q);

}