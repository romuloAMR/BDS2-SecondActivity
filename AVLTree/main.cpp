/**
 * @file main.cpp
 * @brief Ponto de entrada para a execução de testes na implementação da árvore AVL.
 */

#include "headers/AVLTree.h"
#include "headers/Logger.h"


/**
 * @brief Executa testes de rotação para verificar o balanceamento automático da árvore AVL.
 */
void runRotationTests() {
    AVLTree tree;

    Logger::log("\n== Teste de Rotação à Direita ==");
    tree.insert(30);
    tree.insert(20);
    tree.insert(10); // Deve provocar rotação à direita
    Logger::log("Verificar saída da rotação à direita (esperado: 20 como raiz)");
    tree.printTree();

    Logger::log("\n== Teste de Rotação à Esquerda ==");
    tree = AVLTree();
    tree.insert(10);
    tree.insert(20);
    tree.insert(30); // Deve provocar rotação à esquerda
    Logger::log("Verificar saída da rotação à esquerda (esperado: 20 como raiz)");
    tree.printTree();

    Logger::log("\n== Teste de Rotação Dupla (Esquerda-Direita) ==");
    tree = AVLTree();
    tree.insert(30);
    tree.insert(10);
    tree.insert(20); // Deve provocar rotação esquerda-direita
    Logger::log("Verificar saída da rotação esquerda-direita (esperado: 20 como raiz)");
    tree.printTree();

    Logger::log("\n== Teste de Rotação Dupla (Direita-Esquerda) ==");
    tree = AVLTree();
    tree.insert(10);
    tree.insert(30);
    tree.insert(20); // Deve provocar rotação direita-esquerda
    Logger::log("Verificar saída da rotação direita-esquerda (esperado: 20 como raiz)");
    tree.printTree();
}

/**
 * @brief Executa testes gerais de inserção, busca e remoção.
 */
void runTests() {
    AVLTree tree;
    
    Logger::log("== Teste de Inserção ==");
    int values[] = {15, 18,20, 35, 32, 38, 30, 40, 32, 45, 48, 52, 60, 50};
    for (int val : values) {
        tree.insert(val);
    }
    Logger::log("Verificar árvore após inserções");
    tree.printTree();

    Logger::log("\n== Teste de Busca ==");
    Logger::log("Busca pelo valor 15 (esperado: sucesso): " + 
                std::string(tree.search(15) ? "Encontrado" : "Não encontrado"));
    Logger::log("Busca pelo valor 100 (esperado: falha): " + 
                std::string(tree.search(100) ? "Encontrado" : "Não encontrado"));

    Logger::log("\n== Teste de Remoção ==");
    Logger::log("\nÁrvore Atual:\n");
    tree.printTree();
    tree.remove(15);
    Logger::log("Remoção do valor 15 (esperado: árvore balanceada sem 15)");
    tree.printTree();
}

/**
 * @brief Função principal que executa todos os testes.
 * @return int Código de retorno da aplicação.
 */
int main() {
    Logger::log("Iniciando testes na árvore AVL\n");
    runRotationTests();  ///< Executa testes de rotação.
    runTests();          ///< Executa testes de inserção, busca e remoção.
    return 0;
}
