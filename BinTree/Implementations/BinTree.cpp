#include "../Headers/BinTree.hpp"

BinTree::BinTree(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

BinTree::~BinTree() {
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

int BinTree::getData() const {
    return this->data;
}

BinTree* BinTree::getLeft() const {
    return this->left;
}

BinTree* BinTree::getRight() const {
    return this->right;
}

void BinTree::setLeft(BinTree* left) {
    this->left = left;
}

void BinTree::setRight(BinTree* right) {
    this->right = right;
}

void BinTree::setData(int data) {
    this->data = data;
}

void BinTree::insert(const int& value) {
    if (value < this->data) {
        if (this->left == nullptr) {
            this->left = new BinTree(value);
        } else {
            this->left->insert(value);
        }
    } else if (value > this->data) {
        if (this->right == nullptr) {
            this->right = new BinTree(value);
        } else {
            this->right->insert(value);
        }
    }
}

bool BinTree::search(const int& value) const {
    if (value == this->data) {
        return true;
    } else if (value < this->data) {
        return ((this->left == nullptr)?false:this->left->search(value));
    } else {
        return ((this->right == nullptr)?false:this->right->search(value));
    }
}

void BinTree::removeLeaf(BinTree* parent, BinTree* leaf) {
    if (parent->getLeft() == leaf) {
        parent->setLeft(nullptr);
        delete leaf;
    } else {
        parent->setRight(nullptr);
        delete leaf;
    }
}

void BinTree::removeNode(BinTree* parent, BinTree* node) {
    if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        removeLeaf(parent, node);
    } else if (node->getLeft() != nullptr && node->getRight() == nullptr){
        if (parent->getLeft() == node) {
            parent->setLeft(node->getLeft());
            node->setLeft(nullptr);
            delete node;
        } else{
            parent->setRight(node->getLeft());
            node->setLeft(nullptr);
            delete node;
        }
        
    } else if (node->getLeft() == nullptr && node->getRight() != nullptr){
        if (parent->getLeft() == node) {
            parent->setLeft(node->getRight());
            node->setRight(nullptr);
            delete node;
        } else{
            parent->setRight(node->getRight());
            node->setRight(nullptr);
            delete node;
        }
    } else {
        BinTree* temp = node->getRight();
        while (temp->getLeft() != nullptr) {
            temp = temp->getLeft();
        }
        node->setData(temp->getData());
        removeNode(node, temp);
    }
}

void BinTree::removeRoot() {
    if (this->left == nullptr && this->right == nullptr) {
        delete this;
    } else if (this->left != nullptr && this->right == nullptr){
        BinTree* temp = this->left;
        this->setLeft(nullptr);
        delete temp;
    } else if (this->left == nullptr && this->right != nullptr){
        BinTree* temp = this->right;
        this->setRight(nullptr);
        delete temp;
    } else {
        BinTree* temp = this->right;
        while (temp->getLeft() != nullptr) {
            temp = temp->getLeft();
        }
        this->setData(temp->getData());
        removeNode(this, temp);
    }
}

void BinTree::remove(const int& value, BinTree* parent) {
    if (value == this->data) {
        if (parent == nullptr) {
            removeRoot();
        } else {
            removeNode(parent, this);
        }
    } else if (value < this->data) {
        if (this->left != nullptr) {
            this->left->remove(value, this);
        }
    } else {
        if (this->right != nullptr) {
            this->right->remove(value, this);
        }
    }
}

void BinTree::remove(const int& value) {
    remove(value, nullptr);
}