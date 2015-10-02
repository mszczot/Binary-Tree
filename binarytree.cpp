#include <iostream>
#include <vector>
#include <iomanip>
#include "binarytree.h"

using namespace std;
///////////////////////////////////////////////
///            PUBLIC METHODS               ///
///////////////////////////////////////////////

///\brief Default constructor for Binary Tree
///<Creates an empty Binary Tree
BinaryTree::BinaryTree()
{
    root = NULL;
};


///Second constructor for Binary Tree
///<Creates Binary Tree with initial value
BinaryTree::BinaryTree(int new_value)
{
    root = new Node(new_value);
};

///Third constructor for Binary Tree
///<Creates Binary Tree from a collection of existing values
BinaryTree::BinaryTree(const vector<int> &values)
{
    root = NULL;
    for (unsigned i=0; i<values.size(); i++)
    {
        this->Add_Item(values[i]);
    }
};

///Fourth constructor for Binary Tree
///Takes another tree as signature and copy it to new tree
BinaryTree::BinaryTree(const BinaryTree &rhs)
{
    copyTree(rhs);
}
///Public method to insert the value to the binary tree
///<Takes a value that needs to be inserted as a parameter
void BinaryTree::Add_Item(int new_value)
{
    Insert(new_value, root);
};

///Prints the tree in order
void BinaryTree::inorder()
{
    cout << "Inorder:" << endl;
    pinorder(this->root);
    cout << endl;
};

///Prints the tree Pre-order
void BinaryTree::preorder()
{
    cout << "Preorder:" << endl;
    ppreorder(root);
    cout << endl;
};

///Prints  the tree Post-order
void BinaryTree::postorder()
{
    cout << "Postorder:" << endl;
    ppostorder(root);
    cout << endl;
};

///Checks if the specified value exists in the tree
///Returns true if it does
bool BinaryTree::exists(int value)
{
    if (pexists(value, root))
    {
        cout << "The number " << value << " exists in the tree" << endl;
        return true;
    }
    else
    {
        cout << "The number " << value << " does not exist in the tree" << endl;
        return false;
    }
};

///< Public method. Removes specified value from Binary Tree
void BinaryTree::remove(int value)
{
    premove(value, root);
};

///Public method. Deep copies the tree.
void BinaryTree::copyTree(const BinaryTree &source)
{
    this->pcopyTree(root, source.root);
}

void BinaryTree::print(std::ostream &ost)
{
    helpPrint(ost,this->root);
    cout << endl;
}

///Overloading of operator +
BinaryTree& BinaryTree::operator+(const int &value)
{
    BinaryTree *lhs = new BinaryTree(*this);
    lhs->Add_Item(value);
    return *lhs;
}

///Overloading of operator -
BinaryTree& BinaryTree::operator-(const int &value)
{
    this->remove(value);
    return *this;
}

///Overloading of operator =
BinaryTree& BinaryTree::operator=(const BinaryTree &source)
{
    this->copyTree(source);
    delete &source;
    return *this;
}

///Overloading of operator ==
bool BinaryTree::operator==(const BinaryTree &rhs)
{
    return (this->root == 0 && rhs.root == 0)
           || (this->root != 0 && rhs.root != 0 && compare(this->root, rhs.root));
}

///Overloading of operator !=
bool BinaryTree::operator != (const BinaryTree *source)
{
    return (!(this==source));
}
///Overloading of operator <<
ostream& operator<<(ostream &ost, BinaryTree &source)
{
    source.print(ost);
    return ost;
}

///Overloading of operator >>
istream& operator>>(istream &ist, BinaryTree &source)
{
    int value;
    ist >> value;
    source.Add_Item(value);
    return ist;
}

void BinaryTree::nodeCount(BinaryTree &source)
{
    int count = 0;
    count = countNodes(source.root);
    cout << "Number of nodes - " << count << endl;
}

///////////////////////////////////////////////
///             PRIVATE METHODS             ///
///////////////////////////////////////////////

/*//////////////////////////////////////////*/
/*                  NODES                   */
/*//////////////////////////////////////////*/

///Method to find the parent node for supplied value
BinaryTree::Node* BinaryTree::find_parent_node(int value, Node* Root)
{
    Node* parent = Root;
    Node* child = NULL;
    if (parent != NULL && parent->value != value)
    {

        if (parent->value > value)
        {
            child = parent->left_node;
            if (child->value != value)
                parent = find_parent_node(value, child);
        }
        else
        {
            child = parent->right_node;
            if (child->value != value)
                parent = find_parent_node(value, child);
        }
    }
    return parent;
}

///Method to find the next minimum value from supplied value and node
BinaryTree::Node* BinaryTree::next_min_value(Node* Root)
{
    if (Root->left_node == NULL)
        return Root;
    else
        return next_min_value(Root->left_node);
}

/*//////////////////////////////////////////*/
/*                 METHODS                  */
/*//////////////////////////////////////////*/

///Private method to insert the value to the binary tree
///<Takes two parameters: value and the node
void BinaryTree::Insert(int new_value, Node* &Root)
{
    if(Root == NULL)
    {
        Root = new Node(new_value);
    }
    if (new_value < Root->value)
    {
        Insert(new_value, Root->left_node);
    }
    else if (new_value > Root->value)
    {
        Insert(new_value, Root->right_node);
    }
};

///Private method to print the binary tree in order
void BinaryTree::pinorder(Node* Root)
{
    if (Root != NULL)
    {
        pinorder(Root->left_node);
        cout << Root->value << ", ";
        pinorder(Root->right_node);
    }
};

///Private method to print the binary tree pre-ordered
void BinaryTree::ppreorder(Node* Root)
{
    if (Root != NULL)
    {
        cout << Root->value << ", ";
        ppreorder(Root->left_node);
        ppreorder(Root->right_node);
    }
};

///Private method to print the binary tree pre-ordered
void BinaryTree::ppostorder(Node* Root)
{
    if (Root != NULL)
    {
        ppostorder(Root->left_node);
        ppostorder(Root->right_node);
        cout << Root->value << ", ";
    }
};

///Private method to check if the value exists in the tree
bool BinaryTree::pexists(int value, Node* Root)
{
    if (Root != NULL)
    {
        if(Root->value != value)
        {
            if (Root->left_node != NULL && pexists(value, Root->left_node))
                return true;
            else if (Root->right_node != NULL && pexists(value, Root->right_node))
                return true;
        }
        else
        {
            return true;
        }
    }
    return false;
};

///Private Method that removes specified value from the binary tree
void BinaryTree::premove(int value, Node* Root)
{

    if(Root != NULL)
    {
        //if the Root value does not equal specified value, keep looking
        if (Root->value != value)
        {
            if (Root->value > value)
                premove(value, Root->left_node);
            else
                premove(value, Root->right_node);
        }
        else
        {
            //get the parent node for the node to be removed
            Node* parent = find_parent_node(value, root);
            //case when the node to be removed does not have a child nodes
            if (Root->left_node == NULL && Root->right_node == NULL)
            {
                if (parent->value > Root->value)
                {
                    parent->left_node = NULL;
                    Root = NULL;
                    delete Root;
                }
                else
                {
                    parent->right_node = NULL;
                    Root = NULL;
                    delete Root;
                }
            }
            //case when the node to be removed has one child on left
            else if (Root->left_node != NULL && Root->right_node == NULL)
            {
                if (parent->value > Root->value)
                {
                    parent->left_node = Root->left_node;
                    Root = NULL;
                    delete Root;
                }
                else
                {
                    parent->right_node = Root->left_node;
                    Root=NULL;
                    delete Root;
                }
            }
            //case when the node to be removed has one child on right
            else if (Root->right_node != NULL && Root->left_node == NULL)
            {
                if (parent->value > Root->value)
                {
                    parent->left_node = Root->right_node;
                    Root = NULL;
                    delete Root;
                }
                else
                {
                    parent->right_node = Root->right_node;
                    Root=NULL;
                    delete Root;
                }
            }
            //case when the node has nodes on both sides
            //it copies the next minimum value
            //Inserts it in the root and deletes the copied child
            else if (Root->right_node != NULL && Root->left_node != NULL)
            {
                Node* next_min = next_min_value(Root->right_node);
                Node* parent_of_min = find_parent_node(next_min->value, root);
                int val = next_min->value;
                premove(next_min->value, parent_of_min);
                Root->value = val;
            }
        }
    }

}


///Method implementing deep copy of the tree
void BinaryTree::pcopyTree(Node* &destinationRoot, Node* sourceRoot)
{
    if (sourceRoot == NULL)
    {
        destinationRoot = NULL;
    }
    else
    {
        destinationRoot = new Node(sourceRoot);
        pcopyTree(destinationRoot->left_node, sourceRoot->left_node);
        pcopyTree(destinationRoot->right_node, sourceRoot->right_node);
    }
}

///Method to compare two nodes. Returns true if equal
bool BinaryTree::compare(Node* lhs, Node* rhs)
{
    if(lhs==NULL && rhs==NULL)
        return(true);
    else if (lhs!=NULL && rhs!=NULL)
    {
        return(lhs->value == lhs->value &&
               compare(lhs->left_node, rhs->left_node) &&
               compare(lhs->right_node, rhs->right_node)
              );

    }
    else return false;
}

void BinaryTree::helpPrint(ostream &ost, Node * Root)
{
    if (Root != NULL)
    {
        helpPrint(ost, Root->left_node);
        cout << Root->value << ", ";
        helpPrint(ost, Root->right_node);
    }
}

int BinaryTree::countNodes(Node *Root)
{
    if (Root == NULL)
        return 0;
    else
    {
        int count = 1;
        count += countNodes(Root->left_node);
        count += countNodes(Root->right_node);
        return count;
    }
}
