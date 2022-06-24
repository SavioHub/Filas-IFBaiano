//A fila Linear a partir do momento que consegue preencher todas as posiçõs dentro do vetor, não conseguimos usar mais esse vetor
//Mesmo depois de Removerto todod os elee=mentos da Fila, teoricamente não conseguimos fazer mais nada
#include <stdio.h>
#define TAM 10

typedef struct fila
{
    int primeiro;
    int ultimo;
    int fila[TAM];
}Fila;


void inseir(Fila *q, float x){
    if(isFull(*q)==0){
            q->r = (q->r+1) % TAM;
            q->elementos[q->r] = x;
            if(q->f==-1){
                q->f++;
            }
    }
    else{
        printf("Fila cheia. Nao e possivel inserir elementos. OVERFLOW\n");
    }
}
// ----------------------------------------------------------------------------------------------
//Adicionar
void enqueue(int valor){
    
    if (ultimo < TAM -1)
    {
        //caso inicializar com a variavel: ultimo = -1, deve-se fazer o: ultimo++; primeiro de fila[ultimo]
        //caso ser ultimo = 0; deve-se fazer ultimo++; depois de fila[ultimo]
        ultimo++;
        fila[ultimo] = valor;
        printf("\nValor inserido com sucesso!\n\n");
    }else
    {
        printf("\nValor não inserido\n"); 
    }
}

//remover
int dequeue(){ 
    int aux;
    if (primeiro<=ultimo)
    {
        aux = fila[primeiro];//criação do aux, aux recebe fila na posição 0
        fila[primeiro] = -1;
        primeiro++;//atualiza o 0 para 1
        return aux;
    }else
    {
        printf("\nNão existe valor a ser removido\n");
    }
    
}
//examinar
int peek(){
    if (primeiro<=ultimo)
    {
        return fila[primeiro];
    }else
    {
        return -1;
    }
}
//esvaziar
void clear(){
    int i;
    //resetação dos cursores
    primeiro =0;
    ultimo = -1;
    //for para limpar toda a memória
    for (i = 0; i < TAM; i++)
    {
        fila[i] = 0;
    }
}

//Tamanho
int size(){
    return (ultimo - primeiro + 1);
}
// 2 elementos
// ultimo = 1
// primeiro = 0
// ultimo - primeiro + 1 = 2

//listar
void list(){
    int i;
    printf("\nValores dentro da Fila:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("Valor da posição %d = %d\n",i, fila[i]);
    }
    printf("Primeiro = %d\n",primeiro);
    printf("Ultimo = %d\n\n",ultimo);
}


int main(){
    Fila teste;
    start();
    
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

        if (op=='A')
        {
            printf("Digite o valor a ser inserido:\n");
            scanf("%d", &aux);
            enqueue(aux);

        }else if (op == 'R')
        {
            printf("Valor removido = %d\n\n", dequeue());
        }else if (op == 'L')
        {
            list();
        }else if (op == 'E')
        {
            printf("O valor examinado = %d\n", peek());
        }else if (op == 'C')
        {
            clear();
            printf("Limepeza executada!\n");
        }else if (op == 'T')
        {
            printf("Tamanho da Fila = %d\n", size());
        }else if (op == 'S')
        {
            printf("Bye Bye\n");
        }   
    }
    return 0;
}