#include <iostream>
#include <queue>
#include "Headers/RBTree.hpp"

bool create_test_tree() {
    RBTree* tree = new RBTree(10);
    if(tree->getData() != 10) {
        delete tree;
        return false;
    }
    if (tree->getColor() != Color::BLACK) {
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
    RBTree* tree = new RBTree(10);
    tree->setColor(Color::RED);
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
    RBTree* tree = new RBTree(10);
    RBTree* left = new RBTree(5);
    RBTree* right = new RBTree(15);
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
    RBTree* tree = new RBTree(10);
    RBTree* right = new RBTree(15);
    RBTree* right_right = new RBTree(17);
    RBTree* right_left = new RBTree(13);
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
    RBTree* tree = new RBTree(10);
    RBTree* left = new RBTree(5);
    RBTree* left_right = new RBTree(7);
    RBTree* left_left = new RBTree(3);
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
    RBTree* tree = new RBTree(10);
    RBTree* right = new RBTree(15);
    RBTree* right_left = new RBTree(13);
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
    RBTree* tree = new RBTree(10);
    RBTree* left = new RBTree(5);
    RBTree* left_right = new RBTree(7);
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
bool insert_teste_0(){
    // Root color, adapted
    RBTree* tree = new RBTree(10);
    if(tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_teste_1(){
    // Parent is black
    RBTree* tree = new RBTree(10);
    tree->insert(5);
    if(tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    if(tree->getData() != 10){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 5){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_teste_2(){
    // Parent and uncle are black
    RBTree* tree = new RBTree(10);
    tree->insert(5);
    tree->insert(15);
    tree->insert(1);
    if(tree->getData() != 10 || tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 5 || tree->getLeft()->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 15 || tree->getRight()->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getLeft()->getData() != 1 || tree->getLeft()->getLeft()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_teste_3(){
    // Parent is left child red, uncle is black and node is left child
    RBTree* tree = new RBTree(10);
    tree->insert(5);
    tree->insert(1);
    if(tree->getData() != 5 || tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 1 || tree->getLeft()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 10 || tree->getRight()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_teste_4(){
    // Parent is left child red, uncle is black and node is right child
    RBTree* tree = new RBTree(10);
    tree->insert(5);
    tree->insert(7);
    if(tree->getData() != 5 || tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 7 || tree->getLeft()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 10 || tree->getRight()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_teste_5(){
    // Parent is right child red, uncle is black and node is right child
    RBTree* tree = new RBTree(10);
    tree->insert(15);
    tree->insert(20);
    if(tree->getData() != 15 || tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 10 || tree->getLeft()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 20 || tree->getRight()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_teste_6(){
    // Parent is right child red, uncle is black and node is left child
    RBTree* tree = new RBTree(10);
    tree->insert(15);
    tree->insert(13);
    if(tree->getData() != 13 || tree->getColor() != Color::BLACK){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 10 || tree->getLeft()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 15 || tree->getRight()->getColor() != Color::RED){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}

bool remove_test_tree() {
    RBTree* tree = new RBTree(10);
    tree->insert(5);
    tree->insert(15);
    tree->insert(1);
    tree->insert(7);

    tree->remove(1);
    if (tree->getLeft()->getLeft() != nullptr) {
        delete tree;
        return false;
    }

    tree->remove(5);
    if (tree->getLeft()->getData() != 7) {
        delete tree;
        return false;
    }

    tree->remove(10);
    if (tree->getData() != 15) {
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
    std::cout << "Insert test 0: " << ((insert_teste_0())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test 1: " << ((insert_teste_1())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test 2: " << ((insert_teste_2())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test 3: " << ((insert_teste_3())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test 4: " << ((insert_teste_4())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test 5: " << ((insert_teste_5())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test 6: " << ((insert_teste_6())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test: " << ((remove_test_tree()) ? "OK" : "ERROR") << std::endl;

    RBTree* tree = new RBTree(15);
    tree->insert(18);
    tree->insert(20);
    tree->insert(35);
    tree->insert(32);
    tree->insert(38);
    tree->insert(30);
    tree->insert(40);
    tree->insert(32);
    tree->insert(45);
    tree->insert(48);
    tree->insert(52);
    tree->insert(60);
    tree->insert(50);
    tree->print();
    return 0;
}
