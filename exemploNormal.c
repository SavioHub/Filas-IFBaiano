#include <stdio.h>
#include<stdlib.h>
#define TAM 10

typedef struct fila{
    int f;
    int r;
    float elementos[TAM];
}Fila;


void inserir(Fila *q, float x);
void remover(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void imprimir(Fila q);


void inserir(Fila *q, float x){
    if(isFull(*q)==0){
            q->r++;
            q->elementos[q->r] = x;
            
            if(q->f==-1){
                q->f++;
            }
    }
    else{
        printf("Fila cheia. Nao e possivel inserir elementos. OVERFLOW\n");
    }
}

void remover(Fila *q){
    if(isEmpty(*q)==0){
        
        if(q->f == q->r){
            q->f = -1;
            q->r = -1;
        }
        else{
            q->f++;
        }
    }
    else{
        printf("Fila vazia. Nao e possivel remover. UNDERFLOW\n");
    }

}

int isEmpty(Fila q){
    if(q.f == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(Fila q){
    if(q.r == TAM-1){
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
        for(int i=q.f; i<=q.r; i++){
            printf("%.2f ", q.elementos[i]);
        }
        printf("\n");
    }

}

int main(){

    Fila q = {-1, -1}; // p.topo=-1;

    imprimir(q);
    inserir(&q, 4);
    inserir(&q, 2);
    inserir(&q, 5);
    inserir(&q, 4);
    inserir(&q, 4);
    inserir(&q, 2);
    inserir(&q, 5);
    inserir(&q, 4);
    imprimir(q);
    remover(&q);
    imprimir(q);
    remover(&q);
    remover(&q);
    remover(&q);
    imprimir(q);
    inserir(&q, 40);
    inserir(&q, 20);
    inserir(&q, 50);

}