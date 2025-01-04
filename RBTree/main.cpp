#include <iostream>
#include "Headers/RBTree.hpp"

bool create_test_tree() {
    RBTree* tree = new RBTree(10, Color::RED);
    if (tree->getData() != 10) {
        return false;
    }
    if (tree->getColor() != Color::RED) {
        return false;
    }
    if (tree->getLeft() != nullptr) {
        return false;
    }
    if (tree->getRight() != nullptr) {
        return false;
    }
    if (tree->getParent() != nullptr) {
        return false;
    }
    return true;
}
bool is_red_test() {
    RBTree* tree = new RBTree(10, Color::RED);
    if (!tree->isRed()) {
        return false;
    }
    tree->setColor(Color::BLACK);
    if (tree->isRed()) {
        return false;
    }
    return true;
}
bool get_brother_test() {
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* left = new RBTree(5, Color::RED);
    RBTree* right = new RBTree(15, Color::RED);
    tree->setLeft(left);
    tree->setRight(right);
    left->setParent(tree);
    right->setParent(tree);
    if (left->getBrother().getData() != 15) {
        return false;
    }
    if (right->getBrother().getData() != 5) {
        return false;
    }
    return true;
}
bool left_rotate_test() {
    RBTree* a = new RBTree(10, Color::RED);
    RBTree* b = new RBTree(15, Color::RED);
    RBTree* c = new RBTree(20, Color::RED);
    RBTree* d = new RBTree(13, Color::RED);
    a->setRight(b);
    b->setRight(c);
    b->setLeft(d);
    b->setParent(a);
    c->setParent(b);
    d->setParent(b);
    a->leftRotate();
    if (a->getRight()->getData() != 13) {
        std::cout << "a right" << std::endl;
        return false;
    }
    if (a->getParent() != b) {
        std::cout << "a parent" << std::endl;
        return false;
    }
    if (a->getLeft() != nullptr) {
        std::cout << "a left" << std::endl;
        return false;
    }
    if (b->getRight() != c) {
        std::cout << "b right" << std::endl;
        return false;
    }
    if (b->getLeft() != a) {
        std::cout << "b left" << std::endl;
        return false;
    }
    if (b->getParent() != nullptr) {
        std::cout << "b parent" << std::endl;
        return false;
    }
    if (c->getParent() != b) {
        std::cout << "c parent" << std::endl;
        return false;
    }
    if (c->getLeft() != nullptr) {
        std::cout << "c left" << std::endl;
        return false;
    }
    if (c->getRight() != nullptr) {
        std::cout << "c right" << std::endl;
        return false;
    }
    if (d->getParent() != a) {
        std::cout << "d parent" << std::endl;
        return false;
    }
    if (d->getLeft() != nullptr) {
        std::cout << "d left" << std::endl;
        return false;
    }
    if (d->getRight() != nullptr) {
        std::cout << "d right" << std::endl;
        return false;
    }
    return true;
}
bool right_rotate_teste(){
    RBTree* a = new RBTree(10, Color::RED);
    RBTree* b = new RBTree(15, Color::RED);
    RBTree* c = new RBTree(20, Color::RED);
    RBTree* d = new RBTree(17, Color::RED);
    c->setLeft(b);
    b->setLeft(a);
    b->setRight(d);
    b->setParent(c);
    a->setParent(b);
    d->setParent(b);
    c->rightRotate();
    if (b->getLeft() != a) {
        std::cout << "b left" << std::endl;
        return false;
    }
    if (b->getParent() != nullptr) {
        std::cout << "b parent" << std::endl;
        return false;
    }
    if (b->getRight() != c) {
        std::cout << "b right" << std::endl;
        return false;
    }
    if (a->getParent() != b) {
        std::cout << "a parent" << std::endl;
        return false;
    }
    if (a->getLeft() != nullptr) {
        std::cout << "a left" << std::endl;
        return false;
    }
    if (a->getRight() != nullptr) {
        std::cout << "a right" << std::endl;
        return false;
    }
    if (c->getParent() != b) {
        std::cout << "c parent" << std::endl;
        return false;
    }
    if (c->getLeft() != d) {
        std::cout << "c left" << std::endl;
        return false;
    }
    if (c->getRight() != nullptr) {
        std::cout << "c right" << std::endl;
        return false;
    }
    if (d->getParent() != c) {
        std::cout << "d parent" << std::endl;
        return false;
    }
    if (d->getLeft() != nullptr) {
        std::cout << "d left" << std::endl;
        return false;
    }
    if (d->getRight() != nullptr) {
        std::cout << "d right" << std::endl;
        return false;
    }
    return true;
}
bool double_left_rotate_test() {
    RBTree* a = new RBTree(10, Color::RED);
    RBTree* b = new RBTree(15, Color::RED);
    RBTree* c = new RBTree(20, Color::RED);
    a->setRight(c);
    c->setParent(a);
    c->setLeft(b);
    b->setParent(c);
    a->doubleLeftRotate();
    if (b->getParent() != nullptr) {
        std::cout << "b parent" << std::endl;
        return false;
    }
    if (b->getLeft() != a) {
        std::cout << "b left" << std::endl;
        return false;
    }
    if (b->getRight() != c) {
        std::cout << "b right" << std::endl;
        return false;
    }
    if (a->getParent() != b) {
        std::cout << "a parent" << std::endl;
        return false;
    }
    if (a->getLeft() != nullptr) {
        std::cout << "a left" << std::endl;
        return false;
    }
    if (a->getRight() != nullptr) {
        std::cout << "a right" << std::endl;
        return false;
    }
    if (c->getParent() != b) {
        std::cout << "c parent" << std::endl;
        return false;
    }
    if (c->getLeft() != nullptr) {
        std::cout << "c left" << std::endl;
        return false;
    }
    if (c->getRight() != nullptr) {
        std::cout << "c right" << std::endl;
        return false;
    }
    return true;
}
bool double_right_rotate_test() {
    RBTree* a = new RBTree(10, Color::RED);
    RBTree* b = new RBTree(15, Color::RED);
    RBTree* c = new RBTree(20, Color::RED);
    c->setLeft(a);
    a->setParent(c);
    a->setRight(b);
    b->setParent(a);
    c->doubleRightRotate();
    if (b->getParent() != nullptr) {
        std::cout << "b parent" << std::endl;
        return false;
    }
    if (b->getLeft() != a) {
        std::cout << "b left" << std::endl;
        return false;
    }
    if (b->getRight() != c) {
        std::cout << "b right" << std::endl;
        return false;
    }
    if (a->getParent() != b) {
        std::cout << "a parent" << std::endl;
        return false;
    }
    if (a->getLeft() != nullptr) {
        std::cout << "a left" << std::endl;
        return false;
    }
    if (a->getRight() != nullptr) {
        std::cout << "a right" << std::endl;
        return false;
    }
    if (c->getParent() != b) {
        std::cout << "c parent" << std::endl;
        return false;
    }
    if (c->getLeft() != nullptr) {
        std::cout << "c left" << std::endl;
        return false;
    }
    if (c->getRight() != nullptr) {
        std::cout << "c right" << std::endl;
        return false;
    }

    return true;
}
bool search_test() {
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* left = new RBTree(5, Color::RED);
    RBTree* right = new RBTree(15, Color::RED);
    tree->setLeft(left);
    tree->setRight(right);
    left->setParent(tree);
    right->setParent(tree);
    if (!tree->search(5)) {
        return false;
    }
    if (!tree->search(15)) {
        return false;
    }
    if (tree->search(20)) {
        return false;
    }
    return true;
}
bool insert_test_case_0() {
    // Adapting the root case
    RBTree* tree1 = new RBTree(10, Color::BLACK);
    tree1->insert(5);
    RBTree* tree2 = new RBTree(10, Color::RED);
    tree2->insert(5);
    if(tree1->getColor() != Color::BLACK) {
        return false;
    }
    if(tree2->getColor() != Color::BLACK) {
        return false;
    }
}
bool insert_test_case_1() {
    // Parent is black
    RBTree* tree = new RBTree(10, Color::BLACK);
    tree->insert(5);
    if(tree->getColor() != Color::BLACK) {
        return false;
    }
    if (tree->getLeft()->getColor() != Color::RED) {
        return false;
    }
    return true;
}
bool insert_test_case_2() {
    // Parent is red and uncle is red
    RBTree* tree = new RBTree(10, Color::BLACK);
    tree->insert(5);
    tree->insert(15);
    tree->insert(1);
    if(tree->getColor() != Color::BLACK) {
        return false;
    }
    if (tree->getLeft()->getColor() != Color::BLACK) {
        return false;
    }
    if (tree->getRight()->getColor() != Color::BLACK) {
        return false;
    }
    if (tree->getLeft()->getLeft()->getColor() != Color::RED) {
        return false;
    }
    return true;
}
bool insert_test_case_3() {
    // Parent is red, uncle is black, parent is left child and node is left child
    RBTree* tree = new RBTree(10, Color::BLACK);
    tree->insert(8);
    tree->insert(5);
    tree->insert(3);
    if(tree->getColor() != Color::BLACK) {
        return false;
    }
    if(tree->getLeft()->getColor() != Color::RED) {
        return false;
    }
    if(tree->getRight()->getColor() != Color::RED) {
        return false;
    }
    return true;
}
bool insert_test_case_4() {
    // Parent is red, uncle is black, parent is left child and node is right child
    RBTree* tree = new RBTree(10, Color::BLACK);
    tree->insert(8);
    tree->insert(5);
    tree->insert(7);
    if(tree->getColor() != Color::BLACK) {
        return false;
    }
    if(tree->getLeft()->getColor() != Color::RED) {
        return false;
    }
    if(tree->getRight()->getColor() != Color::RED) {
        return false;
    }
    return true;
}
bool insert_test_case_5() {
    // Parent is red, uncle is black, parent is right child and node is right child
    RBTree* tree = new RBTree(10, Color::BLACK);
    tree->insert(15);
    tree->insert(20);
    tree->insert(25);
    if(tree->getColor() != Color::BLACK) {
        return false;
    }
    if(tree->getLeft()->getColor() != Color::RED) {
        return false;
    }
    if(tree->getRight()->getColor() != Color::RED) {
        return false;
    }
    return true;
}
bool insert_test_case_6() {
    // Parent is red, uncle is black, parent is right child and node is left child
    RBTree* tree = new RBTree(10, Color::BLACK);
    tree->insert(15);
    tree->insert(13);
    if(tree->getColor() != Color::BLACK) {
        return false;
    }
    if(tree->getLeft()->getColor() != Color::RED) {
        return false;
    }
    if(tree->getRight()->getColor() != Color::RED) {
        return false;
    }
    return true;
}

int main() {
    std::cout << "Hello, Red-Black Tree!" << std::endl;
    std::cout << "Create test: " << ((create_test_tree)?"OK":"ERROR") << std::endl;
    std::cout << "Is red test: " << ((is_red_test)?"OK":"ERROR") << std::endl;
    std::cout << "Get brother test: " << ((get_brother_test)?"OK":"ERROR") << std::endl;
    std::cout << "Left rotate test: " << ((left_rotate_test)?"OK":"ERROR") << std::endl;
    std::cout << "Right rotate test: " << ((right_rotate_teste)?"OK":"ERROR") << std::endl;
    std::cout << "Double left rotate test: " << ((double_left_rotate_test)?"OK":"ERROR") << std::endl;
    std::cout << "Double right rotate test: " << ((double_right_rotate_test)?"OK":"ERROR") << std::endl;
    std::cout << "Search test: " << ((search_test)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 0: " << ((insert_test_case_0)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 1: " << ((insert_test_case_1)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 2: " << ((insert_test_case_2)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 3: " << ((insert_test_case_3)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 4: " << ((insert_test_case_4)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 5: " << ((insert_test_case_5)?"OK":"ERROR") << std::endl;
    std::cout << "Insert test case 6: " << ((insert_test_case_6)?"OK":"ERROR") << std::endl;
    return 0;
}