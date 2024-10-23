/*
BST: implementação em C++ curta para competições.
- Estrutura do Nó.
- Inserção.
- Remoção.
- Busca.
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {

    int val;
    
    Node* left;
    
    Node* right;
    
    Node(int x) {

        val = x;
        left = NULL;
        right = NULL;
    
    }

};


Node* insert(Node* raiz, int val) {
    
    if(raiz == NULL) return new Node(val);

    if(val >= raiz->val) {

        raiz->right = insert(raiz->right, val);

    } else {

        raiz->left = insert(raiz->left, val);

    }

    return raiz;

}

Node* search(Node* raiz, int val) {

    if(raiz == NULL || raiz->val == val) return raiz;

    if(val >= raiz->val) return search(raiz->right, val);

    return search(raiz->left, val);

}

Node* remove(Node* raiz, int val) {

    if(raiz == NULL) return raiz;

    if(val > raiz->val) {

        raiz->right = remove(raiz->right, val);

    } else if(val < raiz->val) {

        raiz->left = remove(raiz->left, val);

    } else {

        if(raiz->left == NULL) {

            Node* temp = raiz->right;
            
            delete raiz;
            
            return temp;

        }

        if(raiz->right == NULL) {

            Node* temp = raiz->left;

            delete raiz;

            return temp;

        }

        Node* last = raiz->right;
        
        while(last != NULL && last->left != NULL) {
            last = last->left;
        }

        raiz->val = last->val;
        raiz->right = remove(raiz->right, last->val);


    }

    return raiz;

}

int main() {

    Node* raiz = new Node(10);

    insert(raiz, 5);

    if(search(raiz, 5) != NULL) {
        
        cout << "Achou\n";

    } else {

        cout << ":(\n";

    }

    if(remove(raiz, 5) != NULL) {

        cout << "Removi o elemento.\n";

        cout << "Raiz = " << raiz->val << '\n';
        cout << "Esquerda = " << raiz->left << '\n';
        cout << "Direita = " << raiz->right << '\n';

    }

    return 0;
}