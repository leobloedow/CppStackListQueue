#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
class Fila {
private:
    Node<T>* inicio;
    Node<T>* fim;

public:
    Fila();
    void push(T data);
    void pop();
};

template <class T>
Fila<T>::Fila() {
    inicio = nullptr;
    fim = nullptr;
}

template <class T>
void Fila<T>::push(T data) {
    Node<T>* novo = new Node<T>(data);
    if (inicio == nullptr) {
        inicio = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        novo->anterior = fim;
        fim = novo;
    }
    cout << "elemento '" << data << "' inserido no fim da fila!" << endl;
}

template <class T>
void Fila<T>::pop() {
    if (inicio == nullptr) {
        cout << "fila vazia!" << endl;
        return;
    }
    Node<T>* temp = inicio;
    cout << "elemento '" << temp->data << "' removido do inicio da fila!" << endl;
    inicio = inicio->proximo;
    if (inicio != nullptr) {
        inicio->anterior = nullptr;
    } else {
        fim = nullptr;
    }
    delete temp;
}
