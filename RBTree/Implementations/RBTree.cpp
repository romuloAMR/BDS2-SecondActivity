#include "../Headers/RBTree.hpp"

RBTree::RBTree() {
    this->data = 0;
    this->color = Color::BLACK;
    this->issNull = true;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

RBTree::RBTree(int data, Color color) {
    this->data = data;
    this->color = color;
    this->issNull = false;
    this->left = new RBTree();
    this->right = new RBTree();
    this->parent = new RBTree();
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
    if (this->isNull()){
        return false;
    }
    return this->color == Color::RED;
}

bool RBTree::isNull() {
    return this->issNull || this == nullptr;
}

RBTree& RBTree::getBrother() {
    if (this->parent->isNull()) {
        return *this;
    }

    if (this == this->parent->left) {
        if (!this->parent->right->isNull()) {
            return *this->parent->right;
        }
    }

    if (this == this->parent->right) {
        if (!this->parent->left->isNull()) {
            return *this->parent->left;
        }
    }

    return *this;
}

void RBTree::leftRotate() {
    RBTree* a = this;
    RBTree* b = this->right;
    RBTree* d = b->left;
    RBTree* parent = a->parent;

    if (!parent->isNull()) {
        if (parent->left == a) {
            parent->left = b;
        } else {
            parent->right = b;
        }
    }
    b->parent = parent;
    a->parent = b;
    a->right = d;
    if (!d->isNull()) {
        d->parent = a;
    }
    b->left = a;    
}

void RBTree::rightRotate() {
    RBTree* c = this;
    RBTree* b = this->left;
    RBTree* d = b->right;
    RBTree* parent = c->parent;

    if (!parent->isNull()) {
        if (parent->left == c) {
            parent->left = b;
        } else {
            parent->right = b;
        }
    }
    b->parent = parent;
    b->right = c;
    c->parent = b;
    c->left = d;
    if (!d->isNull()) {
        d->parent = c;
    }
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
    if (this->isNull()) {
        return false;
    }
    if (this->data == data) {
        return true;
    }
    if (data < this->data) {
        if (!this->left->isNull()) {
            return this->left->search(data);
        } else {
            return false;
        }
    }
    if (!this->right->isNull()) {
        return this->right->search(data);
    }
    return false;
}

bool RBTree::insert(int data) {
    if (this->isNull()) {
        this->issNull = false;
        this->data = data;
        this->color = Color::RED;
        this->left = new RBTree();
        this->right = new RBTree();
        if (this->parent == nullptr) {
            this->parent = new RBTree();
        }
        this->insertFix();
        return true;
    }
    else {
        if (data < this->data) {
            if(this->left->isNull()) {
                this->left = new RBTree(data, Color::RED);
                this->left->parent = this;
                this->left->insertFix();
                return true;
            }
            return this->left->insert(data);
        }
        else if (data > this->data) {
            if(this->right->isNull()) {
                this->right = new RBTree(data, Color::RED);
                this->right->parent = this;
                this->right->insertFix();
                return true;
            }
            return this->right->insert(data);
        }
    }

    return false;
}

void RBTree::insertFix() {
    if(this->parent->isNull()) {
        this->color = Color::BLACK;
        return;
    }
    RBTree* parent = this->parent;
    if(!parent->isRed()) {
        return;
    }
    else {
        RBTree* uncle = &(this->parent->getBrother());
        RBTree* grandparent = this->parent->parent;
        grandparent->setColor(Color::RED);
        if(uncle->isRed()){
            parent->setColor(Color::BLACK);
            uncle->setColor(Color::BLACK);
            grandparent->insertFix();
        }
        else {
            if(grandparent->left == parent) {
                if(parent->left == this){
                    parent->setColor(Color::BLACK);
                    grandparent->rightRotate();
                }
                else {
                    this->setColor(Color::BLACK);
                    grandparent->doubleRightRotate();
                }
            }
            else {
                if(parent->right == this){
                    parent->setColor(Color::BLACK);
                    grandparent->leftRotate();
                }
                else {
                    this->setColor(Color::BLACK);
                    grandparent->doubleLeftRotate();
                }
            }
        }
    }
}