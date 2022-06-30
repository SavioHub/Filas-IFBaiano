#include <stdio.h>
#define TAM 10

// 0 1 2 3 4
// 3 4 5 6 9

// primeiro = 0
// ultimo = 4

// Para o circulo funcionar, deve-se remover um elemento para que o PRIMEIRO rompa um indice, e assim sendo
//É Possivel adicionar mais elementos de forma circular
typedef struct fila
{
    int primeiro;
    int ultimo;
    int fila[TAM];
} Fila;

void enqueue(Fila *q, int x);
int dequeue(Fila *q, int *x);
int isEmpty(Fila *q);

// Adicionar
void enqueue(Fila *q, int x)
{
    // transformação do vetor linear em circular. Sempre que chegar no final ele volta para o 0
    if ((q->ultimo + 1) % TAM == q->primeiro) // verificação se a fila está cheia
    {
        printf("Fila cheia\n");
    }
    else
    {
        q->fila[q->ultimo] = x;
        q->ultimo = (q->ultimo+1) % TAM;
        // q->ultimo++ % TAM;
        printf("\nValor inserido com sucesso!\n\n");
    }
}

// remover
int dequeue(Fila *q, int *x)
{
    if (isEmpty(q))
    {
        printf("Fila vazia!\n");
    }
    else if (isEmpty(q))
    {
        *x = q->fila[q->primeiro]; // criação do aux, aux recebe fila na posição 0
        q->primeiro = (q->primeiro + 1) % TAM;
        // q->primeiro++ % TAM; // atualiza o 0 para 1
        printf("valor removido com sucesso!\n");
        // return *x;
    }
    else
    {
        printf("\nNão existe valor a ser removido\n");
    }
}

// listar
void list(Fila q)
{
    int i;
    printf("\nValores dentro da Fila:\n");
    for (i = q.primeiro; i < q.ultimo; i++)
    {
        printf("Valor da posição %d = %d\n", i, q.fila[i]);
    }
    printf("Primeiro = %d\n", q.primeiro);
    printf("Ultimo = %d\n\n", q.ultimo);
}

// Vazia
int isEmpty(Fila *q)
{
    if (q->primeiro == q->ultimo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
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
            enqueue(&q, aux);
        }
        else if (op == 'R')
        {
            int remove;
            int valor;
            remove = dequeue(&q, &valor);
            printf("Valor removido = %d\n\n", valor);
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

    return 0;
}