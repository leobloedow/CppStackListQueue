
#include "Pilha.h"
#include <iostream>
#include <string>

int main() {
    // Cria uma pilha de strings
    Pilha<std::string> nomes;

    // Testa o push
    nomes.push("Beltrano");
    nomes.push("Cicrano");
    nomes.push("Fulano");

    std::cout << "--------------------" << std::endl;

    // Testa o find
    nomes.find("Cicrano");
    nomes.find("Ze Ninguem");

    std::cout << "--------------------" << std::endl;

    // Testa o pop
    nomes.pop(); // Remove Fulano
    nomes.pop(); // Remove Cicrano
    nomes.pop(); // Remove Beltrano
    nomes.pop(); // Tenta remover de uma pilha já vazia

    std::cout << "--------------------" << std::endl;
    std::cout << "Programa encerrado." << std::endl;

    return 0;
}
