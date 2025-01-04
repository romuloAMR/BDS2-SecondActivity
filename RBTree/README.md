# Red-Black Tree
  > C++ implementation

## 📚 Software requirements:
  - g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0;

## ✅ How to test:
  Move to RBTree dir and execute:
  ```
  make
  ```

## ✏️ About:
### Definition:
  A red-black tree is a binary search tree, balanced (h=log(n)) and self-adjusting that preserves the following rules:
  - Each node is assigned a Red (R) or Black (B) color;
  - If v is a NULL node or root, then v.color() == B;
  - If v is a node and v.color() == R, then v.leftChild().color() == B and v.rightChild().color() == B;
  - All paths from a node v to its external descendants (NULL nodes) have the same number of black nodes.
### Basic operations:
#### 1 - ROTATIONS:
##### 1.1 - Left rotation:
  Let A,B,C,D ∈ RBTree, such that A<D<B<C and A is root.  
  Left rotation works as in the following image:  
  ![Left rotation](https://github.com/user-attachments/assets/10887734-e7ee-4219-a1ba-61ae3b2b13af)
  
##### 1.2 - Right rotation:
  Let A,B,C,D ∈ RBTree, such that C>D>B>A and C is root.  
  Right rotation works as in the following image:  
  ![Right Rotation](https://github.com/user-attachments/assets/249ca333-b635-4d50-9506-1005a26d8724)
##### 1.3 - Double left rotation:
  Let A,B,C ∈ RBTree, such that A>B>C and A is root.  
  Double left rotation works as in the following image: 
  ![Double left rotation](https://github.com/user-attachments/assets/007a74aa-3bfa-421f-a0b9-72860a11ac57)

##### 1.4 - Double right rotation:
  Let A,B,C ∈ RBTree, such that A<B<C and C is root. 
  Double right rotation works as in the following image: 
  ![Double right rotation](https://github.com/user-attachments/assets/b8869c77-7f69-4e56-a695-af58347b4715)
#### 2 - SEARCH:
  The algorithm can be seen in the following flowchart:  
  ![Search](https://github.com/user-attachments/assets/21312218-4540-4d9c-a647-265ed4eebfde)
#### 3 - INSERT:
  The algorithm can be seen in the following flowcharts:  
  ![Insert](https://github.com/user-attachments/assets/334fca98-c0a3-4635-8a43-112b0b984b8a)
  ![InsertFix](https://github.com/user-attachments/assets/84092b86-e389-4970-b56b-14d03e4bd15a)
#### 4 - REMOVE:
  Still to do
