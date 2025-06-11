#include "Pilha.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Pilha<string> nomes;

    nomes.push("Beltrano");
    nomes.push("Cicrano");
    nomes.push("Fulano");

    cout << "--------------------" << endl;

    // Testa o find
    nomes.find("Cicrano");
    nomes.find("Ze Ninguem");

    cout << "--------------------" << endl;

    // Testa o pop
    nomes.pop(); // Remove Fulano
    nomes.pop(); // Remove Cicrano
    nomes.pop(); // Remove Beltrano
    nomes.pop(); // Tenta remover de uma pilha já vazia

    cout << "--------------------" << endl;
    cout << "Programa encerrado." << endl;

    return 0;
}
