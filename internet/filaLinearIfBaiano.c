// A fila Linear a partir do momento que consegue preencher todas as posiçõs dentro do vetor, não conseguimos usar mais esse vetor
// Mesmo depois de Removerto todod os elee=mentos da Fila, teoricamente não conseguimos fazer mais nada
#include <stdio.h>
#define TAM 10

typedef struct fila
{
    int primeiro;
    int ultimo;
    int elementos[TAM];
} Fila;

// Adicionar
void enqueue(Fila *q, int x)
{

    if (q->ultimo < TAM - 1)
    {
        // caso inicializar com a variavel: ultimo = -1, deve-se fazer o: ultimo++; primeiro de fila[ultimo]
        // caso ser ultimo = 0; deve-se fazer ultimo++; depois de fila[ultimo]
        q->ultimo++;
        q->elementos[q->ultimo] = x;
        printf("\nValor inserido com sucesso!\n\n");
    }
    else
    {
        printf("\nValor não inserido\n");
    }
}

// remover
int dequeue(Fila *q)
{
    int aux;
    if (q->primeiro <= q->ultimo)
    {
        aux = q->elementos[q->primeiro]; // criação do aux, aux recebe fila na posição 0
        q->primeiro++; // atualiza o 0 para 1
        return aux;
    }
    else
    {
        printf("\nNão existe valor a ser removido\n");
    }
}
// examinar
int peek(Fila q)
{
    if (q.primeiro <= q.ultimo)
    {
        return q.elementos[q.primeiro];
    }
    else
    {
        return -1;
    }
}
// esvaziar
void clear(Fila q)
{
    int i;
    // resetação dos cursores
    q.primeiro = 0;
    q.ultimo = -1;
    // for para limpar toda a memória
    for (i = 0; i < TAM - 1; i++)
    {
        q.elementos[i] = 0;
    }
}

// Tamanho
int size(Fila q)
{
    return (q.ultimo - q.primeiro + 1);
}
// 2 elementos
// ultimo = 1
// primeiro = 0
// ultimo - primeiro + 1 = 2

// listar
void list(Fila q)
{
    int i;
    printf("\nValores dentro da Fila:\n");
    for (i = q.primeiro; i <= q.ultimo; i++)
    {
        printf("Valor da posição %d = %d\n", i, q.elementos[i]);
    }
    printf("Primeiro = %d\n", q.primeiro);
    printf("Ultimo = %d\n\n", q.ultimo);
}

int main()
{
    Fila q;
    q.primeiro = 0;
    q.ultimo = -1;

    char op;
    int aux;
    while (op != 'X')
    {
        printf("Digite a opção desejada:\n");
        printf("A - Adicionar elementos\n");
        printf("R - Remover elementos\n");
        printf("L - Listar elementos\n");
        printf("E - Examinar o elemento da cabeça\n");
        printf("C - Limapar a Fila\n");
        printf("T - Tamanho da Fila\n");
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
            remove = dequeue(&q);
            printf("Valor removido = %d\n\n",remove);
        }
        else if (op == 'L')
        {
            list(q);
        }
        else if (op == 'E')
        {
            printf("O valor examinado = %d\n", peek(q));
        }
        else if (op == 'C')
        {
            clear(q);
            printf("Limepeza executada!\n");
        }
        else if (op == 'T')
        {
            printf("Tamanho da Fila = %d\n", size(q));
        }
        else if (op == 'S')
        {
            printf("Bye Bye\n");
        }
    }
    return 0;
}