#include <iostream>
#include "Headers/BinTree.hpp"

bool create_test_tree(){
    BinTree* tree = new BinTree(10);
    if(tree->getData() != 10){
        delete tree;
        return false;
    }
    if (tree->getLeft() != nullptr || tree->getRight() != nullptr){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool insert_test_tree(){
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(15);
    if(tree->getLeft()->getData() != 5 || tree->getRight()->getData() != 15){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool search_test_tree(){
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(15);
    if(!tree->search(5) || !tree->search(15) || !tree->search(10)){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_0(){
    // remove left leaf
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(15);
    tree->remove(5);
    if(tree->search(5)){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_1(){
    // remove right leaf
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(15);
    tree->remove(15);
    if(tree->search(15)){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_2(){
    // remove root with two children
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(15);
    tree->insert(13);
    tree->remove(10);
    if(tree->search(10)){
        delete tree;
        return false;
    }
    if(tree->getData() != 13){
        delete tree;
        return false;
    }
    if (tree->getLeft()->getData() != 5){
        delete tree;
        return false;
    }
    if (tree->getRight()->getData() != 15){
        delete tree;
        return false;
    }
    
    
    delete tree;
    return true;
}
bool remove_test_tree_case_3(){
    // remove left node with left child
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(1);
    tree->remove(5);
    if(tree->search(5)){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 1){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_4(){
    // remove left node with right child
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(7);
    tree->remove(5);
    if(tree->search(5)){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 7){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_5(){
    // remove right node with left child
    BinTree* tree = new BinTree(10);
    tree->insert(15);
    tree->insert(13);
    tree->remove(15);
    if(tree->search(15)){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 13){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_6(){
    // remove right node with right child
    BinTree* tree = new BinTree(10);
    tree->insert(15);
    tree->insert(17);
    tree->remove(15);
    if(tree->search(15)){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 17){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_7(){
    // remove left node with two children
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->insert(3);
    tree->insert(7);
    tree->remove(5);
    if(tree->search(5)){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getData() != 7){
        delete tree;
        return false;
    }
    if(tree->getLeft()->getLeft()->getData() != 3){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_8(){
    // remove right node with two children
    BinTree* tree = new BinTree(10);
    tree->insert(15);
    tree->insert(13);
    tree->insert(17);
    tree->remove(15);
    if(tree->search(15)){
        delete tree;
        return false;
    }
    if(tree->getRight()->getData() != 17){
        delete tree;
        return false;
    }
    if(tree->getRight()->getLeft()->getData() != 13){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_9(){
    // remove root without child
    BinTree* tree = new BinTree(10);
    tree->remove(10);
    if(tree->search(10)){
        delete tree;
        return false;
    }
    return true;
}
bool remove_test_tree_case_10(){
    // remove root with left child
    BinTree* tree = new BinTree(10);
    tree->insert(5);
    tree->remove(10);
    if(tree->search(10)){
        delete tree;
        std::cout << "ERROR 1" << std::endl;
        return false;
    }
    if(tree->getData() != 5){
        delete tree;
        std::cout << "ERROR 2" << std::endl;
        return false;
    }
    delete tree;
    return true;
}
bool remove_test_tree_case_11(){
    // remove root with right child
    BinTree* tree = new BinTree(10);
    tree->insert(15);
    tree->remove(10);
    if(tree->search(10)){
        delete tree;
        return false;
    }
    if(tree->getData() != 15){
        delete tree;
        return false;
    }
    delete tree;
    return true;
}

int main() {

    // Tests
    std::cout << "Hello, Binary Tree!" << std::endl;
    std::cout << "Create test: " << ((create_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test: " << ((insert_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Search test: " << ((search_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 0: " << ((remove_test_tree_case_0())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 1: " << ((remove_test_tree_case_1())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 2: " << ((remove_test_tree_case_2())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 3: " << ((remove_test_tree_case_3())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 4: " << ((remove_test_tree_case_4())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 5: " << ((remove_test_tree_case_5())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 6: " << ((remove_test_tree_case_6())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 7: " << ((remove_test_tree_case_7())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 8: " << ((remove_test_tree_case_8())?"OK":"ERROR") << std::endl;
    //std::cout << "Remove test case 9: " << ((remove_test_tree_case_9())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 10: " << ((remove_test_tree_case_10())?"OK":"ERROR") << std::endl;
    std::cout << "Remove test case 11: " << ((remove_test_tree_case_11())?"OK":"ERROR") << std::endl;


    
    // Prints
    std::vector<int> arr = {10, 5, 15, 3, 7, 13, 17, 4, 16};
    BinTree* tree = new BinTree(arr);
    std::cout << "Pre-order: ";
    tree->printPreOrder();
    std::cout << std::endl;
    std::cout << "In-order: ";
    tree->printInOrder();
    std::cout << std::endl;
    std::cout << "Post-order: ";
    tree->printPostOrder();
    std::cout << std::endl;
    std::cout << "Level-order: ";
    tree->printLevelOrder();
    std::cout << std::endl;
    delete tree;

    return 0;
}