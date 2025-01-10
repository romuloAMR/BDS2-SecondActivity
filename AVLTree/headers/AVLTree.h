/**
 * @file AVLTree.h
 * @brief Declaração da classe AVLTree que implementa uma árvore AVL com balanceamento automático.
 */
#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <queue>

/**
 * @class AVLTree
 * @brief Implementação de uma árvore AVL com operações de inserção, remoção e busca balanceadas.
 */
class AVLTree {
private:
    /**
     * @struct Node
     * @brief Representa um nó na árvore AVL.
     */
    struct Node {
        int key;          ///< Valor armazenado no nó.
        Node* left;       ///< Ponteiro para o filho esquerdo.
        Node* right;      ///< Ponteiro para o filho direito.
        int height;       ///< Altura do nó para fins de balanceamento.

        /**
         * @brief Construtor que inicializa o nó com uma chave.
         * @param k Valor da chave do nó.
         */
        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;  ///< Raiz da árvore AVL.

    int height(Node* node);         ///< Retorna a altura de um nó.
    int getBalance(Node* node);     ///< Retorna o fator de balanceamento de um nó.
    Node* rotateRight(Node* root);  ///< Realiza uma rotação à direita.
    Node* rotateLeft(Node* root);   ///< Realiza uma rotação à esquerda.
    Node* rotateLeftRight(Node* root); ///< Realiza uma rotação esquerda-direita.
    Node* rotateRightLeft(Node* root); ///< Realiza uma rotação direita-esquerda.
    Node* minValueNode(Node* node); ///< Encontra o nó com o menor valor.
    Node* insert(Node* root, int key); ///< Insere um valor na árvore.
    Node* remove(Node* root, int key); ///< Remove um valor da árvore.
    void balance(Node*& root);       ///< Balanceia a árvore a partir do nó raiz fornecido.
    bool search(Node* root, int key);///< Busca um valor na árvore.
    void printLevels(Node* root);    ///< Imprime os níveis da árvore no console.


public:
    /**
     * @brief Construtor padrão da árvore AVL.
     */
    AVLTree();
    ~AVLTree();

    /**
     * @brief Insere um valor na árvore.
     * @param key Valor a ser inserido.
     */
    void insert(int key);

    /**
     * @brief Remove um valor da árvore.
     * @param key Valor a ser removido.
     */
    void remove(int key);

    /**
     * @brief Busca um valor na árvore.
     * @param key Valor a ser buscado.
     * @return true se o valor for encontrado, false caso contrário.
     */
    bool search(int key);

    /**
     * @brief Imprime a árvore no formato de níveis.
     */
    void printTree();

    /**
     * @brief Deleta a árvore usando a raiz
     */
    void deleteTree(Node* root);

    void deleteTree();

    
};

#endif
