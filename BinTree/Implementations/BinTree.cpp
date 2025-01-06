#include "../Headers/BinTree.hpp"

// constructors and destructor
BinTree::BinTree(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

BinTree::BinTree(std::vector<int> arr) {
    int size = arr.size();
    if (size == 0) {
        return;
    }
    this->data = arr[0];
    this->left = nullptr;
    this->right = nullptr;
    
    for (int i = 1; i < size; i++) {
        this->insert(arr[i]);
    }
}


BinTree::~BinTree() {
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->right != nullptr) {
        delete this->right;
    }
}

// getters
int BinTree::getData() const {
    return this->data;
}

BinTree* BinTree::getLeft() const {
    return this->left;
}

BinTree* BinTree::getRight() const {
    return this->right;
}

// setters
void BinTree::setLeft(BinTree* left) {
    this->left = left;
}

void BinTree::setRight(BinTree* right) {
    this->right = right;
}

void BinTree::setData(int data) {
    this->data = data;
}

// insert, search, remove
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
    if (this->getLeft() == nullptr && this->getRight() == nullptr) {
        delete this;
    } else if (this->getLeft() != nullptr && this->getRight() == nullptr) {
        BinTree* temp = this->getLeft();
        this->setData(temp->getData());
        this->setLeft(temp->getLeft());
        this->setRight(temp->getRight());
        temp->setLeft(nullptr);
        temp->setRight(nullptr);
        delete temp;
    } else if (this->getLeft() == nullptr && this->getRight() != nullptr) {
        BinTree* temp = this->getRight();
        this->setData(temp->getData());
        this->setLeft(temp->getLeft());
        this->setRight(temp->getRight());
        temp->setLeft(nullptr);
        temp->setRight(nullptr);
        delete temp;
    } else {
        BinTree* temp = this->getRight();
        BinTree* parent = this;
        while (temp->getLeft() != nullptr) {
            parent = temp;
            temp = temp->getLeft();
        }
        this->setData(temp->getData());
        removeNode(parent, temp);
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

// print
void BinTree::printPreOrder() {
    std::cout << this->data << " ";
    if (this->left != nullptr) {
        this->left->printPreOrder();
    }
    if (this->right != nullptr) {
        this->right->printPreOrder();
    }
}

void BinTree::printInOrder() {
    if (this->left != nullptr) {
        this->left->printInOrder();
    }
    std::cout << this->data << " ";
    if (this->right != nullptr) {
        this->right->printInOrder();
    }
}

void BinTree::printPostOrder() {
    if (this->left != nullptr) {
        this->left->printPostOrder();
    }
    if (this->right != nullptr) {
        this->right->printPostOrder();
    }
    std::cout << this->data << " ";
}

void BinTree::printLevelOrder() {
    std::queue<BinTree*> q;
    q.push(this);
    while (!q.empty()) {
        BinTree* temp = q.front();
        q.pop();
        std::cout << temp->getData() << " ";
        if (temp->getLeft() != nullptr) {
            q.push(temp->getLeft());
        }
        if (temp->getRight() != nullptr) {
            q.push(temp->getRight());
        }
    }
}