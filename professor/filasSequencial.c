#include <stdio.h>
#include<stdlib.h>
#define TAM 5

struct fila
{
    int f;
    int r;
    float elementos[TAM];
};

typedef struct fila Fila;

void enqueue(Fila *q, float x);
void dequeue(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void imprimir(Fila q);



void enqueue(Fila *q, float x)
{
    if(isFull(*q)==0)
    {
        q->r++;
        q->elementos[q->r]= x;
        if(q->f==-1)
        {
            q->f++;
        }
    }
    else
    {
        printf("Fila cheia. Nao e possivel inserir elementos. OVERFLOW\n");
    }
}

void dequeue(Fila *q)
{
    if(isEmpty(*q)==0)
    {
        if(q->f == q->r)
        {
            q->f = -1;
            q->r = -1;
        }
        else
        {
            q->f++;
        }
    }
    else
    {
        printf("Pilha vazia. Nao e possivel remover. UNDERFLOW\n");
    }

}

int isEmpty(Fila q)
{
    if(q.r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Fila q)
{
    if(q.r == TAM - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void imprimir(Fila q)
{
    if(isEmpty(q)==1)
    {
        printf("Fila vazia, nao e possivel imprimir \n");
    }
    else
    {
        printf("\nFila: ");
        for(int i=q.f; i<=q.r; i++){
            printf("%f ", q.elementos[i]);
        }
    }

}

int main()
{

    Fila q = {-1, -1}; // p.topo=-1;
    //local de testes
    enqueue(&q, 5);
    enqueue(&q, 9);
    enqueue(&q, 2);
    enqueue(&q, 4);
    enqueue(&q, 1);
    enqueue(&q, 100);
    dequeue(&q);
     enqueue(&q, 200);
    imprimir(q);


}