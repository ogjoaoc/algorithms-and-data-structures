/*
* Autor : João
* Data : 9/3/2025
* linked.c
* linked list simples em C.
*
* Estruturas:
* - Node: nó da lista, contendo um valor inteiro e um ponteiro para o próximo nó da lista.
* - ListaLigada: a lista encadeada em si, contendo o tamanho da lista e ponteiros para o nó inicial e final.
* - Complexidade de inserção e remoção do início O(1)
* - Find em O(N)
*
* Funções:
* - criaLista: Cria e inicializa uma nova lista encadeada.
* - criaNo: Cria e inicializa um novo nó com um valor fornecido.
* - verificaListaVazia: Verifica se a lista está vazia.
* - resetaLista: Reseta a lista para o estado inicial (vazia).
* - insereFrente: Insere um novo nó no início da lista.
* - insereFim: Insere um novo nó no fim da lista.
* - removeFrente: Remove o nó do início da lista.
* - removeFim: Remove o nó do fim da lista.
* - limpaLista: Remove todos os nós da lista.
* - procura: Procura um valor na lista.
* - printaLista: Imprime todos os valores da lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *prox;
} Node;

typedef struct ListaLigada {
    int tam;
    Node *ini, *fim;    
} ListaLigada;

ListaLigada* criaLista() {
    ListaLigada *lista = (ListaLigada*)malloc(sizeof(ListaLigada));
    lista->ini = NULL;
    lista->fim = NULL;
    lista->tam = 0;
    return lista; 
}

Node* criaNo(int v) {
    Node *no = (Node*)malloc(sizeof(Node));
    no->valor = v;
    no->prox = NULL;
    return no;
}

int verificaListaVazia(ListaLigada *lista) {
    return !lista->tam;
}

void resetaLista(ListaLigada *lista) {
    lista->ini = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

int verFrente(ListaLigada *lista) {
    return lista->ini->valor;
}

int verFim(ListaLigada *lista) {
    return lista->fim->valor;
}

int tamanho(ListaLigada *lista) {
    return lista->tam;  
}

void insereFrente(ListaLigada *lista, int v) {
    Node* no = criaNo(v);
    if(verificaListaVazia(lista)) {
        lista->ini = no;
        lista->fim = no;
        lista->tam++;
        return;
    } 
    lista->tam++;
    Node *temp = lista->ini;
    lista->ini = no;
    lista->ini->prox = temp;
}

// O(1)
void insereFim(ListaLigada *lista, int v) {
    Node* no = criaNo(v);
    if(verificaListaVazia(lista)) {
        lista->ini = no;
        lista->fim = no;
        return;
    } 
    lista->tam++;
    lista->fim->prox = no;
    lista->fim = lista->fim->prox;
}

// O(1)
void removeFrente(ListaLigada *lista) {
    if(verificaListaVazia(lista)) return;
    lista->tam--;
    Node *antigo = lista->ini;
    lista->ini = antigo->prox;
    free(antigo);
    if(verificaListaVazia(lista)) resetaLista(lista);
}

// O(tam da lista)
void removeFim(ListaLigada *lista) {
    if(verificaListaVazia(lista)) return;
    if(lista->tam == 1) {
        removeFrente(lista);
        return;
    }
    Node *penultimo;
    penultimo = lista->ini;
    for(int i = 0; i < tamanho(lista) - 2; i++) {
        penultimo = penultimo->prox;
    }
    lista->tam--;
    free(lista->fim);
    lista->fim = penultimo;
    lista->fim->prox = NULL;
    if(verificaListaVazia(lista)) resetaLista(lista);
}

void limpaLista(ListaLigada *lista) {
    while(!verificaListaVazia(lista)) {
        removeFrente(lista);
    }
}

int procura(ListaLigada *lista, int x) {
    Node *atual = lista->ini;
    while(atual != NULL) {
        if(atual->valor == x) {
            return 1; // achei
        }
        atual = atual->prox;
    }
    return 0;
}

void printaLista(ListaLigada *lista) {
    if(verificaListaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }
    Node *atual = lista->ini;
    int pri = 1;
    while(atual != NULL) {
        if(pri) {
            printf("%d ", atual->valor);
            pri = 0;
        } else {
            printf("-> %d ", atual->valor);
        }
        atual = atual->prox;
    }
    printf("\n");
}

int main() {

    // Inicializando lista
    ListaLigada* lista = criaLista();

    // Add no
    insereFrente(lista, 10);
    insereFrente(lista, 2);

    // Printa : Output (2 -> 10)
    printaLista(lista);

    insereFim(lista, 8);
    insereFim(lista, 5);
    removeFim(lista);
    
    // Printa : Output (2 -> 10 -> 8)
    printaLista(lista);

    limpaLista(lista);

    // Printa : Ooutput (Lista vazia.)
    printaLista(lista);

    free(lista);

}