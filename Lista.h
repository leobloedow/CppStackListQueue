#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class Lista {
private:
    Node<T>* primeiro;
    Node<T>* ultimo;
    int tamanho;

public:
    Lista();
    void push(T data);
    void insertAtPosition(T data, int position);
    void remove(T data);
    bool find(T data);
};

template <class T>
Lista<T>::Lista() {
    primeiro = nullptr;
    ultimo = nullptr;
    tamanho = 0;
}

template <class T>
void Lista<T>::push(T data) {
    Node<T>* novo = new Node<T>(data);
    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = novo;
    } else {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    }
    tamanho++;
    cout << "elemento '" << data << "' inserido no fim da lista." << endl;
}

template <class T>
void Lista<T>::insertAtPosition(T data, int position) {
    if (position < 0 || position > tamanho) {
        cout << "posicao invalida!" << endl;
        return;
    }

    Node<T>* novo = new Node<T>(data);

    if (position == 0) {
        if (primeiro == nullptr) {
            primeiro = novo;
            ultimo = novo;
        } else {
            novo->proximo = primeiro;
            primeiro->anterior = novo;
            primeiro = novo;
        }
    } else if (position == tamanho) {
        ultimo->proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    } else {
        Node<T>* atual = primeiro;
        for (int i = 0; i < position; ++i) {
            atual = atual->proximo;
        }
        novo->proximo = atual;
        novo->anterior = atual->anterior;
        atual->anterior->proximo = novo;
        atual->anterior = novo;
    }
    tamanho++;
    cout << "elemento '" << data << "' inserido na posicao " << position << endl;
}

template <class T>
void Lista<T>::remove(T data) {
    if (primeiro == nullptr) {
        cout << "lista vazia!" << endl;
        return;
    }

    Node<T>* atual = primeiro;
    while (atual != nullptr && atual->data != data) {
        atual = atual->proximo;
    }

    if (atual == nullptr) {
        cout << "elemento '" << data << "' nao encontrado." << endl;
        return;
    }

    cout << "elemento '" << atual->data << "' removido!" << endl;
    if (atual == primeiro && atual == ultimo) {
        primeiro = nullptr;
        ultimo = nullptr;
    } else if (atual == primeiro) {
        primeiro = primeiro->proximo;
        primeiro->anterior = nullptr;
    } else if (atual == ultimo) {
        ultimo = ultimo->anterior;
        ultimo->proximo = nullptr;
    } else {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
    }
    delete atual;
    tamanho--;
}

template <class T>
bool Lista<T>::find(T data) {
    Node<T>* atual = primeiro;
    while (atual != nullptr) {
        if (atual->data == data) {
            cout << "elemento '" << data << "' encontrado!" << endl;
            return true;
        }
        atual = atual->proximo;
    }
    cout << "elemento '" << data << "' nao encontrado" << endl;
    return false;
}
