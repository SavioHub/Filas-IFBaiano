#include <stdio.h>
#include <stdlib.h>
#define TAM 99

typedef struct fila
{
    int primeiro;
    int ultimo;
    int elementos[TAM];

} Fila;

void enqueue(Fila *q, int x);
void dequeue(Fila *q);
int isEmpty(Fila q);
int isFull(Fila q);
void furarFila(Fila *q, int x);
void list(Fila q);

void enqueue(Fila *q, int x)
{

    if (isFull(*q) == 1)
    {
        printf("Fila cheia");
    }
    else
    {
        q->ultimo = (q->ultimo + 1) % TAM;
        q->elementos[q->ultimo] = x;
        if (q->primeiro == -1)
        {
            q->primeiro++;
        }
    }
}
void furarFila(Fila *q, int x)
{
    if (isFull(*q) == 1)
    {
        printf("Fila cheia");
    }
    else
    {
        if (q->primeiro != 0 && q->primeiro != -1)
        {
            q->primeiro--;
            q->elementos[q->primeiro] = x;
        }
        else if (q->primeiro == -1)
        {
            q->primeiro = 0;
            q->ultimo = 0;
            q->elementos[q->primeiro] = x;
        }
        else
        {
            q->primeiro = TAM - 1;
            q->elementos[q->primeiro] = x;
        }
    }
}

void dequeue(Fila *q)
{
    if (isEmpty(*q) == 0)
    {
        if (q->primeiro == q->ultimo)
        {
            q->primeiro = -1;
            q->ultimo = -1;
        }
        else
        {
            q->primeiro = (q->primeiro + 1) % TAM;
        }
    }
}

int isEmpty(Fila q)
{

    if (q.ultimo == -1)
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

    if (q.primeiro < q.ultimo && TAM - 1 == q.ultimo && q.primeiro == 0)
    {
        return 1;
    }
    else if (q.ultimo < q.primeiro && q.ultimo + 1 == q.primeiro)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void list(Fila q)
{

    printf("\nFila = ");
    if (q.primeiro <= q.ultimo)
    {
        for (int i = q.primeiro; i <= q.ultimo; i++)
        {
            printf("%d ", q.elementos[i]);
        }
    }
    else
    {
        for (int i = q.primeiro; i < TAM; i++)
        {
            printf("%d ", q.elementos[i]);
        }
        for (int i = 0; i <= q.ultimo; i++)
        {
            printf("%d ", q.elementos[i]);
        }
    }
}

int main()
{

    int num, conta, idade, att;
    int contcp = 0, contc = 0, contgp = 0, contg = 0;

    Fila q1 = {-1, -1};
    Fila q2 = {-1, -1};
    Fila q3 = {-1, -1};
    Fila q4 = {-1, -1};
    while (num != 4)
    {

        printf("Selecione uma opcao\n");
        printf("1.Funcionario(caixa)\n");
        printf("2.Funcionario(guiche)\n");
        printf("3.Correntista\n");
        scanf("%d", &num);

        if (num == 3)
        {
            printf("Digite o numero da conta:\n");
            scanf("%d", &conta);
            printf("Digite a idade:\n");
            scanf("%d", &idade);
            printf("1.Caixa ou 2.Guiche\n");
            scanf("%d", &att);
            if (att == 1 && idade < 60)
            {
                enqueue(&q1, conta);
            }
            if (att == 1 && idade >= 60)
            {
                enqueue(&q2, conta);
            }
            if (att == 2 && idade < 60)
            {
                enqueue(&q3, conta);
            }
            if (att == 2 && idade >= 60)
            {
                enqueue(&q4, conta);
            }
        }
        if (num == 1)
        {
            printf("Selecione uma opcao\n\n");
            printf("1 - Chamar ficha\n");
            printf("2 - Gerar relatorio\n");
            printf("3 - Visualizar filas\n");
            printf("4 - Sair\n");
            scanf("%d", &num);

            if (num == 1)
            {
                if (isEmpty(q2) != 1)
                {
                    printf("Atendimento ao caixa: conta: %d\n\n", q2.elementos[q2.primeiro]);
                    dequeue(&q2);
                    contcp++;
                }
                else
                {
                    printf("Atendimento ao caixa: conta: %d\n\n", q1.elementos[q1.primeiro]);
                    dequeue(&q1);
                    contc++;
                }
            }
            else if (num == 2)
            {
                printf("Atendimento ao caixa sem prioridade:%d\n", contc);
                printf("Atendimento ao caixa com prioridade:%d\n", contcp);
                printf("Atendimento ao guichê sem prioridade:%d\n", contg);
                printf("Atendimento ao guichê com prioridade:%d\n", contgp);
            }
            else if (num == 3)
            {
                int i;
                for (i = q1.primeiro; i <= q1.ultimo; i++)
                {
                    printf("Atendimento ao caixa sem prioridade:%d\n", q1.elementos[i]);
                }
                for (i = q2.primeiro; i <= q2.ultimo; i++)
                {
                    printf("Atendimento ao caixa com prioridade:%d\n", q2.elementos[i]);
                }
                for (i = q3.primeiro; i <= q3.ultimo; i++)
                {
                    printf("Atendimento ao guichê sem prioridade:%d\n", q3.elementos[i]);
                }
                for (i = q4.primeiro; i <= q4.ultimo; i++)
                {
                    printf("Atendimento ao guichê com prioridade:%d\n", q4.elementos[i]);
                }
            }
            else if (num == 4)
            {
                printf("Fim do expediente\n");
            }
        }
        else if (num == 2)
        {
            printf("\nSelecione uma opcao\n");
            printf("1 - Chamar ficha\n");
            printf("2 - Gerar relatorio\n");
            printf("3 - Visualizar filas\n");
            printf("4 - Sair\n");
            scanf("%d", &num);

            if (num == 1)
            {
                if (isEmpty(q4) != 1)
                {
                    printf("Atendimento ao guichê: conta: %d\n", q4.elementos[q4.primeiro]);
                    dequeue(&q4);
                    contgp++;
                }
                else
                {
                    printf("Atendimento ao guichê: conta: %d\n", q3.elementos[q3.primeiro]);
                    dequeue(&q3);
                    contg++;
                }
            }
            else if (num == 2)
            {
                printf("Atendimento ao caixa sem prioridade:%d\n", contc);
                printf("Atendimento ao caixa com prioridade:%d\n", contg);
                printf("Atendimento ao guichê sem prioridade:%d\n", contg);
                printf("Atendimento ao guichê com prioridade:%d\n", contgp);
            }
            else if (num == 3)
            {
                int i;
                for (i = q1.primeiro; i <= q1.ultimo; i++)
                {
                    printf("Atendimento ao caixa sem prioridade:%d\n", q1.elementos[i]);
                }
                for (i = q2.primeiro; i <= q2.ultimo; i++)
                {
                    printf("Atendimento ao caixa com prioridade:%d\n", q2.elementos[i]);
                }
                for (i = q3.primeiro; i <= q3.ultimo; i++)
                {
                    printf("Atendimento ao guichê sem prioridade:%d\n", q3.elementos[i]);
                }
                for (i = q4.primeiro; i <= q4.ultimo; i++)
                {
                    printf("Atendimento ao guichê com prioridade:%d\n", q4.elementos[i]);
                }
            }
            else if (num == 4)
            {
                printf("Fim do expediente\n");
            }
        }
    }
}