#include <iostream>
#include <queue>
#include "Headers/RBTree.hpp"

bool create_test_tree() {
    RBTree* tree = new RBTree(10, Color::RED);
    if(tree->getData() != 10) {
        delete tree;
        return false;
    }
    if (tree->getColor() != Color::RED) {
        delete tree;
        return false;
    }
    if (!tree->leftIsNull()) {
        delete tree;
        return false;
    }
    if (!tree->rightIsNull()) {
        delete tree;
        return false;
    }
    if (!tree->parentIsNull()) {
        delete tree;
        return false;
    }
    
    delete tree;
    return true;
}
bool is_red_test_tree() {
    RBTree* tree = new RBTree(10, Color::RED);
    if (!tree->isRed()) {
        delete tree;
        return false;
    }
    tree->setColor(Color::BLACK);
    if (tree->isRed()) {
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool get_brother_test_tree() {
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* left = new RBTree(5, Color::BLACK);
    RBTree* right = new RBTree(15, Color::BLACK);
    tree->setLeft(left);
    tree->setRight(right);
    left->setParent(tree);
    right->setParent(tree);
    if (left->getBrother() != right) {
        delete tree;
        return false;
    }
    if (right->getBrother() != left) {
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool left_rotate_test_tree() {
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* right = new RBTree(15, Color::BLACK);
    RBTree* right_right = new RBTree(17, Color::BLACK);
    RBTree* right_left = new RBTree(13, Color::BLACK);
    tree->setRight(right);
    right->setRight(right_right);
    right->setLeft(right_left);
    right->setParent(tree);
    right_right->setParent(right);
    right_left->setParent(right);
    tree = tree->leftRotate();
    if (tree->getData() != 15) {
        delete tree;
        return false;
    }
    if (tree->getLeft()->getData() != 10) {
        delete tree;
        return false;
    }
    if (tree->getRight()->getData() != 17) {
        delete tree;
        return false;
    }
    if (tree->getLeft()->getRight()->getData() != 13) {
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool right_rotate_test_tree(){
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* left = new RBTree(5, Color::BLACK);
    RBTree* left_right = new RBTree(7, Color::BLACK);
    RBTree* left_left = new RBTree(3, Color::BLACK);
    tree->setLeft(left);
    left->setRight(left_right);
    left->setLeft(left_left);
    left->setParent(tree);
    left_right->setParent(left);
    left_left->setParent(left);
    tree = tree->rightRotate();
    if (tree->getData() != 5) {
        delete tree;
        return false;
    }
    if (tree->getLeft()->getData() != 3) {
        delete tree;
        return false;
    }
    if (tree->getRight()->getData() != 10) {
        delete tree;
        return false;
    }
    if (tree->getRight()->getLeft()->getData() != 7) {
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool double_left_rotate_test_tree(){
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* right = new RBTree(15, Color::BLACK);
    RBTree* right_left = new RBTree(13, Color::BLACK);
    tree->setRight(right);
    right->setLeft(right_left);
    right->setParent(tree);
    right_left->setParent(right);
    tree = tree->doubleLeftRotate();
    if (tree->getData() != 13) {
        delete tree;
        return false;
    }
    if (tree->getLeft()->getData() != 10) {
        delete tree;
        return false;
    }
    if (tree->getRight()->getData() != 15) {
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool double_right_rotate_test_tree(){
    RBTree* tree = new RBTree(10, Color::RED);
    RBTree* left = new RBTree(5, Color::BLACK);
    RBTree* left_right = new RBTree(7, Color::BLACK);
    tree->setLeft(left);
    left->setRight(left_right);
    left->setParent(tree);
    left_right->setParent(left);
    tree = tree->doubleRightRotate();
    if (tree->getData() != 7) {
        delete tree;
        return false;
    }
    if (tree->getLeft()->getData() != 5) {
        delete tree;
        return false;
    }
    if (tree->getRight()->getData() != 10) {
        delete tree;
        return false;
    }
    delete tree;
    return true;
}

int main() {
    std::cout << "Hello, Red-Black Tree!" << std::endl;
    std::cout << "Create test: " << ((create_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Is red test: " << ((is_red_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Get brother test: " << ((get_brother_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Left rotate test: " << ((left_rotate_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Right rotate test: " << ((right_rotate_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Double left rotate test: " << ((double_left_rotate_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Double right rotate test: " << ((double_right_rotate_test_tree())?"OK":"ERROR") << std::endl;
    
    return 0;
}