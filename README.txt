README
======
BinaryTree v1.0
Developed by 40180425


Compiling
-----------
Compiler used: g++ on Windows

BinaryTree is made out of main method located in main.cpp, binary tree constructors and methods in 
binarytree.cpp and a test suite in test1.cpp.

After running main you get two options:
1. Run automated test suite
2. Go to main menu

Automated test suite will create an empty binary tree and insert 20 randomly generated numbers
into the tree. It will test the existence of the generated numbers and existence of 10 randomly
generated numbers. At last the test will remove 5 numbers from the tree.

If you choose main menu, binary tree will be created from vector. You will get 4 options:
1. Insert number - reads number from command line and inserts into the tree
2. Print tree - prints tree inorder, postorder and preorder
3. Check if exists - reads number from command line and checks if it exists in the tree
4. Remove number - reads number from command line and removes it from the tree


In order to compile the cipher type in in the console 
make
It will compile all necessary files and run the software 

To clean the files type:
make clean