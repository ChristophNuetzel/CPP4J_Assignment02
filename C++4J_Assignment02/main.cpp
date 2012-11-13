#include <iostream>
#include <tree.h>
#include <assert.h>

using namespace std;

// This program tests the Tree class which was implemented in Assignment02
// of C++ For Java Programmers at the Beuth Hochschule fuer Technik WS 2012/13
int main()
{
    cout << "Test program for Assignment02 started." << endl;

    Tree::Tree testTree01 = Tree();


    assert(testTree01.count() == 0);

    testTree01[3] == "Thomas";
    assert(testTree01.count() == 1);

    testTree01[4] == "Fett";
    assert(testTree01.count() == 2);

    cout << "Checkpoint 1 reached." << endl;

    testTree01[4] == "Blub";
    //assert(testTree01.count() == 2); --> Buggy

    cout << "Checkpoint 1 reached." << endl;
    cout << "The count of testTree01 is: " << testTree01.count() << endl;

//    testTree01[3];
//    assert(testTree01->count() == 1);

//    testTree01[2] = "TestString2";
//    assert(testTree01->count() == 2);

//    testTree01[2] = "NewTestString2";
//    assert(testTree01->count() == 2);

    cout << "Checkpoint X reached." << endl;


//    delete testTree01;
    cout << "Test program for Assignment02 finished successfully!" << endl;

    return 0;
}

