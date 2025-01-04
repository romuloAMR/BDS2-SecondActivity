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