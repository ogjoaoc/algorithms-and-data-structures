/*
* Autor : João
* Data : 10/3/2025
* maxheap.cpp
* implementação simples de um maxheap com base na aula do NepsAcademy.
*
* Estruturas:
* - MaxHeap: estrutura de dados que representa uma heap máxima, contendo um vetor de inteiros.
* - insere e remove em logN
*
* Funções:
* - getEsq: retorna o índice do filho esquerdo de um nó.
* - getDir: retorna o índice do filho direito de um nó.
* - getPai: retorna o índice do pai de um nó.
* - getMax: retorna o valor máximo da heap (raiz).
* - concertaHeap: corrige a posição de um nó após inserção.
* - concertaDel: corrige a posição de um nó após remoção.
* - insere: insere valor na heap.
* - removeMax: remove o maior da heap.
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct MaxHeap {

    vector<int> tree;

    MaxHeap() { tree = {0}; }

    int getEsq(int t) { return 2 * t; } 

    int getDir(int t) { return 2 * t + 1; } 

    int getPai(int t) { return t/2; }

    int getMax() { return tree[1]; }

    void concertaHeap(int t) {
        if(t == 1) return;
        if(tree[getPai(t)] > tree[t]) return;
        swap(tree[getPai(t)], tree[t]);
        concertaHeap(getPai(t));
    }

    void concertaDel(int t) {
        if(tree[getEsq(t)] <= tree[t]) return;
        int max = getEsq(t);
        if(getDir(t) < tree.size() && tree[getDir(t)] >= tree[getEsq(t)]) 
            max = getDir(t);
        if(tree[t] > tree[max]) return;
        swap(tree[t], tree[max]);
        concertaDel(max);
    }

    void insere(int val) {
        tree.push_back(val);
        concertaHeap(tree.size() - 1);
    }

    void removeMax() {
        if(tree.size() <= 1) {
            cout << "Heap vazio.\n";   
            return;
        }
        tree[1] = tree.back();
        tree.pop_back();
        concertaDel(1);
    }
} MaxHeap;

int main() {

    MaxHeap heap;
    
    heap.insere(2);
    heap.insere(5);
    heap.insere(1);
    heap.insere(23);

    cout << "Max aqui -> " << heap.getMax() << '\n';

    heap.removeMax();

    cout << "Max aqui -> " << heap.getMax() << '\n';

}