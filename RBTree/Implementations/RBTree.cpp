#include "../Headers/RBTree.hpp"

// Constructors and Destructors
RBTree::RBTree(int data, Color color) {
    this->data = data;
    this->color = color;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

RBTree::RBTree(int data){
    this->data = data;
    this->color = Color::BLACK;
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
    if(this->data == data){
        return;
    } else if (data > this->data){
        if (this->rightIsNull()) {
            this->right = new RBTree(data, Color::RED);
            this->right->setParent(this);
            this->right->insertFixup();
        } else {
            this->right->insert(data);
        }
    } else {
        if (this->leftIsNull()) {
            this->left = new RBTree(data, Color::RED);
            this->left->setParent(this);
            this->left->insertFixup();
        } else {
            this->left->insert(data);
        }
    }
}

void RBTree::insertFixup() {
    if(this->parentIsNull()) {
        this->setColor(Color::BLACK);
        return;
    } else {
        RBTree* parent = this->getParent();
        if (parent->isRed()) {
            RBTree* grandparent = parent->getParent();
            RBTree* uncle = parent->getBrother();
            if (uncle->isRed()) {
                parent->setColor(Color::BLACK);
                uncle->setColor(Color::BLACK);
                grandparent->setColor(Color::RED);
                grandparent->insertFixup();
            } else {
                if (grandparent->getLeft() == parent){
                    if (parent->getLeft() == this){
                        parent->setColor(Color::BLACK);
                        grandparent->setColor(Color::RED);
                        grandparent = grandparent->rightRotate();
                    } else {
                        this->setColor(Color::BLACK);
                        grandparent->setColor(Color::RED);
                        grandparent = grandparent->doubleRightRotate();
                    }
                } else {
                    if (parent->getRight() == this) {
                        parent->setColor(Color::BLACK);
                        grandparent->setColor(Color::RED);
                        grandparent = grandparent->leftRotate();
                    } else {
                        this->setColor(Color::BLACK);
                        grandparent->setColor(Color::RED);
                        grandparent = grandparent->doubleLeftRotate();
                    }
                }
            }
        }
    }
    return;
}

void RBTree::remove(int data) {
    return;
}

void RBTree::print() {
    std::queue<RBTree*> q;
    q.push(this);

    while (!q.empty()) {
        int levelSize = q.size();

        while (levelSize--) {
            RBTree* current = q.front();
            q.pop();
            std::cout << current->getData() << "(";
            std::cout << (current->getColor() == RED ? "R" : "B") << ") ";
            if (current->getLeft() != nullptr) {
                q.push(current->getLeft());
            }
            if (current->getRight() != nullptr) {
                q.push(current->getRight());
            }
        }
        std::cout << std::endl;
    }
}
