#pragma once

template <class T>
class Node {
public:
    T data;
    Node<T>* proximo;
    Node<T>* anterior;

    Node(T data) {
        this->data = data;
        this->proximo = nullptr;
        this->anterior = nullptr;
    }
};
