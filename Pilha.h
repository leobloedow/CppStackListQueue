//.h
#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class Pilha {
private:
    Node<T>* base;
    Node<T>* topo;
    int tamanho;

public:
    Pilha();
    void push(T data);
    void pop();
    bool find(T data);
};

//cpp

using namespace std;

template <class T>
Pilha<T>::Pilha() {
    base = nullptr;
    topo = nullptr;
    tamanho = 0;
}

template <class T>
void Pilha<T>::push(T data) {
    Node<T>* novo = new Node<T>(data);
    if (topo == nullptr) {
        base = novo;
        topo = novo;
    } else {
        topo->proximo = novo;
        novo->anterior = topo;
        topo = novo;
    }
    tamanho++;
    cout << "elemento '" << data << "' inserido no topo da pilha!" << endl;
}

template <class T>
void Pilha<T>::pop() {
    if (topo == nullptr) {
        cout << "pilha vazia!" << endl;
        return;
    }
    Node<T>* temp = topo;
    cout << "elemento '" << temp->data << "' removido!" << endl;
    if (topo == base) {
        base = nullptr;
        topo = nullptr;
    } else {
        topo = topo->anterior;
        topo->proximo = nullptr;
    }
    delete temp;
    tamanho--;
}

template <class T>
bool Pilha<T>::find(T data) {
    Node<T>* atual = topo;
    while (atual != nullptr) {
        if (atual->data == data) {
            cout << "'" << data << "' encontrado!" << endl;
            return true;
        }
        atual = atual->anterior;
    }
    cout << "elemento nao encontrado." << endl;
    return false;
}
