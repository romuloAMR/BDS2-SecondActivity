/**
 * @file AVLTree.cpp
 * @brief Implementação da classe AVLTree.
 */

#include "../headers/AVLTree.h"
#include <iostream>
#include <queue>
using namespace std;

AVLTree::Node::Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node* root) {
    return root == nullptr ? 0 : root->height;
}

int AVLTree::getBalance(Node* root) {
    return root == nullptr ? 0 : height(root->left) - height(root->right);
}

AVLTree::Node* AVLTree::rotateRight(Node* root) {
    // Realiza uma rotação simples para a direita para balancear a subárvore.
    Node* left = root->left;
    root->left = left->right;
    left->right = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;
    return left;
}

AVLTree::Node* AVLTree::rotateLeft(Node* root) {
    // Realiza uma rotação simples para a esquerda para balancear a subárvore.
    Node* right = root->right;
    root->right = right->left;
    right->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    right->height = max(height(right->left), height(right->right)) + 1;
    return right;
}

AVLTree::Node* AVLTree::rotateLeftRight(Node* root) {
    // Realiza uma rotação dupla (esquerda-direita).
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

AVLTree::Node* AVLTree::rotateRightLeft(Node* root) {
    // Realiza uma rotação dupla (direita-esquerda).
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

AVLTree::Node* AVLTree::minValueNode(Node* root) {
    // Encontra o nó com o menor valor na subárvore à direita.
    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

AVLTree::Node* AVLTree::insert(Node* root, int key) {
    // Insere um valor na subárvore e realiza balanceamento se necessário.
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && key < root->left->key) {
        return rotateRight(root);
    }
    if (balance < -1 && key > root->right->key) {
        return rotateLeft(root);
    }
    if (balance > 1 && key > root->left->key) {
        return rotateLeftRight(root);
    }
    if (balance < -1 && key < root->right->key) {
        return rotateRightLeft(root);
    }
    return root;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

AVLTree::Node* AVLTree::remove(Node* root, int key) {
    // Remove um valor da subárvore e balanceia após a remoção.
    if (root == nullptr) {
        return root;
    }
    if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
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

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rotateRight(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return rotateLeft(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::remove(int key) {
    root = remove(root, key);
}

bool AVLTree::search(Node* root, int key) {
    // Busca recursivamente por um valor na subárvore.
    if (root == nullptr) return false;
    if (root->key == key) return true;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

bool AVLTree::search(int key) {
    return search(root, key);
}

void AVLTree::printLevels(Node* root) {
    // Imprime os nós da árvore nível a nível.
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        size_t levelSize = q.size();
        for (size_t i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << endl;
    }
}

void AVLTree::printTree() {
    printLevels(root);
}
