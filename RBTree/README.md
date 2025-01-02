# Red-Black Tree
  > Rust implementation

## 📚 Software requirements:
  - Rustc (used version 1.83.0);
  - Cargo (used version 1.83.0).

## ✅ How to test:
  ```
  # Still to do
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
  ![Left rotation](https://private-user-images.githubusercontent.com/145867084/399763245-10887734-e7ee-4219-a1ba-61ae3b2b13af.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MzU4Mzg1MzgsIm5iZiI6MTczNTgzODIzOCwicGF0aCI6Ii8xNDU4NjcwODQvMzk5NzYzMjQ1LTEwODg3NzM0LWU3ZWUtNDIxOS1hMWJhLTYxYWUzYjJiMTNhZi5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjUwMTAyJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI1MDEwMlQxNzE3MThaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1jZDQyMTNhMTAzNTJkNmFiZThkNGRlMDFmNDBhY2E0NDJkZmY0OThiZjAxZDgyMzMyYTE2OWI0ZDUyYjQ3ZTI3JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCJ9.FLLdt-ypyQfuwr3CeWpyo1VvzpvhcEQhS_Oy50fIeeg)
  
##### 1.2 - Right rotation:
  Still to do
##### 1.3 - Double left rotation:
  Still to do
##### 1.4 - Double right rotation:
  Still to do
#### 2 - SEARCH:
  Still to do
#### 3 - INSERT:
  Still to do
#### 4 - REMOVE:
  Still to do
