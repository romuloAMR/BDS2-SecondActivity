#ifndef BINTREE_HPP
#define BINTREE_HPP

#include <iostream>
#include <queue>
#include <vector>

class BinTree {
private:
    // data members
    int data;
    BinTree* left;
    BinTree* right;

    // setters
    void setLeft(BinTree* left);
    void setRight(BinTree* right);
    void setData(int data);

    // remove helper functions
    void removeLeaf(BinTree* parent, BinTree* leaf);
    void removeNode(BinTree* parent, BinTree* node);
    void removeRoot();
    void remove(const int& value, BinTree* parent);

public:

    // constructors and destructor
    BinTree(int data);
    BinTree(std::vector<int> arr);
    ~BinTree();

    // getters
    int getData() const;
    BinTree* getLeft() const;
    BinTree* getRight() const;
    
    // insert, search, remove
    void insert(const int& value);
    bool search(const int& value) const;
    void remove(const int& value);

    // print
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    void printLevelOrder();

    // converting a vector in a heap/binary tree
    void heapify(std::vector<int>& arr, int n, int i);
    BinTree* vectorToMaxHeap(std::vector<int>& arr);
};

#endif
