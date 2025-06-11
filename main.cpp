#include "Fila.h"
#include "Lista.h"
#include <iostream>
#include <string>

int main() {
    Fila<std::string> clientes;

    std::cout << "--- Testando a Fila ---" << std::endl;

    // Teste de inserção (push)
    clientes.push("Ana");
    clientes.push("Bruno");
    clientes.push("Carla");

    std::cout << "--------------------" << std::endl;

    // Teste de front

    std::cout << "--------------------" << std::endl;

    // Teste de busca (find)

    std::cout << "--------------------" << std::endl;

    // Teste de remoção (pop)
    clientes.pop(); // Remove Ana
 
    clientes.pop(); // Remove Bruno
    clientes.pop(); // Remove Carla
    clientes.pop(); // Tenta remover de uma fila vazia

    std::cout << "--------------------" << std::endl;
    std::cout << "Programa Fila encerrado." << std::endl;

    return 0;
}
