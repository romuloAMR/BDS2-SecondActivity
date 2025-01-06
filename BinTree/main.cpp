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
    // remove root
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

int main() {

    // Tests
    std::cout << "Hello, Binary Tree!" << std::endl;
    std::cout << "Create test: " << ((create_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Insert test: " << ((insert_test_tree())?"OK":"ERROR") << std::endl;
    std::cout << "Search test: " << ((search_test_tree())?"OK":"ERROR") << std::endl;
    //std::cout << "Remove test case 0: " << ((remove_test_tree_case_0())?"OK":"ERROR") << std::endl;
    //std::cout << "Remove test case 1: " << ((remove_test_tree_case_1())?"OK":"ERROR") << std::endl;
    //std::cout << "Remove test case 2: " << ((remove_test_tree_case_2())?"OK":"ERROR") << std::endl;
    //std::cout << "Remove test case 3: " << ((remove_test_tree_case_3())?"OK":"ERROR") << std::endl;
    //std::cout << "Remove test case 4: " << ((remove_test_tree_case_4())?"OK":"ERROR") << std::endl;
    
    // Prints
    std::vector<int> arr = {10, 5, 3, 15, 7, 17, 13};
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