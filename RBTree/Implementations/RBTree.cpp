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
    RBTree* node = this;

    while (node != nullptr && node->data != data) {
        if (data < node->data) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    if (node == nullptr) {
        std::cout << "Node not found" << std::endl;
        return;
    }

    RBTree* toDelete = node;
    RBTree* replacement = nullptr;

    if (!toDelete->leftIsNull() && !toDelete->rightIsNull()) {
        RBTree* successor = toDelete->right;
        while (!successor->leftIsNull()) {
            successor = successor->left;
        }
        toDelete->data = successor->data;
        toDelete->color = successor->color;
        toDelete = successor;
    }

    replacement = toDelete->leftIsNull() ? toDelete->right : toDelete->left;

    if (replacement != nullptr) {
        replacement->parent = toDelete->parent;
    }

    if (toDelete->parent == nullptr) {
        if (replacement != nullptr) {
            this->data = replacement->data;
            this->color = replacement->color;
            this->left = replacement->left;
            this->right = replacement->right;
            if (this->left) this->left->parent = this;
            if (this->right) this->right->parent = this;
        } else {
            this->data = 0;
            this->color = Color::BLACK;
            this->left = nullptr;
            this->right = nullptr;
        }
    } else {
        if (toDelete == toDelete->parent->left) {
            toDelete->parent->left = replacement;
        } else {
            toDelete->parent->right = replacement;
        }

        if (toDelete->color == Color::BLACK) {
            removeFixup(replacement, toDelete->parent);
        }
    }

    toDelete->left = toDelete->right = nullptr;
    delete toDelete;
}

void RBTree::removeFixup(RBTree* node, RBTree* parent) {
    while ((node == nullptr || node->color == Color::BLACK) && node != this) {
        if (node == parent->left) {
            RBTree* sibling = parent->right;

            if (sibling->color == Color::RED) {
                sibling->color = Color::BLACK;
                parent->color = Color::RED;
                parent->leftRotate();
                sibling = parent->right;
            }

            if ((sibling->left == nullptr || sibling->left->color == Color::BLACK) &&
                (sibling->right == nullptr || sibling->right->color == Color::BLACK)) {
                sibling->color = Color::RED;
                node = parent;
                parent = parent->parent;
            } else {
                if (sibling->right == nullptr || sibling->right->color == Color::BLACK) {
                    if (sibling->left != nullptr) {
                        sibling->left->color = Color::BLACK;
                    }
                    sibling->color = Color::RED;
                    sibling->rightRotate();
                    sibling = parent->right;
                }

                sibling->color = parent->color;
                parent->color = Color::BLACK;
                if (sibling->right != nullptr) {
                    sibling->right->color = Color::BLACK;
                }
                parent->leftRotate();
                node = this;
            }
        } else {
            RBTree* sibling = parent->left;

            if (sibling->color == Color::RED) {
                sibling->color = Color::BLACK;
                parent->color = Color::RED;
                parent->rightRotate();
                sibling = parent->left;
            }

            if ((sibling->left == nullptr || sibling->left->color == Color::BLACK) &&
                (sibling->right == nullptr || sibling->right->color == Color::BLACK)) {
                sibling->color = Color::RED;
                node = parent;
                parent = parent->parent;
            } else {
                if (sibling->left == nullptr || sibling->left->color == Color::BLACK) {
                    if (sibling->right != nullptr) {
                        sibling->right->color = Color::BLACK;
                    }
                    sibling->color = Color::RED;
                    sibling->leftRotate();
                    sibling = parent->left;
                }

                sibling->color = parent->color;
                parent->color = Color::BLACK;
                if (sibling->left != nullptr) {
                    sibling->left->color = Color::BLACK;
                }
                parent->rightRotate();
                node = this;
            }
        }
    }

    if (node != nullptr) {
        node->color = Color::BLACK;
    }
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
