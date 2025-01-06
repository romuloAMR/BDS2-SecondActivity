#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "../Implementations/Color.cpp"
#include <iostream>
#include <queue>

class RBTree {
    private:
        int data;
        RBTree* left;
        RBTree* right;
        RBTree* parent;
        Color color;
        RBTree(int data, Color color);

    public:
        // Constructors and Destructors
        RBTree(int data);
        ~RBTree();
        
        // Getters
        int getData();
        RBTree* getLeft();
        RBTree* getRight();
        RBTree* getParent();
        Color getColor();
        bool leftIsNull();
        bool rightIsNull();
        bool parentIsNull();
        bool isRed();
        RBTree* getBrother();

        // Setters
        void setData(int data);
        void setLeft(RBTree* left);
        void setRight(RBTree* right);
        void setParent(RBTree* parent);
        void setColor(Color color);
        
        // Rotations
        RBTree* leftRotate();
        RBTree* rightRotate();
        RBTree* doubleLeftRotate();
        RBTree* doubleRightRotate();

        // Search, Insert, Remove, Print
        bool search(int data);
        void insert(int data);
        void insertFixup();
        void remove(int data);
        void print();
};

#endif