#include "../Headers/RBTree.hpp"

// Constructors and Destructors
RBTree::RBTree(int data, Color color) {
    this->data = data;
    this->color = color;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

RBTree::~RBTree() {
    if (!this->leftIsNull()) {
        delete this->left;
    }
    if (!this->rightIsNull()) {
        delete this->right;
    }
}

// Getters
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

bool RBTree::leftIsNull() {
    return this->getLeft() == nullptr;
}

bool RBTree::rightIsNull() {
    return this->getRight() == nullptr;
}

bool RBTree::parentIsNull() {
    return this->getParent() == nullptr;
}

bool RBTree::isRed() {
    return this->getColor() == Color::RED;
}

RBTree* RBTree::getBrother() {
    if (this->parentIsNull()) {
        return this;
    }

    if (this == this->parent->left) {
        if (!this->parent->rightIsNull()) {
            return this->parent->right;
        }
    }

    if (this == this->parent->right) {
        if (!this->parent->leftIsNull()) {
            return this->parent->left;
        }
    }

    return this;
}


// Setters
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


// Rotations
RBTree* RBTree::leftRotate() {
    RBTree* newRoot = this->right;
    this->right = newRoot->left;
    newRoot->left = this;
    return newRoot;
}

RBTree* RBTree::rightRotate() {
    RBTree* newRoot = this->left;
    this->left = newRoot->right;
    newRoot->right = this;
    return newRoot;
}

RBTree* RBTree::doubleLeftRotate() {
    this->right = this->right->rightRotate();
    return this->leftRotate();
}

RBTree* RBTree::doubleRightRotate() {
    this->left = this->left->leftRotate();
    return this->rightRotate();
}

// Search, Insert, Remove, Print
bool RBTree::search(int data) {
    if(this->data == data) {
        return true;
    } else if (data < this->data) {
        if (this->leftIsNull()) {
            return false;
        } else {
            return this->left->search(data);
        }
    } else {
        if (this->rightIsNull()) {
            return false;
        } else {
            return this->right->search(data);
        }
    }
    return false;
}

void RBTree::insert(int data) {
    return;
}

void RBTree::remove(int data) {
    return;
}

void RBTree::print() {
    return;
}