#include "../headers/AVLTree.h"

/**
 * @brief Construtor que inicializa a árvore AVL com uma raiz nula.
 */
AVLTree::AVLTree() : root(nullptr) {}

/**
 * @brief Retorna a altura de um nó.
 * @param node Ponteiro para o nó.
 * @return Altura do nó ou 0 se o nó for nulo.
 */
int AVLTree::height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

/**
 * @brief Retorna o fator de balanceamento de um nó.
 * @param node Ponteiro para o nó.
 * @return Diferença entre a altura dos filhos esquerdo e direito.
 */
int AVLTree::getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

/**
 * @brief Realiza uma rotação à direita.
 * @param root Ponteiro para o nó raiz a ser rotacionado.
 * @return Novo nó raiz após a rotação.
 */
AVLTree::Node* AVLTree::rotateRight(Node* root) {
    Node* newNode = root->left;
    root->left = newNode->right;
    newNode->right = root;
    root->height = std::max(height(root->left), height(root->right)) + 1;
    newNode->height = std::max(height(newNode->left), height(newNode->right)) + 1;
    return newNode;
}

/**
 * @brief Realiza uma rotação à esquerda.
 * @param root Ponteiro para o nó raiz a ser rotacionado.
 * @return Novo nó raiz após a rotação.
 */
AVLTree::Node* AVLTree::rotateLeft(Node* root) {
    Node* newNode = root->right;
    root->right = newNode->left;
    newNode->left = root;
    root->height = std::max(height(root->left), height(root->right)) + 1;
    newNode->height = std::max(height(newNode->left), height(newNode->right)) + 1;
    return newNode;
}

/**
 * @brief Balanceia a árvore a partir de um nó raiz.
 * @param root Ponteiro para o nó a ser balanceado.
 */
void AVLTree::balance(Node*& root) {
    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
        }
        root = rotateRight(root);
    } else if (balance < -1) {
        if (getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
        }
        root = rotateLeft(root);
    }
}

/**
 * @brief Insere um valor na árvore AVL.
 * @param key Valor a ser inserido.
 */
void AVLTree::insert(int key) {
    root = insert(root, key);
}

/**
 * @brief Remove um valor da árvore AVL.
 * @param key Valor a ser removido.
 */
void AVLTree::remove(int key) {
    root = remove(root, key);
}

/**
 * @brief Insere um valor em um nó.
 * @param root Nó raiz para inserir.
 * @param key Valor a ser inserido.
 * @return Novo nó raiz após a inserção.
 */
AVLTree::Node* AVLTree::insert(Node* root, int key) {
    if (root == nullptr) return new Node(key);

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root;  // Valor duplicado não permitido.
    }

    root->height = 1 + std::max(height(root->left), height(root->right));
    balance(root);
    return root;
}

/**
 * @brief Remove um valor de um nó.
 * @param root Nó raiz para remoção.
 * @param key Valor a ser removido.
 * @return Novo nó raiz após a remoção.
 */
AVLTree::Node* AVLTree::remove(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = remove(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + std::max(height(root->left), height(root->right));
    balance(root);
    return root;
}

/**
 * @brief Busca um valor na árvore AVL.
 * @param key Valor a ser buscado.
 * @return true se o valor for encontrado, false caso contrário.
 */
bool AVLTree::search(int key) {
    return search(root, key);
}

/**
 * @brief Função auxiliar de busca.
 * @param root Nó raiz para busca.
 * @param key Valor a ser buscado.
 * @return true se encontrado, false caso contrário.
 */
bool AVLTree::search(Node* root, int key) {
    if (root == nullptr) return false;
    if (key == root->key) return true;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

/**
 * @brief Imprime os níveis da árvore AVL.
 */
void AVLTree::printTree() {
    printLevels(root);
}

/**
 * @brief Imprime a árvore em níveis para fins de depuração.
 * @param root Nó raiz para impressão.
 */
void AVLTree::printLevels(Node* root) {
    if (root == nullptr) return;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        size_t levelSize = q.size();
        for (size_t i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            std::cout << current->key << " ";
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        std::cout << std::endl;
    }
}

/**
 * @brief Retorna o nó com o menor valor a partir do nó dado.
 * @param node Nó inicial.
 * @return Nó com o menor valor.
 */
AVLTree::Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}


/**
 * @brief Libera toda a memória alocada pela árvore.
 * @param root Ponteiro para o nó raiz da subárvore.
 */
void AVLTree::deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void AVLTree::deleteTree() {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

/**
 * @brief Destrutor da classe AVLTree para limpar a memória.
 */
AVLTree::~AVLTree() {
    deleteTree();
}

