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

    cout << "Checkpoint 6 reached." << endl;

    testTree01[88] = "TestString[88]";
    testTree01[55] = "TestString[55]";
    testTree01[66] = "TestString[66]";
    testTree01[77] = "TestString[77]";
    testTree01[11] = "TestString[11]";
    testTree01[12] = "TestString[12]";

//    testTree01.clear();
//    assert(testTree01.count() == 0);

  /*  assert(!(testTree01.contains(88)));
    assert(!(testTree01.contains(55)));
    assert(!(testTree01.contains(66)));
    assert(!(testTree01.contains(77)));
    assert(!(testTree01.contains(11)));
    assert(!(testTree01.contains(12)));*/

    cout << testTree01.count() << endl;

  /*  assert(!(testTree01[9456] == "TestString[88]"));
    assert(!(testTree01[55] == "TestString[55]"));
    assert(!(testTree01[66] == "TestString[66]"));
    assert(!(testTree01[77] == "TestString[77]"));
    assert(!(testTree01[11] == "TestString[11]"));
    assert(!(testTree01[12] == "TestString[12]"));*/

    cout << testTree01.count() << endl;
    cout << testTree01.countCompleteNodes() << endl;
    cout << "Checkpoint 7 reached." << endl;

    testTree01[11] = "TestString[11]";
    testTree01[12] = "TestString[12]";

    cout << "Do something nice here" << endl;

    cout << "Checkpoint 8 reached." << endl;

    for(TreeIterator i=testTree01.begin(); i!=testTree01.end(); ++i) {
       std::cout << i.key() << ": " << i.value().data() << std::endl;
    }

    cout << "Also the decrementing iterator:" << endl;

    for(TreeIterator i=testTree01.find(4); i!=testTree01.end(); --i) {
       std::cout << i.key() << ": " << i.value().data() << std::endl;
    }

    cout << "Test program for Assignment02 finished successfully!" << endl;

    return 0;
}

