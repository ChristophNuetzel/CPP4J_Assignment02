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

    testTree01[3] = "Thomas";
    assert(testTree01.count() == 1);
    assert(testTree01[3] == "Thomas");

    testTree01[4] = "Fett";
    assert(testTree01.count() == 2);
    assert(testTree01[3] == "Thomas");
    assert(testTree01[4] == "Fett");
    assert(!(testTree01[4] == "Blubb"));

    cout << "Checkpoint 1 reached." << endl;

    testTree01[4] = "Blubb";
    assert(testTree01.count() == 2);
    assert(testTree01[3] == "Thomas");
    assert(testTree01[4] == "Blubb");
    assert(!(testTree01[4] == "Fett"));

    cout << "Checkpoint 2 reached." << endl;

    testTree01[0] = "TestString[0]";
    assert(testTree01.count() == 3);
    assert((testTree01[0] == "TestString[0]"));
    assert(testTree01[3] == "Thomas");
    assert(testTree01[4] == "Blubb");
    assert(!(testTree01[4] == "Fett"));

    cout << "Checkpoint 3 reached." << endl;

    testTree01[2] = "TestString[2]";
    assert(testTree01.count() == 4);
    assert((testTree01[2] == "TestString[2]"));
    assert((testTree01[0] == "TestString[0]"));
    assert(testTree01[3] == "Thomas");
    assert(testTree01[4] == "Blubb");
    assert(!(testTree01[4] == "Fett"));

    cout << "Checkpoint 4 reached." << endl;

    testTree01[2] = "TestString[zweiter Versuch]";
    assert(testTree01.count() == 4);
    assert(!(testTree01[2] == "TestString[2]"));
    assert(testTree01[2] == "TestString[zweiter Versuch]");
    assert((testTree01[0] == "TestString[0]"));
    assert(testTree01[3] == "Thomas");
    assert(testTree01[4] == "Blubb");
    assert(!(testTree01[4] == "Fett"));

    cout << "Checkpoint 5 reached." << endl;

    testTree01[1] = "TestString[1]";
    assert(testTree01.count() == 5);
    assert(!(testTree01[2] == "TestString[2]"));
    assert(testTree01[2] == "TestString[zweiter Versuch]");
    assert((testTree01[0] == "TestString[0]"));
    assert(testTree01[3] == "Thomas");
    assert(testTree01[4] == "Blubb");
    assert(!(testTree01[4] == "Fett"));


    cout << "Test program for Assignment02 finished successfully!" << endl;

    return 0;
}

