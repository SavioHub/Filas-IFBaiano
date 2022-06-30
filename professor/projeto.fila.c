#include<stdio.h>
#include<stdlib.h>
#define TAM 99

typedef struct fila{

    int f;
    int r;
    int elementos[TAM];

}Fila;



void enqueue(Fila *q, int x){

    if(isFull(*q)==1){
        printf("Fila cheia");
    }
    else{
        q->r = (q->r+1)%TAM;
        q->elementos[q->r]=x;
        if(q->f==-1){
            q->f++;
        }
    }

}
void FurarFila(Fila *q, int x){
    if(isFull(*q)==1){
        printf("Fila cheia");
    }
    else{
        if(q->f != 0 && q->f != -1){
        q->f--;
        q->elementos[q->f]=x;
    }
    else if(q->f == -1){
        q->f = 0;
        q->r = 0;
        q->elementos[q->f]=x;
    }
    else{
        q->f = TAM -1;
        q->elementos[q->f]=x;
    }

    }

}

void dequeue(Fila *q){
    if(isEmpty(*q)==0){
        if(q->f == q->r){
            q->f = -1;
            q->r = -1;
        }
        else{
            q->f = (q->f+1) % TAM;
        }
    }

}


int isEmpty(Fila q){

    if(q.r == -1){
        return 1;
    }
    else{
        return 0;
    }

}

int isFull(Fila q){

    if(q.f < q.r && TAM-1 == q.r && q.f == 0){
        return 1;
    }
    else if(q.r < q.f && q.r + 1 == q.f){
        return 1;
    }
    else{
        return 0;
    }
}

void printP(Fila q){

        printf("\nFila = ");
        if(q.f<=q.r){
            for(int i=q.f; i<=q.r; i++){
                printf("%d ", q.elementos[i]);
            }
        }
        else{
            for(int i=q.f; i<TAM; i++){
                printf("%d ", q.elementos[i]);
            }
            for(int i=0; i<=q.r; i++){
                printf("%d ", q.elementos[i]);
            }

        }

    }



int main(){

    int i, conta, idade, att, contcp=0, contc=0, contgp=0, contg=0;

    Fila q1 = {-1, -1};
    Fila q2 = {-1, -1};
    Fila q3 = {-1, -1};
    Fila q4 = {-1, -1};
while (i != 4){

    printf("Selecione uma opcao\n");
    printf("1.Funcionario(caixa)\n");
    printf("2.Funcionario(guiche)\n");
    printf("3.Correntista\n");
    scanf("%d", &i);
    system("cls");
    if (i == 3){
        printf("Digite o numero da conta:");
        scanf("%d", &conta);
        printf("Digite a idade:");
        scanf("%d", &idade);
        printf("1.Caixa ou 2.Guiche");
        scanf("%d", &att);
        system("cls");
        if(att == 1 && idade < 60){
            enqueue(&q1, conta);
        }
        if(att == 1 && idade >=60){
            enqueue(&q2, conta);
        }
        if(att == 2 && idade < 60){
            enqueue(&q3, conta);
        }
        if(att == 2 && idade >= 60){
            enqueue(&q4, conta);
        }

    }
    if(i == 1){
        printf("Selecione uma opcao\n\n");
        printf("1.Chamar ficha\n");
        printf("2.Gerar relatorio\n");
        printf("3.Visualizar filas\n");
        printf("4.Sair\n");
        scanf("%d", &i);
        system("cls");
        if(i == 1){
            if(isEmpty(q2)!=1){
                printf("Atendimento ao caixa: conta: %d\n\n", q2.elementos[q2.f]);
                dequeue(&q2);
                contcp++;
            }
            else{
                printf("Atendimento ao caixa: conta: %d\n\n", q1.elementos[q1.f]);
                dequeue(&q1);
                contc++;
            }
        }
        else if(i == 2){
            printf("Atendimento ao caixa sem prioridade:%d\n", contc);
            printf("Atendimento ao caixa com prioridade:%d\n", contcp);
            printf("Atendimento ao guiche sem prioridade:%d\n", contg);
            printf("Atendimento ao guiche com prioridade:%d\n", contgp);
        }
        else if(i == 3){
            for(int i=q1.f; i<=q1.r; i++){
            printf("Atendimento ao caixa sem prioridade:%d\n", q1.elementos[i]);
            }
            for(int i=q2.f; i<=q2.r; i++){
            printf("Atendimento ao caixa com prioridade:%d\n", q2.elementos[i]);
            }
            for(int i=q3.f; i<=q3.r; i++){
            printf("Atendimento ao guiche sem prioridade:%d\n", q3.elementos[i]);
            }
            for(int i=q4.f; i<=q4.r; i++){
            printf("Atendimento ao guiche com prioridade:%d\n", q4.elementos[i]);
            }

        }
        else if(i == 4){
            printf("Fim do expediente");
        }


    }
    else if(i == 2){
        printf("\nSelecione uma opcao\n");
        printf("1.Chamar ficha\n");
        printf("2.Gerar relatorio\n");
        printf("3.Visualizar filas\n");
        printf("4.Sair\n");
        scanf("%d", &i);
        system("cls");
        if(i == 1){
            if(isEmpty(q4)!=1){
                printf("Atendimento ao guiche: conta: %d\n", q4.elementos[q4.f]);
                dequeue(&q4);
                contgp++;
            }
            else{
                printf("Atendimento ao guiche: conta: %d\n", q3.elementos[q3.f]);
                dequeue(&q3);
                contg++;
            }
        }
        else if(i == 2){
            printf("Atendimento ao caixa sem prioridade:%d\n", contc);
            printf("Atendimento ao caixa com prioridade:%d\n", contg);
            printf("Atendimento ao guiche sem prioridade:%d\n", contg);
            printf("Atendimento ao guiche com prioridade:%d\n", contgp);
        }
        else if(i == 3){
            for(int i=q1.f; i<=q1.r; i++){
            printf("Atendimento ao caixa sem prioridade:%d\n", q1.elementos[i]);
            }
            for(int i=q2.f; i<=q2.r; i++){
            printf("Atendimento ao caixa com prioridade:%d\n", q2.elementos[i]);
            }
            for(int i=q3.f; i<=q3.r; i++){
            printf("Atendimento ao guiche sem prioridade:%d\n", q3.elementos[i]);
            }
            for(int i=q4.f; i<=q4.r; i++){
            printf("Atendimento ao guiche com prioridade:%d\n", q4.elementos[i]);
            }
        }
        else if(i == 4){
            printf("Fim do expediente");
        }
    }

}


}
