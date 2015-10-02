#include <iostream>
#include <vector>

#include "binarytree.h"
#include "test1.h"

using namespace std;

int main()
{
    int myints[] = {8,15,2,45,100,1,4,3};
    std::vector<int> first;
    first.assign(myints, myints+8);
    int option;
    int decision;
    int exit = 1;

    BinaryTree btree(first);

    while(exit == 1)
    {
        cout << "Press 1 to begin test" << endl;
        cout << "Press 2 to go to Menu" << endl;
        cout << "Press 0 to exit" << endl;
        cin >> option;
        if (option == 1)
            test1();
        if (option == 0)
            exit = 0;
        if (option == 2)
            exit = 2;
    }

    while(exit == 2)
    {
        cout << endl;
        cout << "Binary Tree menu" << endl;
        cout << "Press 1 to insert a number" << endl;
        cout << "Press 2 to print binary tree" << endl;
        cout << "Press 3 to check if number exists" << endl;
        cout << "Press 4 to delete a number" << endl;
        cout << "Press 0 to exit" << endl;
        cin >> decision;
        if (decision == 1)
        {
            cout << "Enter the number followed by ENTER" << endl;
            cin >> btree;
        }
        if (decision == 2)
        {
            btree.inorder();
            btree.postorder();
            btree.preorder();
        }
        if (decision == 3)
        {
            int find = 0;
            cout << "Enter the number you want to find followed by ENTER" << endl;
            cin >> find;
            btree.exists(find);
        }
        if (decision == 4)
        {
            int number;
            cout << "Enter the number to delete" << endl;
            cin >> number;
            btree.remove(number);
        }
        if (decision == 0)
            exit = 0;
    }

    return 0;
}
