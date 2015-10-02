#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "binarytree.h"
#include "test1.h"

using namespace std;

int test1()
{
    int numbers[20];
    srand (time(NULL));
    cout << "TESTING EMPTY CONSTRUCTOR AND ADD_ITEM" << endl << "---------------------------------------" << endl << endl;
    Sleep(2500);
    cout << "Creating empty tree" << endl;
    Sleep(100);
    BinaryTree test;
    cout << "Generating random numbers in range 1 - 100" << endl;
    Sleep(200);
    for (int i=1; i<=20; i++) {
        int randomNumber = rand() % 100 +1;
        test = test + randomNumber;
        cout <<  "Number " << i << " is " << randomNumber << endl;
        numbers[i-1] = randomNumber;
        Sleep(200);
    }
	test.nodeCount(test);
    cout << endl << "Printing tree" << endl << endl;
    test.inorder();
    test.postorder();
    test.preorder();
    Sleep(3000);

    cout << endl << "TESTING EXISTS FUNCTION" << endl << "------------------------" << endl << endl;
    Sleep(3000);
    cout << endl << "Checking all generated numbers" << endl;
    for (int i=0; i<20; i++)
    {
        test.exists(numbers[i]);
        Sleep(200);
    }
    Sleep(200);
    cout << endl << "Checking 10 randomly generated numbers" << endl;
    for (int i=1; i<=10; i++)
    {
        int randomNumber = rand() %100 + 1;
        test.exists(randomNumber);
        Sleep(500);
    }

    cout << endl << "TESTING REMOVE FUNCTION" << endl << "------------------------" << endl << endl;
    Sleep(3000);
    cout << "Removing five numbers from the tree" << endl;
    Sleep(1000);
	
	int a = 1;
	for (int i=0; i<5; i++) {
		cout <<  "Number " << a << " is " << numbers[a] << endl;
		test.remove(numbers[a]);
		Sleep(200);
		a += 3;
	}
      
   	test.nodeCount(test);	
    cout << endl << "Printing tree" << endl << endl;
    test.inorder();
    test.postorder();
    test.preorder();
    Sleep(3000);
    cout << endl;

    return 0;
}
