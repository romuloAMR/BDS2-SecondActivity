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

void runClassTests() {
    AVLTree tree;
    
    Logger::log("== Teste de Inserção ==");
    int values[] = {30, 20, 50, 15, 25, 40, 60, 35, 45, 70};
    for (int val : values) {
        tree.insert(val);
    }
    Logger::log("Verificar árvore após inserções");
    tree.printTree();


    std::cout << "\n\nInserção em sala\n\n";

    AVLTree newTree;
    for (int val : values) {
        newTree.insert(val);
    }
    Logger::log("\n== Teste de inserção única com valor 10 ==");
    newTree.insert(10);
    Logger::log("Verificar árvore após inserção");
    newTree.printTree();
    newTree.remove(10);
    Logger::log("Verificar árvore após remoção do 10");
    newTree.printTree();

    Logger::log("\n== Teste de inserção única com valor 32 ==");
    newTree.insert(32);
    Logger::log("Verificar árvore após inserção");
    newTree.printTree();
    newTree.remove(10);
    Logger::log("Verificar árvore após remoção do 32");
    newTree.printTree();


    std::cout << "\n\nRemoção em sala\n\n";

    // remoção em sala
     AVLTree newTreeRM;
     int newValues[] = {50, 35, 70, 25, 40, 65, 90, 30, 80};
    for (int val : newValues) {
        newTreeRM.insert(val);
    }
    newTreeRM.remove(35);
    Logger::log("Verificar árvore após remoção do 35");
    newTreeRM.printTree();



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

int main() {
    runRotationTests();
    runTests();
    runClassTests();
    return 0;
}
