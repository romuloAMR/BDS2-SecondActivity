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

int main() {
    std::cout << "Hello, Red-Black Tree!" << std::endl;
    std::cout << "Create test: " << create_test_tree() << std::endl;
    std::cout << "Is red test: " << is_red_test() << std::endl;
    std::cout << "Get brother test: " << get_brother_test() << std::endl;
    return 0;
}