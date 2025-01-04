#include "../Headers/RBTree.hpp"

RBTree::RBTree(int data, Color color) {
    this->data = data;
    this->color = color;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

RBTree::~RBTree() {
    delete this->left;
    delete this->right;
}

int RBTree::getData() {
    return this->data;
}

RBTree* RBTree::getLeft() {
    return this->left;
}

RBTree* RBTree::getRight() {
    return this->right;
}

RBTree* RBTree::getParent() {
    return this->parent;
}

Color RBTree::getColor() {
    return this->color;
}

void RBTree::setData(int data) {
    this->data = data;
}

void RBTree::setLeft(RBTree* left) {
    this->left = left;
}

void RBTree::setRight(RBTree* right) {
    this->right = right;
}

void RBTree::setParent(RBTree* parent) {
    this->parent = parent;
}

void RBTree::setColor(Color color) {
    this->color = color;
}

bool RBTree::isRed() {
    if (this == nullptr){
        return false;
    }
    return this->color == Color::RED;
}

bool RBTree::isNull() {
    return this == nullptr;
}

RBTree& RBTree::getBrother() {
    if (this->parent == nullptr) {
        return *this;
    }
    if (this == this->parent->left) {
        return *this->parent->right;
    }
    return *this->parent->left;
}

void RBTree::leftRotate() {
    RBTree* a = this;
    RBTree* b = this->right;
    RBTree* d = b->left;
    RBTree* parent = a->parent;

    if (parent != nullptr) {
        if (parent->left == a) {
            parent->left = b;
        } else {
            parent->right = b;
        }
    }
    b->parent = parent;
    a->parent = b;
    a->right = d;
    if (d != nullptr) {
        d->parent = a;
    }
    b->left = a;
}

void RBTree::rightRotate() {
    RBTree* c = this;
    RBTree* b = this->left;
    RBTree* d = b->right;
    RBTree* parent = c->parent;

    if (parent != nullptr) {
        if (parent->left == c) {
            parent->left = b;
        } else {
            parent->right = b;
        }
    }
    b->parent = parent;
    c->parent = b;
    c->left = d;
    if (d != nullptr) {
        d->parent = c;
    }
    b->right = c;
}

void RBTree::doubleLeftRotate() {
    this->right->rightRotate();
    this->leftRotate();
}

void RBTree::doubleRightRotate() {
    this->left->leftRotate();
    this->rightRotate();
}

bool RBTree::search(int data) {
    if (this == nullptr) {
        return false;
    }
    if (this->data == data) {
        return true;
    }
    if (data < this->data) {
        return this->left->search(data);
    }
    return this->right->search(data);
}