/**
 * @file AVLTree.h
 * @brief Definição da classe AVLTree que implementa uma árvore AVL balanceada.
 */

#ifndef AVL_TREE_H
#define AVL_TREE_H

/**
 * @class AVLTree
 * @brief Classe que representa uma árvore AVL, uma árvore binária de busca balanceada.
 */
class AVLTree {
private:
    /**
     * @struct Node
     * @brief Representa um nó da árvore AVL.
     */
    struct Node {
        int key;            ///< Valor armazenado no nó.
        Node* left;         ///< Ponteiro para o nó filho à esquerda.
        Node* right;        ///< Ponteiro para o nó filho à direita.
        int height;         ///< Altura do nó.
        
        /**
         * @brief Construtor para inicializar um nó com uma chave.
         * @param k Valor da chave.
         */
        Node(int k);
    };

    Node* root; ///< Ponteiro para a raiz da árvore.

    /**
     * @brief Obtém a altura de um nó.
     * @param root Ponteiro para o nó.
     * @return Altura do nó ou 0 se for nulo.
     */
    int height(Node* root);

    /**
     * @brief Calcula o fator de balanceamento de um nó.
     * @param root Ponteiro para o nó.
     * @return Fator de balanceamento.
     */
    int getBalance(Node* root);

    /**
     * @brief Realiza rotação simples à direita.
     * @param root Ponteiro para o nó raiz da subárvore.
     * @return Nova raiz após a rotação.
     */
    Node* rotateRight(Node* root);

    /**
     * @brief Realiza rotação simples à esquerda.
     * @param root Ponteiro para o nó raiz da subárvore.
     * @return Nova raiz após a rotação.
     */
    Node* rotateLeft(Node* root);

    /**
     * @brief Realiza rotação dupla (esquerda-direita).
     * @param root Ponteiro para o nó raiz da subárvore.
     * @return Nova raiz após a rotação.
     */
    Node* rotateLeftRight(Node* root);

    /**
     * @brief Realiza rotação dupla (direita-esquerda).
     * @param root Ponteiro para o nó raiz da subárvore.
     * @return Nova raiz após a rotação.
     */
    Node* rotateRightLeft(Node* root);

    /**
     * @brief Encontra o nó com o menor valor em uma subárvore.
     * @param root Ponteiro para a raiz da subárvore.
     * @return Ponteiro para o nó com o menor valor.
     */
    Node* minValueNode(Node* root);

    /**
     * @brief Insere um novo valor na árvore de forma recursiva.
     * @param root Ponteiro para a raiz atual da subárvore.
     * @param key Valor a ser inserido.
     * @return Nova raiz da subárvore após a inserção.
     */
    Node* insert(Node* root, int key);

    /**
     * @brief Remove um valor da árvore de forma recursiva.
     * @param root Ponteiro para a raiz atual da subárvore.
     * @param key Valor a ser removido.
     * @return Nova raiz da subárvore após a remoção.
     */
    Node* remove(Node* root, int key);

    /**
     * @brief Busca um valor na árvore de forma recursiva.
     * @param root Ponteiro para a raiz atual da subárvore.
     * @param key Valor a ser buscado.
     * @return True se o valor for encontrado, false caso contrário.
     */
    bool search(Node* root, int key);

    /**
     * @brief Imprime os nós da árvore por nível.
     * @param root Ponteiro para a raiz da árvore.
     */
    void printLevels(Node* root);

public:
    /**
     * @brief Construtor padrão que inicializa a árvore vazia.
     */
    AVLTree();

    /**
     * @brief Insere um valor na árvore AVL.
     * @param key Valor a ser inserido.
     */
    void insert(int key);

    /**
     * @brief Remove um valor da árvore AVL.
     * @param key Valor a ser removido.
     */
    void remove(int key);

    /**
     * @brief Busca um valor na árvore AVL.
     * @param key Valor a ser buscado.
     * @return True se o valor for encontrado, false caso contrário.
     */
    bool search(int key);

    /**
     * @brief Imprime a árvore AVL por níveis.
     */
    void printTree();
};

#endif // AVL_TREE_H
