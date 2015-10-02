#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

class BinaryTree
{
    struct Node
    {
        int value;
        Node* left_node;
        Node* right_node;

        Node(int new_value)
        {
            value = new_value;
            left_node = NULL;
            right_node = NULL;
        }
        Node(Node* source)
        {
            value = source->value;
            left_node = source->left_node;
            right_node = source->right_node;
        }
    };

public:
    BinaryTree();
    BinaryTree(int new_value);
    BinaryTree(const std::vector<int> &values);
    BinaryTree(const BinaryTree &rhs);
    void Add_Item(int new_value);
    void inorder();
    void preorder();
    void postorder();
    bool exists(int value);
    void remove(int value);
    void copyTree(const BinaryTree &source);
    void print(std::ostream &ost);
	void nodeCount(BinaryTree &source);
    BinaryTree& operator+(const int &value);
    BinaryTree& operator-(const int &value);
    BinaryTree& operator=(const BinaryTree &source);
    friend std::ostream& operator<<(std::ostream &ost, BinaryTree &source);
    friend std::istream& operator>>(std::istream &ist, BinaryTree &source);
    bool operator == (const BinaryTree &rhs);
    bool operator != (const BinaryTree *source);

private:
    void Insert(int new_value, Node* &Root);
    void pinorder(Node* Root);
    void ppreorder(Node* Root);
    void ppostorder(Node* Root);
    bool pexists(int value, Node* Root);
    void premove(int value, Node* Root);
    void pcopyTree(Node* &destinationRoot, Node* sourceRoot);
    bool compare(Node* lhs, Node* rhs);
    void helpPrint(std::ostream &ost, Node * Root);
	int countNodes(Node *Root);
    Node* root;
    Node* find_parent_node(int value, Node* Root);
    Node* next_min_value(Node* Root);
};
#endif
