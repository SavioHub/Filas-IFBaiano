#include <stdio.h>
#include<stdlib.h>
#define TAM 6

typedef struct fila{
    int primeiro;
    int ultimo;
    float elementos[TAM];
}Fila;

void enqueue(Fila *q, float x);
int dequeue(Fila *q);
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

int dequeue(Fila *q){
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

void list(Fila q){
    if(isEmpty(q)==1){
        printf("Fila vazia, nao e possivel imprimir \n");
    }
    else{
        printf("\nFila = ");
        if(q.primeiro<=q.ultimo){
            for(int i=q.primeiro; i<=q.ultimo; i++){
                printf("%.1f \n", q.elementos[i]);
            }
            printf("\n");
        }
        else{
            for(int i=q.primeiro; i<TAM; i++){
                printf("%.1f \n", q.elementos[i]);
            }
            for(int i=0; i<=q.ultimo; i++){
                printf("%.1f \n", q.elementos[i]);
            }
        }

    }

}

int main(){

    Fila q = {-1, -1};
    char op;
    int aux;

    while (op != 'X')
    {
        printf("Digite a opção desejada:\n");
        printf("A - Adicionar elementos\n");
        printf("R - Remover elementos\n");
        printf("L - Listar elementos\n");
        printf("X - Sair do programa\n");

        fflush(stdin);
        scanf(" %c", &op);

        if (op == 'A')
        {
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &aux);
            enqueue(&q,aux);
        }
        else if (op == 'R')
        {
            int remove;
            remove=dequeue(&q);
            printf("Valor removido = %d\n\n",remove);
        }
        else if (op == 'L')
        {
            list(q);
        }
        else if (op == 'S')
        {
            printf("Bye Bye\n");
        }
    }
}