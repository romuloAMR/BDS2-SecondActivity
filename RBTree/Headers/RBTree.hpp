#ifndef RBTREE_HPP
#define RBTREE_HPP

#include "../Implementations/Color.cpp"

class RBTree {
    private:
        int data;
        RBTree* left;
        RBTree* right;
        RBTree* parent;
        Color color;
    public:
        RBTree(int data, Color color);
        ~RBTree();
        int getData();
        RBTree* getLeft();
        RBTree* getRight();
        RBTree* getParent();
        Color getColor();
        void setData(int data);
        void setLeft(RBTree* left);
        void setRight(RBTree* right);
        void setParent(RBTree* parent);
        void setColor(Color color);
        bool isRed();
        bool isNull();
        RBTree& getBrother();
        void leftRotate();
        void rightRotate();
        void doubleLeftRotate();
        void doubleRightRotate();
};

#endif