#ifndef BINTREE_HPP
#define BINTREE_HPP

class BinTree {
private:
    int data;
    BinTree* left;
    BinTree* right;

    void setLeft(BinTree* left);
    void setRight(BinTree* right);
    void setData(int data);

    void removeLeaf(BinTree* parent, BinTree* leaf);
    void removeNode(BinTree* parent, BinTree* node);
    void removeRoot();
    void remove(const int& value, BinTree* parent);

public:
    BinTree(int data);
    ~BinTree();

    int getData() const;
    BinTree* getLeft() const;
    BinTree* getRight() const;
    

    void insert(const int& value);
    bool search(const int& value) const;
    void remove(const int& value);
};

#endif